#include "color.hpp"
#include <cstring>
#include <iostream>

float* Color::get_color(int R, int G, int B) {
  float *result = new float[24];
  for (int i = 0; i < 24; i++) {
    if(i % 4 == 0) {
      result[i] = float(R) / 256.0f;
    } else if(i % 4 == 1) {
      result[i] = float(G) / 256.0f;
    } else if(i % 4 == 2) {
      result[i] = float(B) / 256.0f;
    } else {
      result[i] = 1.0f;
    }
  }  
  return result;
}
