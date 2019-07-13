//Moter setup for moter one 
#define ENABLE1 5 
#define DIRA1 3 //Direction A1
#define DIRB1 4 //Direction B1

//Moter setup for moter two
#define ENABLE2 8
#define DIRA2 6 //Direction B2
#define DIRB2 7 //Direction A2

#define input 9 //Where we get 
void setup() {
  //Moter one
  pinMode(ENABLE1,OUTPUT);
  pinMode(DIRA1,OUTPUT);
  pinMode(DIRB1,OUTPUT);
  //Moter two
  pinMode(ENABLE2,OUTPUT);
  pinMode(DIRA2,OUTPUT);
  pinMode(DIRB2,OUTPUT);
  Serial.begin(9600);
}
void loop() {
 

}
