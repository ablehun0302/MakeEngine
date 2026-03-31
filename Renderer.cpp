#include "Renderer.h"

URenderer::URenderer()
{
	// 버퍼 생성
	// https://learn.microsoft.com/en-us/windows/console/createconsolescreenbuffer
	ScreenBufferHandler[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenBufferHandler[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// 커서 정보 구조체 설정 -> 커서 숨길것임
	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	ConsoleCursorInfo.dwSize = 1;	// 커서 사이즈
	ConsoleCursorInfo.bVisible = 0; // 커서 숨김

	// 버퍼의 커서 정보 업데이트
	SetConsoleCursorInfo(ScreenBufferHandler[0], &ConsoleCursorInfo);
	SetConsoleCursorInfo(ScreenBufferHandler[1], &ConsoleCursorInfo);
}

URenderer::~URenderer()
{
	CloseHandle(ScreenBufferHandler[0]);
	CloseHandle(ScreenBufferHandler[1]);
}

void URenderer::Clear()
{
	DWORD DW;
	FillConsoleOutputCharacter(ScreenBufferHandler[ActiveBufferIndex], ' ', 80 * 25, COORD{ 0, 0 }, &DW);
}

void URenderer::Render(int InX, int InY, char InMesh)
{
	char MeshString[2] = { 0, };
	MeshString[0] = InMesh;

	SetConsoleCursorPosition(ScreenBufferHandler[ActiveBufferIndex], COORD{ (SHORT)InX,(SHORT)InY });
	WriteFile(ScreenBufferHandler[ActiveBufferIndex], MeshString, 1, NULL, NULL);
}

void URenderer::Flip()
{
	SetConsoleActiveScreenBuffer(ScreenBufferHandler[ActiveBufferIndex]);
	ActiveBufferIndex = ActiveBufferIndex == 0 ? 1 : 0;
}
