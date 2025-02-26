// -----------------------------------------------------------------------------------------------------------------------
// Forza Wind Sim v1.0
// Copyright TheTrain 2025
// -----------------------------------------------------------------------------------------------------------------------
//
// The following text must be included in any distribution of derivatives of this board. All links must also be included.
// Based on the Forza Wind Sim by TheTrain
// Copyright © 2025 TheTrain
//
// Licensed under CC BY 4.0
// https://creativecommons.org/licenses/by/4.0/
//
// Changes from the original design:
// list any changes you make here
//
// -----------------------------------------------------------------------------------------------------------------------
//
// Summary:
//
// The Forza Wind Sim is a simple and low cost way to add wind simulation to Forza Motorsport 2023 for the Xbox.
// You will need the following parts to make this project work:
// 1-4x 4pin PWM computer fans - It is recommended to 120mm fans although you can use larger or smaller ones if you like
// 1x Raspberry Pi Pico W
// 1x Small SSD1305 OLED - Normally 0.96" or 1.31" to display info on the screen.
// 1x Compatible power adapter for the fan (normally 12v but check your fans)
//
// Please note that you must split the ground signal from the power supply and have it go to a GND on the Pico W
//
// -----------------------------------------------------------------------------------------------------------------------
//
// How to wire up the Raspberry Pi Pico W:
//
//                             O  1     [  ]   40  O - OLED VCC
//                             O                   O
//                  OLED GND - O  3                O - Fan GND pin split
//                             O                   O
//                             O                   O
//         OLED SDA - GPIO04 - O  6                O
//         OLED SCL - GPIO05 - O  7                O
//                             O                   O
//  Increase Button - GPIO06 - O  9                O
//  Decrease Button - GPIO07 - O  10               O
//    Reboot Button - GPIO08 - O  11               O
//     Fan PWN pin - GPIO09 -  O  12               O
//                             O                   O
//                             O                   O
//                             O                   O
//                             O                   O
//                             O                   O
//                             O                   O
//                             O                   O
//                             O  20           21  O
//
// -----------------------------------------------------------------------------------------------------------------------

#include <WiFi.h>                        // Required for WiFi to work on the Raspberry Pi Pico W
#include <WiFiUdp.h>                     // Required for UDP to work (Forza telemetry)
#include <Adafruit_GFX.h>                // Required for the connected OLED screen
#include <Adafruit_SSD1306.h>            // Required for the connected OLED screen
#include "hardware/gpio.h"               // Required for GPIO functions (push buttons)
#include "pico/stdlib.h"                 // Required for reboot
#include "hardware/pwm.h"                // Required for PWM functions (fan speed control)

// WiFi credentials
char ssid[] = "XXXXX";                   // Your WiFi SSID (written in quotes)
char password[] = "XXXXX";               // Your Wifi password (written in quotes)

// Static IP configuration
IPAddress localIP(0, 0, 0, 0);           // Static IP address (must match Forza's settings)
IPAddress gateway(0, 0, 0, 0);           // Gateway IP address (usually your router's IP)
IPAddress subnet(0, 0, 0, 0);            // Subnet mask (usually leave this as is)
IPAddress dns(8, 8, 8, 8);               // DNS server (Google's public DNS) [usually leave this as is]

// UDP settings
WiFiUDP udp;                             // Loads up the ability to work with UDP data
unsigned int localPort = 3086;           // Port to listen on (must match Forza's settings)
const int packetSize = 331;              // Size of the Forza "Dash" packet (leave this as is)

// Fan motor settings
const int fanPin = 9;                    // PWM GPIO pin for the fan motor on the Raspberry Pi Pico W
const int minSpeed = 10;                 // Minimum fan speed (try to find the lowest setting before the fan starts spinning)
const int maxSpeed = 255;                // Maximum fan speed (100% duty cycle) [usually leave this as is]
float maxCarSpeed = 40.0;                // Percentage of maximum car speed to make fans run at 100% (adjust as needed)

// Button pins
const int button1Pin = 6;                // GPIO for button 1 - Increase 'maxCarSpeed' by 5%
const int button2Pin = 7;                // GPIO for button 2 - Decrease 'maxCarSpeed' by 5%
const int button3Pin = 8;                // GPIO for button 3 - Force a reboot of the code (good if things get stuck)

// OLED display settings
#define SCREEN_WIDTH 128                 // Width in pixels of the OLED (usually leave this as is)
#define SCREEN_HEIGHT 64                 // Height in pixels of the OLED (usually leave this as is)
#define OLED_RESET -1                    // Reset GPIO pin (usually leave this as '-1')
#define OLED_ADDR 0x3C                   // Address of the OLED display (usually leave this as is) [should be printed on the display somewhere]

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// WiFi retry settings
const int maxWifiRetries = 5;            // Number of times to retry a failed WiFi connection
const int wifiRetryDelay = 1000;         // Number of milliseconds to wait between retries

bool wifiConnected = false;              // Global variable to track WiFi connection status

// Function to clear the display and reboot the Pico
void rebootPico() {
    Serial.println("Rebooting now...");
    display.clearDisplay();
    display.display();
    delay(100);                          // Small delay to ensure the display clears
    watchdog_enable(1000, 1);            // Enable watchdog timer for 1 second
    while(1);                            // Wait for watchdog to trigger reboot
}

// Function to connect to WiFi
void connectWiFi() {
  int retries = 0;
  WiFi.config(localIP, gateway, subnet, dns);
  WiFi.begin(ssid, password);
  display.setCursor(0, 20);
  Serial.print("Connecting to WiFi...");
  display.print("Connecting to WiFi...");
  display.display();
  delay(1000);

  while (WiFi.status() != WL_CONNECTED && retries < maxWifiRetries) {
    Serial.print(".");
    delay(wifiRetryDelay);
    retries++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Forza Wind Sim v1.0");
    display.setCursor(0, 10);
    display.print("---------------------");
    display.setCursor(0, 20);
    display.print("Connecting WiFi...");
    display.setCursor(0, 30);
    display.print("[SUCCESSFUL]");
    display.setCursor(0, 40);
    display.print("IP: ");
    display.print(WiFi.localIP());
    display.display();
    delay(1000);                         // Give time to view IP Address
    wifiConnected = true;                // Set the flag to true
  } else {
    Serial.println("\nWiFi connection failed after multiple retries.");
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Forza Wind Sim v1.0");
    display.setCursor(0, 10);
    display.print("---------------------");
    display.setCursor(0, 20);
    display.print("Connecting WiFi...");
    display.setCursor(0, 30);
    display.print("[FAILED]");
    display.setCursor(0, 40);
    display.print("Rebooting now...");
    display.display();
    wifiConnected = false;               // Set the flag to false
    delay(1000);                         // Give time to view notice that Pico is rebooting
    rebootPico();                        // Reboot if WiFi connection fails multiple times
  }
}

void setup() {
  // Initialize Serial for debugging
  Serial.begin(115200);
  //while (!Serial);                     // Wait for Serial to initialize (mainly for debugging) [take out the // to enable this]

  // Initialize button pins
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("SSD1306 allocation failed"));
    //for (;;);                          // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Forza Wind Sim v1.0");
  display.setCursor(0, 10);
  display.print("---------------------");
  display.display();

  // Connect to WiFi
  connectWiFi();

  // Start UDP
  if (wifiConnected && udp.begin(localPort)) {
    Serial.println("UDP started on port: " + String(localPort));
    display.setCursor(0, 50);
    display.print("UDP port: " + String(localPort));
    display.display();
    delay(2000);
  } else {
      Serial.println("Failed to start UDP");
      display.setCursor(0, 50);
      display.print("UDP listening [FAILED]");
      display.display();
      delay(2000);                       // Give time for display
    rebootPico();                        // Reboot if UDP fails
  }

  // Set up the fan motor pin
  pinMode(fanPin, OUTPUT);
  analogWrite(fanPin, 0);                // Initialize fan speed to 0
}

void loop() {
  // Check for button presses
  if (digitalRead(button1Pin) == LOW) {
    delay(50);                           // Debounce setting (you should not need to adjust)
    if (digitalRead(button1Pin) == LOW) {
      if (maxCarSpeed < 100.0) {
        maxCarSpeed += 5.0;
        if (maxCarSpeed > 100.0) maxCarSpeed = 100.0;  // Ensure it doesn't go over 100
        Serial.print("maxCarSpeed increased to: ");
        Serial.println(maxCarSpeed);
      }
      while (digitalRead(button1Pin) == LOW);
    }
  }

  if (digitalRead(button2Pin) == LOW) {
    delay(50); // Debounce
    if (digitalRead(button2Pin) == LOW) {
      if (maxCarSpeed > 0.0) {
        maxCarSpeed -= 5.0;
        if (maxCarSpeed < 0.0) maxCarSpeed = 0.0;  // Ensure it doesn't go below 0
        Serial.print("maxCarSpeed decreased to: ");
        Serial.println(maxCarSpeed);
      }
      while (digitalRead(button2Pin) == LOW);
    }
  }

  if (digitalRead(button3Pin) == LOW) {
      rebootPico();                      // Reboot if 'Button 3' is pressed
  }

  // Check for UDP packets
  if (wifiConnected) {                   // Only process UDP if WiFi is connected
    int packetLength = udp.parsePacket();
    if (packetLength > 0) {
      Serial.print("Packet received. Length: ");
      Serial.println(packetLength);

      // Read the packet into a buffer
      uint8_t packetBuffer[packetSize];
      int bytesRead = udp.read(packetBuffer, packetSize);

      if (bytesRead != packetLength) {
        Serial.print("Warning: Read ");
        Serial.print(bytesRead);
        Serial.print(" bytes, expected ");
        Serial.println(packetLength);
      }

      // Extract the car speed (offset 244 in the "Dash" packet)
      if (bytesRead == packetSize) {
        float carSpeed;
        memcpy(&carSpeed, &packetBuffer[244], sizeof(float));

        // Print the car speed for debugging
        Serial.print("Car Speed: ");
        Serial.print(carSpeed);
        Serial.println(" %");
        Serial.print("Max Car Speed: ");
        Serial.print(maxCarSpeed);
        Serial.println(" %");

         // Map the car speed to fan speed (0-255)
        int fanSpeed = map(carSpeed, 0, maxCarSpeed, minSpeed, maxSpeed);
        fanSpeed = constrain(fanSpeed, minSpeed, maxSpeed);  // Ensure it's within bounds

        // Set the fan speed using PWM
        analogWrite(fanPin, fanSpeed);

        // Print the fan speed for debugging
        Serial.print("Fan Speed: ");
        Serial.println(fanSpeed);

        // Update the OLED display
          char carSpeedStr[10];          // Buffer to hold the string representation of carSpeed
          char maxCarSpeedStr[10];       // Buffer to hold the string representation of maxCarSpeed
          dtostrf(carSpeed, 4, 1, carSpeedStr);  // Convert carSpeed to string with 1 decimal place
          dtostrf(maxCarSpeed, 4, 1, maxCarSpeedStr);  // Convert maxCarSpeed to string with 1 decimal place

          display.clearDisplay();
          display.setCursor(0, 0);
          display.print("Forza Wind Sim v1.0");
          display.setCursor(0, 10);
          display.print("---------------------");
          display.setCursor(0, 20);
          display.print("Car Speed: ");
          display.print(carSpeedStr);
          display.print("%");
          display.setCursor(0, 30);
          display.print("Speed/Fan Ratio: ");
          display.print(maxCarSpeedStr);
          display.setCursor(0, 40);
          display.print("Fan Speed: ");
          display.print(fanSpeed);
          display.display();
      } else {
        Serial.println("Unexpected packet size");
          display.clearDisplay();
          display.setCursor(0, 0);
          display.print("Forza Wind Sim v1.0");
          display.setCursor(0, 10);
          display.print("---------------------");
          display.setCursor(0, 20);
          display.print("Packet Error");
          display.display();
      }
    } else {
      // Add a small delay to avoid spamming the serial output
      delay(100);
      // Serial.println("No packet received"); // Uncomment for debugging if needed
    }
  } else {
    // If WiFi is not connected, try reconnecting and rebooting.
    Serial.println("WiFi not connected.  Attempting to reconnect.");
    delay(1000); // Wait before attempting to reconnect.
    connectWiFi(); //Try and reconnect to WiFi
  }
}