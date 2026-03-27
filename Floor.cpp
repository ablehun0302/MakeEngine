#include "Floor.h"

AFloor::AFloor(int InX, int InY, char InMesh, int InZOrder)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InZOrder;
}

AFloor::~AFloor()
{
}
