#pragma once
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
using namespace std;


typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;


int RandIntRange(int x, int y);
int GetCursorXPos();
int GetCursorYPos();
void SetCursorType(CURSOR_TYPE c);
void SetCursor(bool bVisible);

// Random integer value in range
int RandIntRange(int x, int y) {
	static int z = 0;
	int tmp;
	if (z == 0) {
		srand((int)time(NULL));
		rand(); rand(); rand(); rand();
		srand(rand());
		z = 1;
	}
	tmp = rand() % (y - x + 1) + x;
	return tmp;
}

// Returns X position of cursor
int GetCursorXPos(){
	CONSOLE_SCREEN_BUFFER_INFO buffInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buffInfo);
	return buffInfo.dwCursorPosition.X;
}

// Returns Y position of cursor
int GetCursorYPos(){
	CONSOLE_SCREEN_BUFFER_INFO buffInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buffInfo);
	return buffInfo.dwCursorPosition.Y;
}

// Sets cursor visible type by CURSOR_TYPE
void SetCursorType(CURSOR_TYPE c){
	CONSOLE_CURSOR_INFO cursorInfo;
	switch (c) {
	case NOCURSOR:
		cursorInfo.dwSize = 1;
		cursorInfo.bVisible = FALSE;
		break;

	case SOLIDCURSOR:
		cursorInfo.dwSize = 100;
		cursorInfo.bVisible = TRUE;
		break;

	case NORMALCURSOR:
		cursorInfo.dwSize = 20;
		cursorInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// Sets cursor visible type by boolean
void SetCursor(bool bVisible){
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor); // ¼³Á¤
}