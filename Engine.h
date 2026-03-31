#pragma once
#include "World.h"
#include "Renderer.h"

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
	URenderer* GetRenderer();

private:
	void Input();
	void Tick();
	void Render();

	UWorld* World;
	URenderer* Renderer;
	bool bIsRunning;
};

#define GEngine			UEngine::GetInstance()