#pragma once
#include"cGameObject.h"

class cPaddle : public cGameObject{
public:
	string gameObjectName;

	cPaddle(int length, string name){
		this->transform.size.x = length;
		string s = "";
		for (int i = 0; i < this->transform.size.x; i++) { s += "*"; }
		this->SetShape(s);
		this->SetName(name);
	}

	void SetName(string name) {
		this->gameObjectName = name;
	}

	void UpdateLength(int length) {
		this->transform.size.x = length;
		string s = "";
		for (int i = 0; i < this->transform.size.x; i++) { s += "*"; }
		this->SetShape(s);
	}
};