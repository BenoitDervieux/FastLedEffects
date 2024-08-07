#ifndef PALETTES_H
#define PALETTES_H

#include <Arduino.h>
#include <FastLED.h>

DEFINE_GRADIENT_PALETTE(heatmap_gp) {
    0, 0, 0, 0,
    128, 255, 0, 0,
    200, 255, 255, 0,
    255, 255, 255, 255
};

CRGBPalette16 purplePalette = CRGBPalette16 {
    CRGB::DarkViolet,
    CRGB::DarkViolet,
    CRGB::DarkViolet,
    CRGB::DarkViolet,

    CRGB::Magenta,
    CRGB::Magenta,
    CRGB::Linen,
    CRGB::Linen,

    CRGB::Magenta,
    CRGB::Magenta,
    CRGB::DarkViolet,
    CRGB::DarkViolet,

    CRGB::DarkViolet,
    CRGB::DarkViolet,
    CRGB::Linen,
    CRGB::Linen
};


#endif