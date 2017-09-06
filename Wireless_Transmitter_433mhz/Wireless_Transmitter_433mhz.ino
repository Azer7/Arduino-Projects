#include <rh_ask.h>
#include <spi.h> // Not actually used but needed to compile
RH_ASK rf;
const int LED = 13;// indicator pin
const int delayTime = 2000;
const char *On_command = "1";
const char *Off_command = "0";
void setup()
{
  pinMode(LED,OUTPUT);
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
 rf.send((uint8_t *)On_command, strlen(On_command));
 rf.waitPacketSent();
 delay(delayTime);
 rf.send((uint8_t *)Off_command, strlen(Off_command));
 rf.waitPacketSent();
 delay(delayTime); 
}
