#pragma once
#include<Windows.h>
using namespace std;


#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER 13
#define SPACE 32
#define BACKSPACE 8


int GetConsoleWindowHeight(HWND hwnd);
int GetConsoleWindowWidth(HWND hwnd);
int GetConsoleWindowTitlebarHeight();
int GetCursorYPos(HWND hwnd, POINT p, int subt);
int GetCursorXPos(HWND hwnd, POINT p, int subt);
float GetNormalizedCursorYPos(HWND hwnd, POINT p, int subt);
float GetNormalizedCursorXPos(HWND hwnd, POINT p, int subt);

// Returns the height of the console window
int GetConsoleWindowHeight(HWND hwnd) {
	RECT rect;
	GetWindowRect(hwnd, &rect);
	int height = rect.bottom - rect.top;
	return height;
}

// Returns the width of the console window
int GetConsoleWindowWidth(HWND hwnd) {
	RECT rect;
	GetWindowRect(hwnd, &rect);
	int height = rect.right - rect.left;
	return height;
}

// Returns the height of the title bar
int GetConsoleWindowTitlebarHeight() {
	int nCaptionHeight = ::GetSystemMetrics(SM_CYCAPTION);
	return nCaptionHeight;
}

// Returns the y position of cursor - subt
int GetCursorYPos(HWND hwnd, POINT p, int subt = 12) {
	GetCursorPos(&p); ScreenToClient(hwnd, &p);

	if (p.y >= 0 && p.y <= GetConsoleWindowHeight(hwnd) - GetConsoleWindowTitlebarHeight() - subt) { return p.y; }
	else if (p.y < 0) { return 0; }
	else { return GetConsoleWindowHeight(hwnd) - GetConsoleWindowTitlebarHeight() - subt; }
}

// Returns the x position of cursor - subt
int GetCursorXPos(HWND hwnd, POINT p, int subt = 12) {
	GetCursorPos(&p); ScreenToClient(hwnd, &p);

	if (p.x >= 0 && p.x <= GetConsoleWindowWidth(hwnd) - subt) { return p.x; }
	else if (p.x < 0) { return 0; }
	else { return GetConsoleWindowWidth(hwnd) - subt; }
}

// Returns the y position of cursor - subt normalized between 0, 1
float GetNormalizedCursorYPos(HWND hwnd, POINT p, int subt = 12) {
	return (float)GetCursorYPos(hwnd, p, subt) / (float)(GetConsoleWindowHeight(hwnd) - GetConsoleWindowTitlebarHeight() - subt);
}

// Returns the x position of cursor - subt normalized between 0, 1
float GetNormalizedCursorXPos(HWND hwnd, POINT p, int subt = 12) {
	return (float)GetCursorXPos(hwnd, p, subt) / (float)(GetConsoleWindowWidth(hwnd) - subt);
}