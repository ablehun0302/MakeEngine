#include "World.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
	for (AActor* Actor : Actors)
	{
		delete Actor;
		Actor = nullptr;
	}
}


void UWorld::Tick()
{
	for (AActor* Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	for (AActor* Actor : Actors)
	{
		Actor->Render();
	}
}

void UWorld::Load()
{
	SpawnActor();
}

AActor* UWorld::SpawnActor()
{
	AActor* NewActor = new AActor();
	Actors.push_back(NewActor);

	return NewActor;
}

std::vector<AActor*>& UWorld::GetActors()
{
	return Actors;
}
