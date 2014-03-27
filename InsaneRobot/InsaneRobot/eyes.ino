void updateEyes()
{
  eyesXServo.write(eyesXPos);
  eyesYServo.write(eyesYPos);
}


void rollEyes(int steps)
{
  int x = eyesXPos;
  int y = eyesYPos;
  
  if(x >= 90 && y >= 90 && x - steps >= eyesXCenter - 45 && y + steps <= eyesYCenter + 45)
  {
    eyesXPos = x - steps;
    eyesYPos = y + steps;
  }
  else if(x <= 90 && y >= 90 && x - steps >= eyesXCenter - 45 && y - steps >= eyesYCenter - 45)
  {
    eyesXPos = x - steps;
    eyesYPos = y - steps;
  }
  else if(x <= 90 && y <= 90 && x + steps <= eyesXCenter + 45 && y - steps >= eyesYCenter - 45)
  {
    eyesXPos = x + steps;
    eyesYPos = y - steps;
  }
  else if(x >= 90 && y <= 90 && x + steps <= eyesXCenter + 45 && y + steps <= eyesYCenter + 45)
  {
    eyesXPos = x + steps;
    eyesYPos = y + steps;
  }
  
  if(eyesXPos >= (90 - steps) && eyesXPos <= (90 + steps) && eyesYPos >= 135 - steps)
  {
    currentRolls++;
  }

  if(currentRolls - 1 == maxRolls)
  {
    rollEyesNow = false;
    eyesXPos = 90;
    eyesYPos = 90;
    currentRolls = 0;
  }
}
