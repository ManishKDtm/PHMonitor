#include "PHMonitor.h"

PHMonitor::PHMonitor(uint8_t pin)
{
  _pin = pin;
}

void PHMonitor::begin()
{
  pinMode(_pin,INPUT);
}

float PHMonitor::readVoltage()
{
  int raw = analogRead(_pin);

#if defined(ESP32)
  float voltage = raw * 3.3 / 4095.0;

#elif defined(ESP8266)
  float voltage = raw * 3.3 / 1023.0;

#else
  float voltage = raw * 5.0 / 1023.0;

#endif

  return voltage;
}

float PHMonitor::readPH()
{
  float v = readVoltage();

  float ph = 7 + (2.5 - v) * 3.5;

  return ph;
}

float PHMonitor::compensatePH(float ph,float temp)
{
  float corrected = ph + 0.03 * (25.0 - temp);

  if(corrected < 0) corrected = 0;
  if(corrected > 14) corrected = 14;

  return corrected;
}