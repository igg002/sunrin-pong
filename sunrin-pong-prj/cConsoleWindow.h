#pragma once
#include<Windows.h>

// ȭ�� �߾� �� ���κ� ����.
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