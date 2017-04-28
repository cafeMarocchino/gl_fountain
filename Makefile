all:
	g++ -o HW1 main.cpp ./object/color.cc ./object/object.cc ./camera/camera.cc ./camera/camera_view.cc ./camera/camera_builder.cc ./camera/camera_position.cc -lGL -lglut -lGLEW -std=c++11
