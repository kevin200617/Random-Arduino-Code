// include the library code:
#include <LiquidCrystal.h>
#include <SimpleDHT.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int pinDHT11 = 2;
SimpleDHT11 dht11;


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2); 
  // Print a message to the LCD.
  lcd.print(" Temp. |humidity");
  
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  // read with raw sample data.
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    lcd.print(" Plug in DHT11!");
    return;
  }
  
    
  {
 
  int TempInF = (temperature * 1.8) + 32;
  
  lcd.print(" ");
  lcd.print((int)TempInF); lcd.print(" *F |  ");
  lcd.print((int)humidity); lcd.println("%   ");
  lcd.print("  ");
  // DHT11 sampling rate is 1HZ.
  delay(1000);}
  delay(1000);
  

  

}
