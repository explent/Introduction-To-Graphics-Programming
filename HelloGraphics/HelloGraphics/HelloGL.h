#pragma once
#define REFRESHRATE 16
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "iostream"
#include "Cube.h"

class HelloGL
{
public:

	HelloGL(int argc, char* argv[]);
	void Keyboard(unsigned char key, int x, int y);
	~HelloGL(void);
	void Display();
	void Update();
private:
	float rotation;
	float cameraSpeed;
	int option;
	Camera* camera;
	Cube* cube[200];
};

