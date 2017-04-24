#include "CameraBuilder.h"

void CameraBuilder::set_position(CameraPosition position) {
  _position = position;
}
void CameraBuilder::set_view(CameraView view) {
  _view = view;
}
Camera CameraBuilder::CameraBuilder() {
  return new Camera(_position, _view);
}
