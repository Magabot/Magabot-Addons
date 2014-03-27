void setupServos()
{
  dispenserServo.attach(dispenserServoPin);
  tiltServo.attach(tiltServoPin);
  eyesXServo.attach(eyesXServoPin);
  eyesYServo.attach(eyesYServoPin);
  
  dispenserServo.write(90);
  tiltServo.write(tilt); 
  eyesXServo.write(eyesXCenter);
  eyesYServo.write(eyesYCenter);
}

void setupMotors()
{
  pinMode(motorAPin, OUTPUT);  
  pinMode(motorBPin, OUTPUT);

  digitalWrite(motorAPin, LOW);
  digitalWrite(motorBPin, LOW);
}

void setupLed()
{
  pinMode(ledRedPin, OUTPUT);  
  pinMode(ledGreenPin, OUTPUT);  
  pinMode(ledBluePin, OUTPUT);
  
  digitalWrite(ledRedPin, HIGH);
  digitalWrite(ledGreenPin, LOW);
  digitalWrite(ledBluePin, HIGH);
}

void setupI2C()
{
  Wire.begin(4); 
  Wire.onReceive(receiveEvent);
}
