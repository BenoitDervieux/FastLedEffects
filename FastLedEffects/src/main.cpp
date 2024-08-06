#include <Arduino.h>
#include <FastLED.h>
#include <FastLedEffects.h>

#define NUM_LEDS 10
#define DATA_PIN_1 23
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN_1, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(100);
  FastLED.show();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  FastLedEffects::movingBar(leds);
}
