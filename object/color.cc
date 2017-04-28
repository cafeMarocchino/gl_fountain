#include "color.h"
#include <cstring>
#include <iostream>

float* Color::get_color(int r, int g, int b) {
  if(fool[r][g][b] != NULL) {
    return fool[r][g][b];
  } else {
    float *result = new float[24];
    for (int i = 0; i < 24; i++) {
      if(i % 4 == 0) {
        result[i] = float(r) / 256.0f;
      } else if(i % 4 == 1) {
        result[i] = float(g) / 256.0f;
      } else if(i % 4 == 2) {
        result[i] = float(b) / 256.0f;
      } else {
        result[i] = 1.0f;
      }
    }
    fool[r][g][b] = result;
    return result;
  }
}
Color::Color() {
  for(int i = 0; i < 256; i++) {
    for(int j = 0; j < 256; j++) {
      for(int n = 0; n < 256; n++) {
        fool[i][j][n] = NULL;
      }
    }
  }
}
Color::~Color() {
  for(int i = 0; i < 256; i++) {
    for(int j = 0; j < 256; j++) {
      for(int n = 0; n < 256; n++) {
        delete fool[i][j][n];
      }
    }
  }
}
