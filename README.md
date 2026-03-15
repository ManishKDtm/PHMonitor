# PHMonitor

[![Arduino Library Version](https://img.shields.io/badge/Arduino-Library%20Manager-brightgreen)](https://www.arduino.cc/en/Guide/Libraries#toc3)
![GitHub stars](https://img.shields.io/github/stars/ManishKDtm/PHMonitor?style=social)
![GitHub release](https://img.shields.io/github/v/release/ManishKDtm/PHMonitor?style=plastic)
![Platforms](https://img.shields.io/badge/Platforms-Arduino%2C%20ESP32%2C%20ESP8266-blue)
![License](https://img.shields.io/github/license/ManishKDtm/PHMonitor)

**PHMonitor** is a professional Arduino library for **pH monitoring** with optional **temperature compensation**, ready-to-use **OLED and LCD displays**, and simple **one-step calibration**. Perfect for students, hobbyists, and IoT water quality projects.

---

## 🔹 Features

- Read raw pH values from analog pH probes  
- Optional **temperature compensation** using Dallas/DS18B20 or onboard sensor  
- Display readings on **16x2 LCD** or **128x64 OLED**  
- Easy **one-step calibration** (pH 7 reference solution)  
- Compatible with **ESP32**, **ESP8266**, and Arduino boards  
- Minimal dependencies for students and quick prototyping  

---

## 📦 Installation

**Arduino IDE:**

1. Open **Sketch → Include Library → Manage Libraries**  
2. Search for `PHMonitor` and click **Install**  

**Manual Installation:**

1. Download the [latest release](https://github.com/ManishKDtm/PHMonitor/releases/latest)  
2. Open Arduino IDE → **Sketch → Include Library → Add .ZIP Library**  
3. Select the downloaded `.zip` file  

---

## 📌 Wiring / Connections

| Sensor / Module     | ESP32 Pin | ESP8266 Pin | Notes |
|--------------------|-----------|------------|-------|
| pH Analog Sensor    | analog pin | analog pin| Connect analog output |
| DS18B20 / Temp      | "         | "          | Optional for temp compensation |
| 16x2 LCD (I2C)      | SDA/SCL   | SDA/SCL    | Default 0x27 |
| 128x64 OLED (I2C)   | SDA/SCL   | SDA/SCL    | Default 0x3C

> Update pins in examples if your wiring is different.

---

## ⚙️ Usage Examples

### 1️⃣  Temperature compensated pH Reading

```cpp
#include <PHMonitor.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define PH_PIN A0
#define TEMP_PIN 2

PHMonitor ph(PH_PIN);

OneWire oneWire(TEMP_PIN);
DallasTemperature tempSensor(&oneWire);

void setup()
{
  Serial.begin(9600);

  ph.begin();
  tempSensor.begin();
}

void loop()
{
  tempSensor.requestTemperatures();

  float temp = tempSensor.getTempCByIndex(0);

  float rawPH = ph.readPH();

  float phComp = ph.compensatePH(rawPH,temp);

  Serial.print("Temp: ");
  Serial.println(temp);

  Serial.print("pH: ");
  Serial.println(phComp);

  delay(2000);
}