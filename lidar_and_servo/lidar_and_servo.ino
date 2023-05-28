#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <HTTPClient.h>
#include <Deneyap_Servo.h>
#include <TFMPlus.h> 

Servo myservo;  
const char* serverNameservoplay = "http://192.168.1.1/servo";
const char* serverNamexxx = "http://192.168.1.1/xxx";
String servoplay, result, kontrol;
float left, right;

int sagled = D3;
int solled = D4;
int onled = D5;
int specialsensor = (A2)analogRead / 8;

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
    tfmP.printFrame();  // display the error and HEX dataa
  }
  server.begin();
}

void loop() {
digitalWrite(solled,LOW);
digitalWrite(sagled,LOW);
digitalWrite(onled,LOW);
delay(20);  
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
myservo.write(0);  
delay(5000);  
myservo.write(30); 
delay(5000); 
myservo.write(60);  
delay(5000);  
myservo.write(90); 
delay(5000);  
myservo.write(120);  
delay(5000);  
myservo.write(150); 
delay(5000);
myservo.write(180);  
delay(100);
myservo.write(90); 
}
else if (servoplay == "MV"){
myservo.write(90); 
tfmP.getData( tfDist, tfFlux, tfTemp);
while (tfDist > 30) {
 result = "L2";
  }
result = "L1";
delay(300);
myservo.write(0);
tfmP.getData( tfDist, tfFlux, tfTemp);
left = tfDist;
delay(300);
myservo.write(180);
tfmP.getData( tfDist, tfFlux, tfTemp);
right = tfDist;
if (left < right){
result = "L5"
}
else if(right < left){
result = "L4" 
}
delay(100);

}
else {
delay(20); 
myservo.write(90);  
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
