#include "Engine.h"

UEngine::UEngine()
{
	Init();
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
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}
