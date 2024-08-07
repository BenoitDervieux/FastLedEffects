#include <FastLED.h>
#include <vector>
class FastLedEffects {
    public:
        static void fill(int r, int g, int b, CRGB leds[]);
        static void blink(int r, int g, int b, CRGB leds[], int long time);
        static void rainbowStatic(CRGB leds[]);
        static void fillGradientTwoColors(int r1, int g1, int b1, int r2, int g2, int b2, CRGB leds[]);
        static void fillGradientThreeColors(int r1, int g1, int b1, int r2, int g2, int b2, int r3, int g3, int b3, CRGB leds[]);
        static void backAndForthNoSmoothOneDot(int r, int g, int b, CRGB leds[], int long time);
        static void backAndForthNoSmoothLengthedDot(int r, int g, int b, CRGB leds[], int long time, int length);
        static void hueFading(int milliseconds, CRGB leds[]);
        static void hueWhiteWave(uint8_t hueInsert, int milliseconds, CRGB leds[]);
        static void displayPaletteLinear(CRGBPalette16 palette, CRGB leds[]);
        static void movingPaletteLinear(CRGBPalette16 palette, int milliseconds, CRGB leds[]);
        static void spotlightingPalette(CRGBPalette16 palette, int milliseconds, int fade, CRGB leds[]);
        static void sinBeat8(int r1, int r2, int r3, int fade, uint8_t bpm, CRGB leds[]);
        static void sinBeat8PhaseOff(int r1, int r2, int r3, int fade, uint8_t bpm, uint8_t phaseOffset, CRGB leds[]);
        static void sinBeat8TimeOff(int r1, int r2, int r3, int fade, uint8_t bpm, int time, CRGB leds[]);
        static void twoSinBeat8(int r1, int g1, int b1, int r2, int g2, int b2, int fade, uint8_t bpm, CRGB leds[]);
        static void threeSinBeat8(int r1, int g1, int b1, int r2, int g2, int b2, int r3, int g3, int b3, int fade, uint8_t bpm, CRGB leds[]);
        static void brightnessSinBeat8Palette(CRGBPalette16 palette, uint8_t bpm, int milliseconds, CRGB leds[]);
        static void funkyRainbowSinBeat8(int fade, CRGB leds[]);
        static void funkyRangeSinBeat8(int fade, CRGB color, CRGB leds[]);
        static void funkyRainbowSinBeat8Two(int fade, CRGB leds[]);
        static void funkyRangeSinBeat8Two(int fade, CRGB color, CRGB leds[]);
        static void movingFunkyPalette(CRGBPalette16 palette, int bpm1, int bpm2, CRGB leds[]);
        static void rainbowWave(int milliseconds, int fade, CRGB leds[]);
        static void choosenWave(int milliseconds, int fade, CRGB color, CRGB leds[]);
        static void firstNoiseRainbow(int bpm, CRGB leds[]);
        static void firstNoiseColor(CRGB color, int bpm, CRGB leds[]);
        static void noisePalette(CRGBPalette16 palette, int scale, CRGB leds[]);
    


        static uint32_t CRGBToInt(const CRGB& color);
        static uint8_t getBeatSinColor(uint32_t Color);
        static std::vector<uint8_t> getArrayRangeValue(uint32_t Color);
    
    private:
        int red;
        int green;
        int blue;
        void setColor(int r, int g, int b);

};