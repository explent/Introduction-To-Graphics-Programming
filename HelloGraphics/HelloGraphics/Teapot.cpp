#include "Teapot.h"
#include <fstream>
#include <string>

Vertex* Teapot::indexedVertices = nullptr;
GLushort* Teapot::indices = nullptr; 

int Teapot::numVertices = 0;
int Teapot::numIndices = 0;

Teapot::Teapot(float x, float y, float z) {
	_rotation = 0.0f;
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

void Teapot::Draw() {
	if (indexedVertices != nullptr && indices != nullptr) {
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, indexedVertices);

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
		glDrawElements(GL_TRIANGLES, 18960, GL_UNSIGNED_SHORT, indices);
		glPopMatrix();

		glDisableClientState(GL_VERTEX_ARRAY);
	}
}

void Teapot::Update() {
	_rotation += 0.1f;
}

bool Teapot::Load(char* path) {
	std::ifstream inFile;
	inFile.open(path);
	if (!inFile.good()) {
		std::cerr << "Can't open obj file " << path << std::endl;
		return false;
	}

	inFile >> numVertices;
	indexedVertices = new Vertex[numVertices];
	for (int i = 0; i < numVertices; i++)
	{
		inFile >> indexedVertices[i].x >> indexedVertices[i].y >> indexedVertices[i].z;

	}

	inFile >> numIndices;
	indices = new GLushort[numIndices];
	for (int i = 0; i < numIndices; i++) {
		inFile >> indices[i];
	}
	inFile.close();
	return true; 
}

Teapot::~Teapot(void) {

}