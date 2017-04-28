#ifndef __CAMERA_H__
#define __CAMERA_H__

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define IN 5
#define OUT 6

#include <iostream>
#include "vec.hpp"
#include "mat.hpp"
#include "camera_position.h"
#include "camera_view.h"


using namespace kmuvcl::math;

class Camera{
  public:
    Camera(CameraPosition* position, CameraView* view);
    ~Camera();
    void set_eye(float x, float y, float z);
    void set_center(float x, float y, float z);
    void set_up(float x, float y, float z);
    void set_fovy(float fovy);
    mat4x4f look_at();
    mat4x4f ortho();
    mat4x4f perspective();
    void move(float value, int direction);
    void zoom(float value, int direction);
  private:
    CameraPosition* _position;
    CameraView* _view;
};

#endif
