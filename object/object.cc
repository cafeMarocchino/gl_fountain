#include "object.h"
 
Color* Object::_color_factory = new Color();

Object::Object(float* vertice, float* colors) {
  _vertice = vertice;
  _colors = colors;
  _number_of_vertex = sizeof(vertice) / sizeof(*vertice);
}
Object::Object(float* vertice) {
  _vertice = vertice;
  _colors = _color_factory->get_color(255, 0, 0);
}
Object::Object() {
  _colors = _color_factory->get_color(255, 0 ,0);
}
void Object::init(float* vertice, float* colors) {
  _vertice = vertice;
  _colors = colors;
  _number_of_vertex = sizeof(vertice) / sizeof(*vertice);
}
void Object::init(float* vertice) {
  _vertice = vertice;
  _colors = _color_factory->get_color(255, 0, 0);
}
mat4x4f Object::get_translate() {
  return _translate;
}
mat4x4f Object::get_rotate() {
  return _rotate;
}
mat4x4f Object::get_scale() {
  return _scale;
}
float* Object::get_vertice() {
  return _vertice;
}
float* Object::get_colors() {
  return _colors;
}
void Object::translate(mat4x4f translate){
  _translate = translate;
}
void Object::translate(float x, float y, float z) {
  _translate = kmuvcl::math::translate(x, y, z);
}
void Object::translate(float value, int diretion) {
  switch(diretion) {
    case XAXIS: 
      _translate = kmuvcl::math::translate(value, 0.0f, 0.0f);
      break;
    case YAXIS:
      _translate = kmuvcl::math::translate(0.0f, value, 0.0f);
      break;
    case ZAXIS:
      _translate = kmuvcl::math::translate(0.0f, 0.0f, value);
      break;
  }
}
void Object::rotate(mat4x4f rotate) {
  _rotate = rotate;
}
void Object::scale(mat4x4f scale) {
  _scale = scale;
}
void Object::scale(float value, int diretion) {
  switch(diretion) {
    case XAXIS: 
      _scale = kmuvcl::math::scale(value, 0.0f, 0.0f);
      break;
    case YAXIS:
      _scale = kmuvcl::math::scale(0.0f, value, 0.0f);
      break;
    case ZAXIS:
      _scale = kmuvcl::math::scale(0.0f, 0.0f, value);
      break;
  }
}
void Object::set_vertice(float* vertice) {
  _vertice = vertice;
}
void Object::set_colors(float* colors) {
  _colors = colors;
}
void Object::set_colors(int r, int g, int b) {
  _colors = _color_factory->get_color(r, g, b);
}
