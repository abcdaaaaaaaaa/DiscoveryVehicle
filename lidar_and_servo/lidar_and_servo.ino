#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "ESPAsyncWebServer.h"
#include <Servo.h>
#include <TFMPlus.h> 

Servo myservo;  
const char* serverNameservoplay = "http://192.168.1.1/servo";
String servoplay;

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
  delay(20);              
myservo.attach(3);  
myservo.write(90);

  delay(2000);

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
  }
  else                  // If the command fails...
  {
    tfmP.printFrame();  // display the error and HEX dataa
  }
  server.begin();
}

void loop() {
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
}
else {
delay(20); 
myservo.write(90);  
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
