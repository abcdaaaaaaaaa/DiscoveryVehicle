#include <WiFi.h>
#include "ESPAsyncWebServer.h"
#include <HTTPClient.h>
#include <Wire.h>
#include "LiquidCrystal_I2C.h"

IPAddress apip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

#define pot    analogRead(A2)

const char* ssid = "HelloSensor";
const char* password = NULL;

const char* serverNamepixy = "http://192.168.1.2/pixy";
const char* serverNameData1 = "http://192.168.1.2/data1";
const char* serverNameData2 = "http://192.168.1.2/data2";

AsyncWebServer server(80);

LiquidCrystal_I2C LCD_I2C_0x27(0x27, 16, 2);

char* kontrol;
char* potnormal;
int x, y, potset;
String Data1, Data2, pixytime;

void setup() {
  Serial.begin(115200);
    WiFi.softAPConfig(apip, gateway, subnet);
    Serial.println("\n[*] Creating AP");
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);
    Serial.print("[+] AP Created with IP Gateway ");
    Serial.println(WiFi.softAPIP());
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
  potset = map(pot,0,8191,1,8);
  vitesayar();
  kontrolayar();
   x = analogRead(A0);  //Ury
   y = analogRead(A1);  //Urx
   
      Data1 = httpGETRequest(serverNameData1);
      Data2 = httpGETRequest(serverNameData2);
      pixytime = httpGETRequest(serverNamepixy);
  
    LCD_I2C_0x27.setCursor(1 - 1, 1 - 1);
    LCD_I2C_0x27.print("MQ-X: %");
    LCD_I2C_0x27.print(Data1);
    LCD_I2C_0x27.setCursor(15 - 1, 1 - 1);
    LCD_I2C_0x27.print(potnormal);     
    LCD_I2C_0x27.print(pixytime);   
    LCD_I2C_0x27.setCursor(1 - 2, 1 - 1);
    LCD_I2C_0x27.print("Data: %");
    LCD_I2C_0x27.print(Data2);
  }

void vitesayar(){
switch(potset){
case 1: potnormal = "A"; break;
case 2: potnormal = "B"; break;
case 3: potnormal = "C"; break;
case 4: potnormal = "D"; break;
case 5: potnormal = "E"; break;
case 6: potnormal = "F"; break;
case 7: potnormal = "G"; break;
case 8: potnormal = "X"; break;
default: potnormal = "D"; break;
}
}

void kontrolayar(){
if(y >= 3200 && y <= 4800 && x >= 3200 && x <= 4800) {
    kontrol = "1";
  Serial.println("Dur");
}
else if(y >= 6400 && y <= 8191) {
    kontrol = "2";
  Serial.println("İleri");
}
else if(y >= 0 && y <= 3600) {
    kontrol = "3";
  Serial.println("Geri");
}
else if(x >= 0 && x <= 3600) {
    kontrol = "4";
  Serial.println("Sol");
}
else if(x >= 6400 && x <= 8191) {
    kontrol = "5";
  Serial.println("Sağ");
}
else{
    kontrol = "1";
  Serial.println("Dur");
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
