#pragma once
#include<string>
#include"cTransform.h"
#include"cGeneral.h"
#include"cConsole.h"

class cGameObject {
public:
	cTransform transform;
	string shape = "";
	bool canCollide = false;

	void Draw() {
		GoToXY(this->transform.position.x, this->transform.position.y);
		cout << shape;
	}

	void SetShape(string s) {
		this->shape = s;
	}

	void SetCollide(bool b) {
		this->canCollide = b;
	}

	string GetGameObjectTransformInfo() {
		return "X : " + std::to_string(this->transform.position.x) + " Y : " + std::to_string(this->transform.position.y);
	}

	bool CheckCollision(cGameObject other) {
		if (other.canCollide && this->canCollide) {
			int otherYPos = (int)other.transform.position.y;
			int otherXPos = (int)other.transform.position.x;

			int thisYPos = (int)this->transform.position.y;
			int thisXPos = (int)this->transform.position.x;

			if ((otherYPos >= thisYPos) && (otherYPos <= (thisYPos + (int)this->transform.size.y)) && (otherXPos >= thisXPos) && (otherXPos <= (thisXPos + (int)this->transform.size.x))) {
				return true;
			} else {
				return false;
			}
		}
		else return false;
	}

	cGameObject ReturnCollisionObject(cGameObject other) {
		if (other.canCollide && this->canCollide) {
			if (other.transform.position.y == this->transform.position.y && other.transform.position.x >= this->transform.size.x && other.transform.position.x <= this->transform.size.x) {
				return other;
			}
		}
	}
};