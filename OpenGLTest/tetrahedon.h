#ifndef TETRAHEDON_H
#define TETRAHEDON_H

#include "visobject.h"
#include <vertex.h>
#include <vector>




class Tetrahedon : public visObject {
public:
	Tetrahedon();
	~Tetrahedon();
	void init(int inMatrixUniform) override;
	void draw() override;

	std::vector<Vertex> Vertex_data;
};

#endif