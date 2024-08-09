#include "main.h"

#include "asset.h"
#include "gif-pros/gifclass.hpp"
#include "liblvgl/lvgl.h"

ASSET(chip_gif)

static void draw_image(lv_obj_t *canvas, int x, int y, v5_image *image) {
  int start_x = x;
  int start_y = y;

  for (int i = 0; i < image->height; i++) {
    for (int j = 0; j < image->width; j++) {
      lv_color_t c = lv_color_hex(image->data[i * image->width + j]);
      lv_color_t d = lv_canvas_get_px(canvas, start_x + j, start_y + i);

      float a_float = c.ch.alpha / 2.55 / 100;
      float a_m_float = 1 - a_float;

      d.ch.red = d.ch.red * a_m_float + c.ch.red * a_float;
      d.ch.green = d.ch.green * a_m_float + c.ch.green * a_float;
      d.ch.blue = d.ch.blue * a_m_float + c.ch.blue * a_float;

      lv_canvas_set_px(canvas, start_x + j, start_y + i, d);
    }
  }
}

void initialize() {}

void opcontrol() {
  Gif gif(chip_gif, lv_scr_act());

  while (true) {
    pros::delay(20);
  }
}
