#include <iostream>
#include "vec.hpp"
#include "mat.hpp"
#include "camera_position.h"
#include "camera_view.h"

using namespace kmuvcl::math;

class Camera{
  public:
    Camera(CameraPosition position, CameraView view);
    void set_eye(float x, float y, float z);
    void set_center(floatx, float y, float z);
    void set_up(float x, float y, float z);
    void set_fovy(float fovy);
    mat4x4f lookAt();
    mat4x4f ortho();
    mat4x4f perspective();
  private:
    CameraPosition _position;
    CameraView _view;
}
