// led-control WS2812B LED Controller Server
// Copyright 2019 jackw01. Released under the MIT License (see LICENSE for details).

#ifndef __ANIMATION_UTILS_H__
#define __ANIMATION_UTILS_H__

#include <math.h>

// Optimized C utility functions
// Waveforms for pattern generation. All have a period of 2 time units and range from 0-1.

// Sine
float wave_sine(float t) {
  return cos(6.283 * t) / 2.0 + 0.5;
}

// Sine approximation (triangle wave with cubic in-out easing)
float wave_cubic(float t) {
  float tri = fabs(fmod(2.0 * t, 2.0) - 1.0);
  if (tri > 0.5) {
    float t2 = 1.0 - tri;
    return 1.0 - 4.0 * t2 * t2 * t2;
  } else {
    return 4.0 * tri * tri * tri;
  }
}

#endif
