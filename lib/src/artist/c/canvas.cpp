/*=============================================================================
   Copyright (c) 2021 Chance Snow, Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include <artist/canvas.hpp>
#include <artist/c/artist.h>

using namespace cycfi;
extern "C" {
   canvas*           artist_canvas_create(canvas_impl* context_) { return (canvas*) new artist::canvas(context_); }
   void              artist_canvas_destroy(canvas* cnv) { delete cnv; }

   void              artist_canvas_pre_scale(canvas* cnv, float sc) { ((artist::canvas*)cnv)->pre_scale(sc); }
   float             artist_canvas_get_pre_scale(canvas* cnv) { return ((artist::canvas*)cnv)->pre_scale(); }

   ///////////////////////////////////////////////////////////////////////////////////
   // Transforms
   void              artist_canvas_translate_pt(canvas* cnv, point p) { ((artist::canvas*)cnv)->translate(*(artist::point*) &p); }
   void              artist_canvas_rotate(canvas* cnv, float rad) { ((artist::canvas*)cnv)->rotate(rad); }
   void              artist_canvas_scale_pt(canvas* cnv, point p) { ((artist::canvas*)cnv)->scale(*(artist::point*) &p); }
   void              artist_canvas_skew(canvas* cnv, double sx, double sy) { ((artist::canvas*)cnv)->skew(sx, sy); }
   point             artist_canvas_device_to_user_pt(canvas* cnv, point p) { return ((artist::canvas*)cnv)->device_to_user(*(artist::point*) &p); }
   point             artist_canvas_user_to_device_pt(canvas* cnv, point p) { return ((artist::canvas*)cnv)->user_to_device(*(artist::point*) &p); }

   void              artist_canvas_translate(canvas* cnv, float x, float y) { ((artist::canvas*)cnv)->translate(x, y); }
   void              artist_canvas_scale_square(canvas* cnv, float xy) { ((artist::canvas*)cnv)->scale(xy); }
   void              artist_canvas_scale(canvas* cnv, float x, float y) { ((artist::canvas*)cnv)->scale(x, y); }
   point             artist_canvas_device_to_user(canvas* cnv, float x, float y) { return ((artist::canvas*)cnv)->device_to_user(x, y); }
   point             artist_canvas_user_to_device(canvas* cnv, float x, float y) { return ((artist::canvas*)cnv)->user_to_device(x, y); }

   affine_transform  artist_canvas_get_transform(canvas* cnv) { return ((artist::canvas*)cnv)->transform(); }
   void              artist_canvas_transform(canvas* cnv, affine_transform const& mat) { ((artist::canvas*)cnv)->transform(mat); }
   void              artist_canvas_transform_spec(canvas* cnv, double a, double b, double c, double d, double tx, double ty) { ((artist::canvas*)cnv)->transform(a, b, c, d, tx, ty); }

   ///////////////////////////////////////////////////////////////////////////////////
   // Paths
   void              artist_canvas_begin_path(canvas* cnv) { ((artist::canvas*)cnv)->begin_path(); }
   void              artist_canvas_close_path(canvas* cnv) { ((artist::canvas*)cnv)->close_path(); }
   void              artist_canvas_fill(canvas* cnv) { ((artist::canvas*)cnv)->fill(); }
   void              artist_canvas_fill_preserve(canvas* cnv) { ((artist::canvas*)cnv)->fill_preserve(); }
   void              artist_canvas_stroke(canvas* cnv) { ((artist::canvas*)cnv)->stroke(); }
   void              artist_canvas_stroke_preserve(canvas* cnv) { ((artist::canvas*)cnv)->stroke_preserve(); }

   void              artist_canvas_clip(canvas* cnv) { ((artist::canvas*)cnv)->clip(); }
   void              artist_canvas_path_clip(canvas* cnv, path* p) { ((artist::canvas*)cnv)->clip(p); }
   rect              artist_canvas_get_clip_extent(canvas* cnv) { return ((artist::canvas*)cnv)->clip_extent(); }
   bool              artist_canvas_point_in_path_pt(canvas* cnv, point p) { return ((artist::canvas*)cnv)->point_in_path(*(artist::point*) &p); }
   bool              artist_canvas_point_in_path(canvas* cnv, float x, float y) { return ((artist::canvas*)cnv)->point_in_path(x, y); }
   rect              artist_canvas_get_fill_extent(canvas* cnv) { return ((artist::canvas*)cnv)->fill_extent(); }

   void              artist_canvas_move_to_pt(canvas* cnv, point p) { ((artist::canvas*)cnv)->move_to(*(artist::point*) &p); }
   void              artist_canvas_line_to_pt(canvas* cnv, point p) { ((artist::canvas*)cnv)->line_to(*(artist::point*) &p); }
   void              artist_canvas_arc_to_pts(canvas* cnv, point p1, point p2, float radius) { ((artist::canvas*)cnv)->arc_to(p1, p2, radius); }
   void              artist_canvas_arc_pt(
                        canvas* cnv,
                        point p, float radius,
                        float start_angle, float end_angle,
                        bool ccw
                     ) { ((artist::canvas*)cnv)->arc(p, radius, start_angle, end_angle, ccw); }
   void              artist_canvas_add_rect(canvas* cnv, const rect& r) { ((artist::canvas*)cnv)->add_rect(r); }
   void              artist_canvas_add_round_rect(canvas* cnv, const rect& r, float radius) { ((artist::canvas*)cnv)->add_round_rect(r, radius); }
   void              artist_canvas_add_circle(canvas* cnv, circle const& c) { ((artist::canvas*)cnv)->add_circle(c); }
   void              artist_canvas_add_path(canvas* cnv, path* p) { ((artist::canvas*)cnv)->add_path(*(artist::path*)p); }
   void              artist_canvas_clear_rect(canvas* cnv, rect const& r) { ((artist::canvas*)cnv)->clear_rect(r); }

   void              artist_canvas_quadratic_curve_to_pts(canvas* cnv, point cp, point end) { ((artist::canvas*)cnv)->quadratic_curve_to(cp, end); }
   void              artist_canvas_bezier_curve_to_pts(canvas* cnv, point cp1, point cp2, point end) { ((artist::canvas*)cnv)->bezier_curve_to(cp1, cp2, end); }

   void              artist_canvas_move_to(canvas* cnv, float x, float y) { ((artist::canvas*)cnv)->move_to(x, y); }
   void              artist_canvas_line_to(canvas* cnv, float x, float y) { ((artist::canvas*)cnv)->line_to(x, y); }
   void              artist_canvas_arc_to(
                        canvas* cnv,
                        float x1, float y1,
                        float x2, float y2,
                        float radius
                     ) { ((artist::canvas*)cnv)->arc_to(x1, y1, x2, y2, radius); }
   void              artist_canvas_arc(
                        canvas* cnv,
                        float x, float y, float radius,
                        float start_angle, float end_angle,
                        bool ccw
                     ) { ((artist::canvas*)cnv)->arc(x, y, radius, start_angle, end_angle, ccw); }
   void              artist_canvas_add_rect_xywh(canvas* cnv, float x, float y, float width, float height) { ((artist::canvas*)cnv)->add_rect(x, y, width, height); }
   void              artist_canvas_add_round_rect_xy(
                        canvas* cnv,
                        float x, float y,
                        float width, float height,
                        float radius
                     ) { ((artist::canvas*)cnv)->add_round_rect(x, y, width, height, radius); }
   void              artist_canvas_add_circle_xy(canvas* cnv, float cx, float cy, float radius) { ((artist::canvas*)cnv)->add_circle(cx, cy, radius); }
   void              artist_canvas_clear_rect_xywh(canvas* cnv, float x, float y, float width, float height) { ((artist::canvas*)cnv)->clear_rect(x, y, width, height); }

   void              artist_canvas_quadratic_curve_to(canvas* cnv, float cpx, float cpy, float x, float y) { ((artist::canvas*)cnv)->quadratic_curve_to(cpx, cpy, x, y); }
   void              artist_canvas_bezier_curve_to(
                        canvas* cnv,
                        float cp1x, float cp1y,
                        float cp2x, float cp2y,
                        float x, float y
                     ) { ((artist::canvas*)cnv)->bezier_curve_to(cp1x, cp1y, cp2x, cp2y, x, y); }

   ///////////////////////////////////////////////////////////////////////////////////
   // Styles
   void              artist_canvas_fill_style(canvas* cnv, color c) { ((artist::canvas*)cnv)->fill_style(c); }
   void              artist_canvas_stroke_style(canvas* cnv, color c) { ((artist::canvas*)cnv)->stroke_style(c); }
   void              artist_canvas_line_width(canvas* cnv, float w) { ((artist::canvas*)cnv)->line_width(w); }
   void              artist_canvas_line_cap(canvas* cnv, line_cap_enum cap) { ((artist::canvas*)cnv)->line_cap(cap); }
   void              artist_canvas_line_join(canvas* cnv, join_enum join) { ((artist::canvas*)cnv)->line_join(join); }
   void              artist_canvas_miter_limit(canvas* cnv, float limit) { ((artist::canvas*)cnv)->miter_limit(limit); }
   void              artist_canvas_shadow_style_offset(canvas* cnv, point offset, float blur, color c) { ((artist::canvas*)cnv)->shadow_style(offset, blur, c); }
   void              artist_canvas_shadow_style_offset_xy(canvas* cnv, float offsetx, float offsety, float blur, color c) { ((artist::canvas*)cnv)->shadow_style(offsetx, offsety, blur, c); }
   void              artist_canvas_shadow_style(canvas* cnv, float blur, color c) { ((artist::canvas*)cnv)->shadow_style(blur, c); }

   void              artist_canvas_stroke_color(canvas* cnv, color c) { ((artist::canvas*)cnv)->stroke_color(c); }
   void              artist_canvas_fill_color(canvas* cnv, color c) { ((artist::canvas*)cnv)->fill_color(c); }

   void              artist_canvas_global_composite_operation(canvas* cnv, composite_op_enum mode) { ((artist::canvas*)cnv)->global_composite_operation(mode); }
   void              artist_canvas_composite_op(canvas* cnv, composite_op_enum mode) { ((artist::canvas*)cnv)->composite_op(mode); }

   ///////////////////////////////////////////////////////////////////////////////////
   // Gradients
   // TODO: Interop with C arrays
   // struct gradient
   // {
   //    void  add_color_stop(canvas* cnv, color_stop cs);
   //    void  add_color_stop(canvas* cnv, float offset, struct color color_);
   //    std::vector<color_stop> color_space = {};
   // };

   // struct linear_gradient : gradient
   // {
   //    linear_gradient(float startx, float starty, float endx, float endy)
   //       : start{ startx, starty }
   //       , end{ endx, endy }
   //    {}

   //    linear_gradient(point start, point end)
   //       : start{ start }
   //       , end{ end }
   //    {}

   //    point start = {};
   //    point end = {};
   // };

   // struct radial_gradient : gradient
   // {
   //    radial_gradient(
   //       float c1x, float c1y, float c1r,
   //       float c2x, float c2y, float c2r
   //    )
   //       : c1{ c1x, c1y }
   //       , c1_radius{ c1r }
   //       , c2{ c2x, c2y }
   //       , c2_radius{ c2r }
   //    {}

   //    radial_gradient(
   //       point c1, float c1r,
   //       point c2, float c2r
   //    )
   //       : c1{ c1 }
   //       , c1_radius{ c1r }
   //       , c2{ c2 }
   //       , c2_radius{ c2r }
   //    {}

   //    point c1 = {};
   //    float c1_radius = {};
   //    point c2 = c1;
   //    float c2_radius = c1_radius;
   // };

   ///////////////////////////////////////////////////////////////////////////////////
   // More Styles
   // TODO: Interop with C arrays for gradients
   // void              artist_canvas_linear_gradient_fill_style(canvas* cnv, linear_gradient const& gr) { ((artist::canvas*)cnv)->fill_style(gr); }
   // void              artist_canvas_radial_gradient_fill_style(canvas* cnv, radial_gradient const& gr) { ((artist::canvas*)cnv)->fill_style(gr); }
   // void              artist_canvas_linear_gradient_stroke_style(canvas* cnv, linear_gradient const& gr) { ((artist::canvas*)cnv)->stroke_style(gr); }
   // void              artist_canvas_radial_gradient_stroke_style(canvas* cnv, radial_gradient const& gr) { ((artist::canvas*)cnv)->stroke_style(gr); }

   ///////////////////////////////////////////////////////////////////////////////////
   // Fill Rule

   void              artist_canvas_fill_rule(canvas* cnv, fill_rule_enum rule) { ((artist::canvas*)cnv)->fill_rule(rule); }

   ///////////////////////////////////////////////////////////////////////////////////
   // Rectangles
   void              artist_canvas_fill_rect(canvas* cnv, rect const& r) { ((artist::canvas*)cnv)->fill_rect(r); }
   void              artist_canvas_fill_round_rect(canvas* cnv, rect const& r, float radius) { ((artist::canvas*)cnv)->fill_round_rect(r, radius); }
   void              artist_canvas_stroke_rect(canvas* cnv, rect const& r) { ((artist::canvas*)cnv)->stroke_rect(r); }
   void              artist_canvas_stroke_round_rect(canvas* cnv, rect const& r, float radius) { ((artist::canvas*)cnv)->stroke_round_rect(r, radius); }

   void              artist_canvas_fill_rect_xywh(canvas* cnv, float x, float y, float width, float height) { ((artist::canvas*)cnv)->fill_rect(x, y, width, height); }
   void              artist_canvas_fill_round_rect_xywh(canvas* cnv, float x, float y, float width, float height, float radius) { ((artist::canvas*)cnv)->fill_round_rect(x, y, width, height, radius); }
   void              artist_canvas_stroke_rect_xywh(canvas* cnv, float x, float y, float width, float height) { ((artist::canvas*)cnv)->stroke_rect(x, y, width, height); }
   void              artist_canvas_stroke_round_rect_xywh(canvas* cnv, float x, float y, float width, float height, float radius) { ((artist::canvas*)cnv)->stroke_round_rect(x, y, width, height, radius); }

   ///////////////////////////////////////////////////////////////////////////////////
   // Font
   void              artist_canvas_font(canvas* cnv, font* const font_) { ((artist::canvas*)cnv)->font(*font_); }

   ///////////////////////////////////////////////////////////////////////////////////
   // Text

   void              artist_canvas_fill_text_pt(canvas* cnv, string_view* utf8, point p) { ((artist::canvas*)cnv)->fill_text(*utf8, p); }
   void              artist_canvas_stroke_text_pt(canvas* cnv, string_view* utf8, point p) { ((artist::canvas*)cnv)->stroke_text(*utf8, p); }
   text_metrics      artist_canvas_measure_text(canvas* cnv, string_view* utf8) { ((artist::canvas*)cnv)->measure_text(*utf8); }

   void              artist_canvas_text_align(canvas* cnv, int align) { ((artist::canvas*)cnv)->text_align(align); }
   void              artist_canvas_text_halign(canvas* cnv, text_halign align) { ((artist::canvas*)cnv)->text_align(align); }
   void              artist_canvas_text_baseline(canvas* cnv, text_valign align) { ((artist::canvas*)cnv)->text_baseline(align); }

   void              artist_canvas_fill_text(canvas* cnv, string_view* utf8, float x, float y) { ((artist::canvas*)cnv)->fill_text(*utf8, x, y); }
   void              artist_canvas_stroke_text(canvas* cnv, string_view* utf8, float x, float y) { ((artist::canvas*)cnv)->stroke_text(*utf8, x, y); }

   ///////////////////////////////////////////////////////////////////////////////////
   // Pixmaps

   void              artist_canvas_draw_pic_src_dst(canvas* cnv, image* pic, rect const& src, rect const& dest) { ((artist::canvas*)cnv)->draw(*pic, src, dest); }
   void              artist_canvas_draw_pic_dst(canvas* cnv, image* pic, rect const& dest) { ((artist::canvas*)cnv)->draw(*pic, dest); }
   void              artist_canvas_draw_pic_pos(canvas* cnv, image* pic, point pos) { ((artist::canvas*)cnv)->draw(*pic, pos); }
   void              artist_canvas_draw_pic_pos_scale(canvas* cnv, image* pic, point pos, float scale) { ((artist::canvas*)cnv)->draw(*pic, pos, scale); }
   void              artist_canvas_draw_pic_xy(canvas* cnv, image* pic, float posx, float posy) { ((artist::canvas*)cnv)->draw(*pic, posx, posy); }
   void              artist_canvas_draw_pic_xy_scale(canvas* cnv, image* pic, float posx, float posy, float scale) { ((artist::canvas*)cnv)->draw(*pic, posx, posy, scale); }
}
