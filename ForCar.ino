#include "FastLED.h"
#define LED_COUNT 16
#define LED_PIN 10
CRGB strip[LED_COUNT];

void setup()
{
  FastLED.addLeds<WS2811, LED_PIN, GRB>(strip, LED_COUNT);
}
 
void loop(){  
  //Police_one();
  Police_two();
}
void Police_two(){
  int myDelay = 70;
  for (int i = 0; i < LED_COUNT/2; i++){
    strip[i-1] = CRGB::Black;
    FastLED.show();
    int k = i;
    while (k <=i + LED_COUNT/2){
      if (k <= LED_COUNT/2){
        strip[k] = CRGB::Blue;
        FastLED.show();
      }else{
        strip[k] = CRGB::Red; 
        FastLED.show();      
      }
      k++;
    }
    delay(myDelay);
  }
  for (int i = LED_COUNT/2; i >0; i--){
    strip[i + LED_COUNT/2+1] = CRGB::Black;
    FastLED.show();
    int k = i;
    while (k <=i + LED_COUNT/2){
      if (k <= LED_COUNT/2){
        strip[k] = CRGB::Blue;
        FastLED.show();
      }else{
        strip[k] = CRGB::Red;   
        FastLED.show();     
      }
      k++;
    }
    delay(myDelay);
  }
}


void Police_one(){
  int my_delay = 30;
  for (int i = 0; i < LED_COUNT/2; i++){    
    strip[i] = CRGB::Blue;
    FastLED.show();
    delay(my_delay);
  }
  
   for (int i = 0; i < LED_COUNT/2-1; i++){    
    strip[i] = CRGB::Black;
    FastLED.show();
    delay(my_delay);
  }
  for (int i = LED_COUNT/2; i < LED_COUNT;  i++){ 
    strip[i] = CRGB::Red;
    FastLED.show();
    delay(my_delay);
  }
  for (int i = LED_COUNT; i >LED_COUNT/2;  i--){ 
    strip[i] = CRGB::Black;
    FastLED.show();
    delay(my_delay);
  }
  for (int i = LED_COUNT/2-1; i >1;  i--){ 
    strip[i] = CRGB::Blue;
    FastLED.show();
    delay(my_delay);
  }
}

