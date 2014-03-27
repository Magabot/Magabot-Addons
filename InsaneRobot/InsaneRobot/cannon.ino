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
