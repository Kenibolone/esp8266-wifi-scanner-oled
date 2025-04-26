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



## Wi-Fi Scanner OLED Display
This project is a Wi-Fi scanner that uses the ESP8266 to scan for available Wi-Fi networks and display the results on an OLED display. It displays key information such as the SSID, signal strength (RSSI), and encryption type of each nearby Wi-Fi network.

The project is designed to be simple and efficient, with a physical button to trigger the Wi-Fi scan. The results are shown on a small 128x64 OLED display for easy viewing.

## Features
Wi-Fi Network Scanning: Scans available Wi-Fi networks in range.

OLED Display: Displays the SSID, signal strength (RSSI), and encryption type for each detected network.

Button-Triggered Scan: Press the button to trigger a new Wi-Fi scan.

Network Sorting: Networks are sorted by RSSI (signal strength) in descending order, with the strongest signals appearing first.

Encryption Type Display: Displays the encryption type (Open, WPA, WPA2, WPA3, etc.) for each network.

## Hardware Required
ESP8266 (e.g., NodeMCU, Wemos D1 Mini)

OLED Display (128x64, I2C)

Push Button (for triggering Wi-Fi scan)

Jumper wires and breadboard (optional)

## Software Required
Arduino IDE

## Libraries:

ESP8266WiFi.h 

Wire.h 

Adafruit_GFX.h 

Adafruit_SSD1306.h 

## Wiring
OLED Display:

VCC to 3.3V (on ESP8266)

GND to GND

SCL to D1 (GPIO5)

SDA to D2 (GPIO4)

Button:

One side of the button connected to D3 (GPIO0)

The other side connected to GND

## Installation
Clone the repository to your local machine:

bash
Copy
Edit
git clone https://github.com/Kenibolone/esp8266-wifi-scanner-oled.git
Open the project in the Arduino IDE.

## Install the required libraries:

Adafruit SSD1306: Go to Sketch > Include Library > Manage Libraries..., then search for Adafruit SSD1306 and install it.

Adafruit GFX: Do the same for Adafruit GFX library.

Select the appropriate board and port:

Go to Tools > Board > ESP8266 (select your board, e.g., NodeMCU 1.0).

Select the correct Port under Tools > Port.

Upload the sketch to the ESP8266.

## How It Works
Button Press: When the button connected to GPIO D3 is pressed, the ESP8266 starts scanning for nearby Wi-Fi networks.

Wi-Fi Scan: The ESP8266 scans available Wi-Fi networks using the WiFi.scanNetworks() function.

Network Display: The SSID, RSSI (signal strength), and encryption type of each network are displayed on the OLED screen, sorted by signal strength (RSSI).

Encryption Types: The program identifies and displays the encryption type (Open, WPA, WPA2, WPA3, etc.) for each network.

## Example Output on OLED Display
Network Name (SSID): "Home Network"

Signal Strength (RSSI): -65 dBm

Encryption Type: WPA2

## Code Explanation
The ESP8266 uses the following components:

Adafruit SSD1306 Library: Manages the OLED display.

WiFi.scanNetworks(): Scans for nearby networks.

Button (GPIO D3): Triggers the scan process.

Debounce Logic: Prevents multiple scans from being triggered in quick succession.

scanWiFi()
This function scans for Wi-Fi networks and displays the results on the OLED. Networks are sorted by RSSI to show the strongest signal first.

getEncryptionType()
Returns a human-readable string for the encryption type of the Wi-Fi network.

displayWiFi()
Displays the SSID, RSSI, and encryption type on the OLED screen. It ensures that the display is updated correctly with no overlap.

## License
This project is licensed under the MIT License - see the LICENSE file for details.

## Future Enhancements
Network Filtering: Allow filtering of networks based on signal strength or encryption type.

Auto-Scan: Implement automatic scanning at regular intervals.

Web Interface: Add a web interface to display the scan results on a browser.

## Contact
For any questions or contributions, feel free to contact me at keninish7965@gmail.com or connect via LinkedIn.
