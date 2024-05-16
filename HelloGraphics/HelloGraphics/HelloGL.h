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
	void Mouse(int button, int state, int x, int y);
	~HelloGL(void);
	void Display();
	void Update();
	void InitObjects();
	void InitGL(int argc, char* argv[]);
	void InitLight();
	void DrawString(const char* text, float x, float y, Color* color);
	void CalculateAndDisplayFPS();
	void Motion(int x, int y) {

	}
private:
	float rotation;
	float cameraSpeed;
	int option;
	int nobjects = 3;
	Camera* camera;
	SceneObject* objects[3];
	Teapot* teapot[200];
	Vector4* _lightPosition;
	Lighting* _lightData;
	int frameCount = 0;
	int previousTime = 0;
	float fps = 0.0f;
};

