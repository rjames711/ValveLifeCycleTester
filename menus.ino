void mainMenu()
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
  print4Lines("A: Increase speed","B: Decrease speed","","Speed: "); 
  while(!digitalRead(buttonA))
  {
    
    
  }
  
}



void print4Lines(String line1,String line2,String line3,String line4 )
{
  String lines[]={line1,line2,line3,line4};
  
   for(int i=0;i<(sizeof(lines)/sizeof(int));i++)
    {
      lcd.setCursor(0,i);
      lcd.print(lines[i]);
    }
  
}
