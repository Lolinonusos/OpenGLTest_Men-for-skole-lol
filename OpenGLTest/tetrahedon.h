#ifndef TETRAHEDON_H
#define TETRAHEDON_H

#include "visobject.h"

class Tetrahedon : public visObject {
public:
	Tetrahedon();
	~Tetrahedon();
	void init(int inMatrixUniform) override;
	void draw() override;

	std::vector<Vertex> Vertex_data;
	glm::mat4x4 mMatrix;

	GLuint BufferID;
};

#endif