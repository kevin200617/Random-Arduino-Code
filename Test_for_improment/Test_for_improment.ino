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
int h=1; 
int m=0; 
int s; 
int flag=1; 
int TIME; 
int pinSet = 3;
int pinHour= 5;
int pinMin = 4;
boolean set = 0;
boolean Hour = 0;
boolean Min = 0;
const long interval = 10000;

unsigned long previousMillis = 0;
void setup() 
{ 
 lcd.begin(16,2); 
 pinMode(pinSet, INPUT);
 pinMode(pinHour, INPUT);
 pinMode(pinMin, INPUT);
} 
void loop() 
{ 
   set = digitalRead(pinSet);
   Hour = digitalRead(pinHour);
   Min = digitalRead(pinMin);
   delay(125);
   s=s+.125;
  if(set == HIGH)
  {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("-TIME--SETTINGS-");
  lcd.setCursor(1,1);
  lcd.print(h);
  lcd.print(":");
  if(m <= 9)
{lcd.print("0");
} 
  lcd.print(m);

  if( Hour == HIGH)
  {h = h +1;
  }
  if(Min == HIGH)
  { m = m +1;
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("-TIME--SETTINGS-");
  lcd.setCursor(1,1);
  lcd.print(h);
  lcd.print(":");
  if(m <= 9)
{lcd.print("0");
} 
  lcd.print(m);
  }
if(s>=60){
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
}


//-------Time 
// setting-------// 

 

