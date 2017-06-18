#pragma once
#include"cVector2.h"

class cTransform {
public:
	float x, y;

	void Translate(cVector2 vector2) {
		this->x += vector2.x;
		this->y += vector2.y;
	}

	void SetTransform(cVector2 vector2) {
		if (!(vector2.x < 0 || vector2.y < 0)) {
			this->x = vector2.x;
			this->y = vector2.y;
		}
	}
};