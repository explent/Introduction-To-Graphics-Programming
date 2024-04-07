#pragma once
#define REFRESHRATE 16
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "iostream"

struct Vector3 {
	float x, y, z;
};

struct Camera {
	Vector3 eye, center, up;
};

class HelloGL
{
public:

	HelloGL(int argc, char* argv[]);
	void Keyboard(unsigned char key, int x, int y);
	~HelloGL(void);
	void Display();
	void DrawPolygon();
	void Update();
private:
	float rotation;
	float cameraSpeed;
	int option;
	Camera* camera;
};

