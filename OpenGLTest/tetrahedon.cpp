#include "tetrahedon.h"
#include <vertex.h>


Tetrahedon::Tetrahedon()
{
	Vertex_data.push_back(Vertex{ 0.0f, 0.0f, 0.0f,  0.0f ,0.0f, 0.0f });
	Vertex_data.push_back(Vertex{ 0.0f, 0.0f, 1.0f,  0.0f ,0.0f, 0.0f });
	Vertex_data.push_back(Vertex{ 0.0f, 1.0f, 0.0f,  0.0f ,0.0f, 0.0f });
	Vertex_data.push_back(Vertex{ 1.0f, 0.0f, 0.0f,  0.0f ,0.0f, 0.0f });
	//Vertex_data.push_back(Vertex{ 0.5f, 0.5f, 1.0f,  0.0f ,0.0f, 0.0f });

}

Tetrahedon::~Tetrahedon()
{
}

void Tetrahedon::init(int inMatrixUniform)
{
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex_data), &Vertex_data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glGenVertexArray(1, &VAO);
	glBindVertexArray(&VAO);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (char*)(sizeof(Vertex_data) * 5);

	glEnableAttribArray(1);
}

void Tetrahedon::draw()
{
	glUniformMatrix4fv(matrixUniform, 1, GL_FALSE, glm::value_ptr(matrix));
	glDrawArrays(GL_TRIANGLES, 0, 4);

}
