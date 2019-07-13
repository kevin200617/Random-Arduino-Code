const int timeLength = 45000; // this is how long th timer will last
const int buzzer = 12;//the pin of the active buzzer
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output
  Serial.begin(9600);
}

void loop(){ 
  { unsigned char i;
  // put your main code here, to run repeatedly:
unsigned long currentMillis = millis();
  if (currentMillis >= timeLength)  
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
 
  Serial.println(((millis()- timeLength)*-1)/1000);

}
