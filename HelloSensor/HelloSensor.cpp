#include "HelloSensor.h"

GeigerCounter::GeigerCounter(int LOG_PERIOD1, byte pin2)
{
  _pin2 = pin2;
  _LOG_PERIOD = LOG_PERIOD1;
  _counts = 0;
  _currentCPM = 0;
  previousMillis = 0;
}

float GeigerCounter::outputSieverts(float x) {
  return x * 0.0057;
}

volatile unsigned long interruptCounts = 0;

void impulseISR() {
  interruptCounts++;
}

void GeigerCounter::begin()
{
  _counts = 0;
  pinMode(_pin2, INPUT);
  attachInterrupt(digitalPinToInterrupt(_pin2), impulseISR, FALLING);
}

void GeigerCounter::radioactive() {
  _counts = interruptCounts;
  count = _counts;

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > _LOG_PERIOD) {
    previousMillis = currentMillis;
    _CPMArray[_currentCPM] = _counts * 2;
    usvhr = outputSieverts(_CPMArray[_currentCPM]);

    interruptCounts = 0;
    _averageCPM = 0; _sdCPM = 0;

    for (int i = 0; i <= _currentCPM; i++) _averageCPM += _CPMArray[i];
    _averageCPM /= (_currentCPM + 1);

    for (int i = 0; i <= _currentCPM; i++) _sdCPM += sq(_CPMArray[i] - _averageCPM);
    _sdCPM = sqrt(_sdCPM / _currentCPM) / sqrt(_currentCPM + 1);

    Avg = outputSieverts(_averageCPM);
    sdCPM = outputSieverts(_sdCPM);
    _currentCPM++;
  }
}
