#include "FastLED.h"

#define DATA_PIN 12 //D6
#define NUM_LEDS 11
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB

#define SLOW_RATE 100
#define FAST_RATE 50
//#define BRIGHTNESS          96
//#define FRAMES_PER_SECOND  120
#define GHUE 0

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup_ws2812(){
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void slow_blink_red(){
  for (int j = 0; j < 2; j++){
    for (int i = 0; i < NUM_LEDS; i++){
      leds[i] = CRGB::Blue;
      FastLED.show();
      delay(SLOW_RATE);
      leds[i] = CRGB::Black;
      FastLED.show();
      delay(SLOW_RATE);
    }
    for (int i = NUM_LEDS - 1; i >= 0; i--){
      leds[i] = CRGB::Blue;
      FastLED.show();
      delay(SLOW_RATE);
      leds[i] = CRGB::Black;
      FastLED.show();
    }
  }
}

void fast_blink_red(){
  for (int j = 0; j < 2; j++){
    for (int i = 0; i < NUM_LEDS; i++){
      leds[i] = CRGB::Blue;
      FastLED.show();
      delay(FAST_RATE);
      leds[i] = CRGB::Black;
      FastLED.show();
      delay(FAST_RATE);
    }
    for (int i = NUM_LEDS - 1; i >= 0; i--){
      leds[i] = CRGB::Blue;
      FastLED.show();
      delay(FAST_RATE);
      leds[i] = CRGB::Black;
      FastLED.show();
    }
  }
}

// Heart getting full and blinking at the end
void heart() {
  for (int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(SLOW_RATE);
  }

  for (int j = 0; j < 3; j++){
    delay(SLOW_RATE);

    for (int k = 0; k < NUM_LEDS; k++){
      leds[k] = CRGB::Blue;
      FastLED.show();
    }
    
    delay(SLOW_RATE);

    for (int l = 0; l < NUM_LEDS; l++){
      leds[l] = CRGB::Black;
      FastLED.show();
    }
  }
}

void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8 (BeatsPerMinute, 64, 255);
  for (int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, GHUE+(i*2), beat-GHUE+(i*10));
  }
}

void rainbow() 
{
  // FastLED's built-in rainbow generator
  fill_rainbow(leds, NUM_LEDS, GHUE, 7);
}

void turn_leds_on(){
  int rand_number = random(1,5);
  Serial.println(rand_number);
  Serial.println("done");
  switch(rand_number){
    case 1:
      slow_blink_red();
      break;
    case 2:
      fast_blink_red();
      break;
    case 3:
      rainbow();
      break;
    case 4:
      heart();
      break;
    case 5:
      bpm();
      break;
  }
}
