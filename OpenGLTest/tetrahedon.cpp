#include "tetrahedon.h"

Tetrahedon::Tetrahedon()
{
	vertices.push_back(Vertex{ 0.0f, 0.0f, 0.0f,  0.0f ,0.0f, 0.0f });
	vertices.push_back(Vertex{ 0.0f, 0.0f, 1.0f,  0.0f ,0.0f, 0.0f });
	vertices.push_back(Vertex{ 0.0f, 1.0f, 0.0f,  0.0f ,0.0f, 0.0f });
	vertices.push_back(Vertex{ 1.0f, 0.0f, 0.0f,  0.0f ,0.0f, 0.0f });
	//Vertex_data.push_back(Vertex{ 0.5f, 0.5f, 1.0f,  0.0f ,0.0f, 0.0f });

}

Tetrahedon::~Tetrahedon()
{
}

void Tetrahedon::init(int inMatrixUniform)
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);


	// Set vertex attribute pointers
	// Vertex positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	// Vertex normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
	// Vertex texture coords
	//glEnableVertexAttribArray(2);
	//glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

	glBindVertexArray(0);
}

void Tetrahedon::draw()
{
	glBindVertexArray(VAO);
	glUniformMatrix4fv(matrixUniform, 1, GL_FALSE, glm::value_ptr(matrix));
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());// vertices.size());

}
