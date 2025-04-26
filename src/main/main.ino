#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define SCAN_BUTTON D3
unsigned long lastPress = 0;
const int debounceDelay = 300;

void setup()
{
  Serial.begin(115200);
  pinMode(SCAN_BUTTON, INPUT_PULLUP);
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop()
{
  if (digitalRead(SCAN_BUTTON) == LOW && (millis() - lastPress > debounceDelay))
  {
    lastPress = millis();
    scanWiFi();
  }
}

void scanWiFi()
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Scanning WiFi...");
  display.display();

  int numNetworks = WiFi.scanNetworks();

  if (numNetworks == 0)
  {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("No Networks found");
    display.display();
    return;
  }

  // Sort networks by RSSI (Signal Strength)
  for (int i = 0; i < numNetworks - 1; i++)
  {
    for (int j = i + 1; j < numNetworks; j++)
    {
      if (WiFi.RSSI(j) > WiFi.RSSI(i))
      {
        // Swap SSID
        String tempSSID = WiFi.SSID(i);
        WiFi.SSID(i) = WiFi.SSID(j);
        WiFi.SSID(j) = tempSSID;

        // Swap RSSI
        int tempRSSI = WiFi.RSSI(i);
        WiFi.RSSI(i) = WiFi.RSSI(j);
        WiFi.RSSI(j) = tempRSSI;

        // Swap Encryption Type
        int tempEnc = WiFi.encryptionType(i);
        WiFi.encryptionType(i) = WiFi.encryptionType(j);
        WiFi.encryptionType(j) = tempEnc;
      }
    }
  }

  display.clearDisplay();
  int y = 0;

  for (int i = 0; i < numNetworks && y < SCREEN_HEIGHT - 8; i++)
  {
    y = displayWiFi(WiFi.SSID(i), WiFi.RSSI(i), WiFi.encryptionType(i), y);
  }

  display.display();
  WiFi.scanDelete();
}

String getEncryptionType(int type)
{
  switch(type)
  {
    case WIFI_AUTH_OPEN: return "Open";
    case WIFI_AUTH_WEP: return "WEP";
    case WIFI_AUTH_WPA_PSK: return "WPA";
    case WIFI_AUTH_WPA2_PSK: return "WPA2";
    case WIFI_AUTH_WPA_WPA2_PSK: return "WPA/WPA2";
    case WIFI_AUTH_WPA3_PSK: return "WPA3";
    case WIFI_AUTH_WPA2_ENTERPRISE: return "WPA2 Ent";
    default: return "Unknown";
  }
}

int displayWiFi(String ssid, int rssi, int encType, int y)
{
  display.setCursor(0, y);
  if (ssid.length() > 12)
  {
    display.println(ssid.substring(0, 12) + "...");
  }
  else 
  {
    display.print(ssid);
  }

  display.setCursor(90, y);
  display.print(rssi);
  
  display.setCursor(60, y);
  display.print(getEncryptionType(encType));
  
  return y + 8;
}
