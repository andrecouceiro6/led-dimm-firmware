#include <SoftPWM.h>

void setup()
{

  for(int led=0;led<=19;led++){
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);   // turn the LED on (HIGH is the voltage level)
  }
  
  SoftPWMBegin();
  
  for(int led=0;led<=19;led++){  
    SoftPWMSet(led, 0);
    SoftPWMSetFadeTime(led, 1000, 1000);
  }
  randomSeed(analogRead(A7));
  
  
}

void loop()
{
  for(int led=0;led<=19;led++){  
    int val=random(0,512);
    val=val-255;
    if (val<0) val=0;
    if (val>255) val=255;
    SoftPWMSet(led, val);
  }
  delay(1000);
}
