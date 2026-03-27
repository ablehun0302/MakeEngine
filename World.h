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

	void Load(const std::string MapFileName);

	template<typename T>
	AActor* SpawnActor();
	std::vector<AActor*>& GetActors();

private:
	std::vector<AActor*> Actors;
};