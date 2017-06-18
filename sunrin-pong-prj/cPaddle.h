#pragma once
#include"cGameObject.h"

class cPaddle : public cGameObject{
public:
	int paddleLength;
	string gameObjectName;

	cPaddle(int length, string name){
		this->paddleLength = length;
		string s = "";
		for (int i = 0; i < this->paddleLength; i++) { s += "*"; }
		this->SetShape(s);
		this->SetName(name);
	}

	void SetName(string name) {
		this->gameObjectName = name;
	}
};