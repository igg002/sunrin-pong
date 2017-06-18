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
int GetUpdateCursorPos(HWND hwnd, POINT p, int subt);
int GetConsoleWindowTitleBarHeight();
float GetNormalizedCursorPos(HWND hwnd, POINT p, int subt);
int GetCursorPosByRow(HWND hwnd, POINT p, int minRow, int maxRow, int subt);


int GetConsoleWindowHeight(HWND hwnd) {
	RECT rect;
	GetWindowRect(hwnd, &rect);
	int height = rect.bottom - rect.top;
	return height;
}

int GetUpdateCursorPos(HWND hwnd, POINT p, int subt = 0) {
	GetCursorPos(&p); ScreenToClient(hwnd, &p);

	if (p.y >= 0 && p.y <= GetConsoleWindowHeight(hwnd) - GetConsoleWindowTitleBarHeight() - subt) { return p.y; }
	else if (p.y < 0) { return 0; }
	else { return GetConsoleWindowHeight(hwnd) - GetConsoleWindowTitleBarHeight() - subt; }
}

int GetConsoleWindowTitleBarHeight() {
	int nCaptionHeight = ::GetSystemMetrics(SM_CYCAPTION);
	return nCaptionHeight;
}

float GetNormalizedCursorPos(HWND hwnd, POINT p, int subt = 0) {
	return (float)GetUpdateCursorPos(hwnd, p, subt) / (float)(GetConsoleWindowHeight(hwnd) - GetConsoleWindowTitleBarHeight() - subt);
}

int GetCursorPosByRow(HWND hwnd, POINT p, int minRow, int maxRow, int subt = 0) {
	if (maxRow * GetNormalizedCursorPos(hwnd, p, subt) < minRow) { return minRow; }
	else return maxRow * GetNormalizedCursorPos(hwnd, p, subt);
}