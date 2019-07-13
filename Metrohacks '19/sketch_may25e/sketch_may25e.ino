#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
 #include "ESP8266WiFi.h"
#define VIN A0 // define the Arduino pin A0 as voltage input (V in)
const float VCC   = 3.3;// supply voltage is from 4.5 to 5.5V. Normally 5V.
const int model = 1;   // enter the model number (see below)
float avgcurrent;
float newabscurrent;
int t1; // timer 1
int t2; // timer 2
float current;
float cutOffLimit = 0;// set the current which below that value, doesn't matter. Or set 0.5
float gt = 1;

float sensitivity[] ={
          0.185,// for ACS712ELCTR-05B-T
          0.100,// for ACS712ELCTR-20A-T
          0.066// for ACS712ELCTR-30A-T
     
         }; 
const float QOV =   VCC/2;// half the voltage (due to current sensor)
float voltage;// internal variable for voltage
void setup() {
 
  Serial.begin(115200);                                  //Serial connection
  WiFi.begin("Kevin's WiFi", "cnpku123");   //WiFi connection
 
  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
 
    delay(500);
    Serial.println("Waiting for connection");
 
  }
 
}
 
void loop() {
 
 if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
 
   HTTPClient http;    //Declare object of class HTTPClient
 
   http.begin("http://192.168.137.70:5849/report-powerstrip");      //Specify request destination
   http.addHeader("Content-Type", "text/plain");  //Specify content-type header
 
   int httpCode = http.POST("Message from ESP8266");   //Send the request
   String payload = http.getString();                  //Get the response payload
 
   Serial.println(httpCode);   //Print HTTP return code
   Serial.println(payload);    //Print request response payload
 
   http.end();  //Close connection
 
 }else{
 
    Serial.println("Error in WiFi connection");   
 
 }
 
  delay(30000);  //Send a request every 30 seconds
 
}
