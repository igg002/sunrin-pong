#pragma once
#include<Windows.h>
using namespace std;


void GoToXY(int x, int y);

// Locate input buffer to input x, y location
void GoToXY(int x, int y){
	COORD Cur; Cur.X = x; Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}