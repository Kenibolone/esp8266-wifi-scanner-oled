# ESP8266 Wi-Fi Scanner with OLED Display

Scans and displays Wi-Fi network names (SSID), MAC addresses (BSSID), and signal strength (RSSI) on a 0.96" OLED display using an ESP8266 (Wemos D1 Mini).

## Hardware
- ESP8266 (Wemos D1 Mini)
- 0.96" OLED (SSD1306)
- Push button (for rescanning)

## Software
- Arduino IDE / PlatformIO
- Libraries:
  - `ESP8266WiFi`
  - `Adafruit_GFX`
  - `Adafruit_SSD1306`

## How it Works
1. On boot, scans for nearby Wi-Fi networks.
2. Displays the top few SSIDs + RSSI on the OLED.
3. Press the button to trigger a new scan.


## File Structure
- `src/main.ino`: Core logic
- `README.md`: This file

## License
MIT
