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
  digitalWrite(led1, HIGH); 
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  delay(100);
      

   //assigning anolog value from readpin into numbers 1-8 for the SwitchCase below
  if (sensorValue >= 0 && sensorValue < 127){
    leds=1;
  }
  if (sensorValue >= 127 && sensorValue < 254){
    leds = 2;
  }
  if (sensorValue >= 2*mul && sensorValue < 3*mul){
    leds = 3;
  }
  if (sensorValue >= 3*mul && sensorValue < 4*mul){
    leds = 4;
  }
  if (sensorValue >= 4*mul && sensorValue < 5*mul){
    leds = 5;
  }
  if (sensorValue >= 5*mul && sensorValue < 6*mul){
    leds = 6;
  }
  if (sensorValue >= 6*mul && sensorValue < 7*mul){
    leds = 7;
  }
  if (sensorValue >= 7*mul && sensorValue <= 8*mul){
    leds = 8;
  }

//Switch case for turning on LEDS
  switch (leds){
    case 1: 
          digitalWrite(led1, HIGH);
          break;
//-------------------------------------------------------    
    case 2: 
          digitalWrite(led1, HIGH);
          digitalWrite(led2, HIGH);
          break;
//------------------------------------------------------- 
    case 3: 
          digitalWrite(led1, HIGH);
          digitalWrite(led2, HIGH);
          digitalWrite(led3, HIGH);
          break;
//------------------------------------------------------- 
     case 4: 
          digitalWrite(led1, HIGH);
          digitalWrite(led2, HIGH);
          digitalWrite(led3, HIGH);
          digitalWrite(led4, HIGH);
          break;
//-------------------------------------------------------
    case 5: 
          digitalWrite(led1, HIGH);
          digitalWrite(led2, HIGH);
          digitalWrite(led3, HIGH);
          digitalWrite(led4, HIGH);
          digitalWrite(led5, HIGH);
          break;
//-------------------------------------------------------  
    case 6: 
          digitalWrite(led1, HIGH);
          digitalWrite(led2, HIGH);
          digitalWrite(led3, HIGH);
          digitalWrite(led4, HIGH);
          digitalWrite(led5, HIGH);
          digitalWrite(led6, HIGH);
          break;
//-------------------------------------------------------  
     case 7: 
          digitalWrite(led1, HIGH);
          digitalWrite(led2, HIGH);
          digitalWrite(led3, HIGH);
          digitalWrite(led4, HIGH);
          digitalWrite(led5, HIGH);
          digitalWrite(led6, HIGH);
          digitalWrite(led7, HIGH);
          break;
//-------------------------------------------------------  
     case 8: 
          digitalWrite(led1, HIGH);
          digitalWrite(led2, HIGH);
          digitalWrite(led3, HIGH);
          digitalWrite(led4, HIGH);
          digitalWrite(led5, HIGH);
          digitalWrite(led6, HIGH);
          digitalWrite(led7, HIGH);
          digitalWrite(led8, HIGH);
          break;
//-------------------------------------------------------  
  }
 
  
}
