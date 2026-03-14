#include <PHMonitor.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define PH_PIN A0

PHMonitor ph(PH_PIN);

Adafruit_SSD1306 oled(128,64,&Wire,-1);

void setup()
{
  ph.begin();

  oled.begin(SSD1306_SWITCHCAPVCC,0x3C);
}

void loop()
{
  float value = ph.readPH();

  oled.clearDisplay();

  oled.setTextSize(1);
  oled.setCursor(0,0);
  oled.print("pH:");

  oled.setCursor(0,20);
  oled.print(value,2);

  oled.display();

  delay(2000);
}