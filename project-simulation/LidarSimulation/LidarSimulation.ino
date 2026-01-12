// https://wokwi.com/projects/452396566835375105

#include <WiFi.h>
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
WiFiClient client;

int Angle[24];
int Green[24];
int Temp;

unsigned long lastTime = 0;
unsigned long timerDelay = 15000;

unsigned int ch1 = 1;
unsigned int ch2 = 2;
unsigned int ch3 = 3;

static const char* verticalKey1 = "YSXKFJYHCZGW00DT";
static const char* verticalKey2 = "X0TOV3MUEEQQD4HK";
static const char* verticalKey3 = "1KKGE6BY2468X6VN";

static const char* horizontalKey1 = "DKH2JAX5CLOA7D83";
static const char* horizontalKey2 = "JCBZHB1KUX0Y09LX";
static const char* horizontalKey3 = "QP8J57RU9BY9NAVE";

const char* ssid = "Wokwi-GUEST";
const char* password = "";

void setup() {
	Serial.begin(115200);

	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);

	scanServo.attach(32);
	scanServo.write(servoX);

	WiFi.mode(WIFI_STA); Serial.println("Connecting to WiFi ");
	WiFi.begin(ssid, password);
	while(WiFi.status() != WL_CONNECTED) { 
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

	randomSeed(micros() + lastTime);

	Temp = random(-10, 61) + 20;

	for (int section = 0; section < 24; section++) {

		randomSeed(micros() + section * 37);

		for (int i = 0; i < 171; i++) {
			stepMotor(stepIndex);
			stepIndex = (stepIndex + 1) % 8;
			delayMicroseconds(1500);
		}

		Angle[section] = random(20, 801) + 1000;
		Green[section] = random(0, 65536) + 10000;
	}

	for (int i = 0; i < 4104; i++) {
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

	for (int i = 16; i < 22; i++)
		ThingSpeak.setField(i - 15, String(Green[i]) + String(Angle[i]));

	ThingSpeak.setField(7, String(Green[22]) + String(Green[23]));
	ThingSpeak.setField(8, String(Angle[22]) + String(Angle[23]) + String(Temp));
	ThingSpeak.writeFields(ch3, key3);

	Serial.println("sent!");

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
