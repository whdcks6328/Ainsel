#pragma once
#include "object.h"

class Item:public object {
public:
	int bigrange = 40, spd = 2;//�c��̏����l��Database�ł��炤
	double angle = 0.0;
	int time = 0;
	static int img_item[4]; // LoadGraph("graphics\\item.png");
	Item(int x, int y, int hp) {//�N���X�̃I�[�o�[���[�f�B���O�BDatabase�ł��̌`�Ŏ��̂��Ă�
		this->x = x;
		this->y = y;
		this->range = 10;
		this->hp = hp;//�̒��Q�[�W�̑�����
	}
	void update();//�ʂ�move�̊֐�����炸�����ɐݒ�
	void draw();
};