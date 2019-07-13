
int on = 255;    
int off = 0; 
int T = 50000;
void setup() {
  pinMode(9,OUTPUT);  
}

void loop() {
    analogWrite(9,on);              
    delay(T);                       
    analogWrite(9,off);             
    delay(T);                      
}
