#include "Teapot.h"
#include <fstream>
#include <string>
#include <vector>

std::vector<Vector3> vertices;

Teapot::Teapot(float x, float y, float z) {
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

bool Teapot::Load(char* path) {
	std::ifstream inFile;
	inFile.open(path);
	if (!inFile.good()) {
		std::cerr << "Can't open obj file " << path << std::endl;
		return false;
	}

	std::string line;
	while (std::getline(inFile, line)) {
		if (!line.empty() && line[0] == 'v') {
			int i = i++;
			std::cout << i;
			vertices.push_back();
			inFile >> vertices[i].x, vertices[i].y, vertices[i].z;
		}
	}
}

Teapot::~Teapot(void) {

}