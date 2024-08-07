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

// Link : https://www.youtube.com/watch?v=2owTxbrmY-s&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=4
void FastLedEffects::sinBeat8(int r1, int r2, int r3, int fade, uint8_t bpm, CRGB leds[]) {
    // This effect do like a shooting star coming back and forth
    uint8_t sinBeat = beatsin8(bpm, 0, NUM_LEDS - 1, 0, 0); // The last 2 zeros are phase offset and time based, not useful yet
    leds[sinBeat] = CRGB(r1, r2, r3);

    fadeToBlackBy(leds, NUM_LEDS, fade);
    FastLED.show();
}

// Link : https://www.youtube.com/watch?v=2owTxbrmY-s&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=4
void FastLedEffects::sinBeat8PhaseOff(int r1, int r2, int r3, int fade, uint8_t bpm, uint8_t phaseOffset, CRGB leds[]) {
    // This function can be useful for adapting to the bpm of the song by modifying the phase
    uint8_t sinBeat = beatsin8(bpm, 0, NUM_LEDS - 1, 0, phaseOffset); 
    leds[sinBeat] = CRGB(r1, r2, r3);
    fadeToBlackBy(leds, NUM_LEDS, fade);
    FastLED.show();
}

// Link : https://www.youtube.com/watch?v=2owTxbrmY-s&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=4
void FastLedEffects::sinBeat8TimeOff(int r1, int r2, int r3, int fade, uint8_t bpm, int time, CRGB leds[]) {
    // This function can be useful for adapting to the bpm of the song by modifying the phase
    // Formula : Period of a wave = 60 / bpm * milliseconds
    uint8_t sinBeat = beatsin8(bpm, 0, NUM_LEDS - 1, time, 0);
    leds[sinBeat] = CRGB(r1, r2, r3);

    fadeToBlackBy(leds, NUM_LEDS, fade);
    FastLED.show();
}
// Link : https://www.youtube.com/watch?v=2owTxbrmY-s&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=4
void FastLedEffects::twoSinBeat8(int r1, int g1, int b1, int r2, int g2, int b2, int fade, uint8_t bpm, CRGB leds[]) {
    uint8_t sinBeat1 = beatsin8(bpm, 0, NUM_LEDS - 1, 0, 0);
    uint8_t sinBeat2 = beatsin8(bpm, 0, NUM_LEDS - 1, 0, 170);
    leds[sinBeat1] = CRGB(r1, g1, b1);
    leds[sinBeat2] = CRGB(r2, g2, b2);
    fadeToBlackBy(leds, NUM_LEDS, fade);
    FastLED.show();
}
// Link : https://www.youtube.com/watch?v=2owTxbrmY-s&list=PLgXkGn3BBAGi5dTOCuEwrLuFtfz0kGFTC&index=4
void FastLedEffects::threeSinBeat8(int r1, int g1, int b1, int r2, int g2, int b2, int r3, int g3, int b3, int fade, uint8_t bpm, CRGB leds[]) {
    uint8_t sinBeat1 = beatsin8(bpm, 0, NUM_LEDS - 1, 0, 0);
    uint8_t sinBeat2 = beatsin8(bpm, 0, NUM_LEDS - 1, 0, 85);
    uint8_t sinBeat3 = beatsin8(bpm, 0, NUM_LEDS - 1, 0, 170);
    leds[sinBeat1] = CRGB(r1, g1, b1);
    leds[sinBeat2] = CRGB(r2, g2, b2);
    leds[sinBeat3] = CRGB(r3, g3, b3);
    fadeToBlackBy(leds, NUM_LEDS, fade);
    FastLED.show();
}

void FastLedEffects::brightnessSinBeat8Palette(CRGBPalette16 palette, uint8_t bpm, int milliseconds, CRGB leds[]) {
    static int more = 0;
    uint8_t sinBeat = beatsin8(bpm, 0, 255, 0, 0);
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette(palette, (255/NUM_LEDS * i + more) % 255, sinBeat);
    }
    EVERY_N_MILLISECONDS(10) {
        more++;
    }
    FastLED.show();
}

void FastLedEffects::funkyRainbowSinBeat8(int fade, CRGB leds[]) {
    // Waves for led position
    uint8_t posBeat = beatsin8(30, 0, NUM_LEDS - 1, 0, 0);
    uint8_t posBeat2 = beatsin8(60, 0, NUM_LEDS - 1, 0, 0);
    // Wave for LED color
    uint8_t colBeat = beatsin8(45, 0, 255, 0, 0);
    leds[(posBeat + posBeat2) / 2] = CHSV(colBeat, 255, 255);
    fadeToBlackBy(leds, NUM_LEDS, fade);
    FastLED.show();
}

void FastLedEffects::funkyRangeSinBeat8(int fade, CRGB color, CRGB leds[]) {
    // Waves for led position
    uint8_t posBeat = beatsin8(30, 0, NUM_LEDS - 1, 0, 0);
    uint8_t posBeat2 = beatsin8(60, 0, NUM_LEDS - 1, 0, 0);
    // Wave for LED color
    uint32_t convertedColor = FastLedEffects::CRGBToInt(color);
    uint8_t colBeat = FastLedEffects::getBeatSinColor(convertedColor);
    leds[(posBeat + posBeat2) / 2] = CHSV(colBeat, 255, 255);
    fadeToBlackBy(leds, NUM_LEDS, fade);
    FastLED.show();
}

void FastLedEffects::funkyRainbowSinBeat8Two(int fade, CRGB leds[]) {
    uint8_t posBeat = beatsin8(30, 0, NUM_LEDS - 1, 0, 0);
    uint8_t posBeat2 = beatsin8(60, 0, NUM_LEDS - 1, 0, 0);
    uint8_t posBeat3 = beatsin8(30, 0, NUM_LEDS - 1, 0, 127);
    uint8_t posBeat4 = beatsin8(60, 0, NUM_LEDS - 1, 0, 127);

    uint8_t colBeat = beatsin8(45, 0, 255, 0, 0);
    leds[(posBeat + posBeat2) / 2] = CHSV(colBeat, 255, 255);
    leds[(posBeat3 + posBeat4) / 2] = CHSV(colBeat, 255, 255);
    fadeToBlackBy(leds, NUM_LEDS, fade);
    FastLED.show();
}

void FastLedEffects::funkyRangeSinBeat8Two(int fade, CRGB color, CRGB leds[]) {
    uint8_t posBeat = beatsin8(30, 0, NUM_LEDS - 1, 0, 0);
    uint8_t posBeat2 = beatsin8(60, 0, NUM_LEDS - 1, 0, 0);
    uint8_t posBeat3 = beatsin8(30, 0, NUM_LEDS - 1, 0, 127);
    uint8_t posBeat4 = beatsin8(60, 0, NUM_LEDS - 1, 0, 127);

    uint32_t convertedColor = FastLedEffects::CRGBToInt(color);
    uint8_t colBeat = FastLedEffects::getBeatSinColor(convertedColor);
    leds[(posBeat + posBeat2) / 2] = CHSV(colBeat, 255, 255);
    leds[(posBeat3 + posBeat4) / 2] = CHSV(colBeat, 255, 255);
    fadeToBlackBy(leds, NUM_LEDS, fade);
    FastLED.show();

}

void FastLedEffects::movingFunkyPalette(CRGBPalette16 palette, int bpm1, int bpm2, CRGB leds[]) {
    uint8_t beatA = beatsin8(bpm1, 0, 255);
    uint8_t beatB = beatsin8(bpm2, 0, 255);
    fill_palette(leds, NUM_LEDS, (beatA + beatB) / 2, 10, palette, 255, LINEARBLEND);
    FastLED.show();
}

void FastLedEffects::rainbowWave(int milliseconds, int fade, CRGB leds[]) {
    uint8_t pos = map(beat8(40, 0), 0, 255, 0, NUM_LEDS - 1);
    leds[pos] = CHSV(hue, 200, 255);
    fadeToBlackBy(leds, NUM_LEDS, fade);
    EVERY_N_MILLISECONDS(milliseconds) {
        hue++;
    }
    FastLED.show();
}

void FastLedEffects::choosenWave(int milliseconds, int fade, CRGB color, CRGB leds[]) {
    uint8_t pos = map(beat8(40, 0), 0, 255, 0, NUM_LEDS - 1);
    std::vector<uint8_t> colors = FastLedEffects::getArrayRangeValue(FastLedEffects::CRGBToInt(color));
    leds[pos] = CHSV(map(hue, 0, 255, colors[0], colors[1]), 200, 255);
    fadeToBlackBy(leds, NUM_LEDS, fade);
    EVERY_N_MILLISECONDS(milliseconds) {
        hue++;
    }
    FastLED.show();
}


// Utility functions
uint32_t FastLedEffects::CRGBToInt(const CRGB& color) {
    return (static_cast<uint32_t>(color.r) << 16) |
           (static_cast<uint32_t>(color.g) << 8)  |
           static_cast<uint32_t>(color.b);
}

uint8_t FastLedEffects::getBeatSinColor(uint32_t Color) {
    uint8_t colBeat;
    switch (Color) {
        case CRGB::Red:
            colBeat = beatsin8(45, 200, 255, 0, 0);
            break;
        case CRGB::Green:
            colBeat = beatsin8(45, 80, 128, 255, 0);
            break;
        case CRGB::Blue:
            colBeat = beatsin8(45, 128, 176, 0, 255);
            break;
        case CRGB::Yellow:
            colBeat = beatsin8(45, 48, 70, 0, 255);
            break;
        case CRGB::Orange:
            colBeat = beatsin8(45, 16, 48, 0, 255);
            break;
        case CRGB::Purple:
            colBeat = beatsin8(45, 192, 224, 0, 255);
            break;
        case CRGB::Aqua:
            colBeat = beatsin8(45, 112, 144, 0, 255);
            break;
        default:
            colBeat = beatsin8(45, 0, 255, 0, 255);
            break;
    }
    return colBeat;
}

std::vector<uint8_t> FastLedEffects::getArrayRangeValue(uint32_t Color) {
    std::vector<uint8_t> arrayOfRanges;
    switch (Color) {
        case CRGB::Red:
            arrayOfRanges = {200, 255};
            break;
        case CRGB::Green:
            arrayOfRanges = {80, 128};
            break;
        case CRGB::Blue:
            arrayOfRanges = {128, 176};
            break;
        case CRGB::Yellow:
            arrayOfRanges = {48, 70};
            break;
        case CRGB::Orange:
            arrayOfRanges = {16, 48};
            break;
        case CRGB::Purple:
            arrayOfRanges = {192, 224};
            break;
        case CRGB::Aqua:
            arrayOfRanges = {112, 144};
            break;
        default:
            arrayOfRanges = {0, 255};
            break;
    }
    return arrayOfRanges;
}