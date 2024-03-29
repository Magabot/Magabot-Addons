#include <Wire.h>
#include <Magabot.h>


Magabot robot;

//Define here what protocol you want to use:
char protocol = 'H'; // 'L' for Low Level and 'H' for High Level // EPROM

int inByte = 'p';
char order = '1'; 


void setup()
{
  Serial.begin(9600);
  robot.actuateMotors(0,0);
  robot.actuateLEDs(255,255,255);
}


void loop() 
{  
  // E2->1 E4->2 E6->3 E8->4 EA->5
  //robot.changeSonarAddress(0x70, 0xE4);
  //while(1);
  
  if (Serial.available() > 0) 
  {
    inByte = Serial.read();
    
    if(protocol == 'l' || protocol == 'L')
    {
      lowLevelProtocol();
    }
    else if(protocol == 'h' || protocol == 'H')
    {
      if(inByte == '1') 
        order = inByte;
      else if(inByte == '2') 
        order = inByte;
      else if(inByte == 'f' || inByte == 'u' || inByte == 'j')
      {
        Wire.beginTransmission(4); // transmit to device #4
        Wire.write(inByte);        // sends five bytes
        Wire.endTransmission();    // stop transmitting
      }
      else if(inByte == 'b')
      {
        Wire.beginTransmission(4); // transmit to device #4
        Wire.write('b');        // sends five bytes
        Wire.endTransmission();    // stop transmitting
      }
      
      
      if(order == '1') 
        SerialAnalyze();
    }
  }
  
  if(protocol == 'h' || protocol == 'H')
    highLevelProtocol();

  robot.update();
}

