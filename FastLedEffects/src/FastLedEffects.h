#include <FastLED.h>
class FastLedEffects {
    public:
        static void fill(int r, int g, int b, CRGB leds[]);
        static void blink(int r, int g, int b, CRGB leds[], int long time);
        static void fillGradientTwoColors(int r1, int g1, int b1, int r2, int g2, int b2, CRGB leds[]);
        static void fillGradientThreeColors(int r1, int g1, int b1, int r2, int g2, int b2, int r3, int g3, int b3, CRGB leds[]);
        static void movingBar(CRGB leds[]);
    
    private:
        int red;
        int green;
        int blue;
        void setColor(int r, int g, int b);

};