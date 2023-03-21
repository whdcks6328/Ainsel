#include "Input.h"
#include "DxLib.h"

	void Input::KeyCheck() {
		GetHitKeyStateAll(buf);
	}
	bool Input::GetKey(int key){
    return buf[key] == 1;
    }
	void Input::update() {
		KeyCheck();
	}
