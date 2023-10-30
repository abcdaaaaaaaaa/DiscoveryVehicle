//for Pixy2SPI_SS.h 
#define PIXY_SPI_CLOCKRATE       8000000
SPI.beginTransaction(SPISettings(PIXY_SPI_CLOCKRATE, MSBFIRST, SPI_MODE3));
//for ZumoMotors.cpp
#define PWM_L 12
#define PWM_R 14
#define DIR_L 26
#define DIR_R 27
#define LEDC_CH_L 1
#define LEDC_CH_R 2

/*
  pinMode(PWM_L,  OUTPUT);
  pinMode(PWM_R,  OUTPUT);
*/
  pinMode(DIR_L, OUTPUT);
  pinMode(DIR_R, OUTPUT);
  
ledcSetup(LEDC_CH_L,20000,10);
ledcSetup(LEDC_CH_R,20000,10);

analogWrite(PWM_L, speed * 64 / 25); // default to using analogWrite, mapping 400 to 255

