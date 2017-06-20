#pragma once
#include<Windows.h>

// 화면 중앙 및 끝부분 저장.
class cConsoleWindow {
private:
	HWND hwnd;
	POINT p;

public:
	cConsoleWindow(HWND hwnd, POINT p) {
		this->hwnd = hwnd;
		this->p = p;
	}
};