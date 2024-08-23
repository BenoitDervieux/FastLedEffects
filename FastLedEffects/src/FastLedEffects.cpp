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

// First Noise
static uint16_t x = 0;
static int scale = 10;
static uint16_t t = 0;

// Noise palette
static uint16_t brightnessScale = 150;
static uint16_t indexScale = 20;



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

void FastLedEffects::firstNoiseRainbow(int bpm, CRGB leds[]) {
    x = 0;
    scale = beatsin8(bpm, 10, 30); // bpm
    t = millis() / 5;
    for (int i = 0; i < NUM_LEDS; i++) {
        uint8_t noise = inoise8(i * scale + x, t);
        uint8_t huetest = map(noise, 50, 190, 0, 255); // Color type of hue
        leds[i] = CHSV(huetest, 255, 255);
    }
    FastLED.show();
}

void FastLedEffects::firstNoiseColor(CRGB color, int bpm, CRGB leds[]) {
    x = 0;
    scale = beatsin8(bpm, 10, 30); // bpm
    t = millis() / 5;
    std::vector<uint8_t> colors = FastLedEffects::getArrayRangeValue(FastLedEffects::CRGBToInt(color));
    for (int i = 0; i < NUM_LEDS; i++) {
        uint8_t noise = inoise8(i * scale + x, t);
        uint8_t huetest = map(noise, 50, 190, colors[0], colors[1]); // Color type of hue
        leds[i] = CHSV(huetest, 255, 255);
    }
    FastLED.show();
}

void FastLedEffects::noisePalette(CRGBPalette16 palette, int scale, CRGB leds[]) {
    for (int i = 0; i < NUM_LEDS; i++) {
        indexScale = scale;
        uint8_t brightness = inoise8(i*brightnessScale, millis() / 5);
        uint8_t index = inoise8(i*indexScale, millis() / 10);
        leds[i] = ColorFromPalette(palette, index, brightness);
    }
    FastLED.show();
}

void FastLedEffects::runFire(CRGBPalette16 palette, CRGB leds[]) {
    int a = millis();
    for (int i = 0; i < NUM_LEDS; i++) {
        uint8_t noise = inoise8(0, i * 60 + a, a / 3);
        uint8_t math = abs8(i - (NUM_LEDS - 1) * 255 / (NUM_LEDS - 1));
        uint8_t indexFire = qsub8(noise, math);
        leds[i] = ColorFromPalette(palette, indexFire, 255, LINEARBLEND);
    }
    FastLED.show();
}

// Second Noise
static uint8_t octaveVal = 2;
static uint16_t xVal = 0;
static int scaleVal = 50;
static uint16_t timeVal = 0;
static uint8_t noiseData[NUM_LEDS];

void FastLedEffects::secondNoise(CRGBPalette16 palette, CRGB leds[]) {

    timeVal = millis() / 4;
    memset(noiseData, 0, NUM_LEDS);
    fill_raw_noise8(noiseData, NUM_LEDS, octaveVal, xVal, scaleVal, timeVal);
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette(palette, noiseData[i], noiseData[NUM_LEDS - i - 1], LINEARBLEND);
    }
    FastLED.show();
}

// Fill Noise 16
static uint8_t hue_octaves = 1;
static uint16_t hue_x = 1;
static int hue_scale = 50;

void FastLedEffects::fillNoise16(CRGB leds[]) {
    octaveVal = 1;
    xVal = 0;
    scaleVal = 100;
    uint16_t ntime = millis() / 3;
    uint8_t hue_shift = 5;
    fill_noise16(leds, NUM_LEDS, octaveVal, xVal, scaleVal, hue_octaves, hue_x, hue_scale, ntime, hue_shift);
    FastLED.show();
}
static uint8_t initialHue = 0;

// Link : https://www.youtube.com/watch?v=r6vMdnqUjTk&list=PLF2KJ6Gy3cZ7ynsp8s4tnqEFmY15CKhmH&index=12
void FastLedEffects::rainbowDave(int density, int delta, CRGB leds[]) {
    // Here the density is the speed of the animation
    fill_rainbow(leds, NUM_LEDS, initialHue += density, delta);
    FastLED.show();
}
static unsigned long lastUpdate = 0;  // Store the last update time
unsigned long interval = 0;   // Interval in milliseconds between updates
// Link : https://www.youtube.com/watch?v=r6vMdnqUjTk&list=PLF2KJ6Gy3cZ7ynsp8s4tnqEFmY15CKhmH&index=12
void FastLedEffects::marqueeDave(int inter, int hueChanging, int length, CRGB leds[]) {
    static byte j = HUE_BLUE;
    interval = inter;
    static int scroll = 0;
    if (millis() - lastUpdate >= interval) {
        lastUpdate = millis();

        j += 1;
        byte k = j;

        CRGB c;
        for (int i = 0; i < NUM_LEDS; i++) {
            leds[i] = c.setHue(k+=hueChanging);
        }
        
        scroll++;
        for (int i = scroll % length; i < NUM_LEDS; i+=length) {
            leds[i] = CRGB::Black;
        }
        FastLED.show();
    }
}

// Would be good to make something more extended later
#define NUM_COLORS 5
static const CRGB TwinkleColors [NUM_COLORS] = {
    CRGB::Red,
    CRGB::Blue,
    CRGB::Purple,
    CRGB::Green,
    CRGB::Orange
};
void FastLedEffects::twinkleOld(int inter, CRGB leds[]) {
    interval = inter;
    if (millis() - lastUpdate >= interval) {
        lastUpdate = millis();
        FastLED.clear(false);
        for (int i = 0; i < NUM_LEDS / 2; i++) {
            leds[random(NUM_LEDS)] = TwinkleColors[random(0, NUM_COLORS)];
            FastLED.show();
        }
    }
}

void FastLedEffects::twinkle(int inter, CRGB leds[]) {
    interval = inter;
    if (millis() - lastUpdate >= interval) {
        lastUpdate = millis();
        static int passCount = 0;
        passCount++;

        if (passCount == NUM_LEDS) {
            passCount = 0;
            FastLED.clear(false);
        }
        leds[random(NUM_LEDS)] = TwinkleColors[random(0, NUM_COLORS)];
        FastLED.show();
    }
}

void FastLedEffects::comet(int inter, int fade, int cometsize,  int delathue, CRGB leds[]) {

    byte fadeAmt = fade;
    int cometSize = cometsize;
    int deltaHue = delathue;

    static byte hueByte = HUE_RED;  // Current comet color
    static int iDirection = 1;      // Current direction
    static int iPos = 0;    // Current comet positon on the strip

     interval = inter;
    if (millis() - lastUpdate >= interval) {
        lastUpdate = millis();
        hueByte += deltaHue;  //Update comet color
        iPos += iDirection;  // Update comet position

        // Flip the comet direction when it hits either end of the strip
        if (iPos == (NUM_LEDS - cometSize) || iPos == 0) {
            iDirection *= -1;
        }

        // Draw the comet at its current position
        for (int i = 0; i < cometSize; i++) {
            leds[iPos + i].setHue(hueByte);
        }

        // Fade the LEDS one step
        for (int j = 0; j < NUM_LEDS; j++) {
            if (random(2) == 1)
                // leds[j] =leds[j].fadeToBlackBy(fadeAmt);
                leds[j].fadeToBlackBy(fadeAmt);
        }
        FastLED.show();
    }
}

void FastLedEffects::cometOnce(int inter, int fade, int cometsize,  int delathue,  double cometspeed, CRGB leds[]) {

    byte fadeAmt = fade;
    int cometSize = cometsize;
    int deltaHue = delathue;
    double cometSpeed = cometspeed;

    static byte hueByte = HUE_RED;  // Current comet color
    static int iDirection = 1;      // Current direction
    static double iPos = 0.0;    // Current comet positon on the strip

    interval = inter;
    if (millis() - lastUpdate >= interval) {
        lastUpdate = millis();
        hueByte += deltaHue;  //Update comet color
        iPos += iDirection * cometSpeed;  // Update comet position

        // Flip the comet direction when it hits either end of the strip
        if (iPos == (NUM_LEDS - cometSize) || iPos == 0) {
            iDirection *= -1;
        }

        // Draw the comet at its current position
        for (int i = 0; i < cometSize; i++) {
            leds[(int)iPos + i].setHue(hueByte);
        }

        // Fade the LEDS one step
        for (int j = 0; j < NUM_LEDS; j++) {
            if (random(2) == 1)
                // leds[j] =leds[j].fadeToBlackBy(fadeAmt);
                leds[j].fadeToBlackBy(fadeAmt);
        }
        FastLED.show();
    }
}

// Link : https://www.youtube.com/watch?v=ysI30OrkiAc&list=PLF2KJ6Gy3cZ7ynsp8s4tnqEFmY15CKhmH&index=10
// Bounce bouncer = Bounce(NUM_LEDS, 1);
Bounce bouncer = Bounce(NUM_LEDS, 1, 64, false);
void FastLedEffects::bounce( CRGB leds[], int balls, byte fade, bool mirror) {
    if (bouncer.GetInstantiated() != balls) {
       bouncer.Recalibrate(balls);
    }
    if (bouncer.GetFade() != fade) {
        bouncer.SetFade(fade);
    }
    if (bouncer.GetMirror() != mirror) {
        bouncer.SetMirror(mirror);
    }
    bouncer.Draw(leds);
}


//+---------------------------------------------------------------------------------
// 
// Utility functions
//
//+---------------------------------------------------------------------------------
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

double FastLedEffects::TimeTo() {
        timeval tv = {0};
        gettimeofday(&tv, nullptr);
        return (double)(tv.tv_usec / 1000000.0 + (double)tv.tv_sec);
}

double FastLedEffects::InitialBallSpeed(double height) {
    return sqrt(-2 * Gravity * height);
}

