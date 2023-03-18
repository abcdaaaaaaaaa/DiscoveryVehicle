#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <MQUnifiedsensor.h>
#include <HTTPClient.h>

IPAddress local_IP(192,168,1,1); 

#define         Board                    ("ESP-32")
#define         Pin2                      analogRead(A2)  
#define         Pin3                      analogRead(A3)  
#define         Pin4                      analogRead(A4)  
#define         Pin135                    analogRead(A5)  
#define         RatioMQ2CleanAir          (9.83)
#define         RatioMQ3CleanAir          (60) //RS / R0 = 60 ppm 
#define         RatioMQ4CleanAir          (4.4) //RS / R0 = 4.4 ppm 
#define         RatioMQ135CleanAir        (3.6) //RS / R0 = 3.6 ppm 
#define         ADC_Bit_Resolution        (13) // 10 bit ADC 
#define         Voltage_Resolution        (3.3) // Volt resolution to calc the voltage
#define         Type                      ("ESP-32") //Board used
//Declare Sensor
MQUnifiedsensor MQ2(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin2, Type);
MQUnifiedsensor MQ3(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin3, Type);
MQUnifiedsensor MQ4(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin4, Type);
MQUnifiedsensor MQ135(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin135, Type);

// Set your access point network credentials
const char* ssid = "***";
const char* password = "***";

WiFiServer server2(80);
String header;

unsigned long counts; //variable for GM Tube events
unsigned long previousMillis; //variable for measuring time
float averageCPM;
float sdCPM;
int currentCPM;
float calcCPM;
float CPMArray[100];
#define LOG_PERIOD 30000

AsyncWebServer server(85);
void setup(){
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
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.println();
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  Serial.print(WiFi.localIP());
  Serial.println("' to connect");

  server.on("/averagecpm", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(averageCPM).c_str());
  });
  server.on("/sdcpm", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(sdCPM).c_str());
  });
  server.on("/cpmarray", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(CPMArray[currentCPM]).c_str());
  });
  // Start server
  server.begin();
  server2.begin();
}
 
void loop(){
  
radyoactivite();
  ///*
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
  WiFiClient client = server2.available();                                 

  if(client)                                                              
  {                                                   
    String currentLine = "";                                              
    while(client.connected()) 
    {                      
      if(client.available())                                              
      {                       
        char c = client.read();                                           
        Serial.write(c);                                                  
        if (c == '\n')                                                    
        {                                                                 
          if(currentLine.length() == 0)                                   
          {     
             
client.println("HTTP/1.1 200 OK");
client.println("Content-type:text/html");
client.println("Connection: close");
client.println();
client.println("<!DOCTYPE html><html>");
client.println("<html><head>");
client.println("<meta charset='utf-8'>");
client.println("<meta name='viewport' content='width=device-width,initial-scale=1'>");
client.println("<link rel=\"icon\" href=\"data:,\">");
client.println("<title>Chernobyl</title>");
client.println("<style>");
client.println("body {");
client.println(" font-family: Arial,Helvetica,sans-serif;");
client.println("background: #000e44;");
client.println("color: #FFFFFF;");
client.println("font-size: 20px;");
client.println("font-weight: bold;");
client.println("</style>");
client.println("</head>");
client.println("<body>"); 
client.println("<h1></h1><table><tbody><tr><th></th><th></th></tr>");
client.println("<tr><td> <font color='orange'>Alcohol:</font></td><td><span class=\"sensor\">");
client.println(Alcohol);
client.println("<tr><td><font color='orange'>Benzene:</td><td><span class=\"sensor\">");
client.println(Benzene);
client.println("<tr><td><font color='orange'>Hexane:</td><td><span class=\"sensor\">");
client.println(Hexane);
client.println("<tr><td><font color='magenta'>CH4:</td><td><span class=\"sensor\">");
client.println(CH4);
client.println("<tr><td><font color='magenta'>Smoke:</td><td><span class=\"sensor\">");
client.println(smoke);
client.println("<tr><td><font color='cyan'>CO2:</td><td><span class=\"sensor\">");
client.println(CO2);
client.println("<tr><td><font color='cyan'>Toluen:</td><td><span class=\"sensor\">");
client.println(Toluen);
client.println("<tr><td><font color='cyan'>NH4:</td><td><span class=\"sensor\">");
client.println(NH4);
client.println("<tr><td><font color='cyan'>Aceton:</td><td><span class=\"sensor\">");
client.println(Aceton);
client.println("<tr><td><font color='red'>LPG:</td><td><span class=\"sensor\">");
client.println(LPG);
client.println("<tr><td><font color='red'>Propane:</td><td><span class=\"sensor\">");
client.println(Propane);
client.println("<tr><td><font color='aquamarine'>CO:</td><td><span class=\"sensor\">");
client.println(CO);
client.println("<tr><td><font color='aquamarine'>H2:</td><td><span class=\"sensor\">");
client.println(H2);
client.println("<tr><td><font color='blue'>Air Quality:</td><td><span class=\"sensor\">");
client.println(Pin135);
client.println("<tr><td><font color='yellow'>Radioactivite:</td><td><span class=\"sensor\">");
client.println("Avg: " + String(averageCPM) + " +/- " + String(sdCPM));
client.println("ArrayVal: " + String(CPMArray[currentCPM]));
client.println("</body></html>");
break;
          }
          }
      }
    }
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

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your Domain name with URL path or IP address with path
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "--"; 
  
  if (httpResponseCode>0) {

    payload = http.getString();
  }
  // Free resources
  http.end();

  return payload;
}
