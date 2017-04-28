#ifndef __OBJECT_H__
#define __OBJECT_H__

#define XAXIS 1
#define YAXIS 2
#define ZAXIS 3


#include "vec.hpp"
#include "mat.hpp"
#include "transform.hpp"
#include "operator.hpp"
#include "color.h"

using namespace::kmuvcl::math;

class Object {
  public :
    Object();
    Object(float* vertice, float* colors);
    Object(float* vertice);
    void init(float* vertice, float* colors);
    void init(float* vertice);
    mat4x4f get_translate();
    mat4x4f get_rotate();
    mat4x4f get_scale();
    float* get_vertice();
    float* get_colors();
    void translate(mat4x4f translate);
    void translate(float value, int diretion);
    void translate(float x, float y, float z);
    void rotate(mat4x4f rotate);
    void scale(mat4x4f scale);
    void scale(float value, int diretion);
    void set_vertice(float* vertice);
    void set_colors(float* colors);
    void set_colors(int r, int g, int b);
  private :
    int _number_of_vertex;
    float* _vertice;
    float* _colors;
    static Color* _color_factory;
    mat4x4f _translate;
    mat4x4f _rotate;
    mat4x4f _scale;
};

#endif
