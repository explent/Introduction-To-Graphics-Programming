#pragma once
#define REFRESHRATE 16
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "iostream"
#include "Cube.h"
#include "Teapot.h"
#include "SceneObject.h"
#include "Pyramid.h"

class HelloGL
{
public:

	HelloGL(int argc, char* argv[]);
	void Keyboard(unsigned char key, int x, int y);
	~HelloGL(void);
	void Display();
	void Update();
	void InitObjects();
	void InitGL(int argc, char* argv[]);
	void InitLight();
	void DrawString(const char* text, float x, float y, Color* color);
private:
	float rotation;
	float cameraSpeed;
	int option;
	Camera* camera;
	SceneObject* objects[3];
	Teapot* teapot[200];
	Vector4* _lightPosition;
	Lighting* _lightData;
};

