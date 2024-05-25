#include <WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "Wokwi-GUEST";  
const char* password = "";
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
  if ((millis() - lastTime) > timerDelay) { 
    Serial.println("döngü başladı");
    ThingSpeak.setField(1, String(1000 + 10000)+String(10 + 1000));
    ThingSpeak.setField(2, String(2000 + 10000)+String(20 + 1000));
    ThingSpeak.setField(3, String(3000 + 10000)+String(30 + 1000));
    ThingSpeak.setField(4, String(4000 + 10000)+String(40 + 1000));
    ThingSpeak.setField(5, String(5000 + 10000)+String(50 + 1000));
    ThingSpeak.setField(6, String(6000 + 10000)+String(60 + 1000));
    ThingSpeak.setField(7, String(7000 + 10000)+String(70 + 1000));
    ThingSpeak.setField(8, String(8000 + 10000)+String(80 + 1000));
  int a = ThingSpeak.writeFields(hello1, myWriteAPIKey1);
    ThingSpeak.setField(1, String(7500 + 10000)+String(90 + 1000));
    ThingSpeak.setField(2, String(6500 + 10000)+String(100 + 1000));
    ThingSpeak.setField(3, String(5500 + 10000)+String(110 + 1000));
    ThingSpeak.setField(4, String(4500 + 10000)+String(120 + 1000));
    ThingSpeak.setField(5, String(3500 + 10000)+String(130 + 1000));
    ThingSpeak.setField(6, String(2500 + 10000)+String(140 + 1000));
    ThingSpeak.setField(7, String(1500 + 10000)+String(150 + 1000));
    ThingSpeak.setField(8, String(500 + 10000)+String(160 + 1000));
  int b = ThingSpeak.writeFields(hello2, myWriteAPIKey2);
    ThingSpeak.setField(1, String(250 + 10000)+String(170 + 1000));
    ThingSpeak.setField(2, String(1250 + 10000)+String(180 + 1000));
    ThingSpeak.setField(3, String(2250 + 10000)+String(190 + 1000));
    ThingSpeak.setField(4, String(3250 + 10000)+String(200 + 1000));
    ThingSpeak.setField(5, String(4250 + 10000)+String(210 + 1000));
    ThingSpeak.setField(6, String(5250 + 10000)+String(220 + 1000));
    ThingSpeak.setField(7, String(6250 + 10000)+String(7250 + 10000));
    ThingSpeak.setField(8, String(230 + 1000)+String(240 + 1000)+String(55 + 20));
  int c = ThingSpeak.writeFields(hello3, myWriteAPIKey3);
    Serial.println("döngü bitti");
    lastTime = millis();
}
}
