/*=============================================================================
   Copyright (c) 2016-2020 Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(ARTIST_FONT_FEBRUARY_11_2020)
#define ARTIST_FONT_FEBRUARY_11_2020

#include <artist/c/font.h>
#include <string_view>
#include <infra/filesystem.hpp>
#include <memory>
#include <vector>

#if defined(ARTIST_SKIA)
class SkFont;
#endif

namespace cycfi::artist
{
#if defined(ARTIST_SKIA)
   using font_impl = SkFont;
   using font_impl_ptr = std::shared_ptr<SkFont>;
#else
   struct font_impl;
   using font_impl_ptr = font_impl*;
#endif

   namespace font_constants
   {
      typedef artist_weight_enum weight_enum;
      typedef artist_slant_enum slant_enum;
      typedef artist_stretch_enum stretch_enum;
   }

   struct font_descr : artist_font_descr
   {
      font_descr           normal() const;
      font_descr           size(float size_) const;

      font_descr           weight(font_constants::weight_enum w) const;
      font_descr           thin() const;
      font_descr           extra_light() const;
      font_descr           light() const;
      font_descr           weight_normal() const;
      font_descr           medium() const;
      font_descr           semi_bold() const;
      font_descr           bold() const;
      font_descr           extra_bold() const;
      font_descr           black() const;
      font_descr           extra_black() const;

      font_descr           style(font_constants::slant_enum s) const;
      font_descr           slant_normal() const;
      font_descr           italic() const;
      font_descr           oblique() const;

      font_descr           stretch(font_constants::stretch_enum s) const;
      font_descr           ultra_condensed() const;
      font_descr           extra_condensed() const;
      font_descr           condensed() const;
      font_descr           semi_condensed() const;
      font_descr           stretch_normal() const;
      font_descr           semi_expanded() const;
      font_descr           expanded() const;
      font_descr           extra_expanded() const;
      font_descr           ultra_expanded() const;

      using slant_enum = font_constants::slant_enum;
   };

   class font
   {
   public:
                           font();
                           font(font_descr descr);
                           font(font const& rhs);
                           font(font&& rhs) noexcept;
                           ~font();

      font&                operator=(font const& rhs);
      font&                operator=(font&& rhs) noexcept;
      explicit             operator bool() const;
      font_impl_ptr        impl() const;

      typedef artist_metrics_info metrics_info;

      metrics_info         metrics() const;
      float                line_height() const;
      float                measure_text(std::string_view str) const;

   private:

      friend class canvas;
      font_impl_ptr        _ptr;
   };

   ////////////////////////////////////////////////////////////////////////////
   // Inlines
   ////////////////////////////////////////////////////////////////////////////
   inline font_impl_ptr font::impl() const
   {
      return _ptr;
   }

   inline font_descr font_descr::normal() const
   {
      font_descr r = *this;
      r._weight = font_constants::weight_enum::weight_normal;
      r._slant = font_constants::slant_enum::slant_normal;
      r._stretch = font_constants::stretch_enum::stretch_normal;
      return r;
   }

   inline font_descr font_descr::size(float size_) const
   {
      font_descr r = *this;
      r._size = size_;
      return r;
   }

   inline font_descr font_descr::weight(font_constants::weight_enum w) const
   {
      font_descr r = *this;
      r._weight = w;
      return r;
   }

   inline font_descr font_descr::thin() const
   {
      font_descr r = *this;
      r._weight = font_constants::weight_enum::thin;
      return r;
   }

   inline font_descr font_descr::extra_light() const
   {
      font_descr r = *this;
      r._weight = font_constants::weight_enum::extra_light;
      return r;
   }

   inline font_descr font_descr::light() const
   {
      font_descr r = *this;
      r._weight = font_constants::weight_enum::light;
      return r;
   }

   inline font_descr font_descr::weight_normal() const
   {
      font_descr r = *this;
      r._weight = font_constants::weight_enum::weight_normal;
      return r;
   }

   inline font_descr font_descr::medium() const
   {
      font_descr r = *this;
      r._weight = font_constants::weight_enum::medium;
      return r;
   }

   inline font_descr font_descr::semi_bold() const
   {
      font_descr r = *this;
      r._weight = font_constants::weight_enum::semi_bold;
      return r;
   }

   inline font_descr font_descr::bold() const
   {
      font_descr r = *this;
      r._weight = font_constants::weight_enum::bold;
      return r;
   }

   inline font_descr font_descr::extra_bold() const
   {
      font_descr r = *this;
      r._weight = font_constants::weight_enum::extra_bold;
      return r;
   }

   inline font_descr font_descr::black() const
   {
      font_descr r = *this;
      r._weight = font_constants::weight_enum::black;
      return r;
   }

   inline font_descr font_descr::extra_black() const
   {
      font_descr r = *this;
      r._weight = font_constants::weight_enum::extra_black;
      return r;
   }

   inline font_descr font_descr::style(font_constants::slant_enum s) const
   {
      font_descr r = *this;
      r._slant = s;
      return r;
   }

   inline font_descr font_descr::slant_normal() const
   {
      font_descr r = *this;
      r._slant = font_constants::slant_enum::slant_normal;
      return r;
   }

   inline font_descr font_descr::italic() const
   {
      font_descr r = *this;
      r._slant = font_constants::slant_enum::italic;
      return r;
   }

   inline font_descr font_descr::oblique() const
   {
      font_descr r = *this;
      r._slant = font_constants::slant_enum::oblique;
      return r;
   }

   inline font_descr font_descr::stretch(font_constants::stretch_enum s) const
   {
      font_descr r = *this;
      r._stretch = s;
      return r;
   }

   inline font_descr font_descr::ultra_condensed() const
   {
      font_descr r = *this;
      r._stretch = font_constants::stretch_enum::ultra_condensed;
      return r;
   }

   inline font_descr font_descr::extra_condensed() const
   {
      font_descr r = *this;
      r._stretch = font_constants::stretch_enum::extra_condensed;
      return r;
   }

   inline font_descr font_descr::condensed() const
   {
      font_descr r = *this;
      r._stretch = font_constants::stretch_enum::condensed;
      return r;
   }

   inline font_descr font_descr::semi_condensed() const
   {
      font_descr r = *this;
      r._stretch = font_constants::stretch_enum::semi_condensed;
      return r;
   }

   inline font_descr font_descr::stretch_normal() const
   {
      font_descr r = *this;
      r._stretch = font_constants::stretch_enum::stretch_normal;
      return r;
   }

   inline font_descr font_descr::semi_expanded() const
   {
      font_descr r = *this;
      r._stretch = font_constants::stretch_enum::semi_expanded;
      return r;
   }

   inline font_descr font_descr::expanded() const
   {
      font_descr r = *this;
      r._stretch = font_constants::stretch_enum::expanded;
      return r;
   }

   inline font_descr font_descr::extra_expanded() const
   {
      font_descr r = *this;
      r._stretch = font_constants::stretch_enum::extra_expanded;
      return r;
   }

   inline font_descr font_descr::ultra_expanded() const
   {
      font_descr r = *this;
      r._stretch = font_constants::stretch_enum::ultra_expanded;
      return r;
   }

   inline font::operator bool() const
   {
      return bool(_ptr);
   }

   inline float font::line_height() const
   {
      auto m = metrics();
      return m.ascent + m.descent + m.leading;
   }

   fs::path get_user_fonts_directory();
}

#endif
