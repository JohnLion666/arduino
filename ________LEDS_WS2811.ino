#include "FastLED.h"
#define LED_COUNT 15
#define LED_PIN 8
CRGB strip[LED_COUNT];





void setup()
{
  FastLED.addLeds<WS2811, LED_PIN, RGB>(strip, LED_COUNT);
}
 
void loop(){  

  for (int i = 0; i < LED_COUNT; i++){    
    strip[i-2] = CRGB(random(255)/25,random(255)/25,random(255)/25);
    strip[i-1] = CRGB(random(255)/10,random(255)/10,random(255)/10);
    strip[i] = CRGB(random(255),random(255),random(255));
   // strip[i-3] = CRGB(random(255)/25,random(255)/25,random(255)/25);
    //strip[i-4] = CRGB(random(255)/40,random(255)/40,random(255)/40);
    FastLED.show();
    delay(70);
    strip[i-2] = CRGB::Black;
    strip[i-1] = CRGB::Black;
    strip[i] = CRGB::Black;
    ///strip[i-3] = CRGB::Black;
    //strip[i-4] = CRGB::Black;
    FastLED.show();
  }
  for (int i = LED_COUNT; i >0;  i--){ 
    strip[i+2] = CRGB(random(255)/25,random(255)/25,random(255)/25);
    strip[i+1] = CRGB(random(255)/10,random(255)/10,random(255)/10);
    strip[i] = CRGB(random(255),random(255),random(255));
    //strip[i-3] = CRGB(random(255)/25,random(255)/25,random(255)/25);
   // strip[i-4] = CRGB(random(255)/40,random(255)/40,random(255)/40);
    FastLED.show();
    delay(70);
    strip[i+2] = CRGB::Black;
    strip[i+1] = CRGB::Black;
    strip[i] = CRGB::Black;
   // strip[i-3] = CRGB::Black;
   // strip[i-4] = CRGB::Black;
    FastLED.show();
  }

}


