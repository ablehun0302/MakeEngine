#include <iostream>
#include "Engine.h"

int main()
{
	UEngine* Engine = new UEngine;

	Engine->GetWorld()->SpawnActor();

	Engine->Run();

	delete Engine;
	Engine = nullptr;

	return 0;
}