#include <Servo.h> 
#include <Wire.h>
#include "IOpindefinitions.h"

Servo dispenserServo;  
Servo tiltServo;
Servo bananaServo;
Servo eyesXServo;
Servo eyesYServo;

char inByte;

int tilt = 90;
int velocity = 150;
int servoDelay = 150;

int eyesXCenter = 90;
int eyesYCenter = 90;
int eyesXPos = 90;
int eyesYPos = 90;

int angleTime;

boolean rollEyesNow = false;
int currentRolls = 0;
int maxRolls = 5;

void setup() 
{ 
  Serial.begin(9600);
  
  setupServos();
  setupMotors();
  setupLed();
  setupI2C();
  
  delay(150);
}
 
void loop() 
{ 
  if(Serial.available() > 0)
  {
    inByte = Serial.read();
  }  
  
  switch(inByte)
  {
    case 'f':
      fire();
      break;
    case 'j':
      if((tilt - 10) >= 0)
        tilt -= 10;
      tiltServo.write(tilt);
      break;
    case 'u':
      if((tilt + 10) <= 90)
        tilt += 10;   
      tiltServo.write(tilt);
      break;
    case 'w':
      if(eyesYPos <= eyesYCenter + 45)
        eyesYPos += 10;
      break;
    case 'x':
      if(eyesYPos >= eyesYCenter - 45)
        eyesYPos -= 10;
      break;
    case 'a':
      if(eyesXPos <= eyesXCenter + 45)
        eyesXPos += 10;
      break;
    case 'd':
      if(eyesXPos >= eyesXCenter - 45)
        eyesXPos -= 10;
      break;
    case 's':
      eyesXPos = 90;
      eyesYPos = 90;
      break;
    case 'r':
      rollEyesNow = true;
      eyesXPos = 90;
      eyesYPos = 135;
  }
  
  if(rollEyesNow)
    rollEyes(5);
  
  updateEyes();
  inByte = 'v';
}



