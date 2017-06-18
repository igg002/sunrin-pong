#pragma once
#include"cVector2.h"

class cTransform {
public:
	int x, y;

	void Translate(cVector2 vector2) {
		this->x += vector2.x;
		this->y += vector2.y;
	}

	void SetTransform(cVector2 vector2) {
		this->x = vector2.x;
		this->y = vector2.y;
	}
};