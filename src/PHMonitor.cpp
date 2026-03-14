#include "PHMonitor.h"

PHMonitor::PHMonitor(uint8_t pin)
{
  _pin = pin;
}

void PHMonitor::begin()
{
  pinMode(_pin, INPUT);

#if defined(ESP32)
  analogReadResolution(12);
#endif
}

float PHMonitor::readVoltage()
{
  const int samples = 10;
  int buffer[samples];

  for(int i=0;i<samples;i++)
  {
    buffer[i] = analogRead(_pin);
    delay(10);
  }

  int sum = 0;

  for(int i=0;i<samples;i++)
  {
    sum += buffer[i];
  }

  float avg = sum / (float)samples;

#if defined(ESP32)

  float voltage = avg * 3.3 / 4095.0;

#elif defined(ESP8266)

  float voltage = avg * 3.3 / 1023.0;

#else

  float voltage = avg * 5.0 / 1023.0;

#endif

  return voltage;
}

float PHMonitor::readPH()
{
  float voltage = readVoltage();

  float ph = 7 + (2.5 - voltage) * 3.5;

  if(ph < 0) ph = 0;
  if(ph > 14) ph = 14;

  return ph;
}

float PHMonitor::compensatePH(float ph,float temp)
{
  float corrected = ph + 0.03 * (25.0 - temp);

  if(corrected < 0) corrected = 0;
  if(corrected > 14) corrected = 14;

  return corrected;
}
