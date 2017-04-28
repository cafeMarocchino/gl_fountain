#include "camera_view.h"

CameraView::CameraView(float left, float right, float bottom, float top, float near, float far) {
  _left = left;
  _right = right;
  _bottom = bottom;
  _top = top;
  _near = near;
  _far = far;
}
CameraView::CameraView(float fovy, float aspect, float near, float far) {
  _fovy = fovy;
  fovy = fovy / 2 * M_PI / 180;
  float top = tan(fovy) * near;
  float right = top * aspect;
  _left = -right;
  _right = right;
  _bottom = -top;
  _top = top;
  _near = near;
  _far = far;
}
void CameraView::set_fovy(float fovy) {
  _fovy = fovy;
  fovy = fovy / 2 * M_PI / 180;
  float top = tan(fovy) * _near;
  float right = top * ((_right - _left) / (_top - _bottom));
  _left = -right;
  _right = right;
  _bottom = -top;
  _top = top;

}
float CameraView::get_fovy() {
  return _fovy;
}
