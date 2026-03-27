#include "Wall.h"

AWall::AWall(int InX, int InY, char InMesh, int InZOrder)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InZOrder;
}

AWall::~AWall()
{
}
