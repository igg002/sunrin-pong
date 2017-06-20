#pragma once
#include<stdlib.h>
#include<time.h>
#include"cGameObject.h"

enum BALLDIRECTION { UPPER_STRAIGHT, UPPER_RIGHT, UPPER_LEFT, LOWER_STRAIGHT, LOWER_RIGHT, LOWER_LEFT };

class cBall : public cGameObject{
public:
	BALLDIRECTION ballDirection;
	float ballSpeed;
	float ballDegree = 1;

	void SetRandomBallDirection() {
		srand((unsigned int)time(NULL));
		this->ballDirection = BALLDIRECTION(rand() % 6);
	}

	void SetBallDirection(BALLDIRECTION direction) {
		this->ballDirection = direction;
	}

	void SetBallSpeed(float speed) {
		this->ballSpeed = speed;
	}

	void SetBallDegree(float degree) {
		this->ballDegree = degree;
	}

	void MoveToDirection() {
		switch (this->ballDirection) {
		case(UPPER_STRAIGHT):
			this->transform.Translate(cVector2(0, -this->ballSpeed));
			break;
		case(UPPER_LEFT):
			this->transform.Translate(cVector2(-this->ballSpeed * this->ballDegree, -this->ballSpeed / this->ballDegree));
			break;
		case(UPPER_RIGHT):
			this->transform.Translate(cVector2(this->ballSpeed * this->ballDegree, -this->ballSpeed / this->ballDegree));
			break;
		case(LOWER_STRAIGHT):
			this->transform.Translate(cVector2(0, this->ballSpeed));
			break;
		case(LOWER_LEFT):
			this->transform.Translate(cVector2(-this->ballSpeed * this->ballDegree, this->ballSpeed / this->ballDegree));
			break;
		case(LOWER_RIGHT):
			this->transform.Translate(cVector2(this->ballSpeed * this->ballDegree, this->ballSpeed / this->ballDegree));
			break;
		}
	}
};