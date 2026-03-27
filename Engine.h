#pragma once
#include "World.h"

class UEngine
{
private:
	UEngine();
	static UEngine* Instance;

public:
	~UEngine();
	static UEngine* GetInstance();
	static char InputValue;

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

