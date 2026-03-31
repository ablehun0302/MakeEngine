#pragma once
#include "Windows.h"

class URenderer
{
public:
	URenderer();
	~URenderer();

	void Clear();
	void Render(int InX, int InY, char InMesh);
	void Flip();

	HANDLE ScreenBufferHandler[2];
	int ActiveBufferIndex = 0;
};

