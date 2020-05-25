#include "types.h"

// TODO: could just generalize to a 2D array that also holds its dimensions
typedef struct image_s {
  int width, height;
  color_at* data;
} image_t;

void image_init_image(image_t *img, int width, int height);
void image_draw(image_t *img, int x, int y, color_at color);

void image_save_to_png(image_t *img);
