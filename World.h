#pragma once
#include "Actor.h"

#include <vector>

class UWorld
{
public:
	UWorld();
	~UWorld();

	void Tick();
	void Render();

	void Load();

	AActor* SpawnActor();
	std::vector<AActor*>& GetActors();

private:
	std::vector<AActor*> Actors;
};

