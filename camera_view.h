#include "vec.hpp"
#include "mat.hpp"
#include "cmath"

using namespace kmuvcl::math;

class CameraView {
  public:
    CameraView(float left, float right, float bottom, float top, float near, float far);
    CameraView(float fovy, float aspect, float near, float far);
    void set_fovy(float fovy);
    virtual mat4x4f ortho();
    virtual mat4x4f frustum();
    virtual mat4x4f perspective();

  private:
    float _left;
    float _right;
    float _bottom;
    float _top;
    float _near;
    float _far;
}
