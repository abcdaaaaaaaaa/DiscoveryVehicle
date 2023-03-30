#include <WiFi.h>
#include "ESPAsyncWebServer.h"
#include <HTTPClient.h>
#define pot    analogRead(A2)
const char* ssid = "****";
const char* password = "****";
//Your IP address or domain name with URL path
const char* serverNameaverage = "http://192.168.1.1/averagecpm";
const char* serverNamesd = "http://192.168.1.1/sdcpm";
const char* serverNamearray = "http://192.168.1.1/cpmarray";
const char* serverNamepixy = "http://192.168.4.1/pixy";

AsyncWebServer server(80);

#include <Wire.h>
#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C LCD_I2C_0x27(0x27, 16, 2);

int x;
int y;
int potset;
char* potnormal;
char* kontrol;
String averageCPM;
String sdCPM;
String CPMArray;

unsigned long previousMillis = 0;
const long interval = 100; 
IPAddress local_IP(192, 168, 1, 3);

void setup() {
  Serial.begin(115200);

  
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  LCD_I2C_0x27.init();
  LCD_I2C_0x27.backlight();
  LCD_I2C_0x27.clear();
    server.on("/xxx", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(kontrol).c_str());
  });
    server.on("/pot", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(potnormal).c_str());
  });
  server.begin();
}

void loop() {
  potset= map(pot, 0, 1023, 0, 255);
  vitesayar();
  kontrolayar();
   x = analogRead(A1);
   y = analogRead(A0);
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis >= interval) {
     // Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED ){ 
      averageCPM = httpGETRequest(serverNameaverage);
      sdCPM = httpGETRequest(serverNamesd);
      CPMArray = httpGETRequest(serverNamearray);
    LCD_I2C_0x27.setCursor(1 - 1, 1 - 1);
    LCD_I2C_0x27.print("Avg:");
    LCD_I2C_0x27.print(averageCPM);
    LCD_I2C_0x27.setCursor(1 - 1, 2 - 1);
    LCD_I2C_0x27.print("Arrayval:");
    LCD_I2C_0x27.print(sdCPM);
    LCD_I2C_0x27.setCursor(10 - 1, 1 - 1);
    LCD_I2C_0x27.print("+/-"); 
    LCD_I2C_0x27.print(CPMArray);
    LCD_I2C_0x27.print(potnormal);
     
      
      // save the last HTTP GET Request
      previousMillis = currentMillis;
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  }
}
void vitesayar(){
  if (potset <= 32){
    potnormal = "X";
  }
  else if (potset <= 64){
    potnormal = "A";
  }
  else if (potset <= 96){
     potnormal = "B";
  }
  else if (potset <= 128){
     potnormal = "C";
  }
  else if (potset <= 160) {
    potnormal = "D";
  }
  else if (potset <= 192){
     potnormal = "E";
  }
  else if (potset <= 224){
     potnormal = "F";
  }
  else {
    potnormal = "G";
  }
}

void kontrolayar(){
if(y >= 400 && y <= 600) {
    kontrol = "1";
}
if(y >= 800 && y <= 1023) {
    kontrol = "2";
}
if(y >= 0 && y <= 450) {
    kontrol = "3";
}
if(x >= 0 && x <= 450) {
    kontrol = "4";
}
if(x >= 600 && x <= 1023) {
    kontrol = "5";
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
