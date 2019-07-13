#define led1 2 //defining Led pins
#define led2 3
#define led3 4
#define led4 5
#define led5 6
#define led6 7
#define led7 8
#define led8 9
 

int readpin = A0;

int leds = 0;

int sensorValue = 0;

int mul = 127;


void setup(){
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  Serial.begin(9600);
 
}
void loop(){
  //Reading the pot
  sensorValue = analogRead(readpin);
  Serial.println(sensorValue);
  Serial.print(" ");

  //reset LEDS to 0
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  
      

   //assigning anolog value from readpin into numbers 1-8 for the SwitchCase below
 if (sensorValue >= 0 && sensorValue < 25){
    digitalWrite(led1, LOW);
  }
  if (sensorValue >= 25 && sensorValue < 127){
      digitalWrite(led1, HIGH);
  }
  if (sensorValue >= 127 && sensorValue < 254){
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
  }
  if (sensorValue >= 254 && sensorValue < 381){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  if (sensorValue >= 381 && sensorValue < 482){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
  if (sensorValue >= 482 && sensorValue < 635){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
  }
  if (sensorValue >= 635 && sensorValue < 762){
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(led4, HIGH);
     digitalWrite(led5, HIGH);
     digitalWrite(led6, HIGH);
  }
  if (sensorValue >= 762 && sensorValue < 889){
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(led4, HIGH);
     digitalWrite(led5, HIGH);
     digitalWrite(led6, HIGH);
     digitalWrite(led7, HIGH);
  }
  if (sensorValue >= 889 && sensorValue <= 1024){
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(led4, HIGH);
     digitalWrite(led5, HIGH);
     digitalWrite(led6, HIGH);
     digitalWrite(led7, HIGH);
     digitalWrite(led8, HIGH);
  }
  delay(50);


 
  
}
