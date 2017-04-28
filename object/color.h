#ifndef __COLOR_H__
#define __COLOR_H__

class Color{
  public:
    Color();
    ~Color();
    float* get_color(int R, int G, int B);

  private:
    float* fool[256][256][256];
};

#endif
