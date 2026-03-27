#include "Player.h"

APlayer::APlayer(int InX, int InY, char InMesh, int InZOrder)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InZOrder;
}

APlayer::~APlayer()
{
}
