#include <Arduino.h>
#include <FastLED.h>
#include <FastLedEffects.h>
#include "Palettes.h"

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
  // FastLedEffects::backAndForthNoSmoothLengthedDot(255, 141, 0, leds, 100, 3);
  // FastLedEffects::rainbowStatic(leds);
  // FastLedEffects::hueFading(30, leds);
  // CRGBPalette16 myPal = purplePalette;
  CRGBPalette16 myPal = heatmap_gp;
  // FastLedEffects::hueWhiteWave(141, 50, leds);
  // FastLedEffects::movingPaletteLinear(myPal, 10, leds);
  FastLedEffects::spotlightingPalette(myPal, 50, 10, leds);
}
