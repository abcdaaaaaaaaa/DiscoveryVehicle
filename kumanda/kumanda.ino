#include <WiFi.h>
#include "ESPAsyncWebServer.h"
#include <HTTPClient.h>
#include <Wire.h>
#include "LiquidCrystal_I2C.h"

IPAddress apip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

#define pot    analogRead(34)
#define pot2   analogRead(35)

const char* ssid = "Chernobyl";
const char* password = NULL;

const char* serverNamepixy = "http://192.168.1.2/pixy";
const char* serverNameData = "http://192.168.1.3/data";
const char* serverNameStg = "http://192.168.1.3/stg";
const char* serverNamedist = "http://192.168.1.3/dist";
const char* serverNametemp = "http://192.168.1.3/temp";
const char* serverNamelih = "http://192.168.1.3/lih";

AsyncWebServer server(80);

LiquidCrystal_I2C LCD_I2C_0x27(0x27, 16, 2);

char* kontrol;
char* potnormal;
char* potnormal2;
int x, y, potset, potset2;
int hello = 0;
String Data, Stg, dist, tempa, lih, pixytime;

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
  delay(2000);
  potset = pot / 16;
  potset2 = pot2 / 16;
  vitesayar();
  kontrolayar();
  lidarayar();
   x = analogRead(32); //Ury
   y = analogRead(33);  //Urx
   
      Data = httpGETRequest(serverNameData);
      Stg = httpGETRequest(serverNameStg);
      pixytime = httpGETRequest(serverNamepixy);
      dist = httpGETRequest(serverNamedist);
      tempa = httpGETRequest(serverNametemp);
  
    LCD_I2C_0x27.setCursor(1 - 1, 1 - 1);
    LCD_I2C_0x27.print("DWH:");
    LCD_I2C_0x27.print(Data);
    LCD_I2C_0x27.setCursor(10 - 1, 1 - 1);
    LCD_I2C_0x27.print(potnormal2); 
    LCD_I2C_0x27.print(":");
    LCD_I2C_0x27.print(dist);
    LCD_I2C_0x27.setCursor(1 - 1, 2 - 1);
    LCD_I2C_0x27.print("Ang:");
    LCD_I2C_0x27.print(Stg);
    LCD_I2C_0x27.setCursor(11 - 1, 2 - 1);
    LCD_I2C_0x27.print(tempa);
    LCD_I2C_0x27.print("C"); 
    LCD_I2C_0x27.setCursor(15 - 1, 2 - 1);
    LCD_I2C_0x27.print(potnormal);
    LCD_I2C_0x27.setCursor(16 - 1, 2 - 1);
    LCD_I2C_0x27.print(pixytime);   
     
   Serial.println("Dongu bitti"); 
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
  switch(hello){
  case 0: 
  {
if(y >= 1600 && y <= 2400 && x >= 1600 && x <= 2400) {
    kontrol = "1";
  Serial.println("Dur");
}
else if(y >= 3200 && y <= 4095) {
    kontrol = "2";
  Serial.println("İleri");
}
else if(y >= 0 && y <= 1800) {
    kontrol = "3";
  Serial.println("Geri");
}
else if(x >= 0 && x <= 1800) {
    kontrol = "4";
  Serial.println("Sol");
}
else if(x >= 2400 && x <= 4095) {
    kontrol = "5";
  Serial.println("Sağ");
}
 }
 break;
case 1:
{
lih = httpGETRequest(serverNamelih);
if(lih == "L1") {
kontrol = "L1";
//Serial.println("Dur");
}
if(lih == "L2") {
kontrol = "L2";
//Serial.println("İleri");
if(lih == "L4") {
kontrol = "L4";
//Serial.println("Sol");
}
if(lih == "L5") {
kontrol = "L5";
//Serial.println("Sağ");
}
}
}
 break;
default:
if(y >= 1600 && y <= 2400 && x >= 1600 && x <= 2400) {
    kontrol = "1";
  Serial.println("Dur");
}
else if(y >= 3200 && y <= 4095) {
    kontrol = "2";
  Serial.println("İleri");
}
else if(y >= 0 && y <= 1800) {
    kontrol = "3";
  Serial.println("Geri");
}
else if(x >= 0 && x <= 1800) {
    kontrol = "4";
  Serial.println("Sol");
}
else if(x >= 2400 && x <= 4095) {
    kontrol = "5";
 Serial.println("Sağ");
}
 break;
}
} 
void lidarayar(){
  if (potset2 <= 32){
    potnormal2 = "L1";
     hello = 0;
  }
  else if (potset2 <= 64){
    potnormal2 = "L2";
     hello = 0;
  }
  else if (potset2 <= 96){
     potnormal2 = "L3";
     hello = 0;
  }
  else if (potset2 <= 128){
     potnormal2 = "AA";
     hello = 0;
  }
  else if (potset2 <= 160) {
    potnormal2 = "R3";
     hello = 0;
  }
  else if (potset2 <= 192){
     potnormal2 = "R2";
     hello = 0;
  }
  else if (potset2 <= 224){
     potnormal2 = "R1";
     hello = 0;
  }
  else if (potset2 == 255){
     potnormal2 = "MV";
     hello = 1;
  }
  else {
    potnormal2 = "OT";
     hello = 0;
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
