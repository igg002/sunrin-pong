#pragma once
#include<string>
#include"cTransform.h"
#include"cGeneral.h"

class cGameObject {
public:
	cTransform transform = cTransform();
	string shape = "";
	bool canCollide = false;

	void Draw() {
		GoToXY(this->transform.x, this->transform.y);
		cout << shape;
	}

	void SetShape(string s) {
		this->shape = s;
	}

	void SetCollide(bool b) {
		this->canCollide = b;
	}

	string GetGameObjectTransformInfo() {
		return "X : " + std::to_string(this->transform.x) + " Y : " + std::to_string(this->transform.y);
	}
};