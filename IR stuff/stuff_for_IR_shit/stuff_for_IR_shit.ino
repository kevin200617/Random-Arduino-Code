#include "IRremote.h"
int receiver = 5;
int latchPin = 11;      // (11) ST_CP [RCK] on 74HC595
int clockPin = 9;      // (9) SH_CP [SCK] on 74HC595
int dataPin = 12;
byte leds = 0;// (12) DS [S1] on 74HC595

IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;   

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
void translateIR() // takes action based on IR code received
{

  switch(results.value)

  case 0xFF629D: for (int i = 0; i < 8; i++); break;
  case 0xFFA857: for (int i = 0; i > -1; i--);    break;
}
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

  

  void loop() {
{
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  
}
  leds = 0;
  updateShiftRegister();
  delay(tDelay);
 
  {
    bitSet(leds, i);
    updateShiftRegister();
    leds = 0;
    delay(tDelay);
  }
   
  {
    bitSet(leds, i);
    updateShiftRegister();
    leds = 0;
    delay(tDelay);
    
}
}

