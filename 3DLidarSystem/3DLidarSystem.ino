#include <WiFi.h>
#include <Wire.h>
#include <TFLI2C.h>
#include <ESP32Servo.h>
#include "ThingSpeak.h"

int in1 = 23;
int in2 = 19;
int in3 = 18;
int in4 = 5;

int servoPin = 32;
int servoX = 90;

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

unsigned int ch1 = 1;
unsigned int ch2 = 2;
unsigned int ch3 = 3;

static const char* verticalKey1 = "YSXKFJYHCZGW00DT";
static const char* verticalKey2 = "X0TOV3MUEEQQD4HK";
static const char* verticalKey3 = "1KKGE6BY2468X6VN";

static const char* horizontalKey1 = "DKH2JAX5CLOA7D83";
static const char* horizontalKey2 = "JCBZHB1KUX0Y09LX";
static const char* horizontalKey3 = "QP8J57RU9BY9NAVE";

const char* ssid = "A.Mert iPhone'u";
const char* password = "bugungunlerdenoyun";

void setup() {
  Serial.begin(115200);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  scanServo.attach(servoPin);
  scanServo.write(servoX);

  Wire.begin();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  ThingSpeak.begin(client);
}

void loop() {
  lidcontrol = 0;

  if (tflI2C.getData(tfDist, tfFlux, tfTemp, tfAddr)) {
    tfTemp = tfTemp / 100 + 20;
    Temp = tfTemp;
    lidcontrol = 1;
  } else {
    lidcontrol = 0;
  }

  if (!lidcontrol) return;

  for (int section = 0; section < 24; section++) {

    for (int i = 0; i < 171; i++) {
      stepMotor(stepIndex);
      stepIndex = (stepIndex + 1) % 8;
      delayMicroseconds(1500);
    }

    if (tflI2C.getData(tfDist, tfFlux, tfTemp, tfAddr)) {
      tfFlux = int16_t(tfFlux + 10000);
      tfDist = int16_t(tfDist + 1000);
      Angle[section] = tfDist;
      Green[section] = tfFlux;
    } else {
      lidcontrol = 0;
      break;
    }
  }

  for (int i = 0; i < 4104; i++) {
    stepIndex = (stepIndex - 1 + 8) % 8;
    stepMotor(stepIndex);
    delayMicroseconds(800);
  }

  servoX = (servoX == 180) ? 90 : 180;
  scanServo.write(servoX);

  if (!lidcontrol) return;

  const char* key1 = (servoX == 180) ? verticalKey1 : horizontalKey1;
  const char* key2 = (servoX == 180) ? verticalKey2 : horizontalKey2;
  const char* key3 = (servoX == 180) ? verticalKey3 : horizontalKey3;

  for (int i = 0; i < 8; i++)
    ThingSpeak.setField(i + 1, String(Green[i]) + String(Angle[i]));
  ThingSpeak.writeFields(ch1, key1);

  for (int i = 8; i < 16; i++)
    ThingSpeak.setField(i - 7, String(Green[i]) + String(Angle[i]));
  ThingSpeak.writeFields(ch2, key2);

  for (int i = 16; i < 22; i++)
    ThingSpeak.setField(i - 15, String(Green[i]) + String(Angle[i]));

  ThingSpeak.setField(7, String(Green[22]) + String(Green[23]));
  ThingSpeak.setField(8, String(Angle[22]) + String(Angle[23]) + String(Temp));
  ThingSpeak.writeFields(ch3, key3);

}

void stepMotor(int s) {
  digitalWrite(in1, steps[s][0]);
  digitalWrite(in2, steps[s][1]);
  digitalWrite(in3, steps[s][2]);
  digitalWrite(in4, steps[s][3]);
}
