all:
	g++ -o simple_camera main.cpp color.cpp -lGL -lglut -lGLEW -std=c++11
