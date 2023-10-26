#include <WiFi.h>
#include <HTTPClient.h>
#include "ESPAsyncWebServer.h"
#include "Wire.h"
#include "I2Cdev.h" 
#include "MPU6050.h"
#include <SPI.h>
#include <Pixy2SPI_SS.h>


IPAddress local_IP(192, 168, 1, 2);
IPAddress gateway(255, 255, 0, 0);
IPAddress subnet(255, 255, 0, 0);

const char* ssid = "HelloSensor";
const char* password = NULL;

String xox;
const int IN2=12; 
const int IN1=13;
const int ENA=14;
const int IN4=25;
const int IN3=26;
const int ENB=27;

Pixy2SPI_SS pixy;

float deadZone = 0.15;
int baseSpeed = 130;
int now = 0;
int cont = 0;
int signature, x, y, width, height, rpm, veri1, veri2, motor_value, gyro_value, minimum, maximum;
float cx, cy, area;

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

const char* serverNamexxx = "http://192.168.1.1/xxx";
const char* serverNamepot = "http://192.168.1.1/pot";

AsyncWebServer server(80);

void setup(){
  Serial.begin(115200);
  WiFi.config(local_IP, gateway, subnet);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 Serial.println(WiFi.localIP());

  Wire.begin();
  mpu.initialize();
  pinMode(IN2,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(ENB,OUTPUT);
  pixy.init();

  server.on("/pixy", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(pixy.ccc.numBlocks).c_str());
  });

  server.on("/data1", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(veri1).c_str());
  });

  server.on("/data2", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(veri2).c_str());
  });

  server.on("/rpm", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(rpm).c_str());
  });
  
  server.begin();
}

void loop(){
  veri1 = map(analogRead(2),0,4095,0,100);
  veri2 = map(analogRead(4),0,4095,0,100);
  
  xox = httpGETRequest(serverNamepot);    
  if (xox == "X")(now = 1);
  else (now = 0);        
switch(now) { 
  case 0:
 {
vites();
mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
gyro_value = map(ax, -17000, 17000, minimum, maximum);
motor_value = abs(gyro_value);
rpm = map(motor_value, 0, 255, 0, 500);
     // Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED ){ 
      
if (httpGETRequest(serverNamexxx) == "1"){
    Serial.println("Dur");
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,LOW);
    analogWrite(ENA,0);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,LOW);
    analogWrite(ENB,0);
    }
    
if (httpGETRequest(serverNamexxx) == "2"){
    Serial.println("İleri");  
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,HIGH);
    analogWrite(ENA,motor_value);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,HIGH);
    analogWrite(ENB,motor_value);
    }
    
if (httpGETRequest(serverNamexxx) == "3"){
    Serial.println("Geri");  
    digitalWrite(IN2,HIGH);
    digitalWrite(IN1,LOW);
    analogWrite(ENA,motor_value);
    digitalWrite(IN4,HIGH);
    digitalWrite(IN3,LOW);
    analogWrite(ENB,motor_value);
    }
    
if (httpGETRequest(serverNamexxx) == "4"){
    Serial.println("Sol");  
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,HIGH);
    analogWrite(ENA,motor_value);
    digitalWrite(IN4,HIGH);
    digitalWrite(IN3,LOW);
    analogWrite(ENB,motor_value);
    }
    
if (httpGETRequest(serverNamexxx) == "5"){
    Serial.println("Sağ");  
    digitalWrite(IN2,HIGH);
    digitalWrite(IN1,LOW);
    analogWrite(ENA,motor_value);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,HIGH);
    analogWrite(ENB,motor_value);
    }
}       
else {
    Serial.println("Dur");
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,LOW);
    analogWrite(ENA,0);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,LOW);
    analogWrite(ENB,0);
    }
 delay(1); 
 }
  break;
  
 case 1:
{
  Serial.println("pixy yapay zeka modu:");  
  float turn = pixyCheck();
if(turn> -deadZone && turn < deadZone){
 turn = 0;
}

if (turn < 0) {
   digitalWrite(IN2,LOW); 
   digitalWrite(IN1,HIGH);
   analogWrite(ENA,80); 
   digitalWrite(IN4,HIGH);
   digitalWrite(IN3,LOW);
   analogWrite(ENB,170); 
   rpm = 177;
}

else if (turn > 0) {
   digitalWrite(IN2,HIGH); 
   digitalWrite(IN1,LOW);
   analogWrite(ENA,170); 
   digitalWrite(IN4,LOW);
   digitalWrite(IN3,HIGH);
   analogWrite(ENB,80); 
   rpm = 177;
}

else {
   digitalWrite(IN2,HIGH); 
   digitalWrite(IN1,LOW);
   analogWrite(ENA,70); 
   digitalWrite(IN4,HIGH);
   digitalWrite(IN3,LOW);
   analogWrite(ENB,70); 
   rpm = 70;
}
 delay(1); 
} 
 break;
 
default:
{
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,LOW);
    analogWrite(ENA,0);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,LOW);
    analogWrite(ENB,0);
    rpm = 0;
}
  break;
}
}

void vites(){
      if (xox == "L"){ 
      minimum = 25;  // 49.02 RPM // (49.02+/-49.02)
      maximum = 25;
     }     
      else if (xox == "A"){  
      minimum = 25;  // 98.04 RPM // (196.08+/-49.02)
      maximum = 100;
     }
      else if (xox == "B"){ 
      minimum = 25;  // 122.55 RPM // (294.12+/-49.02)
      maximum = 150;
      }
      else if (xox == "C"){ 
      minimum = 25;  // 147.06 RPM // (392.16+/-49.02)
      maximum = 200;
      }
      else if (xox == "D"){
      minimum = 25;  // 171.57 RPM // (500+/-49.02)
      maximum = 255;
      }
      else if (xox == "E"){
      minimum = 65;  // 204.90 RPM // (500+/-127.45)
      maximum = 255;
      }
      else if (xox == "F"){
      minimum = 105;  // 237.25 RPM // (500+/-205.88)
      maximum = 255;
      }
      else if (xox == "G"){
      minimum = 145;  // 269.61 RPM // (500+/-282.35)
      maximum = 255;
      }
      else if (xox == "H"){  
      minimum = "255";  // 269.61 RPM // (500+/-500) 
      maximum = "255";
      }
      else{
      minimum = 25;
      maximum = 255;
      now = 0;
      }
}

float pixyCheck() {
 static int i = 0;
 int j;
 uint16_t blocks;
 char buf[32];
 blocks = pixy.ccc.numBlocks;

 if(blocks)
 {
   signature = pixy.ccc.blocks[0].m_signature;
   height = pixy.ccc.blocks[0].m_height;
   width = pixy.ccc.blocks[0].m_width;
   x = pixy.ccc.blocks[0].m_x;
   y = pixy.ccc.blocks[0].m_y;
   cx = (x + (width / 2));
   cy = (y + (height / 2));
   cx = mapfloat(cx, 0, 320, -1, 1);
   cy = mapfloat(cy, 0, 200, 1, -1);
   area = width * height;
}

else {
  cont += 1;
if (cont == 100) {
  cont = 0;
  cx = 0;
  }
 }
 return cx;
}

float mapfloat(long x, long in_min, long in_max, long out_min, long out_max)
{
 return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
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
