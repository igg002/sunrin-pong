#pragma once
#include"cVector2.h"

class cTransform {
public:
	cVector2 position = cVector2(0, 0);
	cVector2 size = cVector2(0, 0);

	void Translate(cVector2 vector2) {
		this->position.x += vector2.x;
		this->position.y += vector2.y;
	}

	void SetTransform(cVector2 vector2) {
		if (!(vector2.x < 0 || vector2.y < 0)) {
			this->position = vector2;
		}
	}

	void SetSize(cVector2 vector2) {
		if (!(vector2.x < 0 || vector2.y < 0)) {
			this->size = vector2;
		}
	}

	cVector2 GetPosition() {
		return this->position;
	}
};