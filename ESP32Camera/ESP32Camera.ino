#include <WiFi.h>

const char* ssidAP      = "ESP32Camera";      
const char* passwordAP  = NULL;               

IPAddress apip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

void setup() {
  Serial.begin(115200);                       
  Serial.setDebugOutput(true);                
  Serial.println();
  
  cameraInit();                               

  WiFi.softAP(ssidAP, passwordAP);
  WiFi.softAPConfig(apip, gateway, subnet);
  delay(100);

  void startCameraServer();                        

  Serial.print("'http://");  
  Serial.print(WiFi.softAPIP());                          
  Serial.println("'Your Camera ip is ready!");      
}       

void loop() {}
