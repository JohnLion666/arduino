char var;

#include "FastLED.h"
#define LED_COUNT 15
#define LED_PIN 10
CRGB strip[LED_COUNT];

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  
  FastLED.addLeds<WS2811, LED_PIN, RGB>(strip, LED_COUNT);
}

void loop() {
    if(Serial.available()){
      var = Serial.read();
    }
    right(var);
    left(var);
    
    myStop(var);

}

void left(int a){
  char b;
  if(a == '1'){
    b = a;
    while(b == '1'){
      digitalWrite(13, 1);
      for (int i = 0; i < LED_COUNT; i++){    
        strip[i-2] = CRGB(255/25,255/25,0);
        strip[i-1] = CRGB(255/10,255/10,0);
        strip[i] = CRGB(255 ,255,0);
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
      if(Serial.read()== '1'){
        b = 0;
      }
    }
  }
}
void right(int a){
  char b;
  if(a == '2'){
    b = a;
    while(b == '2'){
      digitalWrite(13, 0);
      for (int i = LED_COUNT-1; i > -1; i--){    
        strip[i+2] =  CRGB(255/25,255/25,0);
        strip[i+1] = CRGB(255/10,255/10,0);
        strip[i] = CRGB(255 ,255,0);
       // strip[i-3] = CRGB(random(255)/25,random(255)/25,random(255)/25);
        //strip[i-4] = CRGB(random(255)/40,random(255)/40,random(255)/40);
        FastLED.show();
        delay(70);
        strip[i+2] = CRGB::Black;
        strip[i+1] = CRGB::Black;
        strip[i] = CRGB::Black;
        ///strip[i-3] = CRGB::Black;
        //strip[i-4] = CRGB::Black;
        FastLED.show();
      }
      if(Serial.read()== '2'){
        b = 0;
      }
    }
  }
}
void myStop(int a){
  char b;
  if(a == '3'){
    b = a;
    while( b == '3'){
      for(int j = 0; j < 15; j++){
        for(int i =0 ; i < 15; i++){
          strip[i] = CRGB(0,255*j/15,0);
          FastLED.show();
          delay(10);
        }
      }
      if(Serial.read()== '3'){
        b = 0;
        for(int i = 0; i < LED_COUNT; i++){
          strip[i] = CRGB(0,0,0);
          FastLED.show();
        }       
      }
    }
  }
}


