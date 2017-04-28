#include "camera_position.h"

CameraPosition::CameraPosition(float eyex, float eyey, float eyez, 
    float centerx, float centery, float centerz, 
    float upx, float upy, float upz) {
  _eyex = eyex;
  _eyey = eyey;
  _eyez = eyez;
  _centerx = centerx;
  _centery = centery;
  _centerz = centerz;
  _upx = upx;
  _upy = upy;
  _upz = upz;
}
void CameraPosition::set_eye(float x, float y, float z) {
  _eyex = x;
  _eyey = y;
  _eyez = z;
}
void CameraPosition::set_center(float x, float y, float z) {
  _centerx = x;
  _centery = y;
  _centerz = z;
}
void CameraPosition::set_up(float x, float y, float z) {
  _upx = x;
  _upy = y;
  _upz = z;
}
vec3f CameraPosition::get_eye() {
  return vec3f(_eyex, _eyey, _eyez);
}vec3f CameraPosition::get_center() {
  return vec3f(_centerx, _centery, _centerz);
}vec3f CameraPosition::get_up() {
  return vec3f(_upx, _upy, _upz);
}
