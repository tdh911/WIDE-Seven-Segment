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

void setup() {
  // put your setup code here, to run once:

  for(int i = 0; i<14; i++)
    pinMode(i,OUTPUT);
  // set all pins to out

// array of pins for each digit

  for(int i = 0; i<7; i++){
    ones[i] = i;
    tens[i] = i+7;
  }
 

}

void loop() {
  // put your main code here, to run repeatedly:
 
}
void evaluate(int input){
  int digone = input%10;
  int digten = input/10;
  if(digone==0)
    zero(ones);
  else if(digone==1)
    one(ones);
  else if(digone==2)
    two(ones);
  else if(digone==3)
    three(ones);
  else if(digone==4)
    four(ones);
  else if(digone==5)
    five(ones);
  else if(digone==6)
    six(ones);
  else if(digone==7)
    seven(ones);
  else if(digone==8)
    eight(ones);
  else
    nine(ones);
// displays ones value on sev seg

  if(digten==0)
    zero(tens);
  else if(digten==1)
    one(tens);
  else if(digten==2)
    two(tens);
  else if(digten==3)
    three(tens);
  else if(digten==4)
    four(tens);
  else if(digten==5)
    five(tens);
  else if(digten==6)
    six(tens);
  else if(digten==7)
    seven(tens);
  else if(digten==8)
    eight(tens);
  else
    nine(tens);
// displays tens value on sev seg
  return;
}
void reset(int pin[7]){
  for(int i = 0; i<7; i++)
    digitalWrite(pin[i],LOW); //clear all the segments of that digit
   return;
}
// displays 0
void zero(int pin[7]){
  reset(&pin[7]);
  digitalWrite(pin[TOP],HIGH);
  digitalWrite(pin[TR],HIGH);
  digitalWrite(pin[TL],HIGH);
  digitalWrite(pin[BL],HIGH);
  digitalWrite(pin[BR],HIGH);
  digitalWrite(pin[BOT],HIGH);
  return;
}
// displays 1
void one(int pin[7]){
  reset(&pin[7]);
  digitalWrite(pin[TR],HIGH);
  digitalWrite(pin[BR],HIGH);
  return;
}
// displays 2
void two(int pin[7]){
  reset(&pin[7]);
  digitalWrite(pin[TOP],HIGH);
  digitalWrite(pin[TR],HIGH);
  digitalWrite(pin[MID],HIGH);
  digitalWrite(pin[BL],HIGH);
  digitalWrite(pin[BOT],HIGH);
  return;
}
// displays 3
void three(int pin[7]){
  reset(&pin[7]);
  digitalWrite(pin[TOP],HIGH);
  digitalWrite(pin[TR],HIGH);
  digitalWrite(pin[BR],HIGH);
  digitalWrite(pin[MID],HIGH);
  digitalWrite(pin[BOT],HIGH);
  return;
}
// displays 4
void four(int pin[7]){
  reset(&pin[7]);
  digitalWrite(pin[TL],HIGH);
  digitalWrite(pin[TR],HIGH);
  digitalWrite(pin[MID],HIGH);
  digitalWrite(pin[BR],HIGH);
  return;
}
// displays 5
void five(int pin[7]){
  reset(&pin[7]);
  digitalWrite(pin[TOP],HIGH);
  digitalWrite(pin[TL],HIGH);
  digitalWrite(pin[MID],HIGH);
  digitalWrite(pin[BR],HIGH);
  digitalWrite(pin[BOT],HIGH);
  return;
}
void six(int pin[7]){
  reset(&pin[7]);
  digitalWrite(pin[TOP],HIGH);
  digitalWrite(pin[TL],HIGH);
  digitalWrite(pin[MID],HIGH);
  digitalWrite(pin[BL],HIGH);
  digitalWrite(pin[BR],HIGH);
  digitalWrite(pin[BOT],HIGH);
  return;
}
void seven(int pin[7]){
  reset(&pin[7]);
  digitalWrite(pin[TOP],HIGH);
  digitalWrite(pin[TR],HIGH);
  digitalWrite(pin[BR],HIGH);
  return;
}
void eight(int pin[7]){
  reset(&pin[7]);
  for(int i = 0; i < 7; i++)
    digitalWrite(pin[i],HIGH);
   return;
}
void nine(int pin[7]){
  reset(&pin[7]);
  digitalWrite(pin[TOP],HIGH);
  digitalWrite(pin[TL],HIGH);
  digitalWrite(pin[TR],HIGH);
  digitalWrite(pin[MID],HIGH);
  digitalWrite(pin[BR],HIGH);
  digitalWrite(pin[BOT],HIGH);
  return;
}



