using namespace kmuvcl::math;

class CamaraPosition {
  public:
    CameraPosition(float eyex, float eyey, float eyez, 
        float centerx, float centery, float centerz, 
        float upx, float upy, float upz);
    void set_eye(float x, float y, float z);
    void set_center(float x, float y, float z);
    void set_up(float x, float y, float z);
    virtual mat4x4f lookAt();
  private:
    float _eyex, _eyey, _eyez;
    float _centerx, _centery, _centerz;
    float _upx, _upy, _upz;
}
