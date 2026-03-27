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

	template<typename T>
	AActor* SpawnActor();
	std::vector<AActor*>& GetActors();

private:
	std::vector<AActor*> Actors;
};