// Storage for the raw data
#include <IRremote.h>
unsigned int rawCodes[35];
int codeLen;
int IRPIN = 2;
IRrecv irrecv(IRPIN);
decode_results results;
 
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}
void loop()
{
  if (irrecv.decode(&results))
  { 
    extractRaw(&results);
    
    // Displays the raw codes
    for (int i = 0; i < codeLen; i ++)
    {
      Serial.print(rawCodes[i]);
      Serial.print(", ");
    }
    Serial.println(); 

    irrecv.resume(); // Receive the next value
  }
  delay(5);
}

// Extracts the raw data
void extractRaw (decode_results *results) {
  codeLen = results->rawlen - 1;
  // To store raw codes:
  // Drop first value (gap)
  // Convert from ticks to microseconds
  // Tweak marks shorter, and spaces longer
  // to cancel out IR receiver distortion
  for (int i = 1; i <= codeLen; i++)
    if (i % 2)
      // Mark
      rawCodes[i - 1] = results->rawbuf[i]*USECPERTICK - MARK_EXCESS;
    else
      // Space
      rawCodes[i - 1] = results->rawbuf[i]*USECPERTICK + MARK_EXCESS;
}
