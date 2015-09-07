#include <EEPROM.h>


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

int magSensor1=22;
int magSensor2=23;

int motorForward=4;
int motorReverse=5;

int stopReset=28;
int manualForward=29;
int manualReverse=30;

int reset=32;


////////////////////////////////////


int count=0;
int motorSpeed;
int debounce=500;

boolean magSense1;
boolean magSense2;

boolean cycle=false;
boolean motorSwitch;
int motorDirection=0;
int oldMotorDirection=0;


void setup()
{
  pinMode(magSensor1,INPUT);
  pinMode(magSensor2,INPUT);


  pinMode(motorForward,OUTPUT);
  pinMode(motorReverse,OUTPUT);

  pinMode(stopReset,INPUT_PULLUP);
  pinMode(manualForward,INPUT_PULLUP);
  pinMode(manualReverse,INPUT_PULLUP);

  delay(debounce); 
  Serial.begin(9600);
  count=EEPROMReadlong(0);


}

void loop()
{


  magSense1=digitalRead(magSensor1);
  magSense2=digitalRead(magSensor2);

  if(magSense1&&magSense2)
    Serial.println("error both endstop sensor active");

  if(magSense1)
    motorDirection=magSensor1;


  if(magSense2)
    motorDirection=magSensor2;

  if(digitalRead(reset))
  {
    EEPROMWritelong(0,count);
  }

  if(!digitalRead(stopReset))
  {
    manualControl(); 
  }


  if(oldMotorDirection!=motorDirection)
  {



    MotorReverse();
    cycle=!cycle;
    oldMotorDirection=motorDirection;
    if(cycle)
    {
      count++;
      EEPROMWritelong(0,count);
      Serial.print("Count: ");
      Serial.println(count);


    }
  }



}








