#include "Player.h"
#include "Engine.h"

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

void APlayer::Tick()
{
    if (UEngine::InputValue == 'w')
    {
        Y--;
    }
    if (UEngine::InputValue == 's')
    {
        Y++;
    }
    if (UEngine::InputValue == 'a')
    {
        X--;
    }
    if (UEngine::InputValue == 'd')
    {
        X++;
    }
}
