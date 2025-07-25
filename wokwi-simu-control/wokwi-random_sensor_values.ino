#include <WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "Wokwi-GUEST";  
const char* password = "";  
WiFiClient  client;

unsigned long int hello2 = 2;
unsigned long int hello1 = 1;

static const char * myWriteAPIKey1 = "J2UEIZSZTC5568NM";
static const char * myWriteAPIKey2 = "ZVZ3UYIV4PTYA6XP";

unsigned long lastTime = 0;
unsigned long timerDelay = 15000;

int x;

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
  x = 1;
}

void loop() {
int number1 = random(x,101);
int number2 = random(x,101);
int number3 = random(x,101);
int number4 = random(x,101);
int number5 = random(x,101);
int number6 = random(x,101);
int number7 = random(x,101);
int number8 = x;
int number9 = random(x,101);
int number10 = random(x,101);
int number11 = random(x,101);
int number12 = random(x,101);
int number13 = random(x,101);
int number14 = random(x,101);
  if ((millis() - lastTime) > timerDelay) {
    x = x + 1;
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
    ThingSpeak.setField(7, (random(-90, 90) + (random(0, pow(10, 7) + 1) / pow(10, 7)) + 90) * pow(10,7));
    ThingSpeak.setField(8, (random(-180, 180) + (random(0, pow(10, 7) + 1) / pow(10, 7)) + 180) * pow(10,7));
  int b = ThingSpeak.writeFields(hello2, myWriteAPIKey2);
     Serial.println("döngü biti");
    lastTime = millis();
    if(x == 21)(x = 1);
  }
}
