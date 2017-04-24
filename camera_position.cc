#include "CameraPosition.h"

CamaraPosition::CameraPosition(float eyex, float eyey, float eyez, 
    float centerx, float centery, float centerz, 
    float upx, float upy, float upz) {
  _eyex = eyex;
  _eyey = eyey;
  _eyez = eyey;
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
void CamaraPosition::set_center(float x, float y, float z) {
  _centerx = x;
  _centery = y;
  _centerz = z;
}
void CameraPosition::set_up(float x, float y, float z) {
  _upx = x;
  _upy = y;
  _upz = z;
}
