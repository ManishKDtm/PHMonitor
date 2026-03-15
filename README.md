# PHMonitor

[![Arduino Library Version](https://img.shields.io/badge/Arduino-Library%20Manager-brightgreen)](https://www.arduino.cc/en/Guide/Libraries#toc3)
![GitHub stars](https://img.shields.io/github/stars/ManishKDtm/PHMonitor?style=social)
![GitHub release](https://img.shields.io/github/v/release/ManishKDtm/PHMonitor?style=plastic)
![Platforms](https://img.shields.io/badge/Platforms-Arduino%2C%20ESP32%2C%20ESP8266-blue)

Arduino library for **pH monitoring**, **temperature compensation**, and OLED/LCD display. Easy to use for students and IoT projects.

# PHMonitor

Open-source pH monitoring library for Arduino, ESP8266 and ESP32.

## Features
- pH sensor reading
- Simple calibration (2.5V at pH7)
- Temperature compensation
- OLED display support
- LCD display support

## Supported Boards
- Arduino Uno
- ESP8266
- ESP32

## Sensors
- Analog pH Sensor
- DS18B20 Temperature Sensor

## Installation

1. Download the repository
2. Copy the PHMonitor folder into:

Documents/Arduino/libraries

3. Restart Arduino IDE


pH Probe
   ↓
pH Signal Board
   ↓
Arduino ADC
   ↓
PHMonitor Library
   ↓
Serial / OLED / LCD





## Author
Manish Kumar Das
