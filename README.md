# PHMonitor

[![Arduino Library Version](https://img.shields.io/badge/Arduino-Library%20Manager-brightgreen)](https://www.arduino.cc/en/Guide/Libraries#toc3)
![GitHub stars](https://img.shields.io/github/stars/ManishKDtm/PHMonitor?style=social)
![GitHub release](https://img.shields.io/github/v/release/ManishKDtm/PHMonitor?style=plastic)
![Platforms](https://img.shields.io/badge/Platforms-Arduino%2C%20ESP32%2C%20ESP8266-blue)
![License](https://img.shields.io/github/license/ManishKDtm/PHMonitor)

PHMonitor is a **professional Arduino library** for **pH monitoring** with support for:

- Analog pH sensors  
- Temperature compensation (optional, using Dallas/DS18B20 or onboard sensor)  
- OLED and LCD displays  
- Easy calibration for educational and IoT projects  

This library is designed for **students, hobbyists, and makers** who want **quick, reliable water pH monitoring** with real-time readings.

---

## 🔹 Features

- Read raw pH values from analog pH probes  
- Automatic temperature compensation for accurate pH readings  
- Display readings on **16x2 LCD** or **128x64 OLED**  
- Simple **one-step calibration** (pH 7 reference solution)  
- Compatible with **ESP32**, **ESP8266**, and standard Arduino boards  
- Ready-to-use **example sketches**  
- Minimal dependencies, easy integration in any project  

---

## 📦 Installation

1. Open **Arduino IDE** → **Sketch → Include Library → Manage Libraries**  
2. Search for `PHMonitor` and click **Install**  

Or manually:

1. Download the [latest release](https://github.com/ManishKDtm/PHMonitor/releases/latest)  
2. Open Arduino IDE → **Sketch → Include Library → Add .ZIP Library**  
3. Select the downloaded `.zip` file  

---

## 📌 Wiring / Connections

| Sensor/Module       | ESP32 Pin | ESP8266 Pin | Notes |
|--------------------|-----------|------------|-------|
| pH Analog Sensor    | A0 (default) | A0 | Connect analog output |
| DS18B20 / Temp      | 4 | 4 | Optional, only if using temp compensation |
| 16x2 LCD (I2C)      | SDA/SCL | SDA/SCL | 0x27 address default |
| 128x64 OLED (I2C)   | SDA/SCL | SDA/SCL | 0x3C address default |
| Buzzer              | 18 | 18 | Optional alert |
| Buttons             | 5, 19 | 5, 19 | Optional for page / upload |

> Note: Update pins in examples if different.

---

## ⚙️ Usage Examples

The library comes with several example sketches:

| Example | Description |
|---------|-------------|
| `01_Calibration` | Calibrate pH sensor to pH 7 automatically |
| `02_BasicPH` | Basic pH reading without temperature compensation |
| `03_TempCompensation` | Read pH with temperature compensation |
| `04_OLED_Display` | Display readings on OLED |
| `05_LCD_Display` | Display readings on 16x2 LCD |

---

### Example: Basic pH Reading

```cpp
#include <PHMonitor.h>

// Create object
PHMonitor phSensor(A0); // Analog pin

void setup() {
  Serial.begin(115200);
  phSensor.begin();
}

void loop() {
  float ph = phSensor.readPH();
  Serial.print("pH: ");
  Serial.println(ph);
  delay(1000);
}