#include <FastLED.h>
#include <vector>
#include <sys/time.h>
#include "bounce.h"
#include "fire.h"

class FastLedEffects {
    public:
        /*   1 */ static void fill(int r, int g, int b, CRGB leds[]);
        /*   2 */ static void blink(int r, int g, int b, CRGB leds[], int tid);
        /*   3 */ static void rainbowStatic(CRGB leds[]);
        /*   4 */ static void fillGradientTwoColors(int r1, int g1, int b1, int r2, int g2, int b2, CRGB leds[]);
        /*   5 */ static void fillGradientThreeColors(int r1, int g1, int b1, int r2, int g2, int b2, int r3, int g3, int b3, CRGB leds[]);
        /*   6 */ static void backAndForthNoSmoothOneDot(int r, int g, int b, CRGB leds[], int tid);
        /*   7 */ static void backAndForthNoSmoothLengthedDot(int r, int g, int b, CRGB leds[], int tid, int length);
        /*   8 */ static void hueFading(int tid, CRGB leds[]);
        /*   9 */ static void hueWhiteWave(uint8_t hueInsert, int tid, CRGB leds[]);
        /*  10 */ static void displayPaletteLinear(CRGBPalette16 palette, CRGB leds[]);
        /*  11 */ static void movingPaletteLinear(CRGBPalette16 palette, int tid, CRGB leds[]);
        /*  12 */ static void spotlightingPalette(CRGBPalette16 palette, int tid, int fade, CRGB leds[]);
        /*  13 */ static void sinBeat8(int r1, int r2, int r3, int fade, uint8_t bpm, CRGB leds[]);
        /*  14 */ static void sinBeat8PhaseOff(int r1, int r2, int r3, int fade, uint8_t bpm, uint8_t phaseOffset, CRGB leds[]);
        /*  15 */ static void sinBeat8TimeOff(int r1, int r2, int r3, int fade, uint8_t bpm, int time, CRGB leds[]);
        /*  16 */ static void twoSinBeat8(int r1, int g1, int b1, int r2, int g2, int b2, int fade, uint8_t bpm, CRGB leds[]);
        /*  17 */ static void threeSinBeat8(int r1, int g1, int b1, int r2, int g2, int b2, int r3, int g3, int b3, int fade, uint8_t bpm, CRGB leds[]);
        /*  18 */ static void brightnessSinBeat8Palette(CRGBPalette16 palette, uint8_t bpm, int tid, CRGB leds[]);
        /*  19 */ static void funkyRainbowSinBeat8(int fade, CRGB leds[]);
        /*  20 */ static void funkyRangeSinBeat8(int fade, CRGB color, CRGB leds[]);
        /*  21 */ static void funkyRainbowSinBeat8Two(int fade, CRGB leds[]);
        /*  22 */ static void funkyRangeSinBeat8Two(int fade, CRGB color, CRGB leds[]);
        /*  23 */ static void movingFunkyPalette(CRGBPalette16 palette, uint8_t bpm1, uint8_t bpm2, CRGB leds[]);
        /*  24 */ static void rainbowWave(uint8_t bpm, int tid, int fade, CRGB leds[]);
        /*  25 */ static void choosenWave(int tid, int fade, CRGB color, CRGB leds[]);
        /*  26 */ static void firstNoiseRainbow(uint8_t bpm, CRGB leds[]);
        /*  27 */ static void firstNoiseColor(CRGB color, uint8_t bpm, CRGB leds[]);
        /*  28 */ static void noisePalette(CRGBPalette16 palette, int scale, CRGB leds[]);
        /*  29 */ static void runFire(CRGBPalette16 palette, CRGB leds[]);
        /*  30 */ static void secondNoise(CRGBPalette16 palette, CRGB leds[]);
        /*  31 */ static void fillNoise16(CRGB leds[]);

        // From here is the Dave's Garage implementations
        /*  32 */ static void rainbowDave(int density, int delta, int tid, CRGB leds[]);
        /*  33 */ static void marqueeDave(int tid, int density, int length, CRGB leds[]);
        /*  34 */ static void twinkleOld(int tid, CRGB leds[]);
        /*  35 */ static void twinkle(int tid, CRGB leds[]);
        /*  36 */ static void comet(int tid, int fade, int length,  int density, CRGB leds[]);
        /*  37 */ static void cometOnce(int tid, int fade, int length,  int density, double speed, CRGB leds[]);
        /*  38 */ static void bounce(CRGB leds[], int balls, byte fade, bool mirror); // Not the best but we keep it for now 
        /*  39 */ static void fire(int size, int cooling, int sparking, int sparks, int sparkHeight, bool breversed, bool bmirrored);

        // Here opimization to make for the colors and the delay
        /*  40 */ static void storm(int chance, int length, int tid, int fade, CRGB leds[]); // Need to improve the use of delay !!!!
        /*  41 */ static void stormColored(int chance, int length, int tid, int fade, CRGB color, CRGB leds[]); // Need to improve the use of delay !!!!
        /*  42 */ static void stormPalette(int chance, int length, int tid, int fade, CRGBPalette16 palette, CRGB leds[]); // Need to improve the use of delay !!!!

        // Here opimization to make for the colors and the delay
        /*  43 */ static void lighting(int ledstart, int length, int flashes, int dimmer, int frequency, CRGB leds[]);
        /*  44 */ static void lightingColored(int ledstart, int length, int flashes, int dimmer, int frequency, CRGB color, CRGB leds[]);
        /*  45 */ static void lightingPalette(int ledstart, int length, int flashes, int dimmer, int frequency, CRGBPalette16 palette, CRGB leds[]);

        // Links to find new effects
        // This one : https://www.reddit.com/r/FastLED/comments/pytqrm/party_lighting_for_the_garage_club_delta/

        /*  46 */ static void beat8_tail(uint8_t bpm, int fade, CRGB leds[]);
        /*  47 */ static void blendIntoRainbow(int tid, int tid2, CRGB leds[]);
        /*  48 */ static void breatheV2(float pulseSp, CRGB leds[]); // --> Need to add a color option here
        /*  49 */ static void chaseTargetTalesVarA(int tid, CRGB leds[]);
        /*  50 */ static void chaseTargetTalesVarB(int tid, CRGB leds[]);
        /*  51 */ static void chaseTargetTalesVarC(int boilingTime, int tid, int fadeTime, CRGB leds[]);
        /*  52 */ static void everyNTimerVariables(uint16_t timerA, uint16_t timerB, CRGB leds[]);
        /*  53 */ static void fillUpStrip(CRGB leds[]);
        /*  54 */ static void heartBeat2(uint16_t beat_speed, uint8_t dub_offset, CRGB leds[]);
        /*  55 */ static void heartBeat3(bool rainbow, CRGB leds[]); // --> Need to add color option
        /*  56 */ static void heartPulseBloodFlowing(CRGB leds[]); // --> Need to add color option
        /*  57 */ static void lighthouseBeaconV2(int length, int tid, int fade, CRGB leds[]); // --> Need to add color option
        /*  58 */ static void matchingGlitter1(CRGB leds[]); // Check for custom colors
        /*  59 */ static void matchingGlitter2(CRGB leds[]); // Check for custom colors
        /*  60 */ static void matchingGlitter3(bool second, bool thrid, CRGB leds[]); // Check for custom colors
        /*  61 */ static void matchingGlitter4(bool more, CRGB leds[]); // Check for custom colors
        /*  62 */ static void mirrorFadeEnds(int fade, CRGB leds[]);
        /*  63 */ static void Fire2012(int tid,int cooling, int sparking, CRGB leds[]);
        /*  64 */ static void Fire2012_halfStrip(int tid, int cooling, int sparking, bool gReverseDirection, CRGB leds[]);
        /*  65 */ static void movingColoredBar(CRGBPalette16 palette, CRGB leds[], int length = 5, uint8_t frameDelay = 80);
        /*  66 */ static void repeatingPattern(int tid, int tid2, int fade, CRGB leds[]);
        /*  67 */ static void savedPixel(int tid, int tid2,  CRGB leds[]);
        /*  68 */ static void sinCosLinear(CRGB leds[]); // --> Need to add color option
        /*  69 */ static void sparkles(CRGB leds[], int sparkel_duration = random(80, 200), int sparkel_amount = 100, int sparkel_spread = 30);
        
        
        // Fetch from reddit : https://www.reddit.com/r/FastLED/comments/1fjzmfc/bar_shelves/
        /*  70 */ static void shelf(CRGB leds[], int speedDrop = 5, float fpsDrop = 0.08, int spacingDrop = 10, int particlesDrop = 6, float rowDelayDrop = 0.50);
        
    


        static uint32_t CRGBToInt(const CRGB& color);
        static uint8_t getBeatSinColor(uint32_t Color);
        static std::vector<uint8_t> getArrayRangeValue(uint32_t Color);
        static CRGB hsvToRgb(const CHSV& hsv);
        static void DrawPixels(float fPos, float count, CRGB color);
        static int sumPulse(int time_shift);
        static uint8_t pulseWave8(uint32_t ms, uint16_t cycleLength, uint16_t pulseLength);
        static void drawFractionalBar( int pos16, int width, uint8_t hue, uint8_t fadeRate, CRGB leds[]);
        static int id(int row, int col);

    
    private:
        int red;
        int green;
        int blue;
        void setColor(int r, int g, int b);

};