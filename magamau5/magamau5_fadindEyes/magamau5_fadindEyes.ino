int rightRedPin = 3; 
int rightGreenPin = 5; 
int rightBluePin = 6; 

int leftRedPin = 9; 
int leftGreenPin = 10; 
int leftBluePin = 11; 

int leftEarPin = 2;
int rightEarPin = 4;

void setup()  { 
  pinMode(leftEarPin, INPUT);
  pinMode(rightEarPin, INPUT);
  
  digitalWrite(leftEarPin, HIGH);
  digitalWrite(rightEarPin, HIGH);
  
  Serial.begin(9600);
}

void loop()  { 
  //fade(rightRedPin, leftRedPin);
  //fade(rightGreenPin, leftGreenPin);
  //fade(rightBluePin, leftBluePin);
  
  Serial.print("Left: ");
  Serial.print(leftEar());
  Serial.print(" Right: ");
  Serial.println(rightEar());
  
  if (leftEar() == 0)
  {
    analogWrite(rightRedPin, 125);
    analogWrite(rightBluePin, 125);
    analogWrite(rightGreenPin, 255);
  }
  else
 {
   analogWrite(rightRedPin, 255);
   analogWrite(rightBluePin, 255);
   analogWrite(rightGreenPin, 0);
 }
 
  if (rightEar() == 0)
  {
    analogWrite(leftRedPin, 125);
    analogWrite(leftBluePin, 125);
    analogWrite(leftGreenPin, 255);
  }
  else
 {
   analogWrite(leftRedPin, 255);
   analogWrite(leftBluePin, 255);
   analogWrite(leftGreenPin, 0);
 }
}
boolean leftEar()
{
  return digitalRead(leftEarPin);
}

boolean rightEar()
{
  return digitalRead(rightEarPin);
}

void fade(int rightLedPin, int leftLedPin)
{
  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    analogWrite(rightLedPin, fadeValue);      
    analogWrite(leftLedPin, fadeValue);    
    delay(30);                            
  } 
  
  // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(rightLedPin, fadeValue);
    analogWrite(leftLedPin, fadeValue);         
    delay(30);                            
  } 
}
