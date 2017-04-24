#include "camera.h"

Camera::Camera(CameraPosition position, CameraView view) {
  _position = position;
  _view = view;
}
void Camera::set_eye(float x, float y, float z) {
   _position.set_eye(x, y, z);
}
void Camera::set_center(floatx, float y, float z) {
  _position.set_center(x, y, z);
}
void Camera::set_up(float x, float y, float z) {
  _position.set_up(x, y, z);
}
void Camera::set_fovy(float fovy) {
  _position.set_fovy(fovy);
}
