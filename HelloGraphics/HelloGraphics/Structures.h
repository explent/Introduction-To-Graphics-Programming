#pragma once
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

struct Color {
	GLfloat r, g, b;
};

struct Vertex {
	GLfloat x, y, z;
};

struct TexCoord {
	GLfloat u, v;
};

struct Mesh {
	Vertex* Vertices;
	Color* Colors; 
	TexCoord* TexCoords;
	GLushort* Indices; 
	int VertexCount, ColorCount, IndexCount, TexCoordCount; 
};
