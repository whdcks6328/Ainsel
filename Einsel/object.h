#pragma once
#define _USE_MATH_DEFINES
#include<cmath>
#include"DxLib.h"
#define M_PI       3.14159265358979323846

class object {
public:
	int x, y, hp, range;
	bool disappear = false;
	static double CheckLength(object* obj1, object* obj2);//��̃I�u�W�F�N�g�̋����𑪂�֐�
	static bool CheckHit(object* obj1, object* obj2);//��̃I�u�W�F�N�g�̋������e���̔��a�̘a���傫�������������𔻕�
	//�Q??�ɏo������I�u�W�F�N�g�͑S�����̃N���X���p�����邽�߁A�I�u�W�F�N�g?�̃N���X��?��ϐ������炦��
	//���Ȃ݂ɁA���̓�̊֐�������܂蓮���Ă����C�����Ȃ��̂ŁA�ύX�������͍폜�̉�?������B
	virtual void draw() = 0;//�����̂܂Ƃ߁B��?���������ߑ��̏��ɂ͐����ȗ�
	virtual void update() = 0;//������Draw�֐��B��?���������߁i�ȉ����j
};