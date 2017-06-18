#pragma once
#include"cGameObject.h"

class cPaddle : public cGameObject{
public:
	cPaddle(int length){
		string s = "";
		for (int i = 0; i < length; i++) { s += "*"; }
		this->SetShape(s);
	}
};