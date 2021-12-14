/*=============================================================================
   Copyright (c) 2021 Chance Snow, Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include <artist/circle.hpp>
#include <artist/c/point.h>
#include <artist/c/rect.h>

using namespace cycfi;

extern "C" {
   ////////////////////////////////////////////////////////////////////////////
   // Circles
   ////////////////////////////////////////////////////////////////////////////

   rect        artist_circle_bounds(circle c) { return artist::circle(c).bounds(); }

   point       artist_circle_center(circle c) { return artist::circle(c).center(); }
   circle      artist_circle_inset(circle c, float x) { return artist::circle(c).inset(x); }
   circle      artist_circle_move(circle c, float dx, float dy) { return artist::circle(c).move(dx, dy); }
   circle      artist_circle_move_to(circle c, float x, float y) { return artist::circle(c).move_to(x, y); }
}
