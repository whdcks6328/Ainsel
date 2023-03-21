#pragma once
#include "DxLib.h"

class Input {
public:
	char buf[256];

	void KeyCheck();//キーの入力状態を確認
    bool GetKey(int key);//特定のキーの入力を確認し、論理型変数として返す
	void update();
};