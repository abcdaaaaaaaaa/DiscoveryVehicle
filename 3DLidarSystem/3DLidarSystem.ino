#include <WiFi.h>
#include <Wire.h>
#include <TFLI2C.h>
#include <ESP32Servo.h>
#include "ThingSpeak.h"

TFLI2C tflI2C;
Servo myservo;

int Angle0, Angle15, Angle30, Angle45, Angle60, Angle75, Angle90, Angle105, Angle120, Angle135, Angle150, Angle165, Angle180, Angle195, 
Angle210, Angle225, Angle240, Angle255, Angle270, Angle285, Angle300, Angle315, Angle330, Angle345, maxAngle, Green0, Green15, Green30, 
Green45, Green60, Green75, Green90, Green105, Green120, Green135, Green150, Green165, Green180, Green195, Green210, Green225, Green240, 
Green255, Green270, Green285, Green300, Green315, Green330, Green345, Temp, Average;

int lidcontrol = 0;

int16_t  tfAddr = TFL_DEF_ADR;   
uint16_t tfFrame = TFL_DEF_FPS;   

int16_t  tfDist = 0;   
int16_t  tfFlux = 0;  
int16_t  tfTemp = 0;  

const char* ssid = "REPLACE_WİTH_YOUR_SSID";  
const char* password = "REPLACE_WİTH_YOUR_PASSWORD";
WiFiClient  client;

unsigned int hello3 = 3;
unsigned int hello2 = 2;
unsigned int hello1 = 1;

static const char * myWriteAPIKey1 = "0HSEW6FQ65NWH2EP";
static const char * myWriteAPIKey2 = "JCBZHB1KUX0Y09LX";
static const char * myWriteAPIKey3 = "QP8J57RU9BY9NAVE";

unsigned long int lastTime = 0;
unsigned long int timerDelay = 15000;

void setup() {
  Serial.begin(115200);  
  myservo.attach(2);
  Wire.begin();
  myservo.write(0);
  WiFi.mode(WIFI_STA); 
  Serial.println("Connecting to WiFi ");
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

    Serial.println("will connect");
      if(tflI2C.getData( tfDist, tfFlux, tfTemp, tfAddr))
      {
        Serial.println("connected!");
        tfTemp = int16_t( tfTemp / 100 + 20);
        tfFlux = int16_t( tfFlux + 10000);
        tfDist = int16_t( tfDist + 1000);

        Temp = tfTemp;
        
        myservo.write(0);    
        Angle0 = tfDist;
        Green0 = tfFlux;
        delay(10);
        myservo.write(15);
        Angle15 = tfDist;
        Green15 = tfFlux;
        delay(10);
        myservo.write(30);
        Angle30 = tfDist;
        Green30 = tfFlux;
        delay(10);
        myservo.write(45);
        Angle45 = tfDist;
        Green45 = tfFlux;
        delay(10);
        myservo.write(60);
        Angle60 = tfDist;
        Green60 = tfFlux;
        delay(10);
        myservo.write(75);
        Angle75 = tfDist;
        Green75 = tfFlux;
        delay(10);
        myservo.write(90);
        Angle90 = tfDist;
        Green90 = tfFlux;
        delay(10);
        myservo.write(105);
        Angle105 = tfDist;
        Green105 = tfFlux;
        delay(10);
        myservo.write(120);
        Angle120 = tfDist;
        Green120 = tfFlux;
        delay(10);
        myservo.write(135);
        Angle135 = tfDist;
        Green135 = tfFlux;
        delay(10);  
        myservo.write(150);
        Angle150 = tfDist;
        Green150 = tfFlux;
        delay(10);
        myservo.write(165);
        Angle165 = tfDist;
        Green165 = tfFlux;
        delay(10);
        myservo.write(180);
        Angle180 = tfDist;
        Green180 = tfFlux;
        delay(10);
        myservo.write(195);
        Angle195 = tfDist;
        Green195 = tfFlux;
        delay(10);
        myservo.write(210);
        Angle210 = tfDist;
        Green210 = tfFlux;
        delay(10);
        myservo.write(225);
        Angle225 = tfDist;
        Green225 = tfFlux;
        delay(10);
        myservo.write(240);
        Angle240 = tfDist;
        Green240 = tfFlux;
        delay(10);
        myservo.write(255);
        Angle255 = tfDist;
        Green255 = tfFlux;
        delay(10);
        myservo.write(270);
        Angle270 = tfDist;
        Green270 = tfFlux;
        delay(10);
        myservo.write(285);
        Angle285 = tfDist;
        Green285 = tfFlux;
        delay(10);
        myservo.write(300);
        Angle300 = tfDist;
        Green300 = tfFlux;
        delay(10);
        myservo.write(315);
        Angle315 = tfDist;
        Green315 = tfFlux;
        delay(10);
        myservo.write(330);
        Angle330 = tfDist;
        Green330 = tfFlux;
        delay(10);  
        myservo.write(345);
        Angle345 = tfDist;
        Green345 = tfFlux;
        delay(10);
        myservo.write(0);
        lidcontrol = 1;
      }
  
  if ((millis() - lastTime) > timerDelay) {
    if (lidcontrol == 1){ 
    ThingSpeak.setField(1, String(Green0)+String(Angle0));
    ThingSpeak.setField(2, String(Green15)+String(Angle15));
    ThingSpeak.setField(3, String(Green30)+String(Angle30));
    ThingSpeak.setField(4, String(Green45)+String(Angle45));
    ThingSpeak.setField(5, String(Green60)+String(Angle60));
    ThingSpeak.setField(6, String(Green75)+String(Angle75));
    ThingSpeak.setField(7, String(Green90)+String(Angle90));
    ThingSpeak.setField(8, String(Green105)+String(Angle105));
  int c = ThingSpeak.writeFields(hello1, myWriteAPIKey1);
    ThingSpeak.setField(1, String(Green120)+String(Angle120));
    ThingSpeak.setField(2, String(Green135)+String(Angle135));
    ThingSpeak.setField(3, String(Green150)+String(Angle150));
    ThingSpeak.setField(4, String(Green165)+String(Angle165));
    ThingSpeak.setField(5, String(Green180)+String(Angle180));
    ThingSpeak.setField(6, String(Green195)+String(Angle195));
    ThingSpeak.setField(7, String(Green210)+String(Angle210));
    ThingSpeak.setField(8, String(Green225)+String(Angle225));
  int d = ThingSpeak.writeFields(hello2, myWriteAPIKey2);
    ThingSpeak.setField(1, String(Green240)+String(Angle240));
    ThingSpeak.setField(2, String(Green255)+String(Angle255));
    ThingSpeak.setField(3, String(Green270)+String(Angle270));
    ThingSpeak.setField(4, String(Green285)+String(Angle285));
    ThingSpeak.setField(5, String(Green300)+String(Angle300));
    ThingSpeak.setField(6, String(Green315)+String(Angle315));
    ThingSpeak.setField(7, String(Green330)+String(Green345));
    ThingSpeak.setField(8, String(Angle330)+String(Angle345)+String(Temp));
  int e = ThingSpeak.writeFields(hello3, myWriteAPIKey3);
    }
    lastTime = millis();
    lidcontrol = 0;
  }
}

// TfLuna Lidar: [VCC --> 5V] [SDA --> D21] [SCL --> D22] [GND --> GND] [I2C --> GND] 
// Servo: [PIN --> D33] [VCC --> 5V] [GND --> GND]
// Servo2: [PIN --> D32] [VCC --> 5V] [GND --> GND]

