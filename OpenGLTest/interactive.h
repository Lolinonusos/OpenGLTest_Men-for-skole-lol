#pragma once

#include "visObject.h"

// Linus jobber her

//glm::vec3 inPosition;

class Interactive : public visObject {
public:
	Interactive(glm::vec3 inPosition);
	~Interactive();
	void init(int inMatrixUniform) override;
	void draw() override;

	void move(float inX, float inY, float inZ, float deltaTime);

private:
	float movementSpeed = 2.0f; // Not in use yet
	glm::vec3 position;
};

