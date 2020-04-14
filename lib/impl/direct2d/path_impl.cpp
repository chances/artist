/*=============================================================================
   Copyright (c) 2016-2020 Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include <path_impl.hpp>

namespace cycfi::artist
{
   d2d_geometry* path_impl::compute_fill()
   {
      if (_geometries.empty())
         return nullptr;
      if (_geometries.size() == 1)
         return _geometries[0];

      if (_fill_geom)
         return _fill_geom;
      _fill_geom = make_group(_geometries, _mode);
      return _fill_geom;
   }

   void path_impl::clear()
   {
      for (auto& g : _geometries)
         release(g);
      _geometries.clear();
      _elements.clear();
      release(_fill_geom);
   }

   void path_impl::fill(
      d2d_canvas& cnv
    , d2d_paint* paint
    , bool preserve)
   {
      if (!empty())
      {
         cnv.FillGeometry(compute_fill(), paint, nullptr);
         if (!preserve)
            clear();
      }
   }

   void path_impl::stroke(
      d2d_canvas& cnv
    , d2d_paint* paint
    , float line_width
    , bool preserve)
   {
      if (!empty())
      {
         for (auto p : _geometries)
            cnv.DrawGeometry(p, paint, line_width, nullptr);
         if (!preserve)
            clear();
      }
   }
}

