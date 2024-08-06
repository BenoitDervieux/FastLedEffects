#include "FastLedEffects.h"
#define NUM_LEDS 10
#define DATA_PIN_1 23

unsigned long previousMillisBlink = 0;

#define gradLength 4
CRGB grad[gradLength];
uint8_t gradStartPos = 0;
int gradDelta = 1;
#define gradMoveDelay 150

void FastLedEffects::fill(int r, int g, int b, CRGB leds[]) {
    fill_solid(leds, NUM_LEDS, CRGB(r, g, b));
    FastLED.show();
}

void FastLedEffects::blink(int r, int g, int b, CRGB leds[], int long time) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillisBlink >= time) {
        previousMillisBlink = currentMillis;
        fill_solid(leds, NUM_LEDS, CRGB(r, g, b));
        FastLED.show();
    } else {
        fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
        FastLED.show();
    }
}

void FastLedEffects::fillGradientTwoColors(int r1, int g1, int b1, int r2, int g2, int b2, CRGB leds[]) {
    fill_gradient_RGB(leds, NUM_LEDS, CRGB(r1,g1,b1), CRGB(r2,g2,b2));
    FastLED.show();
}

void FastLedEffects::fillGradientThreeColors(int r1, int g1, int b1, int r2, int g2, int b2, int r3, int g3, int b3, CRGB leds[]) {
    fill_gradient_RGB(leds, NUM_LEDS, CRGB(r1,g1,b1), CRGB(r2,g2,b2), CRGB(r3,g3,b3));
    FastLED.show();
}


void FastLedEffects::movingBar(CRGB leds[]){
    CHSV gradStartColor(0,255,255);  // Gradient start color.
    CHSV gradEndColor(161,255,255);
    fill_gradient(grad, gradStartPos, gradStartColor, gradStartPos+gradLength-1, gradEndColor, SHORTEST_HUES);
    EVERY_N_MILLISECONDS(gradMoveDelay) {
    uint8_t count = 0;
    for (uint8_t i = gradStartPos; i < gradStartPos+gradLength; i++) {
      leds[i % NUM_LEDS] = grad[count];
      count++;
    }
    FastLED.show();  // Display the pixels.
    FastLED.clear();  // Clear the strip to not leave behind lit pixels as grad moves.
    
    gradStartPos = gradStartPos + gradDelta;  // Update start position.
    if ( (gradStartPos > NUM_LEDS-1) || (gradStartPos < 0) ) {  // Check if outside NUM_LEDS range
      gradStartPos = gradStartPos % NUM_LEDS;  // Loop around as needed.
    }

  } //end EVERY_N gradMoveDelay
}

