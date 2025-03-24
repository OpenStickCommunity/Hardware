// -----------------------------------------------------------------------------------------------------------------------
// Forza Laptimer v1.0
// Copyright TheTrain 2025
// -----------------------------------------------------------------------------------------------------------------------
//
// The following text must be included in any distribution of derivatives of this board. All links must also be included.
// Based on the Forza Laptimer by TheTrain
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
// The Forza Laptimer is a simple and low cost way to add a lap timer to Forza Motorsport 2023 for the Xbox.
// You will need the following parts to make this project work:
// 1x 3.12" 256x64 OLED
// 1x Raspberry Pi Pico W
//
// Optionally you can print the included case for the Pico W and OLED screen and attach it to your sim rig.
//
// -----------------------------------------------------------------------------------------------------------------------
//
// How to connect the Pico W to a 3.12" 256x64 OLED
//
// On the OLED you will need to ensure it is in 4SPI mode, most come in 80XX mode
// To get it into 4SPI mode you will need to ensure R5 and R8 are bridged.  In 80XX mode R6 and R8 are bridged.
// To convert from 80XX to 4SPI mode remove the resistor from R6 and add it to R5.  You can also just bridge the pads on R5.
//
// OLED pinout:
//
//     GPIO15 - CS <- [16] [15] -> RESET - GPIO16
//     GPIO02 - DC <- [14] [13]
//                    [12] [11]
//                    [10] [09]
//                    [08] [07]
//                    [06] [05] -> MOSI - GPIO19
//   GPIO18 - SCLK <- [04] [03]
//            VBUS <- [02] [01] -> GND
//
// Raspberry Pi Pico W pinout:
//
//                             O  1     [  ]   40  O - VBUS
//                             O                   O
//                  OLED GND - O  3                O
//               DC - GPIO02 - O  4                O
//                             O                   O
//                             O                   O
//                             O                   O
//                             O                   O
//                             O                   O
//                             O                   O
//                             O                   O
//                             O                   O
//                             O                   O
//                             O                   O
//                             O                   O
//                             O               25  O - GPIO19 - MOSI
//                             O               24  O - GPIO18 - SCLK
//                             O                   O
//                             O                   O
//               CS - GPIO15 - O  20           21  O - GPIO16 - RESET
//
// -----------------------------------------------------------------------------------------------------------------------
//
// !!! Very important note about Forza Motorsport on the Xbox !!!
// After changing the UDP Data Out IP Address in game you may need to save, fully shut down the game and then restart it for the UDP data to start sending
//
// -----------------------------------------------------------------------------------------------------------------------
//
// Other note - I don't know if theres a way to retry the UDP if it ever goes to `FAILED` status.  I have never had it fail to test out.  If it does you may need to restart
//
// -----------------------------------------------------------------------------------------------------------------------

#include <WiFi.h>
#include <WiFiUdp.h>
#include <Wire.h>
#include <U8g2lib.h>

// WiFi credentials
char ssid[] = "XXXXX";                  // YOUR_WIFI_SSID
char password[] = "XXXXX";              // YOUR_WIFI_PASSWORD

// Static IP configuration
IPAddress staticIP(10, 0, 0, 121);      // SStatic IP address (must match Forza's settings)
IPAddress gateway(10, 0, 0, 1);         // Gateway IP address (usually your router's IP)
IPAddress subnet(255, 255, 255, 0);     // Subnet mask (usually leave this as is)
IPAddress dns(8, 8, 8, 8);              // DNS server (Google's public DNS) [usually leave this as is]

// UDP settings
WiFiUDP udp;                             // Loads up the ability to work with UDP data
unsigned int localPort = 3085;           // Port to listen on (must match Forza's settings)
const int packetSize = 331;              // Size of the Forza "Dash" packet (leave this as is)
const int lapNumberOffset = 288;         // Correct offset for lap number

// OLED display settings
#define OLED_ADDR 0x3C                   // Address of the OLED display (usually 0x3C or 0x3D)
#define OLED_RESET -1                    // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_WIDTH 256                 // OLED display width
#define SCREEN_HEIGHT 64                 // OLED display height

// U8g2 display declaration (CHANGE THIS TO MATCH YOUR DISPLAY)
U8G2_SSD1322_NHD_256X64_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 15, /* dc=*/ 2, /* reset=*/ 16); // Example for SPI, adjust pins as needed

// VOID Setup
void setup() {
  delay(1000);                           // Add a small delay before everything starts, adjust as needed

  // Initialize Serial for debugging
  Serial.begin(115200);

  // while (!Serial);                    // Remove the '//' here if you want to wait for Serial to initialize (for debugging)

  // U8g2 OLED display init
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_profont12_tf); // Use a default font for "Starting"
  u8g2.drawStr(4, 13, "Forza RaceLogic LapTimer v1.0");
  u8g2.drawStr(4, 24, "-----------------------------"); 
  u8g2.sendBuffer();
  delay(1000);

  // Configure static IP
  WiFi.config(staticIP, gateway, subnet, dns);

  // Connect to WiFi with retry
  Serial.print("Connecting to WiFi...");

  u8g2.setFont(u8g2_font_profont12_tf);
  u8g2.drawStr(4, 35, "Connecting WiFi...");
  u8g2.sendBuffer();

  while (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
    int retryCount = 0;
    while (WiFi.status() != WL_CONNECTED && retryCount < 2) { // Try for 2 seconds
      delay(500);
      retryCount++;
    }
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("\nWiFi connection failed, retrying in 2 seconds...");
      u8g2.clearBuffer();
      u8g2.drawStr(4, 13, "Forza RaceLogic LapTimer v1.0");
      u8g2.drawStr(4, 24, "-----------------------------"); 
      u8g2.drawStr(4, 35, "Connecting WiFi...[RETRY]");
      u8g2.sendBuffer();
      delay(2000); // Wait 2 seconds before retrying
    }
  }

  Serial.println("\nWiFi connected");
  u8g2.clearBuffer();
  u8g2.drawStr(4, 13, "Forza RaceLogic LapTimer v1.0");
  u8g2.drawStr(4, 24, "-----------------------------"); 
  u8g2.drawStr(4, 35, "Connecting WiFi...[CONNECTED]");
  u8g2.sendBuffer();
  delay(1000);

  // Print the assigned IP address
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  u8g2.clearBuffer();
  u8g2.drawStr(4, 13, "Forza RaceLogic LapTimer v1.0");
  u8g2.drawStr(4, 24, "-----------------------------"); 
  u8g2.drawStr(4, 35, "Connecting WiFi...[CONNECTED]");
  u8g2.drawStr(4, 49, "IP Address:.......[");

  // Convert IPAddress to string and print it
  char ipString[16];
  sprintf(ipString, "%d.%d.%d.%d", WiFi.localIP()[0], WiFi.localIP()[1], WiFi.localIP()[2], WiFi.localIP()[3]);
  u8g2.setCursor(u8g2.getStrWidth("IP Address:.......[") + 6 , 49);
  u8g2.print(ipString);
  u8g2.print("]");
  u8g2.sendBuffer();
  delay(1000);

  // Start UDP
  if (udp.begin(localPort)) {
    Serial.println("UDP started");

    u8g2.setFont(u8g2_font_profont12_tf);
    u8g2.drawStr(4, 63, "UDP Status........[Started]");
    u8g2.sendBuffer();
  } else {
    Serial.println("Failed to start UDP");

    u8g2.setFont(u8g2_font_profont12_tf);
    u8g2.drawStr(4, 63, "UDP Status........[Failed]");
    u8g2.sendBuffer();
    while (true); // Halt if UDP fails
  }
  delay(1000);
}

void loop() {
  // Check for UDP packets
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

    // Extract the current lap time (offset 292 in the "Dash" packet)
    float currentLapTime;
    memcpy(&currentLapTime, &packetBuffer[292], sizeof(float));

    // Extract the lap number (2 bytes)
    uint16_t Lap;
    memcpy(&Lap, &packetBuffer[300], sizeof(uint16_t));

    // Convert lap time to minutes, seconds, and milliseconds
    int minutes = (int)(currentLapTime / 60);
    float remainingSeconds = currentLapTime - (minutes * 60);
    int seconds = (int)remainingSeconds;
    int milliseconds = (int)((remainingSeconds - seconds) * 1000);

    // Format the lap time string, always hiding the last two digits of milliseconds
    char lapTimeString[20];
    if (currentLapTime < 1) {
      sprintf(lapTimeString, "%01d", milliseconds / 100); // Display only the first digit of milliseconds
    } else if (currentLapTime < 10) {
      sprintf(lapTimeString, "%01d.%01d", seconds, milliseconds / 100); // Display seconds and first digit of milliseconds
    } else if (currentLapTime < 60) {
      sprintf(lapTimeString, "%02d.%01d", seconds, milliseconds / 100); // Display seconds and first digit of milliseconds
    } else if (currentLapTime < 600) {
      sprintf(lapTimeString, "%01d:%02d.%01d", minutes, seconds, milliseconds / 100); // Display seconds and first digit of milliseconds
    } else {
      sprintf(lapTimeString, "%02d:%02d.%01d", minutes, seconds, milliseconds / 100); // Display minutes, seconds, and first digit of milliseconds
    }
    Serial.print("Current Lap Time: ");
    Serial.println(lapTimeString);

    // Format the lap number to always display two digits
    char lapNumberString[3];
    sprintf(lapNumberString, "%02d", Lap + 1);
    u8g2.clearBuffer();

    // --- Start of Lap Time Display ---

    // Define fonts for each character
    const uint8_t* fonts[] = {
      u8g2_font_logisoso54_tn,           // Font for the first character - First minuet character - [0]0:00.0
      u8g2_font_logisoso54_tn,           // Font for the second character - Second minuet character - 0[0]:00.0
      u8g2_font_logisoso54_tn,           // Font for the third character - ':' character - 00[:]00.0
      u8g2_font_logisoso54_tn,           // Font for the fourth character - First second character - 00:[0]0.0
      u8g2_font_logisoso54_tn,           // Font for the fifth character - Second second character - 00:0[0].0
      u8g2_font_logisoso54_tn,           // Font for the sixth character - '.' character - 00:00[.]0
      u8g2_font_logisoso54_tn,           // Font for the seventh character - First milisecond character - 00:00.[0]
    };

    // Define positions for each character, right-justified
    int charX[] = {
      0,                                 // X position for the first character - First minuet character - [0]0:00.0
      32,                                // X position for the second character - Second minuet character - 0[0]:00.0
      60,                                // X position for the third character - ':' character - 00[:]00.0
      81,                                // X position for the fourth character - First second character - 00:[0]0.0
      113,                               // X position for the fifth character - Second second character - 00:0[0].0
      144,                               // X position for the sixth character - '.' character - 00:00[.]0
      162,                               // X position for the seventh character - First milisecond character - 00:00.[0]
    };

    int charY = 60; // Y position for all characters

    // Convert lapTimeString to an array of characters
    char lapTimeChars[20];
    strcpy(lapTimeChars, lapTimeString);

    int lapTimeLength = strlen(lapTimeChars);          // Get the actual length of the lap time string
    if (lapTimeLength <= 7) {                          // Check if the length is up to 7 characters
      int start_index = 7 - lapTimeLength;             // Calculate the starting index for the charX array
      for (int i = 0; i < lapTimeLength; i++) {
        u8g2.setFont(fonts[i]);                        // Set the font for the current character
        u8g2.setCursor(charX[start_index + i], charY); // Set the position for the current character
        u8g2.print(lapTimeChars[i]);                   // Print the current character
      }
    } else {
      Serial.println("Lap time string too long, skipping display...");
    }
    // --- End of Lap Time Display ---

    // Display the word `Lap` on the OLED
    u8g2.setFont(u8g2_font_crox5hb_tf);  // Font for the word `Lap`
    u8g2.setCursor(214, 22);             // Position of the word `Lap`
    u8g2.print("Lap");                   // What to display on the OLED

    // Display the lap number on the OLED
    u8g2.setFont(u8g2_font_crox4h_tf);   // Font for lap number
    u8g2.setCursor(224, 60);             // Position of lap number
    u8g2.print(lapNumberString);         // What to display on the OLED

    u8g2.sendBuffer();
  } else {
    Serial.println("Unexpected packet size, skipping...");
  }
}