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
	Renderer = new URenderer;
	bIsRunning = true;
}

void UEngine::Term()
{
	delete World;
	delete Renderer;
	World = nullptr;
	Renderer = nullptr;
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

URenderer* UEngine::GetRenderer()
{
	return Renderer;
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

	if (InputValue == 'p')
	{
		bIsRunning = false;
	}
}

void UEngine::Render()
{
	World->Render();
}
