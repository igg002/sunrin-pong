#include<iostream>
#include<Windows.h>
using namespace std;

int GetConsoleWindowTitleBarHeight();

int GetConsoleWindowHeight(HWND hwnd) {
	RECT rect;
	GetWindowRect(hwnd, &rect);
	int height = rect.bottom - rect.top;
	return height;
}

int GetUpdateCursorPos(HWND hwnd, POINT p) {
	GetCursorPos(&p); ScreenToClient(hwnd, &p);
	
	// if (p.y >= 0 && p.y <= GetConsoleWindowHeight(hwnd) - GetConsoleWindowTitleBarHeight()) { return p.y; }
	// if (p.y >= 0 && p.y <= GetConsoleWindowHeight(hwnd) - GetConsoleWindowTitleBarHeight()*2) { return p.y; }
	if (p.y >= 0 && p.y <= GetConsoleWindowHeight(hwnd) - GetConsoleWindowTitleBarHeight() - 12) { return p.y; }
	else if(p.y < 0) { return 0; }
	else { return GetConsoleWindowHeight(hwnd) - GetConsoleWindowTitleBarHeight() - 12; }
}

int GetConsoleWindowTitleBarHeight() {
	int nCaptionHeight = ::GetSystemMetrics(SM_CYCAPTION);
	return nCaptionHeight;
}

float GetNormalizedCursorPos(HWND hwnd, POINT p) {
	return (float)GetUpdateCursorPos(hwnd, p) / (float)(GetConsoleWindowHeight(hwnd) - GetConsoleWindowTitleBarHeight() - 12);
}

int GetCursorPosByRow(HWND hwnd, POINT p, int maxRow) {
	return maxRow * GetNormalizedCursorPos(hwnd, p);
}