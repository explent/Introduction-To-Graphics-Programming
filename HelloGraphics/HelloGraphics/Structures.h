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

struct Vector4 {
	float x, y, z, w;
};

struct Lighting {
	Vector4 Ambient, Diffuse, Specular;
};

struct Material {
	Vector4 Ambient, Diffuse, Specular;
	GLfloat Shininess;
};

struct Mesh {
	Vertex* Vertices;
	Vector3* Normals; 
	TexCoord* TexCoords;
	GLushort* Indices; 
	int VertexCount, NormalCount, IndexCount, TexCoordCount; 
};
