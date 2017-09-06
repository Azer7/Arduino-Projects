#include <rh_ask.h>
#include <spi.h> // Not actually used but needed to compile
RH_ASK rf;
const int LED = 13;// indicator pin
const int delayTime = 2000;
void setup()
{
  pinMode(LED,OUTPUT);
      
        RH_ASK::RH_ASK  ( uint16_t  speed = 2000,
        uint8_t   rxPin = 11,
        uint8_t   txPin = 12,
        uint8_t   pttPin = 10,
        bool  pttInverted = true 
        )   
    
    while (!rf.init())
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
char msg[7] = {'h','e','l','l','o',' ','#'};

  msg[6] = count;
  digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
  rf.send((uint8_t *)msg, 7);
  rf.waitPacketSent(); // Wait until the whole message is gone
  digitalWrite(led_pin, LOW);
  delay(1000);
  count = count + 1;
}
