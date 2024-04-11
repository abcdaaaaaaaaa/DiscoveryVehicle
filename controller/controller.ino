#include <WiFi.h>
#include <ESPAsyncWebSrv.h>
#include <HTTPClient.h>
#include "LiquidCrystal_I2C.h"

IPAddress apip(192,168,1,1);
IPAddress gateway(255,255,255,1);
IPAddress subnet(255,255,255,0);

const char* ssid = "HelloSensor";
const char* password = NULL;

const char* serverNamepixy = "http://192.168.1.2/pixy";
const char* serverNameData1 = "http://192.168.1.2/data1";
const char* serverNameData2 = "http://192.168.1.2/data2";
const char* serverNameRPM = "http://192.168.1.2/rpm";

AsyncWebServer server(80);

LiquidCrystal_I2C LCD_I2C_0x27(0x27, 16, 2);

#define button1 digitalRead(32)
#define button2 digitalRead(33)

char* kontrol;
char* potnormal;
int x, y, result1, result2;
String Data1, Data2, pixytime, RPM, mod;

void setup() {
  Serial.begin(115200);
  pinMode(34,INPUT);
  pinMode(35,INPUT);
  pinMode(32,INPUT_PULLUP);
  pinMode(33,INPUT_PULLUP);
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
  
   x = map(analogRead(34),0,4095,0,10); // Ury->34 // BUTTON->33
   y = map(analogRead(35),0,4095,0,10); // Urx->35 // BUTTON->32
   
  if (button1 == 0){delay(250); result1++;}
  if (result1 == 2)(result1 = 0);

  if (button2 == 0){delay(250); result2++;}
  if (result2 == 9)(result2 = 0);

  modayar();
  vitesayar();
  kontrolayar();
   
      Data1 = httpGETRequest(serverNameData1);
      Data2 = httpGETRequest(serverNameData2);
      pixytime = httpGETRequest(serverNamepixy);
      RPM = httpGETRequest(serverNameRPM);
  
    LCD_I2C_0x27.setCursor(0, 0);
    LCD_I2C_0x27.print("MQ: %" + Data1);
    LCD_I2C_0x27.setCursor(13 - RPM.length(), 0);
    LCD_I2C_0x27.print(RPM + "RPM"); 
    LCD_I2C_0x27.setCursor(0, 1);
    LCD_I2C_0x27.print("SD: %" + Data2);
    LCD_I2C_0x27.setCursor(10, 1);
    LCD_I2C_0x27.print(mod);
    LCD_I2C_0x27.setCursor(14, 1);
    LCD_I2C_0x27.print(potnormal + pixytime); 
  }
  
void modayar(){
switch(result1){
case 0: mod = "CON"; break;
case 1: mod = "DPL"; break;
default: mod = "CON"; break;
}
}

void vitesayar(){
if (mod == "CON"){
switch(result2){
case 0: potnormal = "D"; break;
case 1: potnormal = "L"; break;
case 2: potnormal = "A"; break;
case 3: potnormal = "B"; break;
case 4: potnormal = "C"; break;
case 5: potnormal = "E"; break;
case 6: potnormal = "F"; break;
case 7: potnormal = "G"; break;
case 8: potnormal = "H"; break;
default: potnormal = "D"; break;
}
}
else if (mod == "DPL")(potnormal = "X");
else(potnormal = "D");
}

void kontrolayar(){
if(y >= 4 && y <= 6 && x >= 4 && x <= 6)(kontrol = "1");
else if(y >= 7 && y <= 10)(kontrol = "2"); 
else if(y >= 0 && y <= 3)(kontrol = "3");
else if(x >= 0 && x <= 3)(kontrol = "4");
else if(x >= 7 && x <= 10)(kontrol = "5");
else(kontrol = "1");
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
