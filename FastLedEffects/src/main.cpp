//+-------------------------------------------------------------------------------
// Fast Led Effect library - Benoit Dervieux
// File : main.cpp
//  Description : List a series of functions found on the internet for the Fast Led library.
// Makes them available for a static call for a bigger project.
// History: 8/8/2024 - Updated last
// Github: https://github.com/BenoitDervieux/FastLedEffects
//+-------------------------------------------------------------------------------
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
  // FastLedEffects::spotlightingPalette(myPal, 500, 1, leds);
  // FastLedEffects::sinBeat8(255, 141, 22, 10, 30, leds);
  // FastLedEffects::twoSinBeat8(0,0,255, 255,0,0, 1, 30,leds);
  // FastLedEffects::brightnessSinBeat8Palette(myPal, 30, 30, leds);
  // FastLedEffects::funkyRainbowSinBeat8(10, leds);
  // FastLedEffects::funkyRangeSinBeat8Two(10, CRGB::Red, leds);
  // FastLedEffects::movingFunkyPalette(myPal,45,30, leds);
  // FastLedEffects::rainbowWave(5, 3, leds);
  // FastLedEffects::choosenWave(5, 3, CRGB::Blue, leds);
  // FastLedEffects::firstNoiseRainbow(30, leds);
  // FastLedEffects::noisePalette(myPal, 100, leds);
  // FastLedEffects::runFire(myPal, leds);
  // FastLedEffects::secondNoise(myPal, leds);
  // FastLedEffects::marqueeDave(100, 8, 2, leds);
  FastLedEffects::cometOnce(20, 128, 1, 5, 0.5, leds);
}
