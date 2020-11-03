// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(DOFUS)
RGB_MATRIX_EFFECT(FN)
RGB_MATRIX_EFFECT(CAPSLOCK)
RGB_MATRIX_EFFECT(FN2)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
  static bool DOFUS(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
      rgb_matrix_set_color(i, RGB_YELLOW);
    }
    return led_max < DRIVER_LED_TOTAL;
  }

  static bool FN(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
      rgb_matrix_set_color(i, RGB_CYAN);
    }
    return led_max < DRIVER_LED_TOTAL;
  }

  static bool CAPSLOCK(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
      rgb_matrix_set_color(i, RGB_RED);
    }
    return led_max < DRIVER_LED_TOTAL;
  }

  static bool FN2(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
      rgb_matrix_set_color(i, RGB_GREEN);
    }
    return led_max < DRIVER_LED_TOTAL;
  }
#endif