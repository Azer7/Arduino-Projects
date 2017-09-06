#include <rh_ask.h>
#include <spi.h> // Not actually used but needed to compile
RH_ASK rf;
const int LED = 13;// indicator pin
const int delayTime = 2000;

void setup()
{
//  RH_ASK(2000,11,12,10,false);
  pinMode(LED,OUTPUT);
  if (!rf.init())
  {
  // no RF connected ! or error on initi    
  digitalWrite(LED,1);
  delay(100);
  digitalWrite(LED,0);
  delay(100);          
  }
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
    if (rf.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      
              digitalWrite(led_pin, HIGH); // Flash a light to show received good message
        // Message with a good checksum received, print it.
        Serial.print("Got: ");
        
        for (i = 0; i < buflen; i++)
        {
            Serial.print(buf[i], HEX);
            Serial.print(' ');
        }
        Serial.println();
              digitalWrite(led_pin, LOW);
    }
}
