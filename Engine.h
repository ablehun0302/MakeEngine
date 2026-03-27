#pragma once
#include "World.h"

class UEngine
{
public:
	UEngine();
	~UEngine();

	void Init();
	void Term();

	void Run();

	UWorld* GetWorld();

private:
	void Input();
	void Tick();
	void Render();

	UWorld* World;

	bool bIsRunning;
};

