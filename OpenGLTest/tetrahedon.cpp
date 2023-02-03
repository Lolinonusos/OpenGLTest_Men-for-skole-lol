#include "tetrahedon.h"
#include <vertex.h>

Tetrahedon::Tetrahedon()
{
	Vertex_data.push_back(Vertex{ 1.0f, 1.0f, 0.0f,  0.0f ,0.0f, 0.0f });
	Vertex_data.push_back(Vertex{ 0.0f, 1.0f, 0.0f,  0.0f ,0.0f, 0.0f });
	Vertex_data.push_back(Vertex{ 1.0f, 0.0f, 0.0f,  0.0f ,0.0f, 0.0f });
	Vertex_data.push_back(Vertex{ 0.0f, 0.0f, 0.0f,  0.0f ,0.0f, 0.0f });
	Vertex_data.push_back(Vertex{ 0.5f, 0.5f, 1.0f,  0.0f ,0.0f, 0.0f });

}

Tetrahedon::~Tetrahedon()
{
}

void Tetrahedon::init(int inMatrixUniform)
{
	glGenBuffers(1, &BufferID);
	glBindBuffer(GL_ARRAY_BUFFER, BufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex_data), &Vertex_data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, sizeof(Vertex_data), GL_FLOAT, GL_FALSE, 0, 0);


}

void Tetrahedon::draw()
{
	glViewport(0, 0, 500, 500);
	glDrawArrays(GL_TRIANGLES, 0, 5);

}
