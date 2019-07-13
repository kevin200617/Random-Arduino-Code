 int led1 = 2;
 int led2 = 3;
 int led3 = 4;
 int led4 = 5;
 int led5 = 6;
 int led6 = 7;
 
 #include "IRremote.h"

int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

  
  void translateIR()
  {
    switch(results.value)
    {
  case 0xFF30CF: digitalWrite(led1, HIGH);    break;
  case 0xFF18E7: digitalWrite(led2, HIGH);    break;
  case 0xFF7A85: digitalWrite(led3, HIGH);    break;
  case 0xFF10EF: digitalWrite(led4, HIGH);    break;
  case 0xFF38C7: digitalWrite(led5, HIGH);    break;
  case 0xFF5AA5: digitalWrite(led6, HIGH);    break;
  case 0xFFA25D: 
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW);  
  digitalWrite(led3, LOW); 
  digitalWrite(led4, LOW); 
  digitalWrite(led5, LOW); 
  digitalWrite(led6, LOW);     break;

  }
  
  delay(1); // Do not get immediate repeat
  }
 void setup()   /*----( SETUP: RUNS ONCE )----*/
{
   
  irrecv.enableIRIn(); // Start the receiver

}
  void loop()  
{
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  
}/* --(end main loop )-- */

