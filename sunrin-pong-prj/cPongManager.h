#pragma once
#include<Windows.h>
using namespace std;

class cPongManager {
public:
	bool isQuit = false;

	int p1Score, p2Score;
	int gameOverScore;

	cPongManager(int gameOverScore) {
		this->SetGameOverScore(gameOverScore);
	}

	void Quit() {
		this->isQuit = true; 
	}

	void SetGameOverScore(int score) {
		this->gameOverScore = score; 
	}

	void Victory(cPaddle winner) {
		this->isQuit = true;
		ClearScreen();
		cout << winner.gameObjectName << " Victory!" << endl; 
	}
};