#include <iostream>
#include "Engine.h"

int main()
{
	UEngine* Engine = UEngine::GetInstance();

	Engine->GetWorld()->Load("level01.txt");

	Engine->Run();

	delete Engine;
	Engine = nullptr;

	return 0;
}