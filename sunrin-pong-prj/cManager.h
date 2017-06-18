#pragma once
#include<Windows.h>
using namespace std;

class cManager {
public:
	bool isQuit = false;
	void Quit() { this->isQuit = true; }
};