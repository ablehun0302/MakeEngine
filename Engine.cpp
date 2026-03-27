#include "Engine.h"

#include <conio.h>

UEngine* UEngine::Instance = nullptr;
char UEngine::InputValue = 0;

UEngine::UEngine()
{
	Init();
}

UEngine* UEngine::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new UEngine();
	}
	return Instance;
}

UEngine::~UEngine()
{
	Term();
}

void UEngine::Init()
{
	World = new UWorld;
	bIsRunning = true;
}

void UEngine::Term()
{
	delete World;
	World = nullptr;
}

void UEngine::Run()
{
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

UWorld* UEngine::GetWorld()
{
	return World;
}

void UEngine::Input()
{
	InputValue = 0;
	if (_kbhit())
	{
		InputValue = _getch();
	}
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}
