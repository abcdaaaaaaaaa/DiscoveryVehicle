#include "WiFi.h"
#include "ESPAsyncWebSrv.h"
#include <HTTPClient.h>
#include <Deneyap_Servo.h>
#include <TFMPlus.h> 

Servo myservo;  
const char* serverNameservoplay = "http://192.168.1.1/servo";
const char* serverNamexxx = "http://192.168.1.1/xxx";
String servoplay, result, kontrol;
int left, right, minileft, miniright;

#define sagled  D3
#define solled  D4
#define onled   D5

int specialsensor = analogRead(A2);

const char* ssid = "Chernobyl";
const char* password = NULL;

IPAddress local_IP(192, 168, 1, 3);
IPAddress gateway(255, 255, 0, 0);
IPAddress subnet(255, 255, 0, 0);

TFMPlus tfmP;
int16_t tfDist = 0;    // Distance to object in centimeters
int16_t tfFlux = 0;    // Strength or quality of return signal
int16_t tfTemp = 0;    // Internal temperature of Lidar sensor chip

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.config(local_IP, gateway, subnet);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 Serial.println(WiFi.localIP());
  delay(20);              
myservo.attach(D2);  
myservo.write(90);
  delay(2000);
     server.on("/data", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(specialsensor).c_str());
  });
tfmP.getData( tfDist, tfFlux, tfTemp);
  if( tfmP.getData( tfDist, tfFlux, tfTemp)) // Get data from the device.
  {
    server.on("/dist", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(tfDist).c_str());
  });
    server.on("/stg", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(tfFlux).c_str());
  });
    server.on("/temp", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(tfTemp).c_str());
  });
    server.on("/lih", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(result).c_str());
  });
  }
  else                 
  {
    tfmP.printFrame();  
        server.on("/dist", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(tfDist).c_str());
  });
    server.on("/stg", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(tfFlux).c_str());
  });
    server.on("/temp", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(tfTemp).c_str());
  });
    server.on("/lih", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(result).c_str());
  });
  }
  server.begin();
}

void loop() {
digitalWrite(solled,LOW);
digitalWrite(sagled,LOW);
digitalWrite(onled,LOW);
delay(5);  
servodon();
}

void servodon(){
servoplay = httpGETRequest(serverNameservoplay);
if (servoplay == "L1"){
delay(20); 
myservo.write(0);   
}
else if (servoplay == "L2"){
delay(20); 
myservo.write(30);   
}
else if (servoplay == "L3"){
delay(20); 
myservo.write(60);   
}
else if (servoplay == "AA"){
delay(20); 
myservo.write(90);  
}
else if (servoplay == "R3"){
delay(20); 
myservo.write(120);  
}
else if (servoplay == "R2"){
delay(20); 
myservo.write(150);   
}
else if (servoplay == "R1"){
delay(20); 
myservo.write(180);   
}
else if (servoplay == "OT"){
for(int i=10;i<=170;i=i+5){  
myservo.write(i);    
   }
   }
else if (servoplay == "MV"){
myservo.write(90); 
tfmP.getData( tfDist, tfFlux, tfTemp);
while (tfDist > 30 && WiFi.status()== WL_CONNECTED && servoplay == "MV") {
 result = "L2";
  }
result = "L1";
tfmP.getData( tfDist, tfFlux, tfTemp);
delay(300);
myservo.write(0);
left = tfDist;
myservo.write(45);
minileft = tfDist;
myservo.write(135);
miniright = tfDist;
myservo.write(180);
right = tfDist;
tfmP.getData( tfDist, tfFlux, tfTemp);
if (left && minileft && miniright && right < 30){
// 2 kere geri git
result = "L3";
delay(10);
result = "L3";
delay(10);
result = "L1";
}
else if(left >= minileft && miniright && right){
//sola dön
result = "L4";
delay(10);
result = "L1";
}
else if(right >= minileft && miniright && left){
//sağa dön
result = "L5";
delay(10);
result = "L1";
}
else if(miniright >= minileft && right && left){
//hafif sağa dön
result = "L55";
delay(10);
result = "L1";
}
else if(minileft >= miniright && right && left){
//hafif sola dön  
result = "L45";
delay(10);
result = "L1";
}
else {
result = "L1";
delay(20); 
myservo.write(90);  
}
delay(10);
}
}
void ledyak(){
kontrol = httpGETRequest(serverNamexxx);
    if(WiFi.status()== WL_CONNECTED ){ 
if (kontrol == "1"){
    Serial.println("ledyakma");
    digitalWrite(solled,LOW);
    digitalWrite(sagled,LOW);
    digitalWrite(onled,LOW);
    }
if (kontrol == "2"){
    Serial.println("onledyak");  
    digitalWrite(onled,HIGH);
    digitalWrite(solled,LOW);
    digitalWrite(sagled,LOW);
    }
if (kontrol == "3"){
    Serial.println("arkaledyak");  
    digitalWrite(onled,LOW);
    digitalWrite(solled,HIGH);
    digitalWrite(sagled,HIGH);
    }
if (kontrol == "4"){
    Serial.println("Solledyak");  
    digitalWrite(onled,LOW);
    digitalWrite(solled,HIGH);
    digitalWrite(sagled,LOW);
    }
if (kontrol == "5"){
    Serial.println("Sağledyak");  
    digitalWrite(onled,LOW);
    digitalWrite(solled,LOW);
    digitalWrite(sagled,HIGH);
    }
}       
else {
    Serial.println("ledyakma");
    digitalWrite(onled,LOW);
    digitalWrite(solled,LOW);
    digitalWrite(sagled,LOW);
    }
 delay(1); 
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
