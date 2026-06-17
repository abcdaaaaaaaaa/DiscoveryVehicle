#include <WiFi.h>
#include <Wire.h>
#include <TFLI2C.h>
#include <ESP32Servo.h>
#include <HTTPClient.h>
#include <NetworkClientSecure.h>

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

int Angle[24];
int Green[24];
int Temp;

int lidcontrol = 0;

int16_t tfAddr = TFL_DEF_ADR;
uint16_t tfFrame = TFL_DEF_FPS;

int16_t tfDist = 0;
int16_t tfFlux = 0;
int16_t tfTemp = 0;

static const char* verticalKey1 = "YSXKFJYHCZGW00DT";
static const char* verticalKey2 = "X0TOV3MUEEQQD4HK";
static const char* verticalKey3 = "1KKGE6BY2468X6VN";

static const char* horizontalKey1 = "DKH2JAX5CLOA7D83";
static const char* horizontalKey2 = "JCBZHB1KUX0Y09LX";
static const char* horizontalKey3 = "QP8J57RU9BY9NAVE";

const char* ssid = "REPLACE_WITH_YOUR_SSID";  
const char* password = "REPLACE_WITH_YOUR_PASSWORD";
const char* serverName = "https://lidar.uzay.info/datareceiver.php";

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

  sendData(key1, 0, 8);
  sendData(key2, 8, 16);
  sendData3(key3);
}

void sendData(const char* key, int startIdx, int endIdx) {
  String httpRequestData = "api_key=" + String(key);
  for (int i = startIdx; i < endIdx; i++) {
    int fieldNum = i - startIdx + 1;
    httpRequestData += "&field" + String(fieldNum) + "=" + String(Green[i]) + String(Angle[i]);
  }
  postData(httpRequestData);
}

void sendData3(const char* key) {
  String httpRequestData = "api_key=" + String(key);
  for (int i = 16; i < 22; i++) {
    int fieldNum = i - 15;
    httpRequestData += "&field" + String(fieldNum) + "=" + String(Green[i]) + String(Angle[i]);
  }
  httpRequestData += "&field7=" + String(Green[22]) + String(Green[23]);
  httpRequestData += "&field8=" + String(Angle[22]) + String(Angle[23]) + String(Temp);
  postData(httpRequestData);
}

void postData(String httpRequestData) {
  NetworkClientSecure *client = new NetworkClientSecure;
  if(client) {
      client->setInsecure();
      HTTPClient http;
      if (http.begin(*client, serverName)) {
          http.addHeader("Content-Type", "application/x-www-form-urlencoded");
          int httpResponseCode = http.POST(httpRequestData);
          http.end();
      }
      delete client;
  }
}

void stepMotor(int s) {
  digitalWrite(in1, steps[s][0]);
  digitalWrite(in2, steps[s][1]);
  digitalWrite(in3, steps[s][2]);
  digitalWrite(in4, steps[s][3]);
}
