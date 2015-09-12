void runMenu()
{
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
   lcd.print(motorSpeed);  
    
  }


}

void startMenu()
{
  char letter = 'Z';
  
   
  print4Lines("A: Run","B: Manual Control","C: Edit Parameters",""); 
  

  
   
   while(letter=='Z') 
   {
    letter = readButtons();  
    
    switch(letter)
    {
    case 'A' : runMenu(); break;
    case 'B' : manualControl(); break;
    case 'C' : speedMenu(); break;  
    }
   }
    
    lcd.print("reak");
  
  
}


void print4Lines(String line1,String line2,String line3,String line4 )
{
  String lines[4]={
    line1,line2,line3,line4    };

  lcd.clear();
  
  for(int i=0;i<4;i++)
  {
    lcd.setCursor(0,i);
    lcd.print(lines[i]);
  }



}


