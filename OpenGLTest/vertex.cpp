#include "vertex.h"

std::ostream& operator<<(std::ostream& os, const Vertex& v)
{
	
		os << std::fixed;
		os << "(" << v.position.x << ", " << v.position.y << ", " << v.position.z << ") ";
		os << "(" << v.normal.x << ", " << v.normal.y << ", " << v.normal.z << ") ";
		os << "(" << v.texCoord.x << ", " << v.texCoord.y << ") ";
		return os;
	
}

std::istream& operator>>(std::istream& is, Vertex& v)
{
	{
		// Trenger fire tempor�re variabler som kun skal lese inn parenteser og komma
		char dum, dum2, dum3, dum4;
		is >> dum >> v.position.x >> dum2 >> v.position.y >> dum3 >> v.position.z >> dum4;
		is >> dum >> v.normal.x >> dum2 >> v.normal.x >> dum3 >> v.normal.z >> dum4;
		is >> dum >> v.texCoord.x >> dum2 >> v.texCoord.y >> dum3;
		return is;

	};
}

Vertex::Vertex()
{
}

Vertex::Vertex(float x, float y, float z)
{
	position = glm::vec3(x, y, z);
	normal = glm::vec3(0.0f, 0.0f, 0.0f);
	texCoord = glm::vec2(0.0f, 0.0f);
}

Vertex::Vertex(float x, float y, float z, float r, float g, float b)
{
	position = glm::vec3(x, y, z);
	normal = glm::vec3(r, g, b);
	texCoord = glm::vec2(0.0f, 0.0f);
}

Vertex::Vertex(float x, float y, float z, float r, float g, float b, float u, float v)
{
	position = glm::vec3(x, y, z);
	normal = glm::vec3(r, g, b);
	texCoord = glm::vec2(u, v);
}

Vertex::Vertex(glm::vec3 xyz)
{
	
		position = xyz;
		normal = glm::vec3(0.0f, 0.0f, 0.0f);
		texCoord = glm::vec2(0.0f, 0.0f);

	
}

Vertex::Vertex(glm::vec3 xyz, glm::vec3 rgb, glm::vec2 uv)
{
	position = xyz;
	normal = rgb;
	texCoord = uv;
}
