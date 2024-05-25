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
    Serial.begin("döngü başladı");
    ThingSpeak.setField(1, String(1000)+String(10));
    ThingSpeak.setField(2, String(2000)+String(20));
    ThingSpeak.setField(3, String(3000)+String(30));
    ThingSpeak.setField(4, String(4000)+String(40));
    ThingSpeak.setField(5, String(5000)+String(50));
    ThingSpeak.setField(6, String(6000)+String(60));
    ThingSpeak.setField(7, String(7000)+String(70));
    ThingSpeak.setField(8, String(8000)+String(80));
  int a = ThingSpeak.writeFields(hello1, myWriteAPIKey1);
    ThingSpeak.setField(1, String(7500)+String(90));
    ThingSpeak.setField(2, String(6500)+String(100));
    ThingSpeak.setField(3, String(5500)+String(110));
    ThingSpeak.setField(4, String(4500)+String(120));
    ThingSpeak.setField(5, String(3500)+String(130));
    ThingSpeak.setField(6, String(2500)+String(140));
    ThingSpeak.setField(7, String(1500)+String(150));
    ThingSpeak.setField(8, String(500)+String(160));
  int b = ThingSpeak.writeFields(hello2, myWriteAPIKey2);
    ThingSpeak.setField(1, String(250)+String(170));
    ThingSpeak.setField(2, String(1250)+String(180));
    ThingSpeak.setField(3, String(2250)+String(190));
    ThingSpeak.setField(4, String(2350)+String(200));
    ThingSpeak.setField(5, String(2450)+String(210));
    ThingSpeak.setField(6, String(2550)+String(220));
    ThingSpeak.setField(7, String(2650)+String(230));
    ThingSpeak.setField(8, String(240)+String(250)+String(55));
  int c = ThingSpeak.writeFields(hello3, myWriteAPIKey3);
    Serial.begin("döngü bitti");
}
}
