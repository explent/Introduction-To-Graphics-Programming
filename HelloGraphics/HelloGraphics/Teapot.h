#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "Structures.h"

class Teapot
{
private:
	Vector3 _position;
	static Vertex* indexedVertices;
	static GLushort* indices;
	static int numVertices, numIndices;
	GLfloat _rotation;
public:
	Teapot(float x, float y, float z);
	~Teapot();

	void Draw();
	void Update();
	static bool Load(char* path);
};

