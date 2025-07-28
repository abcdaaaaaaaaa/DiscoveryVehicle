// DiscoveryVechile Sensor Simulation: https://wokwi.com/projects/437363944717980673

#include <WiFi.h>
#include <DHT.h>
#include <TinyGPS++.h>
#include <ThingSpeak.h>
#include <TM1637.h>
#include <Radioactive.h>

#define GeigerPin  (39)
#define analogPin  (35)
#define gasPin     (34)
#define dhtPin     (33)
#define potPin     (32)
#define CLK        (18)
#define DIO        (5)

TM1637 tm(CLK,DIO);

HardwareSerial neogps(2); 
TinyGPSPlus gps;

DHT dht(dhtPin, DHT22);

#define uSvhr1      (true)
#define Avg1        (true)
#define CPM_Count1  (true)
#define sdCPM1      (true)
#define LOG_PERIOD1 (30000)

GeigerCounter Radioactive(uSvhr1, Avg1, CPM_Count1, sdCPM1, LOG_PERIOD1, GeigerPin);

int sec;
String latitude, longitude;

const char* ssid = "Wokwi-GUEST";  
const char* password = ""; 
WiFiClient  client;

unsigned long int hello1 = 1;
static const char * myWriteAPIKey1 = "J2UEIZSZTC5568NM";

unsigned long int hello2 = 2;
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
  sec = map(analogRead(potPin), 0, (1 << 12) - 1, 1, 19);

  switch(sec){
  case (1):
  {
  tm.display(3,5);
  tm.display(2,3);
  tm.display(1,1);
  tm.display(0,0);
  }
  break;
  case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: normal(); break;
  case (10):
  {
  tm.display(3,1);
  tm.display(2,3);
  tm.display(1,1);
  tm.display(0,0);
  }
  break;
  case (11):
  {
  tm.display(3,1);
  tm.display(2,3);
  tm.display(1,1);
  tm.display(0,1);
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
  tm.display(3,10);
  tm.display(2,3);
  tm.display(1,0);
  tm.display(0,3);
  }
  break;
  case (17):
  {
  tm.display(3,11);
  tm.display(2,3);
  tm.display(1,0);
  tm.display(0,3);
  }
  break;
  case (18):
  {
  tm.display(3,10);
  tm.display(2,7);
  tm.display(1,0);
  tm.display(0,3);
  }
  break;
  case (19):
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
    ThingSpeak.setField(1, sec);
    ThingSpeak.setField(2, analogRead(analogPin));
    ThingSpeak.setField(3, (dht.readTemperature() + 140) * 10);
    ThingSpeak.setField(4, (dht.readHumidity() + 100) * 10);
    ThingSpeak.setField(5, analogRead(gasPin));

    latitude  = String((random(-90, 90) + (random(0, pow(10, 6) + 1) / pow(10, 7)) + 90) * pow(10,6)); 
    longitude = String((random(-180, 180) + (random(0, pow(10, 6) + 1) / pow(10, 7)) + 180) * pow(10,6)); 
    if (neogps.available()) {
      char c = neogps.read();
      if (gps.encode(c)) {
        if (gps.location.isValid()) {
         latitude  = String((gps.location.lat() + 90) * pow(10, 7)); 
         longitude = String((gps.location.lng() + 180) * pow(10, 7)); 
        }
      }
    }
    ThingSpeak.setField(6, latitude);
    ThingSpeak.setField(7, longitude);
    int a = ThingSpeak.writeFields(hello1, myWriteAPIKey1);

    lastTime1 = millis();
  }

  if ((millis() - lastTime2) > timerDelay2) {
    ThingSpeak.setField(1, int(Radioactive.usvhr * pow(10, 4)));
    ThingSpeak.setField(2, int(Radioactive.Avg * pow(10, 4)));
    ThingSpeak.setField(3, int(Radioactive.sdCPM * pow(10, 4)));
    ThingSpeak.setField(4, Radioactive.count);
    int b = ThingSpeak.writeFields(hello2, myWriteAPIKey2);

    lastTime2 = millis();
  }
}

void normal(){
tm.display(3,sec);
tm.display(2,sec);
tm.display(1,sec);
tm.display(0,sec);
}

// DHT22 : [GND --> GND] [PIN --> D33] [VCC --> 5V]
// GPS : [GND --> GND] [TX --> D3] [RX --> D1] [VCC --> 5V]
// MQ-X: [PIN --> D35] [GND --> GND] [VCC --> 3.3V]
// Other Sensor: [PIN --> D34] [GND --> GND] [VCC --> 3.3V]
// Potentiometer: [PIN --> D32] [GND --> GND] [VCC --> 3.3V]
// TM1637: [CLK --> D18] [DIO --> D5] [VCC --> 5V] [GND --> GND]
// Geiger Counter: [GND --> GND] [PIN --> VN]
