#pragma once
#include<Windows.h>
using namespace std;

class cManager {
public:
	bool isQuit = false;

	int p1Score, p2Score;
	int gameOverScore;
	float ballSpeed;

	void Quit() { this->isQuit = true; }
	void SetGameOverScore(int score) { this->gameOverScore = score; }
	void SetBallSpeed(float speed) { this->ballSpeed = speed; }
};