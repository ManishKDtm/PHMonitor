#include <PHMonitor.h>
#include <LiquidCrystal_I2C.h>

#define PH_PIN A0

PHMonitor ph(PH_PIN);

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  ph.begin();

  lcd.init();
  lcd.backlight();
}

void loop()
{
  float value = ph.readPH();

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Water pH");

  lcd.setCursor(0,1);
  lcd.print(value,2);

  delay(2000);
}