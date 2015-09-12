
char readButtons()
{
  if(debounce())
    return 'Z';  //Not enough time passed since last button push
    
  if(A())
    return 'A';
  if(B())
    return 'B';
  if(C())
    return 'C';
  if(D())
    return 'D';

  return 'Z'; //No button press registered 
}

boolean A()
{
  if(!(digitalRead(buttonA)))
    return true;

  return false;      
}

boolean B()
{
  if(!(digitalRead(buttonB)))
    return true;

  return false;      
}
boolean C()
{
  if(!(digitalRead(buttonC)))
    return true;

  return false;      
}

boolean D()
{
  if(!(digitalRead(buttonD)))
    return true;

  return false;      
}

boolean debounce()
{
  static long lastTime;  
  const static int bounceTime=300;
  static boolean newDebounce=true;  

  if(newDebounce)
    {
     lastTime=millis();
     newDebounce=false; 
    }

  if(millis()- lastTime < bounceTime)
    return true;

  else 
  {
    newDebounce=true;
    return false;
  }
}


