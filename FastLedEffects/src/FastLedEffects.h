#include <FastLED.h>
#include <vector>
#include <sys/time.h>
#include "bounce.h"
class FastLedEffects {
    public:
        /*   1 */ static void fill(int r, int g, int b, CRGB leds[]);
        /*   2 */ static void blink(int r, int g, int b, CRGB leds[], int long time);
        /*   3 */ static void rainbowStatic(CRGB leds[]);
        /*   4 */ static void fillGradientTwoColors(int r1, int g1, int b1, int r2, int g2, int b2, CRGB leds[]);
        /*   5 */ static void fillGradientThreeColors(int r1, int g1, int b1, int r2, int g2, int b2, int r3, int g3, int b3, CRGB leds[]);
        /*   6 */ static void backAndForthNoSmoothOneDot(int r, int g, int b, CRGB leds[], int long time);
        /*   7 */ static void backAndForthNoSmoothLengthedDot(int r, int g, int b, CRGB leds[], int long time, int length);
        /*   8 */ static void hueFading(int milliseconds, CRGB leds[]);
        /*   9 */ static void hueWhiteWave(uint8_t hueInsert, int milliseconds, CRGB leds[]);
        /*  10 */ static void displayPaletteLinear(CRGBPalette16 palette, CRGB leds[]);
        /*  11 */ static void movingPaletteLinear(CRGBPalette16 palette, int milliseconds, CRGB leds[]);
        /*  12 */ static void spotlightingPalette(CRGBPalette16 palette, int milliseconds, int fade, CRGB leds[]);
        /*  13 */ static void sinBeat8(int r1, int r2, int r3, int fade, uint8_t bpm, CRGB leds[]);
        /*  14 */ static void sinBeat8PhaseOff(int r1, int r2, int r3, int fade, uint8_t bpm, uint8_t phaseOffset, CRGB leds[]);
        /*  15 */ static void sinBeat8TimeOff(int r1, int r2, int r3, int fade, uint8_t bpm, int time, CRGB leds[]);
        /*  16 */ static void twoSinBeat8(int r1, int g1, int b1, int r2, int g2, int b2, int fade, uint8_t bpm, CRGB leds[]);
        /*  17 */ static void threeSinBeat8(int r1, int g1, int b1, int r2, int g2, int b2, int r3, int g3, int b3, int fade, uint8_t bpm, CRGB leds[]);
        /*  18 */ static void brightnessSinBeat8Palette(CRGBPalette16 palette, uint8_t bpm, int milliseconds, CRGB leds[]);
        /*  19 */ static void funkyRainbowSinBeat8(int fade, CRGB leds[]);
        /*  20 */ static void funkyRangeSinBeat8(int fade, CRGB color, CRGB leds[]);
        /*  21 */ static void funkyRainbowSinBeat8Two(int fade, CRGB leds[]);
        /*  22 */ static void funkyRangeSinBeat8Two(int fade, CRGB color, CRGB leds[]);
        /*  23 */ static void movingFunkyPalette(CRGBPalette16 palette, int bpm1, int bpm2, CRGB leds[]);
        /*  24 */ static void rainbowWave(int milliseconds, int fade, CRGB leds[]);
        /*  25 */ static void choosenWave(int milliseconds, int fade, CRGB color, CRGB leds[]);
        /*  26 */ static void firstNoiseRainbow(int bpm, CRGB leds[]);
        /*  27 */ static void firstNoiseColor(CRGB color, int bpm, CRGB leds[]);
        /*  28 */ static void noisePalette(CRGBPalette16 palette, int scale, CRGB leds[]);
        /*  29 */ static void runFire(CRGBPalette16 palette, CRGB leds[]);
        /*  30 */ static void secondNoise(CRGBPalette16 palette, CRGB leds[]);
        /*  31 */ static void fillNoise16(CRGB leds[]);
        /*  32 */ static void rainbowDave(int density, int delta, CRGB leds[]);
        /*  33 */ static void marqueeDave(int inter, int hueChanging, int length, CRGB leds[]);
        /*  34 */ static void twinkleOld(int inter, CRGB leds[]);
        /*  35 */ static void twinkle(int inter, CRGB leds[]);
        /*  36 */ static void comet(int inter, int fade, int cometSize,  int delathue, CRGB leds[]);
        /*  37 */ static void cometOnce(int inter, int fade, int cometsize,  int delathue, double cometspeed, CRGB leds[]);
        /*  38 */ static void bounce(CRGB leds[], int balls, byte fade, bool mirror); // Not the best but we keep it for now 
        /*  39 */
        /*  40 */
        /*  41 */
        /*  42 */
        /*  43 */
        /*  44 */
        /*  45 */
        /*  46 */
        
    


        static uint32_t CRGBToInt(const CRGB& color);
        static uint8_t getBeatSinColor(uint32_t Color);
        static std::vector<uint8_t> getArrayRangeValue(uint32_t Color);
        static double TimeBounce();
        static double TimeTo();
        static double InitialBallSpeed(double height);
    
    private:
        int red;
        int green;
        int blue;
        void setColor(int r, int g, int b);

};