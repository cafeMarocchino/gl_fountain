#include "camera.h"

Camera::Camera(CameraPosition* position, CameraView* view) {
  _position = position;
  _view = view;
}
Camera::~Camera() {
  delete _position;
  delete _view;
}
void Camera::set_eye(float x, float y, float z) {
   _position->set_eye(x, y, z);
}
void Camera::set_center(float x, float y, float z) {
  _position->set_center(x, y, z);
}
void Camera::set_up(float x, float y, float z) {
  _position->set_up(x, y, z);
}
void Camera::set_fovy(float fovy) {
  _view->set_fovy(fovy);
}
mat4x4f Camera::look_at() {
  return _position->look_at();
}
mat4x4f Camera::perspective() {
  return _view->frustum();
}
mat4x4f Camera::ortho() {
  return _view->ortho();
}
void Camera::move(float value, int diretion) {
  switch(diretion) {
    case LEFT:
      _position->set_eye(_position->get_eye()(0) - value, _position->get_eye()(1), _position->get_eye()(2));
      _position->set_center(_position->get_center()(0) - value, _position->get_center()(1), _position->get_center()(2));
      break;
    case RIGHT:
      _position->set_eye(_position->get_eye()(0) + value, _position->get_eye()(1), _position->get_eye()(2));
      _position->set_center(_position->get_center()(0) + value, _position->get_center()(1), _position->get_center()(2));
      break;
    case UP:
      _position->set_eye(_position->get_eye()(0), _position->get_eye()(1) - value, _position->get_eye()(2));
      _position->set_center(_position->get_center()(0), _position->get_center()(1) - value, _position->get_center()(2));
      break;
    case DOWN:
      _position->set_eye(_position->get_eye()(0), _position->get_eye()(1) + value, _position->get_eye()(2));
      _position->set_center(_position->get_center()(0), _position->get_center()(1) + value, _position->get_center()(2));
      break;
  }
}
void Camera::zoom(float value, int diretion) {
  switch(diretion) {
    case IN:
      _view->set_fovy(_view->get_fovy() - value);
      break;
    case OUT:
      _view->set_fovy(_view->get_fovy() + value);
      break;
  }
}

