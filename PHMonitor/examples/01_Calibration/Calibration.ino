#include <PHMonitor.h>

#define PH_PIN A0

PHMonitor ph(PH_PIN);

void setup()
{
  Serial.begin(9600);
  ph.begin();

  Serial.println("------ PH SENSOR CALIBRATION ------");
  Serial.println("Place probe in pH 7 buffer solution");
  Serial.println("Adjust potentiometer until voltage ≈ 2.5V");
  Serial.println("-----------------------------------");
}

void loop()
{
  float voltage = ph.readVoltage();
  float phValue = ph.readPH();

  Serial.print("Voltage: ");
  Serial.print(voltage,3);
  Serial.print(" V  |  Estimated pH: ");
  Serial.println(phValue,2);

  delay(2000);
}