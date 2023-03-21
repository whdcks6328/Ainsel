#pragma once
#include "object.h"

class Bullet :public object {
	int time = 0; 
public:
	bool who;//true�������疡���Afalse��������G
	bool check_once = TRUE;
	double angle;
	int kinds, pattern;//�����l��Database�ł��炤
	double spd = 5.0;//�e�̑��x�͈ꉞ5�ɌŒ�B��X�ς��܂��傤
	int ivy_spd=15;
	static int img_bullet_ameba;// = LoadGraph("graphics\\img_bullet_ameba.png");
	static int img_bullet_cholesterol;// = LoadGraph("graphics\\img_bullet_cholesterol.png");
	static int img_bullet_player; //= LoadGraph("graphics\\img_bullet_player.png");
	static int img_bullet_poisonous[4]; //=LoadDivGraph("graphics\\img_bullet_poisonous.png", 4, 4, 1, 35, 35, img_bullet_poisonous);
	static int img_bullet_virus;//= LoadGraph("graphics\\img_bullet_virus.png");
	static int img_bullet_worm;//= LoadGraph("graphics\\img_bullet_worm.png");
	static int img_bullet_arrow;// = LoadGraph("graphics\\img_bullet_arrow.png");
	static int img_bullet_ivy[16];//LoadDivGraph("graphics\\img_bullet_ivy.png", 16, 1, 16, 30, 30, img_bullet_ivy);
	static int img_bullet_magic;//=LoadGraph("graphics\\img_bullet_magic.png");
	static int img_bullet_shadow[6];//LoadDivGraph("graphics\\img_bullet_shadow.png", 6, 6 ,1 ,250,250,img_bullet_shadow);
	static int img_bullet_arrow_ex;// = LoadGraph("graphics\\img_bullet_arrow_ex.png");
	static int img_bullet_ivy_ex[12];//LoadDivGraph("graphics\\img_bullet_ivy_ex.png", 12, 1, 12, 40, 40,img_bullet_ivy_ex);
	static int img_bullet_meat[3];//LoadDivGraph("graphics\\img_bullet_meat.png", 3, 3, 1, 100, 100,img_bullet_meat);

	Bullet(int x, int y, int hp, int range, int kinds, int pattern, double angle, bool who) {//�N���X�̃I�[�o�[���[�f�B���O�BDatabase�ł��̌`�Ŏ��̂��Ă�
		this->x = x;
		this->y = y;
		this->hp = hp;
		this->range = range;
		this->kinds = kinds;
		this->pattern = pattern;
		this->angle = angle;
		this->who = who;
	}
	void MovePattern_One();//�����̃p�^�[���A���̇@�F�������ˊp�i�U�O�x�@�j�̂܂ܒe������
	void MovePattern_Two();//���̇A�F�Ŗ�������
	void MovePattern_Thr();//���̇B�F�c�^������
	void MovePattern_Fou();//���̇C�F�e������
	void MovePattern_Fiv();//���̇D�F�����I�u�W�F�N�g�̒e
	void MovePattern_Ten();//�v���C���[�̒e
    void Move(int pattern);//�����̃p�^�[�����܂Ƃ߂����
	void update();
	void DrawBulletPoisonous();
	void DrawBulletShadow();
	void DrawBulletMeat();
	void draw();
};