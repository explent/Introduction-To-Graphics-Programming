#include "Cube.h"

Vertex* Cube::indexedVertices = nullptr;
Color* Cube::indexedColors = nullptr;
GLushort* Cube::indices = nullptr;

Cube::Cube(float x, float y, float z) {
	_rotation = 0.0f;
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

void Cube::Draw() {
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
	glColorPointer(3, GL_FLOAT, 0, indexedColors);

	glPushMatrix();
	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	std::cout << _position.x << " " << _position.y << " " << _position.z;
	std::cout << "\n";
}

void Cube::Update() {
	_rotation += 0.1f;
}

Cube::~Cube(void) {

}