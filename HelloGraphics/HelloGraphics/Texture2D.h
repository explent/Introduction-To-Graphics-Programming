#pragma once
#include <Windows.h>
#include "GL/freeglut.h"
#include <gl/GL.h>
#include <gl/GLU.h>

class Texture2D
{
private:
	GLuint _ID;
	int _width, _height;
public:
	Texture2D();
	~Texture2D();

	bool Load(char* path, int width, int height);
	GLuint GETID() const { return _ID; } 
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }
};

