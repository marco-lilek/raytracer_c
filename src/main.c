#include <cglm/vec3.h>
#include <sclog4c/sclog4c.h>

#include "image.h"
#include "scene.h"
#include "config.h"

void init_starter_scene(scene_t *scene) {
  // @TODO NOOP
}

void init_basic_config(config_t *config) {
  config->img_width = 256;
  config->img_height = 256;
}

void init_point_to_world(mat4 *point_to_world, config_t *config) {
  // @TODO NOOP
}

void ray_from_eye_to_sceen(ray_t *ray, mat4 point_to_world) {
  // @TODO NOOP
}

void shoot_ray(scene_t *scene, vec3 color) {
  // @TODO
}

int main() {
  sclog4c_level = SL4C_ALL;

  logm(SL4C_DEBUG, "init scene");

  scene_t *scene = (scene_t *)malloc(sizeof(scene_t));
  init_starter_scene(scene);

  logm(SL4C_DEBUG, "init config");

  config_t config;
  init_basic_config(&config);

  logm(SL4C_DEBUG, "init img");
  
  int width = config.img_width;
  int height = config.img_height;
  image_t *img = (image_t *)malloc(sizeof(image_t));
  image_init_image(img, width, height);

  logm(SL4C_DEBUG, "init point_to_world");
  
  mat4 point_to_world;
  init_point_to_world(&point_to_world, &config);

  logm(SL4C_DEBUG, "starting render");

  ray_t ray;
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < width; y++) {
      ray_from_eye_to_sceen(&ray, point_to_world);

      vec3 color;
      shoot_ray(scene, color);

      image_draw(img, x, y, color);
    }
  }

  logm(SL4C_DEBUG, "completed render");
  
  image_save_to_png(img);

  logm(SL4C_DEBUG, "wrote");
}
