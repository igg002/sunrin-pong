#pragma once
#include"GameSystems.h"
#include"GameLibrary.h"

class PongAI {
public:
	cTransform transform;
	float previousError, error, weight, bias;
	float predictedMovement;

	PongAI() {
		//this->previousError = 0;
		this->weight = RandFloatRange(0.0, 10.0);
		this->bias = RandFloatRange(0.0, 10.0);
	}

	void Predict(cBall ball) {
		float ballXPos = ball.transform.position.x;
		float thisXPos = this->transform.position.x;
		float predictedMovement = (ballXPos * weight);
		this->transform.Translate(cVector2(this->predictedMovement, 0));

		this->previousError = this->error;
		this->error = CalculateError(ballXPos, thisXPos);
	}

	float CalculateError(float ballpos, float thispos) {
		return ballpos - thispos;
	}
};