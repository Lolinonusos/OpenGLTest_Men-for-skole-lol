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
		// Trenger fire temporære variabler som kun skal lese inn parenteser og komma
		char dum, dum2, dum3, dum4;
		is >> dum >> v.position.x >> dum2 >> v.position.y >> dum3 >> v.position.z >> dum4;
		is >> dum >> v.normal.x >> dum2 >> v.normal.x >> dum3 >> v.normal.z >> dum4;
		is >> dum >> v.texCoord.x >> dum2 >> v.texCoord.y >> dum3;
		return is;

	};
}
