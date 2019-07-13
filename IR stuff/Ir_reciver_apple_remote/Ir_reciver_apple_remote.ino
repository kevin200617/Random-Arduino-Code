#include <IRremote.h>


int IRpin = 8;
IRrecv irrecv(IRpin);
decode_results results;
int led = 12;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(led,OUTPUT);

}

  
void loop() {   
  if (irrecv.decode(&results)) 
    {
     Serial.println(results.value);
      delay(10);
      
      if(results.value== 4294967295

)//apple remote hex code for vol+
      {digitalWrite(led,HIGH);
     irrecv.resume();
     delay(100);}
     else{digitalWrite(led,LOW);
     delay(100);

     
  

    }
}
}   
