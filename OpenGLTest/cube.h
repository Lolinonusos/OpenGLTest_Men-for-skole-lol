#ifndef CUBE_H
#define CUBE_H

#include "visObject.h"

class Cube : public visObject {
public:
	Cube();
	~Cube();
	void init(int inMatrixUniform) override;
	void draw() override;
	void alterPosition(glm::vec3 inPos) override {
		matrix = glm::mat4(1.0f);
		matrix = glm::translate(matrix, inPos);
	}
};

#endif