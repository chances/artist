/*=============================================================================
   Copyright (c) 2021 Chance Snow, Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include <artist/font.hpp>
#include <artist/c/font.h>

using namespace cycfi;

artist::font_descr from_c_font_descr(artist_font_descr const& f) {
   return artist::font_descr {
      f._families,
      f._size,
      f._weight,
      f._slant,
      f._stretch,
   };
}

extern "C" {
   artist_font_descr     artist_font_descr_normal(artist_font_descr f) { return from_c_font_descr(f).normal(); }
   artist_font_descr     artist_font_descr_size(artist_font_descr f, float size_) { return from_c_font_descr(f).size(size_); }

   artist_font_descr     artist_font_descr_weight(artist_font_descr f, artist_weight_enum w) { return from_c_font_descr(f).weight(w); }
   artist_font_descr     artist_font_descr_thin(artist_font_descr f) { return from_c_font_descr(f).thin(); }
   artist_font_descr     artist_font_descr_extra_light(artist_font_descr f) { return from_c_font_descr(f).extra_light(); }
   artist_font_descr     artist_font_descr_light(artist_font_descr f) { return from_c_font_descr(f).light(); }
   artist_font_descr     artist_font_descr_weight_normal(artist_font_descr f) { return from_c_font_descr(f).weight_normal(); }
   artist_font_descr     artist_font_descr_medium(artist_font_descr f) { return from_c_font_descr(f).medium(); }
   artist_font_descr     artist_font_descr_semi_bold(artist_font_descr f) { return from_c_font_descr(f).semi_bold(); }
   artist_font_descr     artist_font_descr_bold(artist_font_descr f) { return from_c_font_descr(f).bold(); }
   artist_font_descr     artist_font_descr_extra_bold(artist_font_descr f) { return from_c_font_descr(f).extra_bold(); }
   artist_font_descr     artist_font_descr_black(artist_font_descr f) { return from_c_font_descr(f).black(); }
   artist_font_descr     artist_font_descr_extra_black(artist_font_descr f) { return from_c_font_descr(f).extra_black(); }

   artist_font_descr     artist_font_descr_style(artist_font_descr f, artist_slant_enum s) { return from_c_font_descr(f).style(s); }
   artist_font_descr     artist_font_descr_slant_normal(artist_font_descr f) { return from_c_font_descr(f).slant_normal(); }
   artist_font_descr     artist_font_descr_italic(artist_font_descr f) { return from_c_font_descr(f).italic(); }
   artist_font_descr     artist_font_descr_oblique(artist_font_descr f) { return from_c_font_descr(f).oblique(); }

   artist_font_descr     artist_font_descr_stretch(artist_font_descr f, artist_stretch_enum s) { return from_c_font_descr(f).stretch(s); }
   artist_font_descr     artist_font_descr_ultra_condensed(artist_font_descr f) { return from_c_font_descr(f).ultra_condensed(); }
   artist_font_descr     artist_font_descr_extra_condensed(artist_font_descr f) { return from_c_font_descr(f).extra_condensed(); }
   artist_font_descr     artist_font_descr_condensed(artist_font_descr f) { return from_c_font_descr(f).condensed(); }
   artist_font_descr     artist_font_descr_semi_condensed(artist_font_descr f) { return from_c_font_descr(f).semi_condensed(); }
   artist_font_descr     artist_font_descr_stretch_normal(artist_font_descr f) { return from_c_font_descr(f).stretch_normal(); }
   artist_font_descr     artist_font_descr_semi_expanded(artist_font_descr f) { return from_c_font_descr(f).semi_expanded(); }
   artist_font_descr     artist_font_descr_expanded(artist_font_descr f) { return from_c_font_descr(f).expanded(); }
   artist_font_descr     artist_font_descr_extra_expanded(artist_font_descr f) { return from_c_font_descr(f).extra_expanded(); }
   artist_font_descr     artist_font_descr_ultra_expanded(artist_font_descr f) { return from_c_font_descr(f).ultra_expanded(); }

   artist_font*         artist_font_create() { return (artist_font*) new artist::font(); }
   artist_font*         artist_font_create_with_descr(artist_font_descr descr) { return (artist_font*) new artist::font(from_c_font_descr(descr)); }
   void                 artist_font_destroy(artist_font* f) { delete f; }

   artist_metrics_info  artist_font_metrics(artist_font* f) { return ((artist::font*)f)->metrics(); }
   float                artist_font_line_height(artist_font* f) { return ((artist::font*)f)->line_height(); }
   float                artist_font_measure_text(artist_font* f, string_view* str) { return ((artist::font*)f)->measure_text(*(std::string_view*)str); }
}
