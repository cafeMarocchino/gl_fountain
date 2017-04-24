// hello_world.cpp
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "vec.hpp"
#include "mat.hpp"
#include "transform.hpp"
#include "color.hpp"
#include "camera.h"

using namespace kmuvcl::math;

void mykeyboard(unsigned char key, int x, int y);
void arrow_key(int key, int x, int y);
void myidle();
void init();
void mydisplay();
void draw_vertex(int number_of_vertex);
void create_menu();
void select_menu(int value);
void init_parameters();
GLuint create_shader_from_file(const std::string& filename, GLuint shader_type);

GLuint program; // 쉐이더 프로그램 객체의 레퍼런스 값
GLint  loc_a_position;
GLint  loc_a_color;
GLint  loc_u_M;
GLint  loc_u_V;
GLint  loc_u_P;
float ang = 0.0f;
float zoom = 183.0f;
float eyex = 0.0f, eyey = -100.0f, eyez = 5.0f;
float centerx = 0.0f, centery = -100.0f, centerz = 0.0f;
float upx = 0.0f, upy = 1.0f, upz= 0.0f;
int number_of_vertex = 1000;
mat4x4f T[1000];
vec4f init_position[1000];
float vx[1000];
float vy[1000];
const float g = 9.8f;
float tx[1000];
float ty[1000];

class JhPosition : public CameraPosition {
  public:
    JhPosition(float eyex, float eyey, float eyez,
      float centerx, float centery, float centerz,
      float upx, float upy, float upz) {
      super(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
    }
    JhPosition(float fovy, float aspect, float near, float far) {
      super(fovy, aspect, near, far);
    }
    mat4x4f lookAt() {
      kmuvcl::math::lookAt(_eyex, _eyey, _eyez, _centerx, _centery, _centerz, _upx, _upy, _upz);
    }
};

Camera camera(

float position[] = {
  0.0f, 0.0f, 0.0f, 1.0f,
  3.0f, 0.0f, 0.0f, 1.0f,
  3.0f, 3.0f, 0.0f, 1.0f,
    
  0.0f, 0.0f, 0.0f, 1.0f,
  3.0f, 3.0f, 0.0f, 1.0f,
  0.0f, 3.0f, 0.0f, 1.0f,
};
Color color_factory;
float *red = color_factory.get_color(256, 0, 0);
float *yellow = color_factory.get_color(256, 256, 0);
float *blue = color_factory.get_color(0, 0, 256);
float *green = color_factory.get_color(0, 256, 0);
float *cyan = color_factory.get_color(0, 256, 256);
float *pupple = color_factory.get_color(256, 0, 256);

int main(int argc, char* argv[])
{
  srand(time(NULL));
  init_parameters();
  glutInit(&argc, argv);
  glutInitWindowSize(500, 500);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutCreateWindow("Hello FreeGLUT");
  create_menu();
  init();
  glutDisplayFunc(mydisplay);
  glutKeyboardFunc(mykeyboard);
  glutSpecialFunc(arrow_key);
  glutIdleFunc(myidle);
  glutMainLoop();

  return 0;
}


// GLSL 파일을 읽어서 컴파일한 후 쉐이더 객체를 생성하는 함수
GLuint create_shader_from_file(const std::string& filename, GLuint shader_type)
{
  GLuint shader = 0;
  shader = glCreateShader(shader_type);
  std::ifstream shader_file(filename.c_str());
  std::string shader_string;
  shader_string.assign(
    (std::istreambuf_iterator<char>(shader_file)),
    std::istreambuf_iterator<char>());

  const GLchar* shader_src = shader_string.c_str();

  glShaderSource(shader, 1, (const GLchar**)&shader_src, NULL);
  glCompileShader(shader);

  return shader;
}


void init()
{
  glewInit();

  // 정점 쉐이더 객체를 파일로부터 생성
  GLuint vertex_shader
    = create_shader_from_file("./shader/vertex.glsl", GL_VERTEX_SHADER);

  // 프래그먼트 쉐이더 객체를 파일로부터 생성
  GLuint fragment_shader
    = create_shader_from_file("./shader/fragment.glsl", GL_FRAGMENT_SHADER);

  // 쉐이더 프로그램 생성 및 컴파일
  program = glCreateProgram();
  glAttachShader(program, vertex_shader);
  glAttachShader(program, fragment_shader);
  glLinkProgram(program);

  loc_u_M = glGetUniformLocation(program, "u_M");
  loc_u_V = glGetUniformLocation(program, "u_V");
  loc_u_P = glGetUniformLocation(program, "u_P");


  loc_a_position = glGetAttribLocation(program, "a_position");
  loc_a_color    = glGetAttribLocation(program, "a_color");



  glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
}

void mydisplay()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  mat4x4f M, V, P;
  V = lookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
  P = perspective(zoom, 1.0f, 0.001f, 10000.0f);
  
  glUseProgram(program);
  glUniformMatrix4fv(loc_u_V, 1, false, V);
  glUniformMatrix4fv(loc_u_P, 1, false, P);
  
  draw_vertex(number_of_vertex);
  
  glUseProgram(0);
  glutSwapBuffers();
}

void mykeyboard(unsigned char key, int x, int y) {
  if(key == '+') {
    zoom += 1;
  } else if(key == '-') {
    zoom -= 1;
  }
  glutPostRedisplay();
   std::cout << zoom << std::endl; 
}
void arrow_key(int key, int x, int y) {
   switch(key) {
    case GLUT_KEY_UP:
      eyey += 1;
      centery += 1;
      break;
    case GLUT_KEY_DOWN:
      eyey -= 1;
      centery -= 1;
      break;
    case GLUT_KEY_LEFT:
      eyex -= 1;
      centerx -= 1;
      break;
    case GLUT_KEY_RIGHT:
      eyex += 1;
      centerx += 1;
      break;
    case GLUT_KEY_HOME:
      zoom = 30.0f;
      eyex = 0.0f, eyey = 0.0f, eyez = 5.0f;
      centerx = 0.0f, centery = 0.0f, centerz = 0.0f;
      upx = 0.0f, upy = 1.0f, upz= 0.0f;
      break;
  }
  glutPostRedisplay();
}
void myidle() {
  //T = new mat4x4f[number_of_vertex]();
  for(int i = 0; i < number_of_vertex; i++) {
    ty[i] += 0.02f;
    if(ty[i] < 0) {
      T[i] = translate(0.0f, 0.0f, 0.0f);
    } else {
      tx[i] += 0.01f;
      T[i] = translate(init_position[i](0) + vx[i] * tx[i], -(init_position[i](1) + vy[i] * ty[i] - (0.5f * g * ty[i] * ty[i])), 0.0f);
      if((T[i] * vec4f(0.0f, 0.0f, 0.0f, 0.1f))(1) > 0.0f) {
        vy[i] /= 1.3f;
        ty[i] = 0.0f;
      }
    }
  }
  glutPostRedisplay();
}
void create_menu() {
  glutCreateMenu(select_menu);
  
  glutAddMenuEntry("10", 10);
  glutAddMenuEntry("50", 50);
  glutAddMenuEntry("100", 100);
  glutAddMenuEntry("500", 500);
  glutAddMenuEntry("1000", 1000);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void select_menu(int value) {
  switch(value) {
    case 10:
      number_of_vertex = 10;
      break;
    case 50:
      number_of_vertex = 50;
      break;
    case 100:
      number_of_vertex = 100;
      break;
    case 500:
      number_of_vertex = 500;
      break;
    case 1000:
      number_of_vertex = 1000;
      break;
  }
  init_parameters();
}
void draw_vertex(int number_of_vertex) {
    for (int i = 0; i < number_of_vertex; i++) {
    //mat4x4f R = rotate(ang, 0.0f, 0.0f, 0.0f);
    float *color;
    if(vx[i] > 15)
      color = blue;
    else if(vx[i] > 7.5)
      color = red;
    else if(vx[i] > 0)
      color = green;
    else if(vx[i] > -7.5)
      color = pupple;
    else if(vx[i] > -15)
      color = cyan;
    else 
      color = yellow;
    glVertexAttribPointer(loc_a_position, 4, GL_FLOAT, GL_FALSE, 0, position);   
    glVertexAttribPointer(loc_a_color, 4, GL_FLOAT, GL_FALSE, 0, color);
    glEnableVertexAttribArray(loc_a_color);
    glEnableVertexAttribArray(loc_a_position);

    mat4x4f M = T[i];
    glUniformMatrix4fv(loc_u_M, 1, false, M);
    glDrawArrays(GL_TRIANGLES, 0, 6 /* 정점개수 */);
  
    glDisableVertexAttribArray(loc_a_color);
    glDisableVertexAttribArray(loc_a_position);
  }
}
void init_parameters() {
  for(int i = 0; i < number_of_vertex; i++) {
    init_position[i] = vec4f(float(rand() % 10000) / 1000.0f - 5.0f, float(rand() % 10000) / 1000.0f, 0.0f);
    T[i] = translate((float(rand() % 10000) /1000.0f - 5.0f), float(rand() % 10000) / 1000.0f, 0.0f);
    vx[i] = float(rand() % 4000) / 100.f - 20.0f;
    vy[i] = float(rand() % 500) / 10.f + 20.0f;
    ty[i] = float(rand() % 500) / 10.f - 50.0f;
    tx[i] = 0.01;
  }
}
