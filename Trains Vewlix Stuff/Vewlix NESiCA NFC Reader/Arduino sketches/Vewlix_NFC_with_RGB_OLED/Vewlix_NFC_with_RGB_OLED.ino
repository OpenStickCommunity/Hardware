// --------------------------
// NFC Console Loading System
// Version 2.0
// Designed by: TheTrain
// --------------------------
//
// Attribution
// 
// The following text must be included in any distribution of derivatives of this code. All links must also be included.
//
// Based on the [NFC Console Loading System](https://github.com/OpenStickCommunity/Hardware) designed by TheTrain.
// 
// Copyright 2025 [TheTrain](https://x.com/TheTrain24)(https://github.com/OpenStickCommunity)
//
// [Licensed under CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)
// 
// Changes from the original design:
//  - list any changes you make here
//
// Original idea from:
//    Tapto - An open source NFC loading system for MiSTer (https://github.com/TapToCommunity) [Now replaced with Zaparoo (https://github.com/ZaparooProject)]
//
// Special thanks to:
//    [Lucipher](https://github.com/arntsonl)
//    [NickGuyver](https://github.com/NickGuyver)
//    [Wizzomafizzo](https://github.com/wizzomafizzo)
//
// --------------------------
//
// How to connect everything - For this example I used the new 'Pico Mini RP2040' found on AliExpress which is like the RP2040 SuperMini but has a few more GPIO
//
// Pico Mini RP2040 pinout:
//
//                        FN - O        [  ]       O - VBUS
//                  Option 1 - O                   O - GND
//                    SD SCK - O                   O - RST [not used]
//                   SD MOSI - O                   O - +3v3
//                   SD MISO - O                   O - R3
//            SD Chip Select - O                   O - L3
//                   NFC SDA - O                   O - A1
//                   NFC SCL - O                   O - S2
//                  OLED SDA - O                   O - A2
//                  OLED SCL - O                   O - S1
//                        Up - O                   O - K4
//                      Down - O                   O - K3
//                      Left - O                   O - K2
//                     Right - O                   O - K1
//                               O   O   O   O   O
//                               |   |   |   |   |
//                               P1  P2  RGB P3  P4
//
// --------------------------

#include <Wire.h>
#include <Adafruit_PN532.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <SD.h>
#include <vector>
#include <sstream> 
#include <string.h> 

// SD Card Configuration (SPI0) ---
const int SD_SCK_PIN         = 2; // SPI0 SCK
const int SD_MOSI_PIN        = 3; // SPI0 TX
const int SD_MISO_PIN        = 4; // SPI0 RX
const int SD_CHIP_SELECT_PIN = 5; // SD_CS

// NFC Module Pins (I2C1) ---
constexpr int nfc_sda_pin = 6; // I2C1 SDA
constexpr int nfc_scl_pin = 7; // I2C1 SCL
Adafruit_PN532 nfc(-1, -1, &Wire1);

// OLED Display Configuration (I2C0) ---
const int OLED_SDA_PIN = 8;  // I2C0 SDA
const int OLED_SCL_PIN = 9;  // I2C0 SCL
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// RGB LED Pin ---
constexpr int led_pin = 16; 

// Pin Definitions ---
// Ensure these do NOT conflict with system pins
constexpr int fn_pin = 0;
constexpr int p2s1_pin = 1;
constexpr int up_pin = 10;
constexpr int down_pin = 11;
constexpr int left_pin = 12;
constexpr int right_pin = 13;
constexpr int p1_pin = 14;
constexpr int p2_pin = 15;
constexpr int p3_pin = 17;
constexpr int p4_pin = 18;
constexpr int k1_pin = 19;
constexpr int k2_pin = 20;
constexpr int k3_pin = 21;
constexpr int k4_pin = 22;
constexpr int s1_pin = 23;
constexpr int a2_pin = 25;
constexpr int s2_pin = 26;
constexpr int a1_pin = 27;
constexpr int ls_pin = 28;
constexpr int rs_pin = 29;

// Array of all output pins for easy setup (active low)
constexpr int pin_array[] = {
    up_pin, down_pin, left_pin, right_pin, p1_pin, p2_pin, p3_pin, p4_pin,
    k1_pin, k2_pin, k3_pin, k4_pin, s1_pin, s2_pin, a1_pin, a2_pin, ls_pin,
    rs_pin, p2s1_pin, fn_pin
};

// Setup for the number of RGB LEDs on the attached RGB LED strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(20, led_pin, NEO_GRB + NEO_KHZ800); // 20 LEDs

// --- Dynamic Card Configuration Structures ---
#define MAX_UID_LENGTH 7 // Max length of UIDs expected

struct ActionCommand {
  std::vector<int> pins; // Can hold one or more pins
  int delayLow;          // Milliseconds to hold pins LOW
  int delayHigh;         // Milliseconds to wait after pins go HIGH
};

struct CardConfig {
  uint8_t uid[MAX_UID_LENGTH];
  uint8_t uidLength;
  String oledMessage;
  String oledMessage2;
  std::vector<ActionCommand> actions;
};
std::vector<CardConfig> cardConfigs; // Global list of loaded card configurations

const char* oledWaitingMsg = " ";
const char* oledNotMappedMsg = "-- UID Not Mapped --";
const char* oledSdErrorMsg = "SD Card Error!";

// --- Helper Functions ---

// Maps pin name string (from SD file) to actual GPIO pin number
int getPinByName(const String& name) {
  if (name.equalsIgnoreCase("up_pin")) return up_pin;
  if (name.equalsIgnoreCase("down_pin")) return down_pin;
  if (name.equalsIgnoreCase("left_pin")) return left_pin;
  if (name.equalsIgnoreCase("right_pin")) return right_pin;
  if (name.equalsIgnoreCase("p1_pin")) return p1_pin;
  if (name.equalsIgnoreCase("p2_pin")) return p2_pin;
  if (name.equalsIgnoreCase("p3_pin")) return p3_pin;
  if (name.equalsIgnoreCase("p4_pin")) return p4_pin;
  if (name.equalsIgnoreCase("k1_pin")) return k1_pin;
  if (name.equalsIgnoreCase("k2_pin")) return k2_pin;
  if (name.equalsIgnoreCase("k3_pin")) return k3_pin;
  if (name.equalsIgnoreCase("k4_pin")) return k4_pin;
  if (name.equalsIgnoreCase("s1_pin")) return s1_pin;
  if (name.equalsIgnoreCase("s2_pin")) return s2_pin;
  if (name.equalsIgnoreCase("a1_pin")) return a1_pin;
  if (name.equalsIgnoreCase("a2_pin")) return a2_pin;
  if (name.equalsIgnoreCase("ls_pin")) return ls_pin;
  if (name.equalsIgnoreCase("rs_pin")) return rs_pin;
  if (name.equalsIgnoreCase("p2s1_pin")) return p2s1_pin;
  if (name.equalsIgnoreCase("fn_pin")) return fn_pin;
  
  Serial.print("ERROR: Unknown pin name in SD file: "); Serial.println(name);
  return -1; // Indicates an error / unknown pin
}

bool parseUIDString(const String& uidStr, uint8_t* uidArray, uint8_t& uidLen, uint8_t maxLength) {
  uidLen = 0;
  int currentIndex = 0;
  int nextIndex = 0;
  while (uidLen < maxLength && currentIndex < uidStr.length()) {
    nextIndex = uidStr.indexOf(':', currentIndex);
    if (nextIndex == -1) nextIndex = uidStr.length();
    String byteStr = uidStr.substring(currentIndex, nextIndex);
    if (byteStr.length() == 0) break;
    uidArray[uidLen++] = (uint8_t)strtol(byteStr.c_str(), NULL, 16);
    currentIndex = nextIndex + 1;
  }
  return uidLen > 0;
}

// --- C-STRING HELPER FUNCTIONS ---
int readLineIntoBuffer(File& file, char* buffer, size_t bufferSize) {
  size_t i = 0;
  int c;
  while (i < bufferSize - 1 && (c = file.read()) != -1) {
    if (c == '\n') break;
    if (c != '\r') buffer[i++] = (char)c;
  }
  buffer[i] = '\0';
  return i;
}

void trim(char* str) {
  if (!str) return;
  size_t len = strlen(str);
  if (len == 0) return;
  while (len > 0 && isspace((unsigned char)str[len - 1])) str[--len] = '\0';
  size_t start = 0;
  while (start < len && isspace((unsigned char)str[start])) start++;
  if (start > 0) memmove(str, str + start, len - start + 1);
}

bool startsWith(const char* str, const char* prefix) {
  return strncmp(str, prefix, strlen(prefix)) == 0;
}

bool endsWith(const char* str, const char* suffix) {
  size_t str_len = strlen(str);
  size_t suffix_len = strlen(suffix);
  if (suffix_len > str_len) return false;
  return strcmp(str + str_len - suffix_len, suffix) == 0;
}

void loadConfigsFromSD() {
  Serial.println("Loading configurations from SD card...");
  display.clearDisplay(); 
  display.setCursor(0,20); display.println("Loading .txt files"); 
  display.setCursor(0,30); display.println("from SD card..."); 
  display.display();

  File root = SD.open("/");
  if (!root) {
    Serial.println("Failed to open root directory on SD card!");
    display.clearDisplay(); display.setCursor(0,0); display.println(oledSdErrorMsg); display.println("Check SD Card!"); display.display();
    return;
  }

  char lineBuffer[128];
  File entry;
  while (entry = root.openNextFile()) {
    if (entry.isDirectory() || startsWith(entry.name(), "._") || !endsWith(entry.name(), ".txt")) {
      entry.close();
      continue;
    }

    Serial.print("Processing config file: "); Serial.println(entry.name());
    
    CardConfig currentConfig;
    currentConfig.uidLength = 0;
    currentConfig.oledMessage = "";
    currentConfig.oledMessage2 = ""; 
    bool uidFound = false;
    bool msgFound = false;

    while (entry.available()) {
      readLineIntoBuffer(entry, lineBuffer, sizeof(lineBuffer));
      trim(lineBuffer);
      if (strlen(lineBuffer) == 0) continue;

      if (startsWith(lineBuffer, "UID:")) {
        char* uidStr = lineBuffer + strlen("UID:");
        if (parseUIDString(String(uidStr), currentConfig.uid, currentConfig.uidLength, MAX_UID_LENGTH)) {
          uidFound = true;
        } else { Serial.print("Error parsing UID in file: "); Serial.println(entry.name()); }
      } else if (startsWith(lineBuffer, "MSG:")) {
        currentConfig.oledMessage = String(lineBuffer + strlen("MSG:"));
        currentConfig.oledMessage.trim();
        msgFound = true;
      } else if (startsWith(lineBuffer, "MSG2:")) {
        currentConfig.oledMessage2 = String(lineBuffer + strlen("MSG2:"));
        currentConfig.oledMessage2.trim();
      } 
      else if (startsWith(lineBuffer, "ACTION:SIMUL_PRESS")) {
        char* actionParams = lineBuffer + strlen("ACTION:SIMUL_PRESS");
        trim(actionParams);

        String paramsStr(actionParams);
        int delayHigh, delayLow;

        int lastSpace = paramsStr.lastIndexOf(' ');
        if (lastSpace == -1) {
            Serial.print("  Error parsing ACTION:SIMUL_PRESS (missing delays): "); Serial.println(entry.name());
            continue;
        }
        String delayHighStr = paramsStr.substring(lastSpace + 1);
        delayHigh = delayHighStr.toInt();

        String remainingStr = paramsStr.substring(0, lastSpace);
        remainingStr.trim();
        int secondLastSpace = remainingStr.lastIndexOf(' ');
        if (secondLastSpace == -1) {
            Serial.print("  Error parsing ACTION:SIMUL_PRESS (missing low delay): "); Serial.println(entry.name());
            continue;
        }
        String delayLowStr = remainingStr.substring(secondLastSpace + 1);
        delayLow = delayLowStr.toInt();

        String pinNamesStr = remainingStr.substring(0, secondLastSpace);

        ActionCommand cmd;
        cmd.delayLow = delayLow;
        cmd.delayHigh = delayHigh;

        int currentPos = 0;
        int nextComma = -1;
        bool allPinsValid = true;
        while(currentPos < pinNamesStr.length()) {
            nextComma = pinNamesStr.indexOf(',', currentPos);
            if (nextComma == -1) nextComma = pinNamesStr.length();
            
            String pinName = pinNamesStr.substring(currentPos, nextComma);
            pinName.trim();

            if (pinName.length() > 0) {
                int pin = getPinByName(pinName);
                if (pin != -1) {
                    cmd.pins.push_back(pin);
                } else {
                    Serial.print("  Skipping invalid SIMUL_PRESS (unknown pin: "); Serial.print(pinName); Serial.print(") in "); Serial.println(entry.name());
                    allPinsValid = false;
                    break;
                }
            }
            currentPos = nextComma + 1;
        }

        if (allPinsValid && !cmd.pins.empty()) {
            currentConfig.actions.push_back(cmd);
        }
      }
      else if (startsWith(lineBuffer, "ACTION:PRESS")) {
        char* actionParams = lineBuffer + strlen("ACTION:PRESS");
        trim(actionParams);

        char pinNameStr[32];
        int delayLow, delayHigh;

        if (sscanf(actionParams, "%s %d %d", pinNameStr, &delayLow, &delayHigh) == 3) {
          ActionCommand cmd;
          int pin = getPinByName(String(pinNameStr));
          if (pin != -1) {
            cmd.pins.push_back(pin);
            cmd.delayLow = delayLow;
            cmd.delayHigh = delayHigh;
            currentConfig.actions.push_back(cmd);
          } else {
            Serial.print("  Skipping invalid action (unknown pin: "); Serial.print(pinNameStr); Serial.print(") in "); Serial.println(entry.name());
          }
        } else {
          Serial.print("  Error parsing ACTION:PRESS line in "); Serial.println(entry.name());
        }
      }
    }
    entry.close();

    if (uidFound && msgFound && !currentConfig.actions.empty()) {
      cardConfigs.push_back(currentConfig);
      Serial.println("  Config loaded successfully.");
    } else {
      Serial.print("  Failed to load complete config from: "); Serial.println(entry.name());
      if (!uidFound) Serial.println("    UID missing or invalid.");
      if (!msgFound) Serial.println("    MSG missing.");
      if (currentConfig.actions.empty() && (uidFound || msgFound)) Serial.println("    No valid ACTIONs found.");
    }
  }
  if (root) root.close();
  
  display.setCursor(0,40); 
  display.print(cardConfigs.size()); 
  display.println(" files loaded.");
  display.display();
  delay(2000);

  display.clearDisplay(); 
  display.setCursor(0,0); 
  display.println(oledWaitingMsg); 
  display.display();
}

void setup(void) {
  Serial.begin(115200);
  Serial.println("Initializing output pins...");
  for (int pin_to_init : pin_array) {
    pinMode(pin_to_init, OUTPUT);
    digitalWrite(pin_to_init, HIGH);
  }
  Serial.println("Output pins initialization complete.");
  Serial.println("\n\n--- System Booting Up ---");


  // This must be done BEFORE calling display.begin()
  Serial.println("Configuring I2C0 pins for OLED...");
  Wire.setSDA(OLED_SDA_PIN);
  Wire.setSCL(OLED_SCL_PIN);
  Serial.print("  - SDA set to GPIO "); Serial.println(OLED_SDA_PIN);
  Serial.print("  - SCL set to GPIO "); Serial.println(OLED_SCL_PIN);

  // Now initialize the display on the configured pins
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("CRITICAL: SSD1306 OLED allocation failed (I2C0)! Halting.")); 
    for(;;);
  }
  display.clearDisplay(); display.setTextSize(1); display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0); display.println("  NFC Launcher v1.2  "); display.display(); delay(500);
  display.setCursor(0,10); display.println("---------------------"); display.display(); delay(500);
  display.setCursor(0,20); display.println("OLED Status:  STARTED"); display.display(); delay(500);

  // Configure I2C1 pins for the NFC Module
  Serial.println("Configuring I2C1 pins for NFC...");
  Wire1.setSDA(nfc_sda_pin); 
  Wire1.setSCL(nfc_scl_pin);
  Serial.print("  - SDA set to GPIO "); Serial.println(nfc_sda_pin);
  Serial.print("  - SCL set to GPIO "); Serial.println(nfc_scl_pin);
  Wire1.begin();
  
  nfc.begin();
  if (!nfc.getFirmwareVersion()) {
    Serial.println("CRITICAL: Didn't find PN532 board on I2C1! Halting.");
    display.setCursor(0,30); display.println("NFC Status:    NO NFC"); display.display();
    rp2040.reboot();
  }
  nfc.SAMConfig();
  Serial.println("NFC Reader Ready.");
  display.setCursor(0,30); display.println("NFC Status:   STARTED"); display.display(); delay(500);

  // Configure SPI pins for the SD Card
  Serial.println("Configuring SPI0 pins for SD Card...");
  SPI.setRX(SD_MISO_PIN);
  SPI.setTX(SD_MOSI_PIN);
  SPI.setSCK(SD_SCK_PIN);
  Serial.print("  - MISO (RX) set to GPIO "); Serial.println(SD_MISO_PIN);
  Serial.print("  - MOSI (TX) set to GPIO "); Serial.println(SD_MOSI_PIN);
  Serial.print("  - SCK       set to GPIO "); Serial.println(SD_SCK_PIN);
  Serial.print("  - CS        set to GPIO "); Serial.println(SD_CHIP_SELECT_PIN);

  // Now initialize the SD card with the configured pins
  if (!SD.begin(SD_CHIP_SELECT_PIN)) {
    Serial.println("WARNING: SD Card Initialization failed!");
    display.setCursor(0,40); display.println("SD Card Status: NO SD"); display.display();
    rp2040.reboot();
  } else {
    Serial.println("SD Card Initialized.");
    display.setCursor(0,40); display.println("SD Card Status:    OK"); display.display(); delay(500);
    loadConfigsFromSD();
  }



  strip.begin();
  strip.show();
  setAllLEDs(strip.Color(0, 0, 0));
  Serial.println("NeoPixels Initialized.");
  Serial.println("--- Setup complete. System Ready. ---");
  display.clearDisplay(); display.setCursor(0,0); display.println(oledWaitingMsg); display.display();
}

void loop(void) {
  const CardConfig* matchedConfig = nullptr;
  
  uint8_t uid[MAX_UID_LENGTH] = { 0 };
  uint8_t uidLength = 0;
  uint8_t nfc_success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

  if (nfc_success) {
    Serial.println("--------------------------");
    Serial.print("Card Detected! UID:");
    for (uint8_t i=0; i < uidLength; i++) { Serial.print(" 0x"); Serial.print(uid[i], HEX); }
    Serial.println();

    for (const auto& config : cardConfigs) {
      if (uidLength == config.uidLength && memcmp(uid, config.uid, uidLength) == 0) {
        matchedConfig = &config;
        break;
      }
    }

    display.clearDisplay(); 
    display.setCursor(0, 0);

    if (matchedConfig != nullptr) {
      Serial.print("Allowed Card - MSG: "); Serial.println(matchedConfig->oledMessage);
      display.setCursor(0,10); display.println(matchedConfig->oledMessage);
      display.setCursor(0,20); display.println(matchedConfig->oledMessage2);
      setAllLEDs(strip.Color(0, 255, 0));
    } else {
      Serial.println("Card not found in SD configurations.");
      display.setCursor(0,10); display.println(oledNotMappedMsg);
      setAllLEDs(strip.Color(255, 0, 0));
    }
    
    display.setCursor(0,30); display.print("UID: ");
    display.setCursor(0,40);
    for (uint8_t i = 0; i < uidLength; i++) {
      if (uid[i] < 0x10) display.print("0");
      display.print(uid[i], HEX);
      if (i < uidLength -1) display.print(":");
    }
    
    display.display();

    if (matchedConfig != nullptr) {
      Serial.println("Executing actions...");
      for (const auto& cmd : matchedConfig->actions) {
        Serial.print("  EXECUTE Action -> Pins: ");
        for (size_t i = 0; i < cmd.pins.size(); ++i) {
            Serial.print("GP");
            Serial.print(cmd.pins[i]);
            if (i < cmd.pins.size() - 1) Serial.print(", ");
        }
        Serial.print(" | Low: "); Serial.print(cmd.delayLow);
        Serial.print("ms, High: "); Serial.print(cmd.delayHigh); Serial.println("ms");
        
        executeCommand(cmd);
      }
      Serial.println("Actions complete.");
      delay(1000); 
    } else {
      delay(2000); 
    }
    
    display.clearDisplay(); 
    display.setCursor(0,0); 
    display.println(oledWaitingMsg); 
    display.display();
    setAllLEDs(strip.Color(0, 0, 0));
  }
}

// Helper function to execute an ActionCommand, pressing one or more pins simultaneously.
void executeCommand(const ActionCommand& cmd) {
    if (cmd.pins.empty()) {
        Serial.println("  Action skipped: No valid pins in command.");
        return;
    }

    // 1. Set all pins in the command to LOW (active)
    for (int pin : cmd.pins) {
        if (pin != -1) {
            digitalWrite(pin, LOW);
        }
    }

    // 2. Wait for the specified low-delay
    delay(cmd.delayLow);

    // 3. Set all pins back to HIGH (inactive)
    for (int pin : cmd.pins) {
        if (pin != -1) {
            digitalWrite(pin, HIGH);
        }
    }

    // 4. Wait for the specified high-delay before the next action
    delay(cmd.delayHigh);
}

// Helper function to set all NeoPixel LEDs to a specific color
void setAllLEDs(uint32_t color) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}