#define NOFIELD 505L    // Analog output with no applied field, calibrate this
#include <Time.h>

//This code calculates the number of seconds between two passings of the magnet
// Uncomment one of the lines below according to device in use A1301 or A1302
// This is used to convert the analog voltage reading to milliGauss
// For A1301: 2.5mV = 1Gauss, and 1024 analog steps = 5V, so 1 step = 1953mG
// For A1302: 1.3mV = 1Gauss, and 1024 analog steps = 5V, so 1 step = 3756mG
#define THRESHOLD 500
#define TOMILLIGAUSS 1.953125
// #define TOMILLIGAUSS 3.756010  
int count = 0;
int timecount = 0;
 int betweentwo = 0; //looks for when two highs have been calculated
int lastRead = 0;
time_t t;
void setup() 
{
  Serial.begin(9600);
  t = minute(t);
}

void loop() 
{
    time_t now = minute(t);
  int reading = (analogRead(0));
  if(reading > THRESHOLD && lastRead < THRESHOLD){
	count++;
    }
    lastRead = reading;
    if(now != t){
	Serial.print(count);
	count = 0;
	t = minute(t);
    }
      /*
  Serial.println("reading");
  while (reading > 500) {
      reading = (analogRead(0));
        //  delay(500);
          //Serial.println("a");
          if(betweentwo == 1){
           timecount++;
          delay(10);
          }
  }
    while (reading <= 500) {
      reading = (analogRead(0));
        //Serial.println("b");
                 // delay(500);
           // timecount++;
            //delay(10);
    }
   betweentwo++;
   count++;
   if(betweentwo == 2){
   Serial.println(timecount/100);
   timecount = 0;
   betweentwo = 0;
   }
  
 //Serial.println(count);
  delay(10);*/
}
