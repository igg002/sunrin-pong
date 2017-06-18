#pragma once
#include"cTransform.h"
#include"cGeneral.h"

class cGameObject {
public:
	cTransform transform = cTransform();
	string shape = "";

	void Draw() {
		GoToXY(this->transform.x, this->transform.y);
		cout << shape;
	}

	void SetShape(string s) {
		this->shape = s;
	}
};