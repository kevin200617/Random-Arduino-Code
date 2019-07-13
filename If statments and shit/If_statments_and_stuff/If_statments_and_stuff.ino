int buzzer = 12;//the pin of the active buzzer
void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(5, INPUT_PULLUP);
  pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output
}

void loop() {unsigned char i;
  // put your main code here, to run repeatedly:
  if (digitalRead(5) == LOW)  
 {
   //output an frequency
   for(i=0;i<80;i++)
   {
    digitalWrite(buzzer,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer,LOW);
    delay(1);//wait for 1ms
    }
    //output another frequency
     for(i=0;i<100;i++)
      {
        digitalWrite(buzzer,HIGH);
        delay(2);//wait for 2ms
        digitalWrite(buzzer,LOW);
        delay(2);//wait for 2ms
      }
  }
}
