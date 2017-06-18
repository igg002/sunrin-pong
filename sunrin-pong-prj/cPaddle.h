#pragma once
#include"cGameObject.h"

class cPaddle : public cGameObject{
public:
	int paddleLength;
	cPaddle(int length){
		this->paddleLength = length;
		string s = "";
		for (int i = 0; i < this->paddleLength; i++) { s += "*"; }
		this->SetShape(s);
	}
};