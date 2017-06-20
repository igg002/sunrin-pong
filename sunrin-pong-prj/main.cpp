#include<iostream>
#include<Windows.h>
#include<string>
#include"GameLibrary.h"
#include"ConsoleLibrary.h"
#include"GameSystems.h"
using namespace std;


#define INITIAL_WINDOW_X 700
#define INITIAL_WINDOW_Y 500
#define INITIAL_CURSOR_VISIBILITY false

#define INITIAL_PAD_SIZE 10

#define BALL_SPAWN_MIN_MAX 2
#define RESET_WAIT_SECONDS 3

#define MIN_PAD_SIZE 1
#define MAX_PAD_SIZE 10

#define MIN_WINDOW_X 200
#define MAX_WINDOW_X 800
#define MIN_WINDOW_Y 200
#define MAX_WINDOW_Y 800

#define INTIAL_BALL_SPEED 0.1
#define MIN_BALL_SPEED 0.1
#define MAX_BALL_SPEED 0.8

#define DELAY 0.25


HWND hwnd;
POINT p;

cPongManager m_manager = cPongManager(11);
cConsoleWindow m_Window = cConsoleWindow(hwnd, p);

cBall ball;

cPaddle P1Paddle = cPaddle(INITIAL_PAD_SIZE, "Player One");
cPaddle P2Paddle = cPaddle(INITIAL_PAD_SIZE, "Player Two");

cGameObject leftWall;
cGameObject rightWall;

cGameObject P1ScoreZone;
cGameObject P2ScoreZone;

cGameObject P1ScoreUI;
cGameObject P2ScoreUI;


void ResetStage();

void Initialize() {
	// Start, Initialize
	hwnd = GetConsoleWindow();
	p.x = 0; p.y = 0;

	SetWindowSize(hwnd, INITIAL_WINDOW_Y, INITIAL_WINDOW_X);
	SetCursor(INITIAL_CURSOR_VISIBILITY);

	P1Paddle.canCollide = true;
	P2Paddle.canCollide = true;

	leftWall.canCollide = true;
	rightWall.canCollide = true;

	P1ScoreZone.canCollide = true;
	P2ScoreZone.canCollide = true;

	ball.canCollide = true;
	ball.SetBallSpeed(INTIAL_BALL_SPEED);
	ball.transform.SetTransform(cVector2(GetConsoleSizeCol() / 2, GetConsoleSizeRow() / 2));
	ball.SetShape("¤·");
	ball.SetRandomBallDirection();
}

void Update() {
	// Input, Update
	P1Paddle.transform.SetTransform(cVector2(GetCursorColPos(hwnd, p, P1Paddle.transform.size.x), 1));
	P2Paddle.transform.SetTransform(cVector2(GetCursorColPos(hwnd, p, P2Paddle.transform.size.x), GetConsoleSizeRow() - 1));

	leftWall.transform.SetTransform(cVector2(0, 0));
	rightWall.transform.SetTransform(cVector2(GetConsoleSizeCol(), 0));

	leftWall.transform.SetSize(cVector2(0, GetConsoleSizeRow()));
	rightWall.transform.SetSize(cVector2(1, GetConsoleSizeRow()));

	P1ScoreZone.transform.SetTransform(cVector2(0, 0));
	P2ScoreZone.transform.SetTransform(cVector2(0, GetConsoleSizeRow()));

	P1ScoreZone.transform.SetSize(cVector2(GetConsoleSizeCol(), 0));
	P2ScoreZone.transform.SetSize(cVector2(GetConsoleSizeCol(), 0));

	P1ScoreUI.transform.SetTransform(cVector2(GetConsoleSizeCol() / 2, P1Paddle.transform.position.y + 2));
	P2ScoreUI.transform.SetTransform(cVector2(GetConsoleSizeCol() / 2, P2Paddle.transform.position.y - 2));

	P1ScoreUI.SetShape(std::to_string(m_manager.p1Score));
	P2ScoreUI.SetShape(std::to_string(m_manager.p2Score));

	if (P1Paddle.CheckCollision(ball)) {
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
		P1Paddle.UpdateLength(RandIntRange(MIN_PAD_SIZE, MAX_PAD_SIZE));
		ball.ballDegree = RandFloatRange(1.0, 6.0);
		WaitForSeconds(DELAY);
	}

	if (P2Paddle.CheckCollision(ball)) {
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
		P2Paddle.UpdateLength(RandIntRange(MIN_PAD_SIZE, MAX_PAD_SIZE));
		ball.ballDegree = RandFloatRange(1.0, 6.0);
		WaitForSeconds(DELAY);
	}

	if (leftWall.CheckCollision(ball) || rightWall.CheckCollision(ball)) {
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

	ball.MoveToDirection();

	if (P1ScoreZone.CheckCollision(ball)) { m_manager.p2Score++; ResetStage(); }
	if (P2ScoreZone.CheckCollision(ball)) { m_manager.p1Score++; ResetStage(); }
}

void Render() {
	// Clear, Render
	ClearScreen();
	SetCursor(INITIAL_CURSOR_VISIBILITY);

	P1Paddle.Draw();
	P2Paddle.Draw();
	P1ScoreUI.Draw();
	P2ScoreUI.Draw();
	ball.Draw();

	if (m_manager.p1Score == m_manager.gameOverScore) { m_manager.Victory(P1Paddle); }
	if (m_manager.p2Score == m_manager.gameOverScore) { m_manager.Victory(P2Paddle); }
}

void main() {
	Initialize();
	while (!m_manager.isQuit) {
		Update();
		Render();
	}
}

void ResetStage() {
	SetWindowSize(hwnd, RandIntRange(MIN_WINDOW_Y, MAX_WINDOW_Y), RandIntRange(MIN_WINDOW_X, MAX_WINDOW_X));
	ball.ballSpeed = RandFloatRange(MIN_BALL_SPEED, MAX_BALL_SPEED);

	P1Paddle.UpdateLength(INITIAL_PAD_SIZE);
	P2Paddle.UpdateLength(INITIAL_PAD_SIZE);

	ball.transform.SetTransform(cVector2(RandIntRange(BALL_SPAWN_MIN_MAX, GetConsoleSizeCol() - BALL_SPAWN_MIN_MAX), GetConsoleSizeRow() / 2));
	ball.SetRandomBallDirection();

	Update();
	Render();

	WaitForSeconds(3);
}