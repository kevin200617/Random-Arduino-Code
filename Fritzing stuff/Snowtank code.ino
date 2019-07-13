#define Right 2 // Button
#define Left 3 // Button
#define Forward 4 // Button
#define Backward 5 // Button
// Right motor
#define ENABLE1 6 
#define DIRA1 7
#define DIRB1 8
//Left Motor
#define ENABLE2 6
#define DIRA2 7
#define DIRB2 8

#define F_Leds 10 //Front Leds, controlled with a transiter
#define B_Leds 11 // back Leds, controlled with a transiter
void setup() {
for(int i = 0; i<6; i++){
digitalWrite(F_Leds, HIGH);
digitalWrite(B_Leds, HIGH);
delay(500);
digitalWrite(F_Leds, LOW);
digitalWrite(B_Leds, LOW);
delay(500);
}
pinMode(F_Leds,OUTPUT);
pinMode(B_Leds,OUTPUT);
pinMode(ENABLE1,OUTPUT);
pinMode(DIRA1,OUTPUT);
pinMode(DIRB1,OUTPUT);
pinMode(ENABLE2,OUTPUT);
pinMode(DIRA2,OUTPUT);
pinMode(DIRB2,OUTPUT);
pinMode(Right, INPUT);
pinMode(Left, INPUT);
pinMode(Forward, INPUT);
pinMode(Backward, INPUT);
}

void loop() {
  digitalRead(Left);
  digitalRead(Right);
  digitalRead(Forward);
  digitalRead(Backward);
  delay(5);
while (Left == HIGH){
  digitalWrite(DIRA1,LOW);
  digitalWrite(DIRB1,HIGH);
  digitalWrite(DIRA2,HIGH); 
  digitalWrite(DIRB2,LOW);
  delay(5);
}
while (Right == HIGH){
  digitalWrite(DIRA1,HIGH);
  digitalWrite(DIRB1,LOW);
  digitalWrite(DIRA2,LOW); 
  digitalWrite(DIRB2,HIGH);
  delay(5);
}
while (Forward == HIGH){
  digitalWrite(DIRA1,HIGH);
  digitalWrite(DIRB1,LOW);
  digitalWrite(DIRA2,HIGH); 
  digitalWrite(DIRB2,LOW);
  delay(5);
}
while (Backward == HIGH){
  digitalWrite(DIRA1,LOW);
  digitalWrite(DIRB1,HIGH);
  digitalWrite(DIRA2,LOW); 
  digitalWrite(DIRB2,HIGH);
  delay(5);
}

}