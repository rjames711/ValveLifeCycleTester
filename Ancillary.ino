void MotorReverse()
{
  
  if(motorSwitch)
    {
     digitalWrite(motorReverse,LOW);
     digitalWrite(motorForward,HIGH);
    } 
    
   else
     {
       digitalWrite(motorForward,LOW);
       digitalWrite(motorReverse,HIGH);
     } 
     
   motorSwitch=!motorSwitch;

  delay(50);
}


void manualControl()
{
  Serial.println("entering manual control");
  digitalWrite(motorForward,LOW);
  digitalWrite(motorReverse,LOW);
  delay(debounce);
  
    while(!digitalRead(stopReset))
    {
      while(digitalRead(manualForward))
      {
        digitalWrite(motorReverse,LOW);
        digitalWrite(motorForward,HIGH);
       
      }
      
      while(digitalRead(manualReverse))
      {
        digitalWrite(motorForward,LOW);
        digitalWrite(motorReverse,HIGH);
      }
      digitalWrite(motorForward,LOW);
      digitalWrite(motorReverse,LOW);  
      
    }

  delay(debounce);
  digitalWrite(motorForward,LOW);
  digitalWrite(motorReverse,LOW);
  Serial.println("leaving manual control");
}

