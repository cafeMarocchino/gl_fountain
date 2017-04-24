#include "CameraView.cc"

CameraView::CameraView(float left, float right, float bottom, float top, float near, float far) {
  _left = left;
  _right = right;
  _bottom = bottom;
  _top = top;
  _near = near;
  _far = far;
}
CameraView::CameraView(float fovy, float aspect, float near, float far) {
  fovy = fovy / 2 * M_PI / 180;
  float top = tan(fovy) * zNear;
  float right = top * aspect;
  _left = -right;
  _right = right;
  _bottom = -top;
  _top = top;
  _near = near;
  _far = far;
}
void CameraView::set_fovy(float fovy) {
  fovy = fovy / 2 * M_PI / 180;
  float top = tan(fovy) * zNear;
  float right = top * _aspect;
  _left = -right;
  _right = right;
  _bottom = -top;
  _top = top;

}
