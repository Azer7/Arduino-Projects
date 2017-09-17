#include <RH_ASK.h>
#include <spi.h> // Not actually used but needed to compile

RH_ASK rf;
const int LED = 13;// indicator pin
const int delayTime = 2000;
const int RECEIVE = A5;

void setup()
{
  Serial.begin(9600);
  pinMode(11, INPUT);
  
  pinMode(LED,OUTPUT);
        uint16_t  speed = 2000;
        uint8_t   rxPin = 11;
        uint8_t   txPin = 12;
        uint8_t   pttPin = 10;
        bool  pttInverted = true;   

        RH_ASK(speed, rxPin, txPin, pttPin, pttInverted);

  if (!rf.init())
  {
  // no RF connected ! or error on initi    
  digitalW rite(LED,1);
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
      
              digitalWrite(LED, HIGH); // Flash a light to show received good message
        // Message with a good checksum received, print it.
        Serial.print("Got: ");
        
        for (i = 0; i < buflen; i++)
        {
          if(i != buflen - 1)
            Serial.print((char)buf[i]);
         else
            Serial.print(buf[i]);
            
            Serial.print(' ');
        }
        
        Serial.println();
        delay(100);
        digitalWrite(LED, LOW);
    }
}
