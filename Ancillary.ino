


void runTest()
{
  char button='Z';
  
  runMenu();
  
  while(button=='Z') 
  {
    button = readButtons();

    if(!(digitalRead(magSensor1))&&!(digitalRead(magSensor2)))
      Serial.println("error both endstop sensor active");

    if(!digitalRead(magSensor1))
      motorDirection=magSensor1;

    if(!digitalRead(magSensor2))
      motorDirection=magSensor2;

    if(oldMotorDirection!=motorDirection)
      MotorReverse();  
  }
   
   motorStop
   
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
  
  print4Lines("B: Clockwise","C: Counterclockwise","D: Main menu","");
  
  stopMotor();
  
  delay(100); 

  while(!D())
  {
    while(B())
    {
      digitalWrite(motorReverse,LOW);
      analogWrite(motorForward,motorSpeed);
 
}

    while(C())
    {
      digitalWrite(motorForward,LOW);
      analogWrite(motorReverse,motorSpeed);
    
    }
  stopMotor(); 
 
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


