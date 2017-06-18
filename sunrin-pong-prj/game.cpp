#include<iostream>
#include<Windows.h>
#include"cInput.h"
#include"cConsole.h"
#include"cGeneral.h"
#include"cGraphics.h"
#include"cGameObject.h"
#include"cTransform.h"
#include"cVector2.h"
#include"cBall.h"
#include"cPaddle.h"
#include"cManager.h"
using namespace std;


#define MAPSIZEY 30
#define MAPSIZEX 119
#define ACTIVEMAPMINY 1
#define ACTIVEMAPMAXY 28
#define REDUCEDMAPVALUE 12
#define PLAYERONEPADX 1
#define PLAYERTWOPADX 117
#define PADSIZE 7


void Update() {
	HWND hwnd = GetConsoleWindow();
	POINT p; p.x = 0; p.y = 0;

	SetWindowsSize(hwnd, 500, 500);

	cout << "Get Console Window Height : " << GetConsoleWindowHeight(hwnd) << endl;
	cout << "Get Console Window Titlebar Height : " << GetConsoleWindowTitlebarHeight() << endl;
	cout << "Get Cursor Y Position : " << GetCursorYPos(hwnd, p, 12) << endl;
	cout << "Get Normalized Cursor Y Position : " << GetNormalizedCursorYPos(hwnd, p) << endl;

	SetCursor(false);
	ClearScreen();
}

void main() {
	cManager manager = cManager();
	while (!manager.isQuit) Update();
}