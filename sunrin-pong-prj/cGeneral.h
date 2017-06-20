#pragma once
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
using namespace std;


typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;


int RandIntRange(int x, int y);
void SetCursorType(CURSOR_TYPE c);
void SetCursor(bool bVisible);
int GetConsoleSizeRow();
int GetConsoleSizeCol();

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

// Random float value in range
float RandFloatRange(float x, float y) {
	return ((y - x)*((float)rand() / RAND_MAX)) + x;
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

// Returns console row size
int GetConsoleSizeRow() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	return rows;
}

// Returns console column size
int GetConsoleSizeCol() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	return columns;
}

// Wait for Seconds
void WaitForSeconds(float seconds) {
	Sleep(seconds * 1000);
}