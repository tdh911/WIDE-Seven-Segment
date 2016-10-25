#define TOP 0
#define TR 1
#define TL 2
#define MID 3
#define BL 4
#define BR 5
#define BOT 6

/*TOP @ pins 0 and 7
  TR @ pins 1 and 8
  TL @ pins 2 and 9
  MID @ pins 3 and 10
  BL @ pins 4 and 11
  BR @ pins 5 and 12
  BOT @ pins 6 and 13
*/
static int tens[7];
static int ones[7];

//This code also calculates RPM
#define NOFIELD 505L    // Analog output with no applied field, calibrate this

//This code calculates the number of seconds between two passings of the magnet
// Uncomment one of the lines below according to device in use A1301 or A1302
// This is used to convert the analog voltage reading to milliGauss
// For A1301: 2.5mV = 1Gauss, and 1024 analog steps = 5V, so 1 step = 1953mG
// For A1302: 1.3mV = 1Gauss, and 1024 analog steps = 5V, so 1 step = 3756mG

#define TOMILLIGAUSS 1.953125
// #define TOMILLIGAUSS 3.756010
int count = 0;
int timecount = 0;
int betweentwo = 0; //looks for when two highs have been calculated

void setup() {
  // put your setup code here, to run once:

  for (int i = 0; i < 14; i++)
    pinMode(i, OUTPUT);
  // set all pins to out

  pinMode(A0,INPUT);

  // array of pins for each digit

  for (int i = 0; i < 7; i++) {
    //ones[i] = i;
    ones[i] = i + 7;
  }
  for(int i = 7; i<14; i++)
  digitalWrite(i,HIGH);
  Serial.begin(9600);

}

void loop() {
  int reading = analogRead(0);
  while (reading > 500) {
      reading = (analogRead(0));
        //  delay(500);
          //Serial.println("a");
           timecount++;
          delay(2);
        if(timecount >= 3000){
         evaluate(count);
         Serial.println(count);
          count = 0;
          timecount = 0;
        }
  }
    while (reading <= 500) {
      reading = (analogRead(0));
        //Serial.println("b");
                 // delay(500);
           timecount++;
           delay(2);
       if(timecount >= 1500){
        evaluate(count);
        Serial.println(count);
        count = 0;
        timecount = 0;
       }
    }
    //When program reaches here, have an LED blink
   count++;
   if(timecount >= 3000){
   evaluate(count);
   Serial.println(count);
   count = 0;
   timecount = 0;
   }
}
void evaluate(int input) {
  if(input>9)
    input = 9;
  int digone = input;
  //int digten = input / 10;
  if (input > 99) {
    eight(ones);
    eight(tens);
  }
  if (digone == 0)
    zero(ones);
  else if (digone == 1)
    one(ones);
  else if (digone == 2)
    two(ones);
  else if (digone == 3)
    three(ones);
  else if (digone == 4)
    four(ones);
  else if (digone == 5)
    five(ones);
  else if (digone == 6)
    six(ones);
  else if (digone == 7)
    seven(ones);
  else if (digone == 8)
    eight(ones);
  else
    nine(ones);
  // displays ones value on sev seg
/*
  if (digten == 0)
    zero(tens);
  else if (digten == 1)
    one(tens);
  else if (digten == 2)
    two(tens);
  else if (digten == 3)
    three(tens);
  else if (digten == 4)
    four(tens);
  else if (digten == 5)
    five(tens);
  else if (digten == 6)
    six(tens);
  else if (digten == 7)
    seven(tens);
  else if (digten == 8)
    eight(tens);
  else
    nine(tens);*/
  // displays tens value on sev seg
  return;
}
void reset(int pin[7]) {
  for (int i = 0; i < 7; i++)
    digitalWrite(i+7, HIGH); //clear all the segments of that digit
  return;
}
// displays 0
void zero(int pin[7]) {
  reset(&pin[7]);
  digitalWrite(pin[TOP], LOW);
  digitalWrite(pin[TR], LOW);
  digitalWrite(pin[TL], LOW);
  digitalWrite(pin[BL], LOW);
  digitalWrite(pin[BR], LOW);
  digitalWrite(pin[BOT], LOW);
  return;
}
// displays 1
void one(int pin[7]) {
  reset(&pin[7]);
  digitalWrite(pin[TR], LOW);
  digitalWrite(pin[BR], LOW);
  return;
}
// displays 2
void two(int pin[7]) {
  reset(&pin[7]);
  digitalWrite(pin[TOP], LOW);
  digitalWrite(pin[TR], LOW);
  digitalWrite(pin[MID], LOW);
  digitalWrite(pin[BL], LOW);
  digitalWrite(pin[BOT], LOW);
  return;
}
// displays 3
void three(int pin[7]) {
  reset(&pin[7]);
  digitalWrite(pin[TOP], LOW);
  digitalWrite(pin[TR], LOW);
  digitalWrite(pin[BR], LOW);
  digitalWrite(pin[MID], LOW);
  digitalWrite(pin[BOT], LOW);
  return;
}
// displays 4
void four(int pin[7]) {
  reset(&pin[7]);
  digitalWrite(pin[TL], LOW);
  digitalWrite(pin[TR], LOW);
  digitalWrite(pin[MID], LOW);
  digitalWrite(pin[BR], LOW);
  return;
}
// displays 5
void five(int pin[7]) {
  reset(&pin[7]);
  digitalWrite(pin[TOP], LOW);
  digitalWrite(pin[TL], LOW);
  digitalWrite(pin[MID], LOW);
  digitalWrite(pin[BR], LOW);
  digitalWrite(pin[BOT], LOW);
  return;
}
void six(int pin[7]) {
  reset(&pin[7]);
  digitalWrite(pin[TOP], LOW);
  digitalWrite(pin[TL], LOW);
  digitalWrite(pin[MID], LOW);
  digitalWrite(pin[BL], LOW);
  digitalWrite(pin[BR], LOW);
  digitalWrite(pin[BOT], LOW);
  return;
}
void seven(int pin[7]) {
  reset(&pin[7]);
  digitalWrite(pin[TOP], LOW);
  digitalWrite(pin[TR], LOW);
  digitalWrite(pin[BR], LOW);
  return;
}
void eight(int pin[7]) {
  reset(&pin[7]);
  for (int i = 0; i < 7; i++)
    digitalWrite(pin[i], LOW);
  return;
}
void nine(int pin[7]) {
  reset(&pin[7]);
  digitalWrite(pin[TOP], LOW);
  digitalWrite(pin[TL], LOW);
  digitalWrite(pin[TR], LOW);
  digitalWrite(pin[MID], LOW);
  digitalWrite(pin[BR], LOW);
  digitalWrite(pin[BOT], LOW);
  return;
}



