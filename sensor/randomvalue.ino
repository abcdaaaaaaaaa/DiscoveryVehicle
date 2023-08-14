#include <WiFi.h>
#include "ThingSpeak.h"
#include "TM1637.h"


#define CLK 2
#define DIO 4
TM1637 tm1637(CLK,DIO);


const char* ssid = "Wokwi-GUEST";  
const char* password = "";  
WiFiClient  client;

unsigned long hello2 = 2;
unsigned long hello1 = 1;

const char * myWriteAPIKey1 = "J2UEIZSZTC5568NM";
const char * myWriteAPIKey2 = "ZVZ3UYIV4PTYA6XP";

unsigned long lastTime = 0;
unsigned long timerDelay = 15000;

const long int number15 = 40032287;
const long int number16 = 35220634;
int x, sec;

void setup() {
tm1637.init();
tm1637.set(BRIGHT_TYPICAL);

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
sec = map(analogRead(27),0,4095,1,13);

int number1 = random(x,101);
int number2 = random(x,101);
int number3 = random(x,101);
int number4 = random(x,101);
int number5 = random(x,101);
int number6 = random(x,101);
int number7 = random(x,101);
int number8 = sec;
int number9 = random(x,101);
int number10 = random(x,101);
int number11 = random(x,101);
int number12 = random(x,101);
int number13 = random(x,101);
int number14 = random(x,101);
x = x + 5;
if(x == 100)(x = 10);
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
     Serial.println("döngü biti");
    lastTime = millis();
  }
switch(sec){
case (1):
{
tm1637.display(3,5);
tm1637.display(2,3);
tm1637.display(1,1);
tm1637.display(0,0);
}
break;
case (2):
{
normal();
}
break;
case (3):
{
normal();
}
break;
case (4):
{
normal();
}
break;
case (5):
{
normal();
}
break;
case (6):
{
normal();
}
break;
case (7):
{
normal();
}
break;
case (8):
{
normal();
}
break;
case (9):
{
normal();
}
break;
case (10):
{
tm1637.display(3,1);
tm1637.display(2,3);
tm1637.display(1,1);
tm1637.display(0,0);
}
break;
case (11):
{
tm1637.display(3,6);
tm1637.display(2,3);
tm1637.display(1,1);
tm1637.display(0,0);
}
break;
case (12):
{
tm1637.display(3,10);
tm1637.display(2,3);
tm1637.display(1,0);
tm1637.display(0,3);
}
break;
case (13):
{
tm1637.display(3,10);
tm1637.display(2,9);
tm1637.display(1,0);
tm1637.display(0,3);
}
break;
default:
{
tm1637.display(3,5);
tm1637.display(2,3);
tm1637.display(1,1);
tm1637.display(0,0);  
}
break;
}

}

void normal(){
tm1637.display(3,sec);
tm1637.display(2,sec);
tm1637.display(1,sec);
tm1637.display(0,sec);
}
