#include <Servo.h> 
#include <Wire.h>

Servo dispenserServo;  
Servo tiltServo;
Servo bananaServo;

int dispenserServoPin = 9;
int tiltServoPin = 10;
int bananaServoPin = 3;

int motorAPin = 5; 
int motorBPin = 6; 

int ledRedPin = 11; 
int ledGreenPin = 12; 
int ledBluePin = 13; 

char inByte;

int tilt = 90;
int velocity = 150;
int servoDelay = 160;

int angleTime;

void setup() 
{ 
  Serial.begin(9600);
  
  dispenserServo.attach(dispenserServoPin);
  tiltServo.attach(tiltServoPin);
  bananaServo.attach(bananaServoPin);
  
  dispenserServo.write(90);
  tiltServo.write(tilt); 
  bananaServo.write(90);
  
  delay(150);
  
  pinMode(motorAPin, OUTPUT);  
  pinMode(motorBPin, OUTPUT);

  pinMode(ledRedPin, OUTPUT);  
  pinMode(ledGreenPin, OUTPUT);  
  pinMode(ledBluePin, OUTPUT);
  
  digitalWrite(motorAPin, LOW);
  digitalWrite(motorBPin, LOW);
  
  digitalWrite(ledRedPin, HIGH);
  digitalWrite(ledGreenPin, HIGH);
  digitalWrite(ledBluePin, LOW);
  
  Wire.begin(4); 
  Wire.onReceive(receiveEvent);
}
 
void loop() 
{ 
  if(Serial.available() > 0)
  {
    inByte = Serial.read();
  }  
  
  if(inByte == 'f')
  {
    fire();
    inByte = 'v';
  } 
  else if(inByte == 'b')
  {
    dropBanana();
    inByte = 'v';
  } 
  else if(inByte == 'j')
  {
    if((tilt - 10) >= 0)
      tilt -= 10;
      
    tiltServo.write(tilt);
    inByte = 'v';
  }
  else if(inByte == 'u')
  {
    if((tilt + 10) <= 90)
      tilt += 10;   
    
    tiltServo.write(tilt);
    inByte = 'v';
  }
  else if(inByte == '+')
  {
    velocity += 10;
    Serial.println(velocity);
    inByte = 'v';
  }
  else if(inByte == '-')
  {
    velocity -= 10;
    Serial.println(velocity);
    inByte = 'v';
  }
  
  if(millis() > angleTime)
  {
    angleTime = millis() + 500;
    Serial.println(tilt);
  }
}

void receiveEvent(int howMany)
{
  inByte = Wire.read();
  Serial.println(inByte);
}


void dropBanana()
{
  bananaServo.write(0);
  delay(600);  
  bananaServo.write(90);
  delay(1000); 
}

void fire()
{
  digitalWrite(ledRedPin, LOW);
  digitalWrite(ledGreenPin, LOW);
  digitalWrite(ledBluePin, HIGH);
  analogWrite(motorAPin, velocity);
  analogWrite(motorBPin, velocity);
  
  delay(1500); 

  digitalWrite(ledRedPin, LOW);
  digitalWrite(ledGreenPin, HIGH);
  digitalWrite(ledBluePin, HIGH);
  dispenserServo.write(180);
  
  delay(servoDelay);
  
  dispenserServo.write(90);
  
  delay(350);
  
  analogWrite(motorAPin, 0);
  analogWrite(motorBPin, 0);
  digitalWrite(ledRedPin, HIGH);
  digitalWrite(ledGreenPin, LOW);
  digitalWrite(ledBluePin, HIGH); 
}
