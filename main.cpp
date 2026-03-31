#include <iostream>
#include "Engine.h"

int main()
{
	GEngine->GetWorld()->Load("level01.txt");

	GEngine->Run();

	delete GEngine;

	return 0;
}