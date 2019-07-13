#include <LiquidCrystal.h>
#include <SimpleDHT.h>
/* Digital Winding Clock - Arduino Clock for beginners   
No RTC, 
Just set it to exact time using the push buttons each time you switch on the clock 
Made by Techno (sǝɹoɟ ǝǝןuuɐ) 
Feel free to modify 
*/
 
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 
int pinDHT11 = 2;
SimpleDHT11 dht11;
int h=8; 
int m=7; 
int s; 
int flag=20; 
int TIME; 
const long interval = 10000;

unsigned long previousMillis = 0;
void setup() 
{ 
 lcd.begin(16,2); 
} 
void loop() 
{ 
unsigned long currentMillis = millis();
lcd.setCursor(0,0); 
s=s+1; 
lcd.print("----- TIME -----");
lcd.setCursor(5,1); 
lcd.print(h); 
lcd.print(":");
if(m <= 9)
{lcd.print("0");
} 
lcd.print(m);  
if(flag<12)lcd.print(" AM        "); 
if(flag==12)lcd.print(" PM        "); 
if(flag>12)lcd.print(" PM        "); 
if(flag==24)flag=0; 
delay(1000); 
lcd.clear(); 
if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
  lcd.clear();
  lcd.print(" Temp. |humidity");
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
  delay(2000);
  lcd.clear();
  s=s+4;
}

if(s==60){ 
 s=0; 
 m=m+1; 
} 
if(m==60) 
{ 
 m=0; 
 h=h+1; 
 flag=flag+1; 
} 
if(h==13) 
{ 
 h=1; 
}


//-------Time 
// setting-------// 

} 

