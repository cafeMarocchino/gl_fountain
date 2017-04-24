#include <iostream>
#include "vec.hpp"
#include "mat.hpp"
#include "camera.h"
#include "camera_position.h"
#include "camera_view.h"

class CameraBuilder {
  public:
    void set_position(CameraPosition position);
    void set_view(CameraView view);
    Camera build();

  private:
    CameraPosition _position;
    CameraView _view;
}
