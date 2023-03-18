#include <WiFi.h>
#include "ESPAsyncWebServer.h"
#include <HTTPClient.h>
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

const char* ssid = "****";
const char* password = "*****";
String xox;
const int IN2=D5; 
const int IN1=D4;
const int ENA=D2;
const int IN4=D7;
const int IN3=D6;
const int ENB=D3;

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

int motor_value;
int gyro_value;
const char* serverNamexxx = "http://192.168.1.3/xxx";
const char* serverNamepot = "http://192.168.1.3/pot";

int minimum;
int maximum;
void setup(){
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Wire.begin();
  mpu.initialize();
  pinMode(IN2,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(ENB,OUTPUT);
}
void loop(){
  vites();
mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
gyro_value = map(ax, 0, 17000, minimum,maximum);
motor_value = abs(gyro_value);
     // Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED ){ 
if (httpGETRequest(serverNamexxx) == "1"){
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,LOW);
    analogWrite(ENA,0);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,LOW);
    analogWrite(ENB,0);
    }
if (httpGETRequest(serverNamexxx) == "2"){
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,HIGH);
    analogWrite(ENA,motor_value);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,HIGH);
    analogWrite(ENB,motor_value);
    }
if (httpGETRequest(serverNamexxx) == "3"){
    digitalWrite(IN2,HIGH);
    digitalWrite(IN1,LOW);
    analogWrite(ENA,motor_value);
    digitalWrite(IN4,HIGH);
    digitalWrite(IN3,LOW);
    analogWrite(ENB,motor_value);
}
if (httpGETRequest(serverNamexxx) == "4"){
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,HIGH);
    analogWrite(ENA,motor_value);
    digitalWrite(IN4,HIGH);
    digitalWrite(IN3,LOW);
    analogWrite(ENB,motor_value);
}
if (httpGETRequest(serverNamexxx) == "5"){
    digitalWrite(IN2,HIGH);
    digitalWrite(IN1,LOW);
    analogWrite(ENA,motor_value);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,HIGH);
    analogWrite(ENB,motor_value);
    }
}       
else {
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,LOW);
    analogWrite(ENA,0);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,LOW);
    analogWrite(ENB,0);
    }
}
void vites(){
  xox = httpGETRequest(serverNamepot);
      if (xox == "X"){
      minimum = 10;
      maximum = 60; 
      }
      else if (xox == "A"){
      minimum = 0;
      maximum = 100;
     }
      else if (xox == "B"){
      minimum = 0;
      maximum = 150;
      }
      else if (xox == "C"){
      minimum = 0;
      maximum = 200;
      }
      else if (xox == "D"){
      minimum = 0;
      maximum = 255;
      }
      else if (xox == "E"){
      minimum = 45;
      maximum = 255;
      }
      else if (xox == "F"){
      minimum = 95;
      maximum = 255;
      }
      else if (xox == "G"){
      minimum = 145;
      maximum = 255;
      }
      else{
      minimum = 0;
      maximum = 255;
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
