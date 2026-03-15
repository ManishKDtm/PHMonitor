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