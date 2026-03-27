#include "Goal.h"

AGoal::AGoal(int InX, int InY, char InMesh, int InZOrder)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InZOrder;
}

AGoal::~AGoal()
{
}
