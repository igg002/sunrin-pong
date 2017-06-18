#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include"cInput.h"
#include"cGeneral.h"
#include"cGraphics.h"


#define MAPSIZEY 30
#define MAPSIZEX 119
#define ACTIVEMAPMINY 1
#define ACTIVEMAPMAXY 28
#define REDUCEDMAPVALUE 12
#define PLAYERONEPADX 1
#define PLAYERTWOPADX 117
#define PADSIZE 7


using namespace std;


bool quit;
int gameMap[MAPSIZEY][MAPSIZEX];

void UpdateGameMap(HWND hwnd, POINT p) {
	for (int i = 0; i < MAPSIZEY; i++) {
		for (int j = 0; j < MAPSIZEX; j++) {
			if ((j == PLAYERONEPADX || j == PLAYERTWOPADX) && (i == GetCursorPosByRow(hwnd, p, ACTIVEMAPMINY, ACTIVEMAPMAXY, REDUCEDMAPVALUE))) { gameMap[i][j] = 1; }
			else { gameMap[i][j] = 0; }
		}
	}
}

void Quit() {
	quit = true;
}

void Update() {
	HWND hwnd = GetConsoleWindow();
	POINT p; p.x = p.y = 0;

	/*UpdateGameMap(hwnd, p);
	for (int i = 0; i < MAPSIZEY; i++) {
		for (int j = 0; j < MAPSIZEX; j++) {
			gotoxy(j, i); printf("%d", gameMap[i][j]);
		}
		printf("\n");
	}*/
}

void main() {
	while (!quit) Update();
}