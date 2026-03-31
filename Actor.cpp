#include "Actor.h"

#include <Windows.h>

#include "Engine.h"

AActor::AActor(int InX, int InY, char InMesh, int InZOrder) :
    X(InX), Y(InY), Mesh(InMesh), ZOrder(InZOrder)
{
}

AActor::~AActor()
{
}

void AActor::BeginPlay()
{
}

void AActor::Tick()
{
}

void AActor::Render()
{
    /*COORD Coordinate;
    Coordinate.X = X;
    Coordinate.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coordinate);

    std::cout << Mesh;*/
    GEngine->GetRenderer()->Render(X, Y, Mesh);
}

void AActor::SetActorLocation(int InX, int InY)
{
    X = InX;
    Y = InY;
}

int AActor::GetZOrder()
{
    return ZOrder;
}
