#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>
#include <fstream>

class Vertex {
private:

	

	//! Overloaded ostream operator which writes all vertex data on an open textfile stream
	friend std::ostream& operator<< (std::ostream& os, const Vertex& v);

	//! Overloaded ostream operator which reads all vertex data from an open textfile stream
	friend std::istream& operator>> (std::istream & is, Vertex & v);

public:

	glm::vec3 position{0};
	glm::vec3 normal{0};
	glm::vec2 texCoord{0};

	// This is overloading
	Vertex();
	Vertex(glm::vec3 xyz) ;
	Vertex(glm::vec3 xyz, glm::vec3 rgb) ;
	Vertex(glm::vec3 xyz, glm::vec3 rgb, glm::vec2 uv) ;

	Vertex(float x, float y, float z) ;

	Vertex(float x, float y, float z, float r, float g, float b) ;

	Vertex(float x, float y, float z, float r, float g, float b, float u, float v);

};

#endif