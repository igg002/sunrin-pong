#pragma once
#include<Windows.h>
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;


void ClearScreen();
void SetConsoleByCommand(int cols, int lines);
void DrawStageEdge(int mapHeight, int mapWidth);
void SetWindowsSize(HWND hwnd, int height, int width);

// Clear Screen
void ClearScreen() { system("cls"); }

// Set console size by columns and rows
void SetConsoleByCommand(int cols, int lines) {
	string consoleCommandString = "mode con:cols=" + std::to_string(cols) + " lines=" + std::to_string(lines);
	const char *consoleCommand = consoleCommandString.c_str();
	system(consoleCommand);
}

// Draw stage edges by inserted width and height
void DrawStageEdge(int mapHeight, int mapWidth) {
	for (int i = 0; i<mapHeight; i++){
		for (int j = 0; j< mapWidth; j++){
			if (i == 0 || i == mapHeight - 1 || j == 0 || j == mapWidth - 1) printf("¢É");
			else printf("  ");
		}
		printf("\n");
	}
}

void SetWindowsSize(HWND hwnd, int height, int width) {
	RECT r;
	GetWindowRect(hwnd, &r);
	MoveWindow(hwnd, r.left, r.top, width, height, TRUE);
}