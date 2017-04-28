#ifndef __CAMERA_POSITION_H__
#define __CAMERA_POSITION_H__

#include "vec.hpp"
#include "mat.hpp"

using namespace kmuvcl::math;

class CameraPosition {
  public:
    CameraPosition(float eyex, float eyey, float eyez, 
        float centerx, float centery, float centerz, 
        float upx, float upy, float upz);
    void set_eye(float x, float y, float z);
    vec3f get_eye();
    void set_center(float x, float y, float z);
    vec3f get_center();
    void set_up(float x, float y, float z);
    vec3f get_up();
    virtual mat4x4f look_at() = 0;
  protected:
    float _eyex, _eyey, _eyez;
    float _centerx, _centery, _centerz;
    float _upx, _upy, _upz;
};

#endif
