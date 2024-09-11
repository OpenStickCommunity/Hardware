// --------------------------
// NFC Console Loading System
// Version 1.0
// Designed by: TheTrain
// --------------------------
//
// Attribution
// 
// The following text must be included in any distribution of derivatives of this code. All links must also be included.
//
// Based on the [NFC Console Loading System](https://github.com/OpenStickCommunity/Hardware) designed by TheTrain.
// 
// Copyright 2024 [TheTrain](https://x.com/TheTrain24)(https://github.com/OpenStickCommunity)
//
// [Licensed under CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)
// 
// Changes from the original design:
//  - list any changes you make here
//
// Original idea from:
//    Tapto - An open source NFC loading system for MiSTer (https://github.com/TapToCommunity)
//
// Special thanks to:
//    [Lucipher](https://github.com/arntsonl)
//    [NickGuyver](https://github.com/NickGuyver)
//    [Wizzomafizzo](https://github.com/wizzomafizzo)

#include <Adafruit_PN532.h>
#include <Wire.h>
#include <Adafruit_NeoPixel.h>

// Define the SDA and SCL pins.
// These must be kept on an I2C pair and in order.
// Reference your board pinout diagram to see which pins are connected to which I2C pairs.
// Please note that these are GPIO pins, not the numbered pins on some boards.
// Please note that GPIO pins start at 0 (GPIO0).

constexpr int sda_pin = 4;
constexpr int scl_pin = 5;

// GPIO pin for the WS2812b LEDs
constexpr int led_pin = 0;

// Define which inputs are on which pins.
// Please note that these are GPIO pins, not the numbered pins on some boards.
// Please note that GPIO pins start at 0 (GPIO0).

//                           // GP2040 | Xinput | Switch  | PS3/4/5  | Dinput | Arcade |
constexpr int up_pin = 1;    // UP     | UP     | UP      | UP       | UP     | UP     |
constexpr int down_pin = 2;  // DOWN   | DOWN   | DOWN    | DOWN     | DOWN   | DOWN   |
constexpr int left_pin = 3;  // LEFT   | LEFT   | LEFT    | LEFT     | LEFT   | LEFT   |
constexpr int right_pin = 6; // RIGHT  | RIGHT  | RIGHT   | RIGHT    | RIGHT  | RIGHT  |
constexpr int p1_pin = 7;    // B3     | X      | Y       | Square   | 1      | P1     |
constexpr int p2_pin = 8;    // B4     | Y      | X       | Triangle | 4      | P2     |
constexpr int p3_pin = 9;    // R1     | RB     | R       | R1       | 6      | P3     |
constexpr int p4_pin = 10;   // L1     | LB     | L       | L1       | 5      | P4     |
constexpr int k1_pin = 11;   // B1     | A      | B       | Cross    | 2      | K1     |
constexpr int k2_pin = 12;   // B2     | B      | A       | Circle   | 3      | K2     |
constexpr int k3_pin = 13;   // R2     | RT     | ZR      | R2       | 8      | K3     |
constexpr int k4_pin = 14;   // L2     | LT     | ZL      | L2       | 7      | K4     |
constexpr int s1_pin = 15;   // S1     | Back   | Minus   | Select   | 9      | Coin   |
constexpr int s2_pin = 26;   // S2     | Start  | Plus    | Start    | 10     | Start  |
constexpr int a1_pin = 27;   // A1     | Guide  | Home    | PS       | 13     | ~      |
constexpr int ls_pin = 28;   // L3     | LS     | LS      | L3       | 11     | LS     |
constexpr int rs_pin = 29;   // R3     | RS     | RS      | R3       | 12     | RS     |

// Since the Waveshare RP2040 Zero only has 20 easily accessible GPIO pins A2 (capture) and player 2 coin are disable by default.
// You can add one of these back in if you remove something from above, like the RS button.
// Make sure you change the GPIO pin accordingly.

constexpr int a2_pin = 99;   // A2     | ~      | Capture | ~        | 14     | ~      |
constexpr int p2s1_pin = 99; // S1     | Back   | Minus   | Select   | 9      | Coin   |

// Define the pin array.  
// You can add additional inputs here.

constexpr int pin_array[] = {up_pin, down_pin, left_pin, right_pin, p1_pin, p2_pin, p3_pin, p4_pin, k1_pin, k2_pin, k3_pin, k4_pin, s1_pin, s2_pin, a1_pin, ls_pin, rs_pin, a2_pin, p2s1_pin};

Adafruit_PN532 nfc(sda_pin, scl_pin);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(20, led_pin, NEO_GRB + NEO_KHZ800); // 10 LEDs, GPIO pin, type

// Define the allowed UID values
// To find out the UID vales of your cards just upload this sketch and tap a card.
// If not in the list it will come back saying "Found an NFC card, but not allowed".
// It will also display the IUD in the serial monitor (remember to connect at 115200 baud).
// Depending on the NFC card or token you are using it may be either 4 or 7 characters long.
// An example 7 character UID is { 0x4, 0x79, 0x35, 0x10, 0xB9, 0x2A, 0x81 }.

const uint8_t allowedUIDs[][7] = {
  { 0x6B, 0x45, 0x8B, 0x2F },  // UID 0 - Launch [Game name here]
  { 0xF3, 0x45, 0x22, 0x2A },  // UID 1 - Press the `Home` button
  { 0x79, 0xD3, 0x8B, 0x2F },  // UID 2 - Press the Player 1 `Select` button
  { 0xA7, 0x3D, 0x8B, 0x2F }   // UID 3 - Press the Player 2 `Select` button
  // Add more allowed UIDs here
};

void setup(void) {
  Serial.begin(115200);
  
  // set each pin as output and high
  for (int pin : pin_array) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }

  strip.begin(); // Initialize NeoPixel strip object
  strip.show(); // Turn off all LEDs by default
  
  delay(1000);
  Serial.println("Serial connection has been at 115200 baud.");
  nfc.begin();  
  Serial.println("NFC board has been found and started.");
  
  uint32_t nfc_version = nfc.getFirmwareVersion();
  
  if (!nfc_version) {
    Serial.print("Didn't find PN53x board");
    while (1);
  }
  
  nfc.SAMConfig();
  Serial.println("Waiting for an NFC card to be tapped...");
  
  // Fade LEDs to black to white on first boot
  // Note that cards cannot be tapped until this fade is completed

  for (int i = 0; i <= 255; i++) {
    setAllLEDs(strip.Color(i, i, i));
    delay(5); // Adjust delay for desired fade speed
  }
}

void loop(void) {
  bool isAllowedUID = false;
  
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };
  uint8_t uidLength = 0;
  uint8_t nfc_success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

  if (nfc_success) {
    // Check if the UID is in the allowed list
    for (int i = 0; i < sizeof(allowedUIDs) / sizeof(allowedUIDs[0]); i++) {
      if (memcmp(uid, allowedUIDs[i], uidLength) == 0) {
        isAllowedUID = true;
        break;
      }
    }

    if (isAllowedUID) {
      Serial.println("--------------------------"); // This just adds a nice line to the serial monitor output to help keep multiple taps seperated
      Serial.println("Found an allowed NFC card!");
      Serial.print("UID Length: ");Serial.print(uidLength, DEC);Serial.println(" bytes");
      Serial.print("UID Value: ");
    
      for (uint8_t i=0; i < uidLength; i++) {
        Serial.print(" 0x");Serial.print(uid[i], HEX);
      }
      Serial.println("");

      // Set all LEDs to green for 1 second
      setAllLEDs(strip.Color(0, 255, 0));

      // Do different things based on the UID
      // Example:
      //      writeDelay(a1_pin, 100, 500);
      //            a1_pin = The input pin you set at the top
      //            100 = The amount of time in ms (1/1000 of a second) to hold down the button before releasing
      //            500 = The amount of time in ms (1/1000 of a second) to wait after the button has been pressed before moving to the next line
      
      if (memcmp(uid, allowedUIDs[0], uidLength) == 0) {
        Serial.println("UID 1 detected - Pressing the `Home` button");  
        writeDelay(a1_pin, 100, 1000);
      } 
      
    else if (memcmp(uid, allowedUIDs[1], uidLength) == 0) {
        Serial.println("UID 2 detected - Pressing the Player 1 `Select` button");
        writeDelay(s1_pin, 100, 2000);
      }

    else if (memcmp(uid, allowedUIDs[2], uidLength) == 0) {
        Serial.println("UID 3 detected - Pressing the Player 2 `Select` button");
        writeDelay(p2s1_pin, 100, 1000);
      }

    else if (memcmp(uid, allowedUIDs[3], uidLength) == 0) {
        Serial.println("UID 4 detected - Launching [Game name here]");
        writeDelay(a1_pin, 100, 500);
        writeDelay(left_pin, 100, 500);
        writeDelay(k2_pin, 100, 2000);
        writeDelay(p4_pin, 100, 500);
        writeDelay(right_pin, 100, 250);
        writeDelay(right_pin, 100, 500);
        writeDelay(k2_pin, 100, 1000);
        writeDelay(k2_pin, 100, 1000);
        writeDelay(k2_pin, 100, 2000);
      }
    
      // Add more conditional actions for other allowed UIDs
      // UID list starts at 0
      // You write your list of UIDs starting on line 27
    }
  
  else {
      Serial.println("----------------------------------"); // This just adds a nice line to the serial monitor output to help keep multiple taps seperated
      Serial.println("Found an NFC card, but not allowed");
      Serial.print("UID Length: ");Serial.print(uidLength, DEC);Serial.println(" bytes");
      Serial.print("UID Value: ");
      for (uint8_t i=0; i < uidLength; i++) {
        Serial.print(" 0x");Serial.print(uid[i], HEX);
      }
      Serial.println("");
      
      // Set all LEDs to red for 1 second
      setAllLEDs(strip.Color(255, 0, 0));
      delay(1000);

    delay(1000); // This delay forces a 1000ms delay between card scanning preventing double taps
    

    // Each button press has a wait legth at the end
    // The last button pressed will also have a wait if you add it
    // The above wait will be in adition to the last button pressed wait
    // If you do not have a sufficent amount of overall wait time your card may tap twice
    // This wait will also prevent taps from other cards from being made
    }
    
  }
  
  // Set LEDs back to white
  setAllLEDs(strip.Color(255, 255, 255));
}

void writeDelay(int pin, int delay_low, int delay_high) {
    digitalWrite(pin, LOW);
    delay(delay_low);
    digitalWrite(pin, HIGH);
    delay(delay_high);
}

// Helper function to set all LEDs to a specific color
void setAllLEDs(uint32_t color) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}