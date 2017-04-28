#ifndef __CAMERA_VIEW_H__
#define __CAMERA_VIEW_H__


#include <cmath>
#include "../vec.hpp"
#include "../mat.hpp"

using namespace kmuvcl::math;

class CameraView {
  public:
    CameraView(float left, float right, float bottom, float top, float near, float far);
    CameraView(float fovy, float aspect, float near, float far);
    void set_fovy(float fovy);
    float get_fovy();
    virtual mat4x4f ortho() = 0;
    virtual mat4x4f frustum() = 0;
  protected:
    float _left;
    float _right;
    float _bottom;
    float _top;
    float _near;
    float _far;
    float _fovy;
};

#endif
