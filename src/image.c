#include "image.h"
#include <cglm/util.h>
#include <lodepng.h>
#include <assert.h>
#include <sclog4c/sclog4c.h>

void image_init_image(image_t *img, int width, int height) {
  img->width = width;
  img->height = height;
  img->data = (vec3 *)malloc(sizeof(vec3) * width * height);
}

void image_draw(image_t *img, int x, int y, vec3 color) {
  glm_vec3_copy(color, img->data[y * img->width + x]);
}

static char convert(float v) {
  return (char)(255.0 * glm_clamp(v, 0.0, 1.0));
}

inline static float image_read(image_t *img, int e, int o) {
  return img->data[e][o];
}

void image_save_to_png(image_t *img) {
  int width = img->width;
  int height = img->height;
  int len = width * height;
  logm(SL4C_DEBUG, "rendering w %d h %d len %d", width, height, len);
  char *encoded = (char *)malloc(sizeof(char) * len * 4);
  for (int i = 0; i < len; i++) {
    encoded[i*4+0] = convert(img->data[i][0]);
    encoded[i*4+1] = convert(img->data[i][1]);
    encoded[i*4+2] = convert(img->data[i][2]);
    encoded[i*4+3] = 255;
  }

  int error = lodepng_encode32_file("dummy.png", encoded, width, height);
  if (error) {
    logm(SL4C_ERROR, "lodepng error %s", lodepng_error_text(error));
    assert(0);
  }
}
