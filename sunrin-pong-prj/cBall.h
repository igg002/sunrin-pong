#pragma once
#include<stdlib.h>
#include<time.h>
#include"cGameObject.h"

enum BALLDIRECTION { UPPER_STRAIGHT, UPPER_RIGHT, UPPER_LEFT, LOWER_STRAIGHT, LOWER_RIGHT, LOWER_LEFT };

class cBall : public cGameObject{
public:
	BALLDIRECTION ballDirection;

	void SetRandomBallDirection() {
		srand((unsigned int)time(NULL));
		this->ballDirection = BALLDIRECTION(rand() % 6);
	}

	void SetBallDirection(BALLDIRECTION direction) {
		this->ballDirection = direction;
	}
};