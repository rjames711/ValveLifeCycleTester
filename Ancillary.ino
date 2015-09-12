


void runTest()
{
  if(!(digitalRead(buttonA)))
  {
    lcd.print("AAAAAAAAAAAAA");
    Serial.println("A");
  }

  if(!(digitalRead(buttonB)))
  {
    lcd.print("BBBBBBBBBBB");
    Serial.println("B");
  } 

  if(!(digitalRead(buttonC)))
  {
    lcd.print("CCCCCCCCCCC");
    Serial.println("C");
  }

  if(!(digitalRead(buttonD)))
  {
    lcd.print("DDDDDDDDDDD");
    Serial.println("D");
  } 

  if(!(digitalRead(magSensor1))&&!(digitalRead(magSensor2)))
    Serial.println("error both endstop sensor active");

  if(!digitalRead(magSensor1))
    motorDirection=magSensor1;

  if(!digitalRead(magSensor2))
    motorDirection=magSensor2;

  if(digitalRead(resetCount))
    EEPROMWritelong(0,count);

  if(!digitalRead(stopReset))
    manualControl(); 

  if(oldMotorDirection!=motorDirection)
    MotorReverse();  

}



void MotorReverse()
{

  if(motorSwitch)
  {
    analogWrite(motorReverse,0);
    analogWrite(motorForward,motorSpeed);
  } 

  else
  {
    analogWrite(motorForward,0);
    analogWrite(motorReverse,motorSpeed);
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
    lcd.setCursor(6, 0);
    lcd.print("Count: ");
    lcd.print(count);


  }


}


void manualControl()
{
  Serial.println("entering manual control");
  digitalWrite(motorForward,LOW);
  digitalWrite(motorReverse,LOW);
//  delay(debounce);

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
//  delay(debounce);
}


void  stopMotor()
{
    digitalWrite(motorForward,LOW);
    digitalWrite(motorReverse,LOW);
}
    
