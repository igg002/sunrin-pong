#include<iostream>
#include<Windows.h>
#include<string>
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

#define BALL_SPAWN_MIN_MAX 2
#define RESET_WAIT_SECONDS 3

void CheckBallCollision();
void CheckScore();
void ResetGame();
void Victory(cPaddle winner);


HWND hwnd;
POINT p; 

cManager manager = cManager();
cBall ball = cBall();
cPaddle cursorPaddleP1 = cPaddle(10, "Player One");
cPaddle cursorPaddleP2 = cPaddle(10, "Player Two");
cGameObject P1ScoreUI = cGameObject();
cGameObject P2ScoreUI = cGameObject();


void Initialize() {
	hwnd = GetConsoleWindow();
	p.x = 0; p.y = 0;

	SetWindowsSize(hwnd, 500, 700);
	SetCursor(false);

	manager.SetGameOverScore(11);
	manager.SetBallSpeed(0.1);

	ball.transform.SetTransform(cVector2(GetConsoleSizeCol() / 2, GetConsoleSizeRow() / 2));
	ball.SetShape("¤·");
	ball.SetRandomBallDirection();
}

void Update() {	
	// Input, Update

	ClearScreen();

	cursorPaddleP1.transform.SetTransform(cVector2(GetCursorColPos(hwnd, p, cursorPaddleP1.paddleLength), 1));
	cursorPaddleP2.transform.SetTransform(cVector2(GetCursorColPos(hwnd, p, cursorPaddleP2.paddleLength), GetConsoleSizeRow() - 1));
	cursorPaddleP1.Draw();
	cursorPaddleP2.Draw();

	P1ScoreUI.transform.SetTransform(cVector2(GetConsoleSizeCol() / 2, cursorPaddleP1.transform.y + 3));
	P2ScoreUI.transform.SetTransform(cVector2(GetConsoleSizeCol() / 2, cursorPaddleP2.transform.y - 3));
	P1ScoreUI.SetShape(std::to_string(manager.p1Score));
	P2ScoreUI.SetShape(std::to_string(manager.p2Score));
	P1ScoreUI.Draw();
	P2ScoreUI.Draw();
	
	CheckBallCollision();

	switch (ball.ballDirection) {
	case(UPPER_STRAIGHT):
		ball.transform.Translate(cVector2(0, -manager.ballSpeed));
		break;
	case(UPPER_LEFT):
		ball.transform.Translate(cVector2(-manager.ballSpeed, -manager.ballSpeed));
		break;
	case(UPPER_RIGHT):
		ball.transform.Translate(cVector2(manager.ballSpeed, -manager.ballSpeed));
		break;
	case(LOWER_STRAIGHT):
		ball.transform.Translate(cVector2(0, manager.ballSpeed));
		break;
	case(LOWER_LEFT):
		ball.transform.Translate(cVector2(-manager.ballSpeed, manager.ballSpeed));
		break;
	case(LOWER_RIGHT):
		ball.transform.Translate(cVector2(manager.ballSpeed, manager.ballSpeed));
		break;
	}

	CheckScore();
	ball.Draw();
}

void Render() {
	// Clear, Draw

}

void CheckBallCollision() {
	if ((int)ball.transform.y == cursorPaddleP1.transform.y) {
		if (ball.transform.x >= cursorPaddleP1.transform.x && ball.transform.x <= cursorPaddleP1.transform.x + cursorPaddleP1.paddleLength) {
			switch (ball.ballDirection) {
			case(UPPER_STRAIGHT):
				ball.SetBallDirection(BALLDIRECTION(RandIntRange(3, 5)));
				break;
			case(UPPER_LEFT):
				ball.SetBallDirection(LOWER_LEFT);
				break;
			case(UPPER_RIGHT):
				ball.SetBallDirection(LOWER_RIGHT);
				break;
			}
		}
	}

	if ((int)ball.transform.y == cursorPaddleP2.transform.y) {
		if (ball.transform.x >= cursorPaddleP2.transform.x && ball.transform.x <= cursorPaddleP2.transform.x + cursorPaddleP1.paddleLength) {
			switch (ball.ballDirection) {
			case(LOWER_STRAIGHT):
				ball.SetBallDirection(BALLDIRECTION(RandIntRange(0, 2)));
				break;
			case(LOWER_RIGHT):
				ball.SetBallDirection(UPPER_RIGHT);
				break;
			case(LOWER_LEFT):
				ball.SetBallDirection(UPPER_LEFT);
				break;
			}
		}
	}

	if ((int)ball.transform.x == GetConsoleSizeCol() || (int)ball.transform.x == 0) {
		switch (ball.ballDirection) {
		case(LOWER_RIGHT):
			ball.SetBallDirection(LOWER_LEFT);
			break;
		case(LOWER_LEFT):
			ball.SetBallDirection(LOWER_RIGHT);
			break;
		case(UPPER_RIGHT):
			ball.SetBallDirection(UPPER_LEFT);
			break;
		case(UPPER_LEFT):
			ball.SetBallDirection(UPPER_RIGHT);
			break;
		}
	}
}

void CheckScore() {
	if (manager.p1Score == manager.gameOverScore || manager.p2Score == manager.gameOverScore) {
		manager.Quit();
	}

	if (ball.transform.y <= 0) {
		manager.p2Score += 1;
		ResetGame();
	}

	if (ball.transform.y >= GetConsoleSizeRow()) {
		manager.p1Score += 1;
		ResetGame();
	}
}

void ResetGame() {
	ball.transform.SetTransform(cVector2(RandIntRange(BALL_SPAWN_MIN_MAX, GetConsoleSizeCol()- BALL_SPAWN_MIN_MAX), GetConsoleSizeRow() / 2));
	WaitForSeconds(RESET_WAIT_SECONDS);
	ball.SetRandomBallDirection();
}

void main() {
	Initialize();
	while (!manager.isQuit) {
		Update();
		Render();
	}
	if (manager.p1Score == manager.gameOverScore) { manager.Victory(cursorPaddleP1); }
	else { manager.Victory(cursorPaddleP2); }
}