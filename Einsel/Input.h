#pragma once
#include "DxLib.h"

class Input {
public:
	char buf[256];

	void KeyCheck();//�L�[�̓��͏�Ԃ��m�F
    bool GetKey(int key);//����̃L�[�̓��͂��m�F���A�_���^�ϐ��Ƃ��ĕԂ�
	void update();
};