#include <WiFi.h>
#include <Wire.h>
#include <TFLI2C.h>
#include <TinyGPS++.h>
#include <ESP32Servo.h>
#include "ThingSpeak.h"
#include "TM1637.h"
#include "HelloSensor.h"

#define ADC_BIT_RESU  (12)
#define space1        (35)
#define space2        (34)

#define LOG_PERIOD1 (30000)
#define GeigerPin1  (39)

#define CLK (18)
#define DIO (15)

TM1637 tm1637(CLK,DIO);
TFLI2C tflI2C;

HelloSensor MQ(ADC_BIT_RESU, space1), other(ADC_BIT_RESU, space2);
GeigerCounterPin Radyoactivite(GeigerPin1, LOG_PERIOD1);

HardwareSerial neogps(1); 
TinyGPSPlus gps;
Servo myservo, secondservo;

int value1, value2, value3, value4, value5, value6, value7, sec, Angle0, Angle15, Angle30, Angle45, Angle60, Angle75, Angle90, 
Angle105, Angle120, Angle135, Angle150, Angle165, Angle180, Angle195, Angle210, Angle225, Angle240, Angle255, Angle270, Angle285, 
Angle300, Angle315, Angle330, Angle345, maxAngle, Green0, Green15, Green30, Green45, Green60, Green75, Green90, Green105, 
Green120, Green135, Green150, Green165, Green180, Green195, Green210, Green225, Green240, Green255, Green270, Green285, Green300, 
Green315, Green330, Green345, Average, Temp0, Temp15, Temp30, Temp45, Temp60, Temp75, Temp90, Temp105, Temp120, Temp135, 
Temp150, Temp165, Temp180, Temp195, Temp210, Temp225, Temp240, Temp255, Temp270, Temp285, Temp300, Temp315, Temp330, Temp345;
int lidcontrol, gpscontrol = 0;

String latitude, longitude;

int16_t  tfAddr = TFL_DEF_ADR;   
uint16_t tfFrame = TFL_DEF_FPS;   

int16_t  tfDist = 0;   
int16_t  tfFlux = 0;  
int16_t  tfTemp = 0;  

const char* ssid = "REPLACE_WİTH_YOUR_SSID";  
const char* password = "REPLACE_WİTH_YOUR_PASSWORD";
WiFiClient  client;

unsigned int hello6 = 6;
unsigned int hello5 = 5;
unsigned int hello4 = 4;
unsigned int hello3 = 3;
unsigned int hello2 = 2;
unsigned int hello1 = 1;

static const char * myWriteAPIKey1 = "J2UEIZSZTC5568NM";
static const char * myWriteAPIKey2 = "ZVZ3UYIV4PTYA6XP";
static const char * myWriteAPIKey3 = "0HSEW6FQ65NWH2EP";
static const char * myWriteAPIKey4 = "JCBZHB1KUX0Y09LX";
static const char * myWriteAPIKey5 = "QP8J57RU9BY9NAVE";
static const char * myWriteAPIKey6 = "YSXKFJYHCZGW00DT";

unsigned long int lastTime = 0;
unsigned long int timerDelay = 15000;

void setup() {
  Serial.begin(115200);  
  MQ.begin();
  other.begin();
  Radyoactivite.begin();
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);
  myservo.attach(33);
  secondservo.attach(32);
  neogps.begin(9600, SERIAL_8N1, 3, 1);
  Wire.begin();
  myservo.write(0);
  delay(10000);
  secondservo.write(0);
  WiFi.mode(WIFI_STA); Serial.println("Connecting to WiFi ");
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  
  ThingSpeak.begin(client);
}

void loop() {
sec = map(analogRead(36),0,(1 << ADC_BIT_RESU) - 1,1,14);
switch(sec){
case (1):
{
MQ135doing();
}
break;
case (2):
{
normal();
MQ.RSRoMQAir(9.8);
MQ.setRL(20);
MQ.dangerousPer(10.2); 
value1 = MQ.MQ2DataH2();
MQ.dangerousPer(7.96);
value2 = MQ.MQ2DataLPG();
MQ.dangerousPer(31.63);
value3 = MQ.MQ2DataCO();
MQ.dangerousPer(16.33);
value4 = MQ.MQ2DataAlcohol();
MQ.dangerousPer(8.38);
value5 = MQ.MQ2DataPropane();
MQ.dangerousPer(17.86);
value6 = MQ.MQ2DataCH4(); 
MQ.dangerousPer(18.98);
value7 = MQ.MQ2Datasmoke();
// value8 = MQ.MQ2DataAir();
}
break;
case (3):
{
normal();
MQ.RSRoMQAir(60.53);
MQ.setRL(200);
MQ.dangerousPer(48.97);
value1 = MQ.MQ3DataLPG();
MQ.dangerousPer(74.69);
value2 = MQ.MQ3DataCH4();
MQ.dangerousPer(57);
value3 = MQ.MQ3DataCO();
MQ.dangerousPer(0.67);
value4 = MQ.MQ3DataAlcohol();
MQ.dangerousPer(2.92);
value5 = MQ.MQ3DataBenzene();
MQ.dangerousPer(38);
value6 = MQ.MQ3DataHexane();  
value7 = MQ.MQ3DataAir();
}
break;
case (4):
{
normal();
MQ.RSRoMQAir(4.4);
MQ.setRL(20);
MQ.dangerousPer(64.43);
value1 = MQ.MQ4DataH2();
MQ.dangerousPer(34.32);
value2 = MQ.MQ4DataLPG();
MQ.dangerousPer(22.73);
value3 = MQ.MQ4DataCH4();
MQ.dangerousPer(86.14);
value4 = MQ.MQ4DataCO();
MQ.dangerousPer(82.05);
value5 = MQ.MQ4DataAlcohol();
MQ.dangerousPer(80.23);
value6 = MQ.MQ4DataSmoke();
value7 = MQ.MQ4DataAir(); 
}
break;
case (5):
{
normal();
MQ.RSRoMQAir(6.5);
MQ.setRL(20);
MQ.dangerousPer(15.12);
value1 = MQ.MQ5DataH2();
MQ.dangerousPer(5.54);
value2 = MQ.MQ5DataLPG();
MQ.dangerousPer(7.92);
value3 = MQ.MQ5DataCH4();
MQ.dangerousPer(44.15);
value4 = MQ.MQ5DataCO();
MQ.dangerousPer(39.38);
value5 = MQ.MQ5DataAlcohol();
value6 = MQ.MQ5DataAir();
value7 = 0;
}
break;
case (6):
{
normal();
MQ.RSRoMQAir(10);
MQ.setRL(20);
MQ.dangerousPer(33.7);
value1 = MQ.MQ6DataH2();
MQ.dangerousPer(10);
value2 = MQ.MQ6DataLPG();
MQ.dangerousPer(13.5);
value3 = MQ.MQ6DataCH4();
MQ.dangerousPer(78);
value4 = MQ.MQ6DataCO();
MQ.dangerousPer(61.2);
value5 = MQ.MQ6DataAlcohol();
value6 = MQ.MQ6DataAir();
value7 = 0;
}
break;
case (7):
{
normal();
MQ.RSRoMQAir(26);
MQ.setRL(10);
MQ.dangerousPer(3.08);
value1 = MQ.MQ7DataH2();
MQ.dangerousPer(30.77);
value2 = MQ.MQ7DataLPG();
MQ.dangerousPer(49.18);
value3 = MQ.MQ7DataCH4();
MQ.dangerousPer(3.85);
value4 = MQ.MQ7DataCO();
MQ.dangerousPer(57.69);
value5 = MQ.MQ7DataAlcohol();
value6 = MQ.MQ7DataAir();
value7 = 0;
}
break;
case (8):
{
normal();
MQ.RSRoMQAir(70);
MQ.setRL(10);
MQ.dangerousPer(1.43);
value1 = MQ.MQ8DataH2();
MQ.dangerousPer(27.53);
value2 = MQ.MQ8DataLPG();
MQ.dangerousPer(63.47);
value3 = MQ.MQ8DataCH4();
MQ.dangerousPer(80.57);
value4 = MQ.MQ8DataCO();
MQ.dangerousPer(14.81);
value5 = MQ.MQ8DataAlcohol();
value6 = MQ.MQ8DataAir();
value7 = 0;
}
break;
case (9):
{
normal();
MQ.RSRoMQAir(9.7);
MQ.setRL(20);
MQ.dangerousPer(10.31);
value1 = MQ.MQ9DataLPG();
MQ.dangerousPer(18.04);
value2 = MQ.MQ9DataCH4();
MQ.dangerousPer(8);
value3 = MQ.MQ9DataCO();
value4 = MQ.MQ9DataAir();
value5 = value6 = value7 = 0;
}
break;
case (10):
{
tm1637.display(3,1);
tm1637.display(2,3);
tm1637.display(1,1);
tm1637.display(0,0);
MQ.RSRoMQAir(12);
MQ.setRL(100);
MQ.dangerousPer(23.75);
value1 = MQ.MQ131DataNOx();
MQ.dangerousPer(8.33);
value2 = MQ.MQ131DataCL2();
MQ.dangerousPer(4.166);
value3 = MQ.MQ131DataO3();
value4 = MQ.MQ131DataAir();
value5 = value6 = value7 = 0;
}
break;
case (11):
{
tm1637.display(3,6);
tm1637.display(2,3);
tm1637.display(1,1);
tm1637.display(0,0);
MQ.RSRoMQAir(3.54);
MQ.setRL(20);
MQ.dangerousPer(40.68);
value1 = MQ.MQ136DataH2S();
MQ.dangerousPer(72);
value2 = MQ.MQ136DataNH4();
MQ.dangerousPer(81.64);
value3 = MQ.MQ136DataCO();
value4 = MQ.MQ136DataAir();
value5 = value6 = value7 = 0;
}
break;
case (12):
{
tm1637.display(3,7);
tm1637.display(2,3);
tm1637.display(1,1);
tm1637.display(0,0);
MQ.RSRoMQAir(3.54);
MQ.setRL(47);
MQ.dangerousPer(81.64);
value1 = MQ.MQ137DataCO();
MQ.dangerousPer(72);
value2 = MQ.MQ137DataEthanol();
MQ.dangerousPer(40.68);
value3 = MQ.MQ137DataNH3();
value4 = MQ.MQ137DataAir();
value5 = value6 = value7 = 0;
}
break;
case (13):
{
tm1637.display(3,10);
tm1637.display(2,3);
tm1637.display(1,0);
tm1637.display(0,3);
MQ.RSRoMQAir(1);
MQ.setRL(47);
MQ.dangerousPer(17);
value1 = MQ.MQ303ADataIso();
MQ.dangerousPer(13);
value2 = MQ.MQ303ADataHyd();
MQ.dangerousPer(10);
value3 = MQ.MQ303ADataEthanol();
value4 = MQ.MQ303ADataAir();
value5 = value6 = value7 = 0;
}
break;
case (14):
{
tm1637.display(3,10);
tm1637.display(2,9);
tm1637.display(1,0);
tm1637.display(0,3);
MQ.setRL(50);
MQ.RSRoMQAir(11);
MQ.dangerousPer(11.4545);
value1 = MQ.MQ309ADataH2();
MQ.dangerousPer(9.0909);
value2 = MQ.MQ309ADataCH4();
MQ.dangerousPer(54.5454); 
value3 = MQ.MQ309ADataCO();
MQ.dangerousPer(49.0909);
value4 = MQ.MQ309ADataAlcohol();
MQ.RSRoMQAir(100);
MQ.dangerousPer(0.15); 
value5 = MQ.MQ309ADataLowCO();
MQ.dangerousPer(81.9);
value6 = MQ.MQ309ADataSecondH2();
value7 = MQ.MQ309ADataAir();
}
break;
default:
{
sec = 1;
MQ135doing();
}
break;
}

    if(tflI2C.getData( tfDist, tfFlux, tfTemp, tfAddr))
    {
        tfTemp = int16_t( tfTemp / 100 + 20);
        tfFlux = int16_t( tfFlux + 10000);
        tfDist = int16_t( tfDist + 1000);
        
        Angle0 = tfDist;
        Green0 = tfFlux;
        Temp0  = tfTemp;
        delay(10);
        secondservo.write(15);
        Angle15 = tfDist;
        Green15 = tfFlux;
        Temp15  = tfTemp;
        delay(10);
        secondservo.write(30);
        Angle30 = tfDist;
        Green30 = tfFlux;
        Temp30  = tfTemp;
        delay(10);
        secondservo.write(45);
        Angle45 = tfDist;
        Green45 = tfFlux;
        Temp45  = tfTemp;
        delay(10);
        secondservo.write(60);
        Angle60 = tfDist;
        Green60 = tfFlux;
        Temp60  = tfTemp;
        delay(10);
        secondservo.write(75);
        Angle75 = tfDist;
        Green75 = tfFlux;
        Temp75  = tfTemp;
        delay(10);
        secondservo.write(90);
        Angle90 = tfDist;
        Green90 = tfFlux;
        Temp90  = tfTemp;
        delay(10);
        secondservo.write(105);
        Angle105 = tfDist;
        Green105 = tfFlux;
        Temp105  = tfTemp;
        delay(10);
        secondservo.write(120);
        Angle120 = tfDist;
        Green120 = tfFlux;
        Temp120  = tfTemp;
        delay(10);
        secondservo.write(135);
        Angle135 = tfDist;
        Green135 = tfFlux;
        Temp135  = tfTemp;
        delay(10);  
        secondservo.write(150);
        Angle150 = tfDist;
        Green150 = tfFlux;
        Temp150  = tfTemp;
        delay(10);
        secondservo.write(165);
        Angle165 = tfDist;
        Green165 = tfFlux;
        Temp165  = tfTemp;
        delay(10);
        secondservo.write(180);
        Angle180 = tfDist;
        Green180 = tfFlux;
        Temp180  = tfTemp;
        delay(10);
        myservo.write(180);
        secondservo.write(165);
        Angle195 = tfDist;
        Green195 = tfFlux;
        Temp195  = tfTemp;
        delay(10);
        secondservo.write(150);
        Angle210 = tfDist;
        Green210 = tfFlux;
        Temp210  = tfTemp;
        delay(10);
        secondservo.write(135);
        Angle225 = tfDist;
        Green225 = tfFlux;
        Temp225  = tfTemp;
        delay(10);
        secondservo.write(120);
        Angle240 = tfDist;
        Green240 = tfFlux;
        Temp240  = tfTemp;
        delay(10);
        secondservo.write(105);
        Angle255 = tfDist;
        Green255 = tfFlux;
        Temp255  = tfTemp;
        delay(10);
        secondservo.write(90);
        Angle270 = tfDist;
        Green270 = tfFlux;
        Temp270  = tfTemp;
        delay(10);
        secondservo.write(75);
        Angle285 = tfDist;
        Green285 = tfFlux;
        Temp285  = tfTemp;
        delay(10);
        secondservo.write(60);
        Angle300 = tfDist;
        Green300 = tfFlux;
        Temp300  = tfTemp;
        delay(10);
        secondservo.write(45);
        Angle315 = tfDist;
        Green315 = tfFlux;
        Temp315  = tfTemp;
        delay(10);
        secondservo.write(30);
        Angle330 = tfDist;
        Green330 = tfFlux;
        Temp330  = tfTemp;
        delay(10);  
        secondservo.write(15);
        Angle345 = tfDist;
        Green345 = tfFlux;
        Temp345  = tfTemp;
        delay(10);
        myservo.write(0);
        secondservo.write(0);
        lidcontrol = 1;
Average = (Angle0 + Angle15 + Angle30 + Angle45 + Angle60 + Angle75 + Angle90 + Angle105 + Angle120 + Angle135 + Angle150 + Angle165 + Angle180 +
Angle195 + Angle210 + Angle225 + Angle240 + Angle255 + Angle270 + Angle285 + Angle300 + Angle315 + Angle330 + Angle345) / 12;
int angles[] = {Angle0, Angle15, Angle30, Angle45, Angle60, Angle75, Angle90, Angle105, Angle120, Angle135, Angle150, Angle165, Angle180,
Angle195, Angle210, Angle225, Angle240, Angle255, Angle270, Angle285, Angle300, Angle315, Angle330, Angle345};
for (int i = 0; i < 24; i++) {if (angles[i] > maxAngle) (maxAngle = angles[i]);}
if (Average < maxAngle)(Average = maxAngle);
Average += 1000
    }

Radyoactivite.radyoactivite();

  if (neogps.available()) {
    char c = neogps.read();
    if (gps.encode(c)) {
      if (gps.location.isValid()) {
       latitude  = (gps.location.lat(), 6) * pow(10,6); 
       longitude = (gps.location.lng(), 6) * pow(10,6); 
       gpscontrol = 1;
      }
    }
  }
  
  if ((millis() - lastTime) > timerDelay) {

    ThingSpeak.setField(1, value1);
    ThingSpeak.setField(2, value2);
    ThingSpeak.setField(3, value3);
    ThingSpeak.setField(4, value4);
    ThingSpeak.setField(5, value5);
    ThingSpeak.setField(6, value6);
    ThingSpeak.setField(7, value7);
    ThingSpeak.setField(8, sec);
  int a = ThingSpeak.writeFields(hello1, myWriteAPIKey1);
    ThingSpeak.setField(1, Radyoactivite.usvhr*100);
    ThingSpeak.setField(2, Radyoactivite.Avg*100); // 10 +/- 11
    ThingSpeak.setField(3, Radyoactivite.sdCPM*100); // 10 +/- 11
    ThingSpeak.setField(4, Radyoactivite.count);    
    ThingSpeak.setField(5, MQ.MQData100());    
    ThingSpeak.setField(6, other.MQData100());   
    if (gpscontrol == 1){ 
    ThingSpeak.setField(7, latitude);
    ThingSpeak.setField(8, longitude);
    }
    int b = ThingSpeak.writeFields(hello2, myWriteAPIKey2);
    if (lidcontrol == 1){ 
    ThingSpeak.setField(1, String(Green0)+String(Green15));
    ThingSpeak.setField(2, String(Green30)+String(Green45));
    ThingSpeak.setField(3, String(Green60)+String(Green75));
    ThingSpeak.setField(4, String(Green90)+String(Green105));
    ThingSpeak.setField(5, String(Green120)+String(Green135));
    ThingSpeak.setField(6, String(Green150)+String(Green165));
    ThingSpeak.setField(7, String(Green180)+String(Green195));
    ThingSpeak.setField(8, String(Green210)+String(Green225));
  int c = ThingSpeak.writeFields(hello3, myWriteAPIKey3);
    ThingSpeak.setField(1, String(Green0)+String(Green255));
    ThingSpeak.setField(2, String(Green30)+String(Green285));
    ThingSpeak.setField(3, String(Green60)+String(Green315));
    ThingSpeak.setField(4, String(Green90)+String(Green345));
    ThingSpeak.setField(5, String(Average)+String(Temp0)+String(Temp15)+String(Temp30));
    ThingSpeak.setField(6, String(Temp45)+String(Angle0)+String(Angle15));
    ThingSpeak.setField(7, String(Temp60)+String(Angle30)+String(Angle45));
    ThingSpeak.setField(8, String(Temp75)+String(Angle60)+String(Angle75));
  int d = ThingSpeak.writeFields(hello4, myWriteAPIKey4);
    ThingSpeak.setField(1, String(Temp90)+String(Angle90)+String(Angle105));
    ThingSpeak.setField(2, String(Temp105)+String(Angle120)+String(Angle135));
    ThingSpeak.setField(3, String(Temp120)+String(Angle150)+String(Angle165));
    ThingSpeak.setField(4, String(Temp135)+String(Angle180)+String(Angle195));
    ThingSpeak.setField(5, String(Temp150)+String(Angle210)+String(Angle225));
    ThingSpeak.setField(6, String(Temp165)+String(Angle240)+String(Angle255));
    ThingSpeak.setField(7, String(Temp180)+String(Angle270)+String(Angle285));
    ThingSpeak.setField(8, String(Temp195)+String(Angle300)+String(Angle315));
  int e = ThingSpeak.writeFields(hello5, myWriteAPIKey5);
    ThingSpeak.setField(1, String(Temp210)+String(Angle330)+String(Angle345));
    ThingSpeak.setField(2, String(Temp225)+String(Temp240)+String(Temp255)+String(Temp270)+String(Temp285));
    ThingSpeak.setField(3, String(Temp300)+String(Temp315)+String(Temp330)+String(Temp345));
  int f = ThingSpeak.writeFields(hello6, myWriteAPIKey6);
    }
    lastTime = millis();
    gpscontrol = 0;
    lidcontrol = 0;
  }
}

void normal(){
tm1637.display(3,sec);
tm1637.display(2,sec);
tm1637.display(1,sec);
tm1637.display(0,sec);
}

void MQ135doing(){
tm1637.display(3,5);
tm1637.display(2,3);
tm1637.display(1,1);
tm1637.display(0,0);
MQ.RSRoMQAir(3.6);
MQ.setRL(20);
MQ.dangerousPer(42.5);
value1 = MQ.MQ135DataCO();
MQ.dangerousPer(25.55);
value2 = MQ.MQ135DataAlcohol();
MQ.dangerousPer(27.77);
value3 = MQ.MQ135DataCO2();
MQ.dangerousPer(21.944);
value4 = MQ.MQ135DataToluen();
MQ.dangerousPer(29.166);
value5 = MQ.MQ135DataNH4();
MQ.dangerousPer(20.55);
value6 = MQ.MQ135DataAceton();
value7 = MQ.MQ135DataAir();
}

// GPS : [GND --> GND] [TX --> D3] [RX --> D1] [VCC --> 3.3V]
// Geiger Counter: [PIN --> D39] [GND --> GND] [VCC --> 5V]
// TfLuna Lidar: [VCC --> 5V] [SDA --> D21] [SCL --> D22] [GND --> GND] [I2C --> GND] 
// MQ-X: [PIN --> D35, D35 (motor-control)] [GND --> GND, GND (motor-control] [VCC --> 3.3V (motor-control)]
// Other Sensor: [PIN --> D34, D34 (motor-control)] [GND --> GND, GND (motor-control] [VCC --> 3.3V (motor-control)]
// Potentiometer: [PIN --> D36] [GND --> GND] [VCC --> 3.3V]
// TM1637: [CLK --> D18] [DIO --> D15] [VCC --> 5V] [GND --> GND]
// Servo: [PIN --> D33] [VCC --> 5V] [GND --> GND]
// Servo2: [PIN --> D32] [VCC --> 5V] [GND --> GND]
