#include <iostream>
#include "../../camera.h"
#include "../../camera_view.h"
#include "../../camera_builder.h"
#include "../../camera_position.h"
#include "../../transform.hpp"

int main() {
  class JhCameraPosition : public CameraPosition {
    public :
      JhCameraPosition(float eyex, float eyey, float eyez, 
        float centerx, float centery, float centerz, 
        float upx, float upy, float upz) : CameraPosition(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz){}
      mat4x4f look_at() {
        kmuvcl::math::lookAt(_eyex, _eyey, _eyez, _centerx, _centery, _centerz, _upx, _upy, _upz);
      }
  };
  class JhCameraView : public CameraView {
    public :
      JhCameraView(float left, float right, float bottom, float top, float near, float far)
        : CameraView(left, right, bottom, top, near, far) {}
      JhCameraView(float fovy, float aspect, float near, float far) : CameraView(fovy, aspect, near, far) {} 
      mat4x4f ortho() {
        kmuvcl::math::ortho(_left, _right, _bottom, _top, _near, _far);
      }
      mat4x4f frustum() {
        kmuvcl::math::frustum(_left, _right, _bottom, _top, _near, _far);
      }
  };
  CameraBuilder builder;
  builder.set_position(new JhCameraPosition(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.f, 0.0f, 1.0f, 0.0f));
  builder.set_view(new JhCameraView(183.0f, 1.0f, 0.01f, 10000.0f));
  Camera* camera = builder.build();
  std::cout << camera->look_at() << std::endl << camera->ortho() << std::endl << camera->perspective() << std::endl;

  return 0;
}
