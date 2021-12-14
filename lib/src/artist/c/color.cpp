/*=============================================================================
   Copyright (c) 2021 Chance Snow, Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include <artist/color.hpp>
#include <artist/c/color.h>

using namespace cycfi;

extern "C" {
   ////////////////////////////////////////////////////////////////////////////
   // Colors
   ////////////////////////////////////////////////////////////////////////////
   color artist_color_rgb_u32(uint32_t rgb) { return artist::rgb(rgb); }
   color artist_color_rgba_u32(uint32_t rgba) { return artist::rgba(rgba); }
   color artist_color_rgb(uint8_t r, uint8_t g, uint8_t b) { return artist::rgb(r, g, b); }
   color artist_color_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { return artist::rgba(r, g, b, a); }
   color artist_color_hsl(float h, float s, float l) { return artist::hsl(h, s, l); }
   color artist_color_opacity(color src, float alpha_) { return artist::color(src).opacity(alpha_); }
   color artist_color_level(color src, float amount) { return artist::color(src).level(amount); }
}
