/*=============================================================================
   Copyright (c) 2016-2020 Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(ARTIST_CIRCLE_APRIL_17_2016)
#define ARTIST_CIRCLE_APRIL_17_2016

#include <artist/c/circle.h>
#include <artist/rect.hpp>
#include <algorithm>

namespace cycfi::artist
{
   ////////////////////////////////////////////////////////////////////////////
   // Circles
   ////////////////////////////////////////////////////////////////////////////
   struct circle : artist_circle
   {
      constexpr   circle();
      constexpr   circle(float cx, float cy, float radius);
      constexpr   circle(point c, float radius);
      constexpr   circle(artist_circle const& c);
      constexpr   circle(rect const& r);
                  circle(circle const&) = default;
      circle&     operator=(circle const&) = default;

      rect        bounds() const { return { cx-radius, cy-radius, cx+radius, cy+radius }; }
      bool        operator==(circle const& other) const;
      bool        operator!=(circle const& other) const;

      point       center() const;
      circle      inset(float x) const;
      circle      move(float dx, float dy) const;
      circle      move_to(float x, float y) const;
   };

   ////////////////////////////////////////////////////////////////////////////
   // Inlines
   ////////////////////////////////////////////////////////////////////////////
   inline constexpr circle::circle()
    : circle(0.0, 0.0, 0.0)
   {}

   inline constexpr circle::circle(point c, float radius)
    : circle(c.x, c.y, radius)
   {}

   inline constexpr circle::circle(artist_circle const& c)
    : circle(c.cx, c.cy, c.radius)
   {}

   inline constexpr circle::circle(rect const& r)
    : circle(center_point(r), std::min(r.width(), r.height()))
   {}

   inline bool circle::operator==(circle const& other) const
   {
      return (other.cx == cx) && (other.cy == cy) && (other.radius == radius);
   }

   inline bool circle::operator!=(circle const& other) const
   {
      return !(*this == other);
   }

   inline point circle::center() const
   {
      return { cx, cy };
   }

   inline circle circle::inset(float x) const
   {
      return { cx, cy, radius-x };
   }

   inline circle circle::move(float dx, float dy) const
   {
      return { cx+dx, cy+dy, radius };
   }

   inline circle circle::move_to(float x, float y) const
   {
      return { x, y, radius };
   }
}

#endif
