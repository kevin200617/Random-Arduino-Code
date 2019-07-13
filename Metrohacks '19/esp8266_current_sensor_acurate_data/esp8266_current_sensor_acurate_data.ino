
 
/*
 * 
 * Arduino Sketch for Allegro ACS712 Current Sensor 
 * this sensor can measure current at range of up to 30A
 * It operates with 5V
 * Please watch video instruction and explanation for this code.
 * 
 * Written by Ahmad Shamshiri on Sunday Jun 17, 2018 at 22:06 at Ajax, Ontario, Canada
 * for Robojax.com
 * View the video instruction at https://youtu.be/DVp9k3xu9IQ
 * This code has been downloaded from Robojax.com
 */
#define VIN A0 // define the Arduino pin A0 as voltage input (V in)
const float VCC   = 3.3;// supply voltage is from 4.5 to 5.5V. Normally 5V.
const int model = 1;   // enter the model number (see below)
float newabscurrent;
int t1; // timer 1
int t2; // timer 2
float current;
float cutOffLimit = 0;// set the current which below that value, doesn't matter. Or set 0.5
float c1;
int n;
float sum;
/*
          "ACS712ELCTR-05B-T",// for model use 0
          "ACS712ELCTR-20A-T",// for model use 1
          "ACS712ELCTR-30A-T"// for model use 2  
sensitivity array is holding the sensitivy of the  ACS712
current sensors. Do not change. All values are from page 5  of data sheet          
*/
float sensitivity[] ={
          0.185,// for ACS712ELCTR-05B-T
          0.100,// for ACS712ELCTR-20A-T
          0.066// for ACS712ELCTR-30A-T
     
         }; 


const float QOV =   VCC/2;// half the voltage (due to current sensor)
float voltage;// internal variable for voltage

void setup() {
    //Robojax.com ACS712 Current Sensor 
    Serial.begin(9600);// initialize serial monitor
    Serial.println("Robojax Tutorial");
    Serial.println("ACS712 Current Sensor");
    
} 

void loop() {
  //Robojax.com ACS712 Current Sensor 
  float voltage_raw =   (VCC/ 1023.0)* analogRead(VIN);// Read the voltage from sensor
  voltage =  voltage_raw - QOV + 0.000 ;// 0.000 is a value to make voltage zero when there is no current
  float raw_current = (voltage / sensitivity[model]); //current that may be posstive or negetive
  float abscurrent = sqrt(raw_current*raw_current); //current that is postive
  
  if (t2 <= 10) {
      if (t1 <= 10){
        if  (newabscurrent < abscurrent){
          newabscurrent = abscurrent;
        }
  
        }
        else { 
          newabscurrent = 0;
          t1 = 0;
          t2++;
          }
          
    if (current < newabscurrent){
      current = newabscurrent;
    }
  }
  else {
    current = newabscurrent;
    t2 = 0;
  }
  sum += current;
  if (n=10){
    float avgcurrent = (sum/2) -.6;
    Serial.print("I: "); 
    Serial.print(avgcurrent,2); // print the current with 2 decimal places
    Serial.println("A");
    n=0;
    sum=0;
  }
  n++;
  t1++;
  delay(100);
}
