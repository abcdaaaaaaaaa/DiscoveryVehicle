#include <WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "Wokwi-GUEST";  
const char* password = "";  
WiFiClient  client;

unsigned long int hello5 = 5;
unsigned long int hello4 = 4;
unsigned long int hello3 = 3;
unsigned long int hello2 = 2;
unsigned long int hello1 = 1;

static const char * myWriteAPIKey1 = "J2UEIZSZTC5568NM";
static const char * myWriteAPIKey2 = "ZVZ3UYIV4PTYA6XP";
static const char * myWriteAPIKey3 = "0HSEW6FQ65NWH2EP";
static const char * myWriteAPIKey4 = "JCBZHB1KUX0Y09LX";
static const char * myWriteAPIKey5 = "QP8J57RU9BY9NAVE";

unsigned long lastTime = 0;
unsigned long timerDelay = 14500;

const long int number15 = 40032287;
const long int number16 = 35220634;
int x, Average, MaxAngle;

void setup() {
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.begin(115200);
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  
  ThingSpeak.begin(client);  
  x = 10;
}

void loop() {
int number1 = random(x,101);
int number2 = random(x,101);
int number3 = random(x,101);
int number4 = random(x,101);
int number5 = random(x,101);
int number6 = random(x,101);
int number7 = random(x,101);
int number8 = random(1,14);
int number9 = random(x,101);
int number10 = random(x,101);
int number11 = random(x,101);
int number12 = random(x,101);
int number13 = random(x,101);
int number14 = random(x,101);
x = x + 5;
if(x == 100)(x = 10);
int Angle0 = random(0,8001);
int Angle30 = random(0,8001);
int Angle60 = random(0,8001);
int Angle90 = random(0,8001);
int Angle120 = random(0,8001);
int Angle150 = random(0,8001);
int Angle180 = random(0,8001);

Average = (Angle0 + Angle30 + Angle60 + Angle90 + Angle120 + Angle150 + Angle180)/3.5;
int angles[] = {Angle0, Angle30, Angle60, Angle90, Angle120, Angle150, Angle180};
for (int i = 0; i < 7; i++) {if (angles[i] > maxAngle) (maxAngle = angles[i]);}
if (Average < maxAngle)(Average = maxAngle);

int Temp0 = random(-10,61);
int Temp30 = random(-10,61);
int Temp60 = random(-10,61);
int Temp90 = random(-10,61);
int Temp120 = random(-10,61);
int Temp150 = random(-10,61);
int Temp180 = random(-10,61);

int Green0 = random(0,256);
int Green30 = random(0,256);
int Green60 = random(0,256);
int Green90 = random(0,256);
int Green120 = random(0,256);
int Green150 = random(0,256);
int Green180 = random(0,256);

  if ((millis() - lastTime) > timerDelay) {
    Serial.println("döngü basladi");
    ThingSpeak.setField(1, number1);
    ThingSpeak.setField(2, number2);
    ThingSpeak.setField(3, number3);
    ThingSpeak.setField(4, number4);
    ThingSpeak.setField(5, number5);
    ThingSpeak.setField(6, number6);
    ThingSpeak.setField(7, number7);
    ThingSpeak.setField(8, number8);
  int a = ThingSpeak.writeFields(hello1, myWriteAPIKey1);
    ThingSpeak.setField(1, number9);
    ThingSpeak.setField(2, number10);
    ThingSpeak.setField(3, number11);
    ThingSpeak.setField(4, number12);
    ThingSpeak.setField(5, number13);
    ThingSpeak.setField(6, number14);
    ThingSpeak.setField(7, number15);
    ThingSpeak.setField(8, number16);
  int b = ThingSpeak.writeFields(hello2, myWriteAPIKey2);
    ThingSpeak.setField(1, Green0);
    ThingSpeak.setField(2, Green30);
    ThingSpeak.setField(3, Green60);
    ThingSpeak.setField(4, Green90);
    ThingSpeak.setField(5, Green120);
    ThingSpeak.setField(6, Green150);
    ThingSpeak.setField(7, Green180);
  int c = ThingSpeak.writeFields(hello3, myWriteAPIKey3);
    ThingSpeak.setField(1, Angle0);
    ThingSpeak.setField(2, Angle30);
    ThingSpeak.setField(3, Angle60);
    ThingSpeak.setField(4, Angle90);
    ThingSpeak.setField(5, Angle120);
    ThingSpeak.setField(6, Angle150);
    ThingSpeak.setField(7, Angle180);
    ThingSpeak.setField(8, Average);
  int d = ThingSpeak.writeFields(hello4, myWriteAPIKey4);
    ThingSpeak.setField(1, Temp0);
    ThingSpeak.setField(2, Temp30);
    ThingSpeak.setField(3, Temp60);
    ThingSpeak.setField(4, Temp90);
    ThingSpeak.setField(5, Temp120);
    ThingSpeak.setField(6, Temp150);
    ThingSpeak.setField(7, Temp180);
  int e = ThingSpeak.writeFields(hello5, myWriteAPIKey5);
     Serial.println("döngü biti");
    lastTime = millis();
  }
}
