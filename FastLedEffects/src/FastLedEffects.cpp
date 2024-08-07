#include "FastLedEffects.h"
#define NUM_LEDS 10
#define DATA_PIN_1 23

// Blink effect
unsigned long previousMillisBlink = 0;
// Back And Forth One Dot effect
static int posBackAndForthOneDot = 0;           // Current position of the dot
static int directionBackAndForthOneDot = 1;

// Backa And Forth Lengthed Dot effect
static int posBackAndForthLengthed = 0;           // Current position of the dot
static int directionBackAndForthLengthed = 1;

// Hue fading
static uint8_t hue = 0;

// Moving Palette
static uint8_t paletteIndex = 0;

// Add link to fastLed : 
// Add link to video : https://www.youtube.com/watch?v=4Ut4UK7612M&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=2
void FastLedEffects::fill(int r, int g, int b, CRGB leds[]) {
    fill_solid(leds, NUM_LEDS, CRGB(r, g, b));
    FastLED.show();
}

// Add link to fastLed : 
// Add link to video : https://www.youtube.com/watch?v=4Ut4UK7612M&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=2
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

// Add link to fastLed : 
// Add link to video : https://www.youtube.com/watch?v=4Ut4UK7612M&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=2
void FastLedEffects::rainbowStatic(CRGB leds[]) {
    fill_rainbow(leds, NUM_LEDS, 0, 255 / NUM_LEDS);
    FastLED.show();
}

// Add link to fastLed : 
// Add link to video : https://www.youtube.com/watch?v=4Ut4UK7612M&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=2
void FastLedEffects::fillGradientTwoColors(int r1, int g1, int b1, int r2, int g2, int b2, CRGB leds[]) {
    fill_gradient_RGB(leds, NUM_LEDS, CRGB(r1,g1,b1), CRGB(r2,g2,b2));
    FastLED.show();
}

void FastLedEffects::fillGradientThreeColors(int r1, int g1, int b1, int r2, int g2, int b2, int r3, int g3, int b3, CRGB leds[]) {
    fill_gradient_RGB(leds, NUM_LEDS, CRGB(r1,g1,b1), CRGB(r2,g2,b2), CRGB(r3,g3,b3));
    FastLED.show();
}

// Add link to video : https://www.youtube.com/watch?v=4Ut4UK7612M&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=2
void FastLedEffects::backAndForthNoSmoothOneDot(int r, int g, int b, CRGB leds[], int long time) {
    EVERY_N_MILLISECONDS(time) {   // Update every 100 milliseconds
        // Turn off all LEDs
        fill_solid(leds, NUM_LEDS, CRGB::Black);

        // Light up the current position
        leds[posBackAndForthOneDot] = CRGB(r, g, b);  // Red color for the dot
        FastLED.show();

        // Update the position
        posBackAndForthOneDot += directionBackAndForthOneDot;

        // Reverse direction at the ends
        if (posBackAndForthOneDot == 0 || posBackAndForthOneDot == NUM_LEDS - 1) {
            directionBackAndForthOneDot = -directionBackAndForthOneDot;
        }
    }
}

void FastLedEffects::backAndForthNoSmoothLengthedDot(int r, int g, int b, CRGB leds[], int long time, int length) {
    EVERY_N_MILLISECONDS(time) {   // Update every 100 milliseconds
        // Turn off all LEDs
        fill_solid(leds, NUM_LEDS, CRGB::Black);

        // Light up the current position
        for (int i = posBackAndForthLengthed; i < posBackAndForthLengthed + length; i++) {
            leds[i] = CRGB(r, g, b);  // Red color for the dot 
        }
        FastLED.show();
        // Update the position
        posBackAndForthLengthed += directionBackAndForthLengthed;

        // Reverse direction at the ends
        if (posBackAndForthLengthed == 0 || posBackAndForthLengthed == NUM_LEDS - 1) {
            directionBackAndForthLengthed = -directionBackAndForthLengthed;
        }
    }
}

void FastLedEffects::hueFading(int milliseconds, CRGB leds[]) {
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CHSV(hue, 255, 255);
    }
    EVERY_N_MILLISECONDS(10) {
        hue++;
    }
    FastLED.show();
}

void FastLedEffects::hueWhiteWave(uint8_t hueInsert, int milliseconds, CRGB leds[]) {
    EVERY_N_MILLISECONDS(milliseconds) {
        leds[0] = CHSV(hueInsert, random8(), random8(100, 255));

        for (int i = NUM_LEDS - 1; i > 0; i--) {
            leds[i] = leds[i - 1];
        }
        FastLED.show();
    }
}

void FastLedEffects::displayPaletteLinear(CRGBPalette16 palette, CRGB leds[]) {
    fill_palette(leds, NUM_LEDS, 0, 255/NUM_LEDS, palette, 100, LINEARBLEND);
    FastLED.show();
}

void FastLedEffects::movingPaletteLinear(CRGBPalette16 palette, int milliseconds, CRGB leds[]) {
    fill_palette(leds, NUM_LEDS, paletteIndex, 255/NUM_LEDS, palette, 100, LINEARBLEND);
    EVERY_N_MILLISECONDS(milliseconds) {
        paletteIndex++;
    }
    FastLED.show();
}

// Link: https://www.youtube.com/watch?v=Ukq0tH2Tnkc&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=3
void FastLedEffects::spotlightingPalette(CRGBPalette16 palette, int milliseconds, int fade, CRGB leds[]) {
    EVERY_N_MILLISECONDS(milliseconds) {
        leds[random(0, NUM_LEDS - 1)] = ColorFromPalette(palette, random8(), 255, LINEARBLEND);
    }
    fadeToBlackBy(leds, NUM_LEDS, fade);
    FastLED.show();
}


