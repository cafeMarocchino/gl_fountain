object:
	./object/color.cc ./object/object.cc

camera:
	./camera/camera.h ./camera/camera_view ./camera/camera_builder ./camera/camera_position/

all:
	g++ -o simple_camera main.cpp object camera -lGL -lglut -lGLEW -std=c++11
