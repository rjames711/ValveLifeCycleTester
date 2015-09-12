#include <Hx711.h>
Hx711 scale(A8, A9);


byte cal1, cal2;
double b;
double rise;
double run;
double slope;
int y1,y2;
long x1,x2;



void calibrate1()
{
  Serial.println("hit cal button");
  while(!digitalRead(cal1));
  Serial.println("calibrate point 1");
  y1=0;
  x1=scale.getValue();


  while(!digitalRead(cal2));
  Serial.println("calibrate point 2");
  y2=452;
  x2=scale.getValue();

  rise=y2-y1;
  run=x2-x1;

  slope= rise/run;

  b=y1-slope*x1;

  Serial.println(rise);
  Serial.println(run);
  Serial.println(slope);

}

double getForce(long rawVal)
{
  return (slope*rawVal+b); 
}

