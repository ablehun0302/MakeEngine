#include "Monster.h"

AMonster::AMonster(int InX, int InY, char InMesh, int InZOrder)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InZOrder;
}

AMonster::~AMonster()
{
}
