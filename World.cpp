#include "World.h"

#include "Actor.h"
#include "Player.h"
#include "Monster.h"
#include "Wall.h"
#include "Goal.h"

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
	SpawnActor<APlayer>()->SetActorLocation(0, 0);
	SpawnActor<AActor>()->SetActorLocation(0, 1);
	SpawnActor<AMonster>()->SetActorLocation(0, 2);
	SpawnActor<AWall>()->SetActorLocation(0, 3);
	SpawnActor<AGoal>()->SetActorLocation(0, 4);
}

template<typename T>
AActor* UWorld::SpawnActor()
{
	AActor* NewActor = new T();
	Actors.push_back(NewActor);

	return NewActor;
}

std::vector<AActor*>& UWorld::GetActors()
{
	return Actors;
}
