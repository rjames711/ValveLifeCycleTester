void MotorReverse()
{
  
  if(motorSwitch)
    {
    analogWrite(motorReverse,0);
     analogWrite(motorForward,50);
    } 
    
   else
     {
       analogWrite(motorForward,0);
       analogWrite(motorReverse,50);
     } 
     
   motorSwitch=!motorSwitch;

  delay(50);
     cycle=!cycle;
    oldMotorDirection=motorDirection;
    if(cycle)
    {
      count++;
      EEPROMWritelong(0,count);
      //      Serial.print("Count: ");
      //      Serial.println(count);
      lcd.setCursor(20, 0);
      lcd.print("Count: ");
      lcd.print(count);


    }
  
  
}


void manualControl()
{
  Serial.println("entering manual control");
  digitalWrite(motorForward,LOW);
  digitalWrite(motorReverse,LOW);
  delay(debounce);
  
    while(digitalRead(stopReset))
    {
      while(!digitalRead(manualForward))
      {
        digitalWrite(motorReverse,LOW);
        digitalWrite(motorForward,HIGH);
       
      }
      
      while(!digitalRead(manualReverse))
      {
        digitalWrite(motorForward,LOW);
        digitalWrite(motorReverse,HIGH);
      }
      digitalWrite(motorForward,LOW);
      digitalWrite(motorReverse,LOW);  
      
    }


  digitalWrite(motorForward,LOW);
  digitalWrite(motorReverse,LOW);
  Serial.println("leaving manual control");
    delay(debounce);
}

