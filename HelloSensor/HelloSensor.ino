// ESP32 Wrover Module
// Partition Scheme: "Huge APP (3MB No OTA/1MB SPIFFS)"

#include <WiFi.h>
#include <DHT.h>
#include <HTTPClient.h>
#include <NetworkClientSecure.h>
#include <TM1637.h>
#include "HelloSensor.h"
#include <Deneyap_GPSveGLONASSkonumBelirleyici.h>

#define ADC_BIT_RESU (12)
#define GeigerPin  (39)
#define analogPin  (35)
#define gasPin     (34)
#define dhtPin     (33)
#define potPin     (32)
#define CLK        (18)
#define DIO        (5)

GPS GPS;
TM1637 tm(CLK,DIO);
DHT dht(dhtPin, DHT22);

GeigerCounter Radioactive(GeigerPin);

const char* ssid = "REPLACE_WITH_YOUR_SSID";  
const char* password = "REPLACE_WITH_YOUR_PASSWORD";
const char* serverName = "https://air.uzay.info/datareceiver.php";
const char* serverName2 = "https://data.uzay.info/datareceiver.php";

int sec;

static const char * myWriteAPIKey1 = "J2UEIZSZTC5568NM";
static const char * myWriteAPIKey2 = "ZVZ3UYIV4PTYA6XP";

unsigned long int lastTime1 = 0;
unsigned long int timerDelay1 = 15000;

unsigned long int lastTime2 = 0;
unsigned long int timerDelay2 = 30000;

void setup() {
  Serial.begin(115200);
  tm.init();
  tm.set(BRIGHT_TYPICAL);
  tm.display(0, 1);
  tm.display(1, 2);
  tm.display(2, 3);
  tm.display(3, 4);
  dht.begin();
  pinMode(potPin, INPUT);
  pinMode(gasPin, INPUT);
  pinMode(analogPin, INPUT);
  Radioactive.begin();
  if (!GPS.begin(0x2F)) {
      delay(3000);
      Serial.println("I2C connection failed.");
      // while (1);
  }
  WiFi.mode(WIFI_STA); Serial.println("Connecting to WiFi ");
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  sec = map(analogRead(potPin), 0, (1 << ADC_BIT_RESU) - 1, 1, 21);

  switch(sec){
  case (1):
  {
  tm.display(3,5);
  tm.display(2,3);
  tm.display(1,1);
  tm.display(0,0);
  }
  break;
  case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: normal();
  break;
  case (10):
  {
  tm.display(3,1);
  tm.display(2,3);
  tm.display(1,1);
  tm.display(0,1);
  }
  break;
  case (11):
  {
  tm.display(3,1);
  tm.display(2,3);
  tm.display(1,1);
  tm.display(0,0);
  }
  break;
  case (12):
  {
  tm.display(3,6);
  tm.display(2,3);
  tm.display(1,1);
  tm.display(0,0);
  }
  break;
  case (13):
  {
  tm.display(3,7);
  tm.display(2,3);
  tm.display(1,1);
  tm.display(0,0);
  }
  break;
  case (14):
  {
  tm.display(3,8);
  tm.display(2,3);
  tm.display(1,1);
  tm.display(0,0);
  }
  break;
  case (15):
  {
  tm.display(3,4);
  tm.display(2,1);
  tm.display(1,2);
  tm.display(0,0);
  }
  break;
  case (16):
  {
  tm.display(3,6);
  tm.display(2,1);
  tm.display(1,2);
  tm.display(0,0);
  }
  break;
  case (17):
  {
  tm.display(3,10);
  tm.display(2,3);
  tm.display(1,0);
  tm.display(0,3);
  }
  break;
  case (18):
  {
  tm.display(3,11);
  tm.display(2,3);
  tm.display(1,0);
  tm.display(0,3);
  }
  break;
  case (19):
  {
  tm.display(3,10);
  tm.display(2,6);
  tm.display(1,0);
  tm.display(0,3);
  }
  case (20):
  {
  tm.display(3,10);
  tm.display(2,7);
  tm.display(1,0);
  tm.display(0,3);
  }
  case (21):
  {
  tm.display(3,10);
  tm.display(2,9);
  tm.display(1,0);
  tm.display(0,3);
  }
  break;
  }

  Radioactive.radioactive();

  if ((millis() - lastTime1) > timerDelay1) {
    GPS.readGPS(RMC);
    long lat = (long)((GPS.readLocationLat() + 90.0) * 10000000);
    long lng = (long)((GPS.readLocationLng() + 180.0) * 10000000);

    String httpRequestData = "api_key=" + String(myWriteAPIKey1) + 
                             "&field1=" + String(sec) + 
                             "&field2=" + String(analogRead(analogPin)) + 
                             "&field3=" + String((dht.readTemperature() + 140) * 10) + 
                             "&field4=" + String((dht.readHumidity() + 100) * 10) + 
                             "&field5=" + String(analogRead(gasPin)) + 
                             "&field6=" + String(lat) + 
                             "&field7=" + String(lng);

    NetworkClientSecure *client = new NetworkClientSecure;
    if(client) {
        client->setInsecure();
        HTTPClient http;
        if (http.begin(*client, serverName)) {
            http.addHeader("Content-Type", "application/x-www-form-urlencoded");
            int httpResponseCode = http.POST(httpRequestData);
            http.end();
        }
        delete client;
    }
    lastTime1 = millis();
  }

  if ((millis() - lastTime2) > timerDelay2) {
    String httpRequestData = "api_key=" + String(myWriteAPIKey2) + 
                             "&field1=" + String(int(Radioactive.usvhr * pow(10, 4))) + 
                             "&field2=" + String(int(Radioactive.Avg * pow(10, 4))) + 
                             "&field3=" + String(int(Radioactive.sdCPM * pow(10, 4))) + 
                             "&field4=" + String(Radioactive.count);

    NetworkClientSecure *client = new NetworkClientSecure;
    if(client) {
        client->setInsecure();
        HTTPClient http;
        if (http.begin(*client, serverName2)) {
            http.addHeader("Content-Type", "application/x-www-form-urlencoded");
            int httpResponseCode = http.POST(httpRequestData);
            http.end();
        }
        delete client;
    }
    lastTime2 = millis();
  }
}

void normal(){
tm.display(3,sec);
tm.display(2,sec);
tm.display(1,sec);
tm.display(0,sec);
}

// MQ-X: [PIN --> D35 (main-esp32), D35 (motor-control esp32)] [GND --> GND (main-esp32), GND (motor-control esp32)] [VCC --> 3.3V (main-esp32)]
// Other Sensor: [PIN --> D34 (main-esp32), D34 (motor-control esp32)] [GND --> GND (main-esp32), GND (motor-control esp32)] [VCC --> 3.3V (main-esp32)]
// Potentiometer: [PIN --> D32] [GND --> GND] [VCC --> 3.3V]

// DHT22: [GND --> GND] [PIN --> D33] [VCC --> 3.3V]
// GPS: [GND --> GND] [SCL --> D22] [SDA --> D21] [VCC --> 3.3V]
// TM1637: [CLK --> D18] [DIO --> D5] [VCC --> 3.3V] [GND --> GND]
// Geiger Counter: [PIN --> D39] [GND --> GND] [VCC --> 5V]
