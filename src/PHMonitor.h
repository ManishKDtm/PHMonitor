#ifndef PHMONITOR_H
#define PHMONITOR_H

#include <Arduino.h>

class PHMonitor {

public:

  PHMonitor(uint8_t pin);

  void begin();

  float readVoltage();
  float readPH();
  float compensatePH(float ph,float temp);

private:

  uint8_t _pin;

};

#endif