#include "World.h"

#include <fstream>
#include <string>
#include <algorithm>

#include "Actor.h"
#include "Player.h"
#include "Monster.h"
#include "Wall.h"
#include "Goal.h"
#include "Floor.h"

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

void UWorld::Load(std::string MapFileName)
{
	std::ifstream MapFile(MapFileName);

	if (!MapFile.is_open())
	{
		return;
	}

	std::string Line;
	int Y = 0;
	while (std::getline(MapFile,Line))
	{
		for (int X = 0; X < Line.length(); X++)
		{
			if (Line[X] == '#')
			{
				SpawnActor<AWall>()->SetActorLocation(X, Y);
				SpawnActor<AFloor>()->SetActorLocation(X, Y);
			}
			if (Line[X] == 'P')
			{
				SpawnActor<APlayer>()->SetActorLocation(X, Y);
				SpawnActor<AFloor>()->SetActorLocation(X, Y);
			}
			if (Line[X] == 'M')
			{
				SpawnActor<AMonster>()->SetActorLocation(X, Y);
				SpawnActor<AFloor>()->SetActorLocation(X, Y);
			}
			if (Line[X] == 'G')
			{
				SpawnActor<AGoal>()->SetActorLocation(X, Y);
				SpawnActor<AFloor>()->SetActorLocation(X, Y);
			}
			if (Line[X] == ' ')
			{
				SpawnActor<AFloor>()->SetActorLocation(X, Y);
			}
		}
		Y++;
	}

	std::sort(Actors.begin(), Actors.end(),
		[](AActor* A, AActor* B)
		{
			return A->GetZOrder() < B->GetZOrder();
		});
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
