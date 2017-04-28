#include "camera_builder.h"

void CameraBuilder::set_position(CameraPosition* position) {
  _position = position;
}
void CameraBuilder::set_view(CameraView* view) {
  _view = view;
}
Camera* CameraBuilder::build() {
  return new Camera(_position, _view);
}
