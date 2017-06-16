#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#include"Mouse.h"

using namespace std;

#define MAPSIZEY 30;
#define MAPSIZEX 55;
#define PADSIZE 7;

int main(){
	HWND hwnd = GetConsoleWindow();
	POINT p; p.x = p.y = 0;

	while (true){
		system("cls");

		cout << GetUpdateCursorPos(hwnd, p) << endl;
		cout << GetNormalizedCursorPos(hwnd, p) << endl;
		cout << GetCursorPosByRow(hwnd, p, 30) << endl << endl;

		cout << GetUpdateCursorPos(hwnd, p, 12) << endl;
		cout << GetNormalizedCursorPos(hwnd, p, 12) << endl;
		cout << GetCursorPosByRow(hwnd, p, 30, 12) << endl;

		// Classify, Cleanup
	}
}