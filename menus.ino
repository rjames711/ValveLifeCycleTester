
void startMenu()
{
  char letter = 'Z';


  print4Lines("A: Run","B: Manual Control","C: Edit Parameters",""); 

  while(letter=='Z') 
  {
    letter = readButtons();  

    switch(letter)
    {
    case 'A' : 
      runTest(); 
      break;
    case 'B' : 
      manualControl(); 
      break;
    case 'C' : 
      speedMenu(); 
      break;  
    }
  }

  lcd.print("reak");

}


void editParameters()
{
  char button = 'Z';

  print4Lines("A: Change Speed","B: Set time stop","C: Set max Load","D: Reset count");

  while(button=='Z')
    button=readButtons();

  switch(button)
  {
  case 'A':  
    speedMenu(); 
    break;
  case 'B':  
    timeStopMenu(); 
    break;
  case 'C':  
    loadStopMenu(); 
    break;
  case 'D':  
    resetCount(); 
    break;

  }   


}

void timeStopMenu()
{
char button;


while(buttons!='B');
{
button=readButtons();

if(button=='B')
    timeStop+=1000;
}



}

void timestopActive()
{
  stopMotor();
  
  char button;

  print4Lines("Error: Did not reach","endstop within time","limit. Check setup","Press any button");

  do
    button=readButtons();
  while(button=='Z');    
  
}

void resetCount()
{
}

void loadStopMenu()
{
}



void runMenu()
{  
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("Count: ");
  lcd.print(count);
  lcd.setCursor(0,1);
  lcd.print("Right Force: ");
  lcd.setCursor(1,2);
  lcd.print("Left Force: ");
}

void speedMenu()
{
  char letter=NULL;
  print4Lines("A: Increase speed","D: Decrease speed","B: Main Menu","Speed: "); 

  while(letter!='B')
  {
    letter=readButtons();

    if(letter=='A')
      motorSpeed+=10;

    if(letter=='D')
      motorSpeed-=10;

    lcd.setCursor(8,3);
    if(motorSpeed<100)
      lcd.print(0);
    lcd.print(motorSpeed);  

  }


}


void print4Lines(String line1,String line2,String line3,String line4 )
{
  String lines[4]={
    line1,line2,line3,line4          };

  lcd.clear();

  for(int i=0;i<4;i++)
  {
    lcd.setCursor(0,i);
    lcd.print(lines[i]);
  }

}


