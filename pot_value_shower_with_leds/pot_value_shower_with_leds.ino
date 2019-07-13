#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define led5 6
#define led6 7
#define led7 8
#define led8 9

int  sensorPin  =  A0;   
int  sensorValue =  0;  
int var = 0;
int sV1 =0;
int sV2 =0;
int sV3 =0;
int sV4 =0;
int sV5 =0;
int sV6 =0;
int sV7 =0;
int sV8 =0;
int sV9 =0;
int sV10 = 0;

int mult = 1250;

int wait = 10;
void setup() {
  // put your setup code here, to run once:
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

void loop() {
  sV1 = analogRead(sensorPin);
  delay(wait);
  sV2 = analogRead(sensorPin);
  delay(wait);
  sV3 = analogRead(sensorPin);
  delay(wait);
  sV4 = analogRead(sensorPin);
  delay(wait);
  sV5 = analogRead(sensorPin);
  delay(wait);
  sV6 = analogRead(sensorPin);
  delay(wait);
  sV7 = analogRead(sensorPin);
  delay(wait);
  sV8 = analogRead(sensorPin);
  delay(wait);
  sV9 = analogRead(sensorPin);
  delay(wait);
  sV10 = analogRead(sensorPin);
  delay(wait);
   sensorValue = (sV10 + sV9 + sV8 + sV7 + sV6 + sV5 + sV4 + sV3 + sV2 + sV1)/10000;
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
        digitalWrite(led6, LOW);
        digitalWrite(led7, LOW);
        digitalWrite(led8, LOW);
        // (1-8)* (MULTPLYER= (10k/8))
        Serial.println(sensorValue);
        Serial.print(" ");
  if (sensorValue >= 0 && sensorValue < 127){
    digitalWrite(led1, HIGH);}
   if (sensorValue >= 127 && sensorValue < 254){
   digitalWrite(led2, HIGH);
   digitalWrite(led1, HIGH);}
   if (sensorValue >= 20000 && sensorValue < 30000){
   digitalWrite(led2, HIGH);
   digitalWrite(led1, HIGH);
   digitalWrite(led3, HIGH);}
   if (sensorValue >= 30000 && sensorValue < 40000){
   digitalWrite(led2, HIGH);
   digitalWrite(led1, HIGH);
   digitalWrite(led3, HIGH);
   digitalWrite(led4, HIGH);}
   if (sensorValue >= 40000 && sensorValue < 50000){
   digitalWrite(led2, HIGH);
   digitalWrite(led1, HIGH);
   digitalWrite(led3, HIGH);
   digitalWrite(led4, HIGH);
   digitalWrite(led5, HIGH);}
   if (sensorValue >= 60000 && sensorValue < 70000){
   digitalWrite(led2, HIGH);
   digitalWrite(led1, HIGH);
   digitalWrite(led3, HIGH);
   digitalWrite(led4, HIGH);
   digitalWrite(led5, HIGH);
   digitalWrite(led6, HIGH);}
   if (sensorValue >= 12 && sensorValue < 14){
   digitalWrite(led2, HIGH);
   digitalWrite(led1, HIGH);
   digitalWrite(led3, HIGH);
   digitalWrite(led4, HIGH);
   digitalWrite(led5, HIGH);
   digitalWrite(led6, HIGH);
   digitalWrite(led7, HIGH);}
   if (sensorValue >= 14){
   digitalWrite(led2, HIGH);
   digitalWrite(led1, HIGH);
   digitalWrite(led3, HIGH);
   digitalWrite(led4, HIGH);
   digitalWrite(led5, HIGH);
   digitalWrite(led6, HIGH);
   digitalWrite(led7, HIGH);
   digitalWrite(led8, HIGH);}
  Serial.println(sensorValue);
    
        
      
  }
        
        
  
  
  
  
