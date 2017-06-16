#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "System.h"
using namespace std;
void DrawMap();
void SetCursor(bool bVisible);

int main(){
	DrawMap();
	setCursor(0);
	getch();
	return 0;

}




