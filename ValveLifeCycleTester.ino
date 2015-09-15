#include <EEPROM.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(25,27,29,31,33,35);


////Pin Settings////




byte magSensor1=22;
int magSensor2=23;

int motorForward=4;
int motorReverse=5;

int stopReset=28;
int manualForward=29;
int manualReverse=30;



int buttonA=24;  //White wire
int buttonB=30;  //Green wire
int buttonC=28;  //Pink
int buttonD=32;  //Blue
int buttonGround=26;  // A pin in the button cable connector used as ground (written digital LOW) to pull buttons low when pressed


int load1=8;
int load2=9;


////////////////////////////////////


int count=0;
int motorSpeed=100;
int timeStop=7000;
int maxLoad=7;      



boolean cycle=false;
boolean motorSwitch;
int motorDirection=0;
int oldMotorDirection=0;
int oldTime=0;

void setup()
{
  pinMode(load1,INPUT);
  pinMode(load2,INPUT);

  pinMode(magSensor1,INPUT);
  pinMode(magSensor2,INPUT);


  pinMode(motorForward,OUTPUT);
  pinMode(motorReverse,OUTPUT);

  pinMode(stopReset,INPUT_PULLUP);
  pinMode(manualForward,INPUT_PULLUP);
  pinMode(manualReverse,INPUT_PULLUP);
  pinMode(buttonA,INPUT_PULLUP);
  pinMode(buttonB,INPUT_PULLUP);
  pinMode(buttonC,INPUT_PULLUP);
  pinMode(buttonD,INPUT_PULLUP);
  pinMode(buttonGround,OUTPUT);
  
  digitalWrite(buttonGround, LOW);  //Acts as ground for button cable
  
  
  lcd.begin(20,4);
  
//  delay(debounce); 
  Serial.begin(9600);
  count=EEPROMReadlong(0);
//  mainMenu();



}

char letter='Z';

void loop()
{

  startMenu();
 
// letter=readButtons();
//if(letter!='Z')
//  lcd.print(letter);
//double h=6.3847;
//Serial.println(h);
//delay(100);


}











