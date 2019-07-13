#include <LiquidCrystal.h>

/* Digital Winding Clock - Arduino Clock for beginners   
No RTC, 
Just set it to exact time using the push buttons each time you switch on the clock 
Made by Techno (sǝɹoɟ ǝǝןuuɐ) 
Feel free to modify 
8=3
9=4
*/
 
LiquidCrystal 
lcd(7, 8, 9, 10, 11, 12); 
int h=17; 
int m=30; 
int s; 
int flag; 
int TIME; 
 
void setup() 
{ 
 lcd.begin(16,2); 
} 
void loop() 
{ 
lcd.setCursor(0,0); 
s=s+1; 
lcd.print("TIME  "); 
lcd.print(h); 
lcd.print(":"); 
lcd.print(m);  
if(flag<12)lcd.print(" AM"); 
if(flag==12)lcd.print(" PM"); 
if(flag>12)lcd.print(" PM"); 
if(flag==24)flag=0; 
delay(1000); 
lcd.clear(); 
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
lcd.setCursor(0,1); 
lcd.print("HAVE A NICE DAY"); 
//-------Time 
// setting-------// 

} 

