#include <PHMonitor.h>

#define PH_PIN A0

PHMonitor ph(PH_PIN);

void setup()
{
  Serial.begin(9600);
  ph.begin();
}

void loop()
{
  float value = ph.readPH();

  Serial.print("pH: ");
  Serial.println(value);

  delay(2000);
}