#include <RH_ASK.h>
#include <spi.h> // Not actually used but needed to compile
RH_ASK rf;
const int LED = 13;// indicator pin

void setup()
{  

  pinMode(LED,OUTPUT);

        uint16_t  speed = 2000;
        uint8_t   rxPin = 11;
        uint8_t   txPin = 12;
        uint8_t   pttPin = 10;
        bool  pttInverted = true;   

        RH_ASK(speed, rxPin, txPin, pttPin, pttInverted);
    while (!rf.init())
    {
      // no RF connected ! or error on initi
      digitalWrite(LED,1);
      delay(100);
      digitalWrite(LED,0);
      delay(100);      
    }
}

byte count = 1;

void loop()
{
//char msg[7] = {'h','e','l','l','o',' ','#'};

char msg[2] = {'1','#'};
  msg[1] = count;
  digitalWrite(LED, HIGH); // Flash a light to show transmitting
  rf.send((uint8_t *)msg, 2);
  rf.waitPacketSent(); // Wait until the whole message is gone
  digitalWrite(LED, LOW);
  delay(500);
  count = count + 1;

}
