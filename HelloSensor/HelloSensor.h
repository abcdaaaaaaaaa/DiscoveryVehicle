#ifndef HELLOSENSOR_H
#define HELLOSENSOR_H

#include <Arduino.h>

class GeigerCounter
{
private:
  byte _pin2;
  int _LOG_PERIOD;
  float _averageCPM, _sdCPM;
  float _CPMArray[100];
  int _currentCPM;
  unsigned long previousMillis;
  unsigned long _counts;

  float outputSieverts(float x);

public:
  GeigerCounter(int LOG_PERIOD1, byte pin2);
  void begin();
  void radioactive();
  float usvhr;
  float count;
  float Avg;
  float sdCPM;
};

#endif
