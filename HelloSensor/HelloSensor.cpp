#include "HelloSensor.h"
#include "Arduino.h"

HelloSensor::HelloSensor(int bitadc, float Rload, byte pin)
{
  _pin=pin;
  _Rload=Rload;
  _bitadc=bitadc;
}

void HelloSensor::begin()
{
  pinMode(_pin,INPUT);
}

//**************************************Ready Calibration**************************************\\

void HelloSensor::MQ2calibrate(){_R0 = 2.74;}
void HelloSensor::MQ3calibrate(){_R0 = 0.45;}
void HelloSensor::MQ4calibrate(){_R0 = 6.14;}
void HelloSensor::MQ5calibrate(){_R0 = 4.16;}
void HelloSensor::MQ6calibrate(){_R0 = 2.71;}
void HelloSensor::MQ7calibrate(){_R0 = 0.98;}
void HelloSensor::MQ8calibrate(){_R0 = 0.386;}
void HelloSensor::MQ9calibrate(){_R0 = 2.816;}
void HelloSensor::MQ131calibrate(){_R0 = 0.67;}
void HelloSensor::MQ135calibrate(){_R0 = 8.2809;}
void HelloSensor::MQ136calibrate(){_R0 = 7.5;}
void HelloSensor::MQ303Acalibrate(){_R0 = 27;}
void HelloSensor::MQ309Acalibrate(){_R0 = 2.458;}

float HelloSensor::readValue()
{
  _RS = ((_Rload/(analogRead(_pin)*(1/(pow(2,_bitadc)-1))))-(_Rload));
  _ratio = ( _RS / _R0);
 return pow(_ratio,_vb)*_va;
}

//**************************************ppm Value**************************************\\

float HelloSensor::MQData100(){return map(analogRead(_pin),0,(_bitadc-1),0,100);}
float HelloSensor::MQ2DataAir(){return map(analogRead(_pin),1,(_bitadc-1),300,10000);}
float HelloSensor::MQ3DataAir(){return map(analogRead(_pin),1,(_bitadc-1),25,500);}
float HelloSensor::MQ4DataAir(){return map(analogRead(_pin),1,(_bitadc-1),300,10000);}
float HelloSensor::MQ5DataAir(){return map(analogRead(_pin),1,(_bitadc-1),200,10000);}
float HelloSensor::MQ6DataAir(){return map(analogRead(_pin),1,(_bitadc-1),300,10000);}
float HelloSensor::MQ7DataAir(){return map(analogRead(_pin),1,(_bitadc-1),10,10000);}
float HelloSensor::MQ8DataAir(){return map(analogRead(_pin),1,(_bitadc-1),10,10000);}
float HelloSensor::MQ9DataAir(){return map(analogRead(_pin),1,(_bitadc-1),10,10000);}
float HelloSensor::MQ131DataAir(){return map(analogRead(_pin),1,(_bitadc-1),5,100);}
float HelloSensor::MQ135DataAir(){return map(analogRead(_pin),1,(_bitadc-1),10,1000);}
float HelloSensor::MQ136DataAir(){return map(analogRead(_pin),1,(_bitadc-1),10,200);}
float HelloSensor::MQ303ADataAir(){return map(analogRead(_pin),1,(_bitadc-1),10,10000);}
float HelloSensor::MQ309ADataAir(){return map(analogRead(_pin),1,(_bitadc-1),30,3000);}

//**************************************MQ-2**************************************\\

float HelloSensor::MQ2DataH2(){_va = 987.99;_vb = -2.162;return readValue();}
float HelloSensor::MQ2DataLPG(){_va = 574.25;_vb = -2.222; return readValue();}
float HelloSensor::MQ2DataCO(){_va = 36974;_vb = -3.109;return readValue();}
float HelloSensor::MQ2DataAlcohol(){_va = 3616.1;_vb = -2.675;return readValue();}
float HelloSensor::MQ2DataPropane(){_va = 658.71;_vb = -2.168;return readValue();}

//**************************************MQ-3**************************************\\

float HelloSensor::MQ3DataLPG(){_va = 44771;_vb = -3.245;return readValue();}
float HelloSensor::MQ3DataCH4(){_va = 2*10^31;_vb = 19.01;return readValue();}
float HelloSensor::MQ3DataCO(){_va = 521853;_vb = -3.821;return readValue();}
float HelloSensor::MQ3DataAlcohol(){_va = 0.3934;_vb = -1.504;return readValue();}
float HelloSensor::MQ3DataBenzene(){_va = 4.8387;_vb = -2.68;return readValue();}
float HelloSensor::MQ3DataHexane(){_va = 7585.3;_vb = -2.849;return readValue();}

//**************************************MQ-4**************************************\\

float HelloSensor::MQ4DataLPG(){_va = 3811.9;_vb = -3.113;return readValue();}
float HelloSensor::MQ4DataCH4(){_va = 1012.7;_vb = -2.786;return readValue();}
float HelloSensor::MQ4DataCO(){_va = 200000000000000;_vb = -19.05;return readValue();}
float HelloSensor::MQ4DataAlcohol(){_va = 60000000000;_vb = -14.01;return readValue();}
float HelloSensor::MQ4DataSmoke(){_va = 30000000;_vb = -8.308;return readValue();}

//**************************************MQ-5**************************************\\

float HelloSensor::MQ5DataH2(){_va = 1163.8;_vb = -3.874;return readValue();}
float HelloSensor::MQ5DataLPG(){_va = 80.897; _vb = -2.431;return readValue();}
float HelloSensor::MQ5DataCH4(){_va = 177.65;_vb = -2.56;return readValue();}
float HelloSensor::MQ5DataCO(){_va = 491204; _vb = -5.826; return readValue();}
float HelloSensor::MQ5DataAlcohol(){_va = 97124;_vb = -4.918;return readValue();}

//**************************************MQ-6**************************************\\

float HelloSensor::MQ6DataH2(){_va = 88158;_vb =  -3.597;return readValue();}
float HelloSensor::MQ6DataLPG(){_va = 1009.2;_vb =  -2.35; return readValue();}
float HelloSensor::MQ6DataCH4(){_va = 2127.2;  _vb = -2.526;return readValue();}
float HelloSensor::MQ6DataCO(){_va = 1000000000000000; _vb = -13.5;return readValue();}
float HelloSensor::MQ6DataAlcohol(){_va = 50000000;_vb = -6.017;return readValue();}

//**************************************MQ-7**************************************\\

float HelloSensor::MQ7DataH2(){_va = 69.014;_vb = -1.374; return readValue();}
float HelloSensor::MQ7DataLPG(){_va = 700000000;_vb = -7.703;return readValue();}
float HelloSensor::MQ7DataCH4(){_va = 60000000000000;_vb = -10.54;return readValue();}
float HelloSensor::MQ7DataCO(){_va = 99.042;_vb = -1.518;return readValue();}
float HelloSensor::MQ7DataAlcohol(){_va = 40000000000000000;_vb = -12.35;return readValue();}

//**************************************MQ-8**************************************\\

float HelloSensor::MQ8DataH2(){_va = 976.97;_vb = -0.688;return readValue();}
float HelloSensor::MQ8DataLPG(){_va = 10000000;_vb = -3.12;return readValue();}
float HelloSensor::MQ8DataCH4(){_va = 80000000000000;_vb = -6.666;return readValue();}
float HelloSensor::MQ8DataCO(){_va = 2000000000000000000;_vb = -8.074;return readValue();}
float HelloSensor::MQ8DataAlcohol(){_va = 76101; _vb = -1.86;return readValue();}

//**************************************MQ-9**************************************\\

float HelloSensor::MQ9DataLPG(){_va = 1000.5;_vb = -2.186;return readValue();}
float HelloSensor::MQ9DataCH4(){_va = 4269.6;_vb = -2.648;return readValue();}
float HelloSensor::MQ9DataCO(){_va = 599.65;_vb = -2.244;return readValue();}

//**************************************MQ-131**************************************\\

float HelloSensor::MQ131DataNOx(){_va = -462.43;_vb = -2.204;return readValue();}
float HelloSensor::MQ131DataCL2(){_va = 47.209;_vb = -1.186;return readValue();}
float HelloSensor::MQ131DataO3(){_va = 23.943;_vb = -1.11;return readValue();}

//**************************************MQ-135**************************************\\

float HelloSensor::MQ135DataCO(){_va = 605.18;_vb = -3.937;return readValue();}
float HelloSensor::MQ135DataAlcohol(){_va = 77.255;_vb = -3.18;return readValue();}
float HelloSensor::MQ135DataCO2(){_va = 110.47;_vb = -2.862; return readValue();}
float HelloSensor::MQ135DataToluen(){_va = 44.947;_vb = -3.445;return readValue();}
float HelloSensor::MQ135DataNH4(){_va = 102.2;_vb = -2.473;return readValue();}
float HelloSensor::MQ135DataAceton(){_va = 34.668;_vb = -3.369; return readValue();}

//**************************************MQ-136**************************************\\

float HelloSensor::MQ136DataH2S(){_va = 36.737;_vb = -3.536;return readValue();}
float HelloSensor::MQ136DataNH4(){_va = 98.551;_vb = -2.475;return readValue();}
float HelloSensor::MQ136DataCO(){_va = 503.34;_vb = -3.774;return readValue();}

//**************************************MQ-303A**************************************\\

float HelloSensor::MQ303ADataIso(){_va = 6.2144;_vb = -2.894;return readValue();}
float HelloSensor::MQ303ADataHyd(){_va = 4.1487;_vb = -2.716;return readValue();}
float HelloSensor::MQ303ADataEthanol(){_va = 3.4916;_vb = -2.432;return readValue();}

//**************************************MQ-309A**************************************\\

float HelloSensor::MQ309ADataH2(){_va = 1532.9;_vb = -1.951;return readValue();}
float HelloSensor::MQ309ADataCH4(){_va = 980.24;_vb = -1.68;return readValue();}
float HelloSensor::MQ309ADataCO(){_va = 1000000;_vb = -4.01;return readValue();}
float HelloSensor::MQ309ADataAlcohol(){_va = 473622;_vb = -3.647;return readValue();}

GeigerCounterPin::GeigerCounterPin(byte pin2, int LOG_PERIOD1)
{
  _pin2=pin2;
  _LOG_PERIOD=LOG_PERIOD1;
}
 
unsigned long _counts;

void _impulse() {
   _counts++;
}

float outputSieverts(float x) {
    float y = x * 0.0057;
    return y;
}

void GeigerCounterPin::begin()
{
    _counts = 0;
    _currentCPM = 0;
    _averageCPM = 0;
    _sdCPM = 0;
    _calcCPM = 0;
    pinMode(_pin2, INPUT);
    attachInterrupt(digitalPinToInterrupt(_pin2), _impulse, FALLING);
}

void GeigerCounterPin::radyoactivite()
{
    count = _counts ;

    unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > _LOG_PERIOD) {
    previousMillis = currentMillis;
    _CPMArray[_currentCPM] = _counts * 2;

    usvhr = outputSieverts(_CPMArray[_currentCPM]);

    _counts = 0;
    _averageCPM = 0;
    _sdCPM = 0;
  
    //calc avg and sd
    for (int x=0;x<_currentCPM+1;x++)  {
      _averageCPM = _averageCPM + _CPMArray[x];
    }
    _averageCPM = _averageCPM / (_currentCPM + 1);
    for (int x=0;x<_currentCPM+1;x++)  {
      _sdCPM = _sdCPM + sq(_CPMArray[x] - _averageCPM);
    }
    _sdCPM = sqrt(_sdCPM / _currentCPM) / sqrt(_currentCPM+1);

       Avg = outputSieverts(_averageCPM);
       sdCPM = outputSieverts(_sdCPM);
    _currentCPM = _currentCPM + 1;
}
}
