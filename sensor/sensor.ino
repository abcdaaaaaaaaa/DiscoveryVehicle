#include "WiFi.h"
#include "ThingSpeak.h"
#include <MQUnifiedsensor.h>
#include <TinyGPS++.h>


#define         Board                    ("ESP-32")
#define         Pin2                      analogRead(A2)  
#define         Pin3                      analogRead(A3)  
#define         Pin4                      analogRead(A4)  
#define         Pin135                    analogRead(A5)  
#define         SpaceData                 analogRead(A1)
#define         SpaceData2                analogRead(A0)
#define         rxPin                     digitalRead(D0)
#define         txPin                     digitalRead(D1)

#define         RatioMQ2CleanAir          (9.83)
#define         RatioMQ3CleanAir          (60) //RS / R0 = 60 ppm 
#define         RatioMQ4CleanAir          (4.4) //RS / R0 = 4.4 ppm 
#define         RatioMQ135CleanAir        (3.6) //RS / R0 = 3.6 ppm 
#define         ADC_Bit_Resolution        (13) // 10 bit ADC 
#define         Voltage_Resolution        (3.3) // Volt resolution to calc the voltage
#define         Type                      ("ESP-32") //Board used

MQUnifiedsensor MQ2(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin2, Type);
MQUnifiedsensor MQ3(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin3, Type);
MQUnifiedsensor MQ4(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin4, Type);
MQUnifiedsensor MQ135(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin135, Type);

unsigned long counts, previousMillis; 
float averageCPM, sdCPM, calcCPM, CPMArray[100];
String latitude, longitude;
int currentCPM, MQ2A, MQ3A, MQ4A, MQ135A, Data1, Data2;

#define LOG_PERIOD 30000
HardwareSerial neogps(1);
TinyGPSPlus gps;

const char* ssid = "REPLACE_WITH_YOUR_SSID";  
const char* password = "REPLACE_WITH_YOUR_PASSWORD";  
WiFiClient  client;

unsigned long hello3 = 3;
unsigned long hello2 = 2;
unsigned long hello1 = 1;

const char * myWriteAPIKey1 = "J2UEIZSZTC5568NM";
const char * myWriteAPIKey2 = "ZVZ3UYIV4PTYA6XP";
const char * myWriteAPIKey3 = "0HSEW6FQ65NWH2EP";

unsigned long lastTime = 0;
unsigned long timerDelay = 15000;

void setup() {
  MQ2.init();
  MQ2.setRegressionMethod(1);
  MQ2.setR0(1.82);
  MQ3.init();
  MQ3.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ3.setR0(0.45);
  MQ4.init();
  MQ4.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ4.setR0(14.23);
  MQ135.init();
  MQ135.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ135.setR0(9.03); 
  counts = 0;
  currentCPM = 0;
  averageCPM = 0;
  sdCPM = 0;
  calcCPM = 0;
  pinMode(D8, INPUT);
  attachInterrupt(digitalPinToInterrupt(D8), impulse, FALLING);  
  Serial.begin(115200);  
  WiFi.mode(WIFI_STA);  Serial.println("Connecting to WiFi ");
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

 radyoactivite();

  MQ2.update();
  MQ3.update();
  MQ4.update();
  MQ135.update(); 

  
  MQ2.setA(574.25); MQ2.setB(-2.222);  // LPG
  float LPG = MQ2.readSensor(); 
  
  MQ2.setA( 987.99); MQ2.setB(-2.162); // H2
  float H2 = MQ135.readSensor(); 
  
  MQ2.setA(658.71); MQ2.setB(-2.168); //Propane
  float Propane = MQ2.readSensor(); 
  
  MQ3.setA(0.3934); MQ3.setB(-1.504); //Alcohol
  float Alcohol = MQ3.readSensor(); 

  MQ3.setA(4.8387); MQ3.setB(-2.68); //Benzene
  float Benzene = MQ3.readSensor(); 
  
  MQ3.setA(7585.3); MQ3.setB(-2.849); //Hexane
  float Hexane = MQ3.readSensor(); 

  MQ4.setA(1012.7); MQ4.setB(-2.786); //CH4
  float CH4 = MQ4.readSensor(); 

  MQ4.setA(30000000); MQ4.setB(-8.308); //smoke 
  float smoke = MQ4.readSensor(); 

  MQ135.setA(605.18); MQ135.setB(-3.937); //CO
  float CO = MQ135.readSensor(); 
  
  MQ135.setA(110.47); MQ135.setB(-2.862); //CO2
  float CO2 = MQ135.readSensor(); 

  MQ135.setA(44.947); MQ135.setB(-3.445); //Toulen
  float Toluen = MQ135.readSensor(); 
  
  MQ135.setA(102.2 ); MQ135.setB(-2.473); //NH4
  float NH4 = MQ135.readSensor(); 

  MQ135.setA(34.668); MQ135.setB(-3.369); // Aceton
  float Aceton = MQ135.readSensor(); 

if (Pin2 == 0){
   MQ2A = 0;  
}
else{
   MQ2A = map(Pin2,0,8191,300,10000);
}
if (Pin3 == 0){
   MQ3A = 0;  
}
else{  
   MQ3A = map(Pin3,0,8191,25,500);
}
if (Pin4 == 0){
   MQ4A = 0;   
}
else{
   MQ4A = map(Pin4,0,8191,300,10000);
}
if (Pin135 == 0){
   MQ135A = 0;   
} 
else{
   MQ135A = map(Pin135,0,8191,10,1000);
}
   Data1 = map(SpaceData,0,8191,0,100);
   Data2 = map(SpaceData2,0,8191,0,100);


  if ((millis() - lastTime) > timerDelay) {

    ThingSpeak.setField(1, Alcohol);
    ThingSpeak.setField(2, Benzene);
    ThingSpeak.setField(3, Hexane);
    ThingSpeak.setField(4, CH4);
    ThingSpeak.setField(5, smoke);
    ThingSpeak.setField(6, CO2);
    ThingSpeak.setField(7, Toluen);
    ThingSpeak.setField(8, NH4);
  int a = ThingSpeak.writeFields(hello1, myWriteAPIKey1);
    ThingSpeak.setField(1, Aceton);
    ThingSpeak.setField(2, LPG);
    ThingSpeak.setField(3, Propane);
    ThingSpeak.setField(4, CO);
    ThingSpeak.setField(5, H2);
    ThingSpeak.setField(6, MQ135A);
    ThingSpeak.setField(7, Data1);
    ThingSpeak.setField(8, Data2);
  int b = ThingSpeak.writeFields(hello2, myWriteAPIKey2);
    ThingSpeak.setField(1, averageCPM);
    ThingSpeak.setField(2, sdCPM);
    ThingSpeak.setField(3, CPMArray[currentCPM]);
    ThingSpeak.setField(4, latitude);
    ThingSpeak.setField(5, longitude);
    ThingSpeak.setField(6, MQ2A);    
    ThingSpeak.setField(7, MQ3A);    
    ThingSpeak.setField(8, MQ4A);    
  int c = ThingSpeak.writeFields(hello3, myWriteAPIKey3);
 
    lastTime = millis();
  }
}
void impulse() {
  counts++;
}

float outputSieverts(float x)  {
  float y = x * 0.0057;
  return y;
}
    
void radyoactivite(){  
unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > LOG_PERIOD) {
    previousMillis = currentMillis;
    CPMArray[currentCPM] = counts * 2;

    counts = 0;
    averageCPM = 0;
    sdCPM = 0;
    //calc avg and sd
    for (int x=0;x<currentCPM+1;x++)  {
      averageCPM = averageCPM + CPMArray[x];
    }
    averageCPM = averageCPM / (currentCPM + 1);
    for (int x=0;x<currentCPM+1;x++)  {
      sdCPM = sdCPM + sq(CPMArray[x] - averageCPM);
    }
    sdCPM = sqrt(sdCPM / currentCPM) / sqrt(currentCPM+1);

    //Serial.println("Avg: " + String(averageCPM) + " +/- " + String(sdCPM) + "  ArrayVal: " + String(CPMArray[currentCPM]));
    currentCPM = currentCPM + 1;
  }
}

int sendGpsToServer()
{
  boolean newData = false;
  for (unsigned long start = millis(); millis() - start < 2000;){
    while(neogps.available()){
      if(gps.encode(neogps.read())){
        if(gps.location.isValid() == 1){
          newData = true;
          break;
        }
      }
    }
  }

  if(true){
    newData = false;
     
    latitude = String(gps.location.lat(), 6); 
    longitude = String(gps.location.lng(), 6); 

  }
   
}
