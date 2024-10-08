//+-------------------------------------------------------------------------------
// Fast Led Effect library - Benoit Dervieux
// File : main.cpp
//  Description : List a series of functions found on the internet for the Fast Led library.
// Makes them available for a static call for a bigger project.
// History: 9/8/2024 - Updated last
// Github: https://github.com/BenoitDervieux/FastLedEffects
//+-------------------------------------------------------------------------------
#include <Arduino.h>
#include <FastLED.h>
#include <FastLedEffects.h>
#include "Palettes.h"

#define NUM_LEDS 10
#define DATA_PIN_1 23
#define BRIGHTNESS 100

CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812B, DATA_PIN_1, GRB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();
  
}

void loop() {
  CRGBPalette16 myPal = lavaPalette;

  // FastLedEffects::blink(255, 141, 0, leds, 50);
  // FastLedEffects::backAndForthNoSmoothOneDot(255, 141, 0, leds, 15);
  // FastLedEffects::backAndForthNoSmoothLengthedDot(255, 141, 0, leds, 30, 3);
  // put your main code here, to run repeatedly:
  // FastLedEffects::backAndForthNoSmoothLengthedDot(255, 141, 0, leds, 100, 3);
  // FastLedEffects::rainbowStatic(leds);
  // FastLedEffects::hueFading(1, leds);
  // FastLedEffects::hueWhiteWave(25, 50, leds);
  // FastLedEffects::hueWhiteWave(141, 50, leds);
  // FastLedEffects::movingPaletteLinear(myPal, 10, leds);
  // FastLedEffects::spotlightingPalette(myPal, 500, 1, leds);
  // FastLedEffects::sinBeat8PhaseOff(255, 141, 22, 10, 230, 256, leds);
  // FastLedEffects::twoSinBeat8(0,0,255, 255,0,0, 1, 30,leds);
  // FastLedEffects::brightnessSinBeat8Palette(myPal, 30, 30, leds);
  // FastLedEffects::funkyRainbowSinBeat8(10, leds);
  // FastLedEffects::funkyRangeSinBeat8Two(10, CRGB::Red, leds);
  // FastLedEffects::movingFunkyPalette(myPal,45,30, leds);
  // FastLedEffects::rainbowWave(60, 5, 1, leds);
  // FastLedEffects::choosenWave(5, 3, CRGB::Blue, leds);
  // FastLedEffects::firstNoiseRainbow(30, leds);
  // FastLedEffects::noisePalette(myPal, 1000, leds);
  // FastLedEffects::runFire(myPal, leds);
  // FastLedEffects::secondNoise(myPal, leds);
  // FastLedEffects::rainbowDave(10, 4, 100, leds);
  // FastLedEffects::marqueeDave(100, 8, 2, leds);
  // FastLedEffects::cometOnce(20, 128, 1, 5, 0.5, leds);
  // int balls, int length, int fadeRate, bool bMirrored, double SpeedKnob, int StartHeight
  // FastLedEffects::bounce(leds, 1, 2, 32, 1.0, 1, CRGB::Blue); 
  // FastLedEffects::bounce(leds, 2, 64, false);

  // FastLedEffects::DrawMarqueeComparison();

  // FastLedEffects::fire(NUM_LEDS, 200, 100, 2, 2, false, false);
  
  // FastLedEffects::stormColored(20, 15, 40, 70, CRGB::Red, leds);

  // FastLedEffects::stormPalette(20, 15, 40, 70, myPal, leds);
  // FastLedEffects::lightingPalette(0, 0, 15, 2, 100, myPal, leds);
  // FastLedEffects::beat8_tail(2, 32, leds);
  // FastLedEffects::blendIntoRainbow(150, 2, leds);
  // FastLedEffects::chaseTargetTalesVarC(2000, 50, 70, leds);

  // FastLedEffects::everyNTimerVariables(1000, 500, leds); 
  // FastLedEffects::fillUpStrip(leds);
  // FastLedEffects::heartBeat2(1100, 180, leds);
  // FastLedEffects::heartPulseBloodFlowing(leds);
  // FastLedEffects::lighthouseBeaconV2(4, 10, 0, leds);
  // FastLedEffects::matchingGlitter4(true, leds);
  // FastLedEffects::Fire2012_halfStrip(30, 90, 50, true, leds);
  // FastLedEffects::movingColoredBar(myPal, leds, 3, 40);
  // FastLedEffects::repeatingPattern(50, 200, 32, leds);
  // FastLedEffects::savedPixel(100, leds);
  // FastLedEffects::sinCosLinear(leds);
  // FastLedEffects::sparkles(leds);
  // FastLedEffects::firstNoiseRainbow(30, leds);

  // CRGBPalette16 myPal = heatmap_gp;
}
