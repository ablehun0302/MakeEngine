#pragma once
#include <iostream>

class AActor
{
public:
	AActor(int InX = 0, int InY = 0, char InMesh = ' ');
	~AActor();

	void BeginPlay();
	void Tick();
	void Render();

	void SetActorLocation(int InX, int InY);

protected:
	int X;
	int Y;
	char Mesh;
};

