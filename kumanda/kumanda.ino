#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <HTTPClient.h>
#include <Wire.h>
#include "LiquidCrystal_I2C.h"

IPAddress apip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

#define pot    analogRead(A2)
#define pot2   analogRead(A3)

const char* ssid = "Chernobyl";
const char* password = NULL;

const char* serverNamepixy = "http://192.168.1.2/pixy";
const char* serverNameData = "http://192.168.1.3/data";
const char* serverNameStg = "http://192.168.1.3/stg";
const char* serverNamedist = "http://192.168.1.3/dist";
const char* serverNametemp = "http://192.168.1.3/temp";

AsyncWebServer server(80);

LiquidCrystal_I2C LCD_I2C_0x27(0x27, 16, 2);

char* kontrol;
char* potnormal;
char* potnormal2;
int x, y, potset, potset2;
String Data, Stg, dist, tempa, pixytime;

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
    server.on("/servo", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(potnormal2).c_str());
  });
  server.begin();
}

void loop() {
  potset= map(pot, 0, 1023, 0, 255);
  potset2= map(pot2, 0, 1023, 0, 255);
  vitesayar();
  kontrolayar();
  lidarayar();
   x = analogRead(A1);
   y = analogRead(A0);
   
      Data = httpGETRequest(serverNameData);
      Stg = httpGETRequest(serverNameStg);
      pixytime = httpGETRequest(serverNamepixy);
      dist = httpGETRequest(serverNamedist);
      tempa = httpGETRequest(serverNametemp);
      
    LCD_I2C_0x27.setCursor(1 - 1, 1 - 1);
    LCD_I2C_0x27.print("Data:");
    LCD_I2C_0x27.print(Data);
    LCD_I2C_0x27.setCursor(10 - 1, 1 - 1);
    LCD_I2C_0x27.print("Stg:");
    LCD_I2C_0x27.print(Stg);
    LCD_I2C_0x27.setCursor(1 - 1, 2 - 1);
    LCD_I2C_0x27.print(potnormal2); 
    LCD_I2C_0x27.print(":");
    LCD_I2C_0x27.print(dist);
    LCD_I2C_0x27.print("cm"); 
    LCD_I2C_0x27.setCursor(10 - 1, 2 - 1);
    LCD_I2C_0x27.print(tempa);
    LCD_I2C_0x27.print("C"); 
    LCD_I2C_0x27.setCursor(15 - 1, 2 - 1);
    LCD_I2C_0x27.print(potnormal);
    LCD_I2C_0x27.setCursor(16 - 1, 2 - 1);
    LCD_I2C_0x27.print(pixytime);    
    
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
void lidarayar(){
  if (potset2 <= 32){
    potnormal2 = "L1";
  }
  else if (potset2 <= 64){
    potnormal2 = "L2";
  }
  else if (potset2 <= 96){
     potnormal2 = "L3";
  }
  else if (potset2 <= 128){
     potnormal2 = "AA";
  }
  else if (potset2 <= 160) {
    potnormal2 = "R3";
  }
  else if (potset2 <= 192){
     potnormal2 = "R2";
  }
  else if (potset2 <= 224){
     potnormal2 = "R1";
  }
  else {
    potnormal2 = "OT";
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
