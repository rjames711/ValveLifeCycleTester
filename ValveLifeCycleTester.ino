#include <EEPROM.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(42,43,44,45,46,47);

////Pin Settings for arduino Uno////
//int magSensor1=2;
//int magSensor2=3;
//
//int motorForward=4;
//int motorReverse=5;
//
//int stopReset=8;
//int manualForward=9;
//int manualReverse=10;
//int reset=12;

////Pin Settings for arduino Mega////




byte magSensor1=22;
int magSensor2=23;

int motorForward=4;
int motorReverse=5;

int stopReset=28;
int manualForward=29;
int manualReverse=30;

int resetCount=32;

int buttonA=33;
int buttonB=34;
int buttonC=35;
int buttonD=36;


int load1=8;
int load2=9;


////////////////////////////////////


int count=0;
int motorSpeed;
int debounce=500;


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
  
  lcd.begin(20,4);
  
  delay(debounce); 
  Serial.begin(9600);
  count=EEPROMReadlong(0);
  mainMenu();



}

void loop()
{

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











