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

static const char* verticalKey = "YSXKFJYHCZGW00DT";
static const char* horizontalKey = "DKH2JAX5CLOA7D83";

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
    Temp = tfTemp / 100 + 20;
    lidcontrol = 1;
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

  sendData();
}

void sendData() {

  const char* key = (servoX == 180) ? verticalKey : horizontalKey;

  String httpRequestData = "api_key=" + String(key);

  for (int i = 0; i < 22; i++) {
    httpRequestData += "&field" + String(i + 1) + "=" + String(Green[i]) + String(Angle[i]);
  }

  httpRequestData += "&field23=" + String(Green[22]) + String(Green[23]);
  httpRequestData += "&field24=" + String(Angle[22]) + String(Angle[23]);
  httpRequestData += "&field25=" + String(Temp);

  postData(httpRequestData);
}

void postData(String httpRequestData) {
  NetworkClientSecure *client = new NetworkClientSecure;

  if (client) {
    client->setInsecure();

    HTTPClient http;
    if (http.begin(*client, serverName)) {
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      http.POST(httpRequestData);
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
