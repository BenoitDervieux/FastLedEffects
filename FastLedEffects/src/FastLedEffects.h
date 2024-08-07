#include <FastLED.h>
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
    
    private:
        int red;
        int green;
        int blue;
        void setColor(int r, int g, int b);

};