#include <WiFi.h>
#include <Wire.h>
#include <TFLI2C.h>
#include <ESP32Servo.h>
#include "ThingSpeak.h"

int in1 = 23;
int in2 = 19;
int in3 = 18;
int in4 = 5;

int steps[8][4] = {
  {1,0,0,0},
  {1,1,0,0},
  {0,1,0,0},
  {0,1,1,0},
  {0,0,1,0},
  {0,0,1,1},
  {0,0,0,1},
  {1,0,0,1}
};

int stepIndex = 0;
int servoX = 180;

Servo scanServo;
TFLI2C tflI2C;
WiFiClient client;

int Angle[24];
int Green[24];
int Temp;

int lidcontrol = 0;

int16_t tfAddr = TFL_DEF_ADR;
uint16_t tfFrame = TFL_DEF_FPS;

int16_t tfDist = 0;
int16_t tfFlux = 0;
int16_t tfTemp = 0;

unsigned long lastTime = 0;
unsigned long timerDelay = 15000;

unsigned int ch1 = 1;
unsigned int ch2 = 2;
unsigned int ch3 = 3;

static const char* verticalKey1 = "YSXKFJYHCZGW00DT";
static const char* verticalKey2 = "X0TOV3MUEEQQD4HK";
static const char* verticalKey3 = "1KKGE6BY2468X6VN";

static const char* horizontalKey1 = "0HSEW6FQ65NWH2EP";
static const char* horizontalKey2 = "JCBZHB1KUX0Y09LX";
static const char* horizontalKey3 = "QP8J57RU9BY9NAVE";

const char* ssid = "REPLACE_WİTH_YOUR_SSID";  
const char* password = "REPLACE_WİTH_YOUR_PASSWORD";  

void setup() {
  Serial.begin(115200);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  scanServo.attach(32);
  scanServo.write(servoX);

  Wire.begin();

  Serial.println("Connecting to WiFi ");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  ThingSpeak.begin(client);
}

void loop() {

  if ((millis() - lastTime) < timerDelay) return;

  lidcontrol = 0;

  if (tflI2C.getData(tfDist, tfFlux, tfTemp, tfAddr)) {

    tfTemp = int16_t(tfTemp / 100 + 20);
    tfFlux = int16_t(tfFlux + 10000);
    tfDist = int16_t(tfDist + 1000);

    Temp = tfTemp;
    lidcontrol = 1;

    for (int section = 0; section < 24; section++) {

      for (int i = 0; i < 171; i++) {
        stepMotor(stepIndex);
        stepIndex = (stepIndex + 1) % 8;
        delayMicroseconds(1500);
      }

      Angle[section] = tfDist;
      Green[section] = tfFlux;
    }

  } else {
    Serial.print("-");
  }

  if (!lidcontrol) return;

  for (int i = 0; i < 4096; i++) {
    stepIndex = (stepIndex - 1 + 8) % 8;
    stepMotor(stepIndex);
    delayMicroseconds(800);
  }

  const char* key1 = (servoX == 180) ? verticalKey1 : horizontalKey1;
  const char* key2 = (servoX == 180) ? verticalKey2 : horizontalKey2;
  const char* key3 = (servoX == 180) ? verticalKey3 : horizontalKey3;

  for (int i = 0; i < 8; i++)
    ThingSpeak.setField(i + 1, String(Green[i]) + String(Angle[i]));
  ThingSpeak.writeFields(ch1, key1);

  for (int i = 8; i < 16; i++)
    ThingSpeak.setField(i - 7, String(Green[i]) + String(Angle[i]));
  ThingSpeak.writeFields(ch2, key2);

  for (int i = 16; i < 23; i++)
    ThingSpeak.setField(i - 15, String(Green[i]) + String(Angle[i]));

  ThingSpeak.setField(8, String(Green[23]) + String(Angle[23]) + String(Temp));
  ThingSpeak.writeFields(ch3, key3);

  lastTime = millis();

  servoX = (servoX == 180) ? 90 : 180;
  scanServo.write(servoX);
}

void stepMotor(int s) {
  digitalWrite(in1, steps[s][0]);
  digitalWrite(in2, steps[s][1]);
  digitalWrite(in3, steps[s][2]);
  digitalWrite(in4, steps[s][3]);
}

// TfLuna Lidar: [VCC --> 5V] [SDA --> D21] [SCL --> D22] [GND --> GND] [I2C --> GND]
