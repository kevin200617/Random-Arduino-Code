// define pin numbers
int factor#1 = 5;
int factor#2 = 6;
// runs once at the beginning
void setup() {
    // set pins to output
    pinMode(5, OUTPUT);
    pinMode (6, OUTPUT);
    pinMode (3, OUTPUT);
}

// runs over and over
void loop() 
{
    // turn on both LEDs
    digitalWrite(ledPin1, HIGH);
    delay(5000);
    digitalWrite (ledPin2, HIGH);
    delay(2000);
    // turn off both LEDs
    digitalWrite(ledPin1, LOW);
    digitalWrite (ledPin2, LOW);  
    delay(1000);
}
