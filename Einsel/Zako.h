#pragma once
#include "object.h"
#include <stdlib.h>

class Zako :public object {
	int time = 0;
public:
	int wall_left = 75, wall_right = 525;//���E�̕ǂ͂����ɐݒ�
	int spd_ameba = 1;//�e�U�R�L�����̃X�s�[�h�͎�ɂ����Ŏw��i�܂���cpp)
	int	spd_cholesterol = 3;
	int	spd_poisonous = 2; 
	int poisonous_count = 0;
	int	xspd_sugikahun = 0, yspd_sugikahun = 0;
	int r = 20, xspd_virus = 2, yspd_virus = 2;
	int	spd_worm= 1;
	double angle = 0 ;
	int kinds;//�����l��Database�iStage�j�ł��炤�B
	static int img_ameba[5]; // LoadDivGraph("graphics\\img_ameba.png", 5, 5, 1, 60, 60, Zako::img_ameba);
	static int img_cholesterol[8]; //LoadDivGraph("graphics\\img_cholestirol.png", 8, 8, 1, 70, 70, Zako::img_poisonous);
	static int img_poisonous[4]; //LoadDivGraph("graphics\\img_poisonous.png", 4, 4, 1, 45, 80, Zako::img_poisonous);
	static int img_sugikahun[4];// = LoadDivGraph("graphics\\img_sugikahun.png", 4, 4, 1, 50, 50, img_sugikahun);
	static int img_virus[4];//LoadDivGraph("graphics\\img_virus.png", 4, 4, 1, 90, 90, Zako::img_virus);
	static int img_worm[6];//LoadDivGraph("graphics\\img_worm.png", 6, 6, 1, 65, 100, Zako::img_worm);
	Zako(int x, int y, int hp, int range, int kinds, double angle) {//�N���X�̃I�[�o�[���[�f�B���O�BDatabase�ł��̌`�Ŏ��̂��Ă�
		this->x = x;
		this->y = y;	
		this->hp = hp;
		this->range = range;
		this->kinds = kinds;
		this->angle = angle;
	}
	void MovePattern_Ameba();//�A���[�o�[�̓����p�^�[��
	void MovePattern_Cholesterol();//���ʃR���X�e���[���̓����p�^�[��
	void MovePattern_Poisonous();//�|�C�Y�i�X�E�o�N�e���A�̓����p�^�[��
	void MovePattern_Sugikahun();//�X�M�J�t���̓����p�^�[��
	void MovePattern_Virus();//�r�[���X�̓����p�^�[��
	void MovePattern_Worm();//���[���̓����p�^�[��
	void Move(int kinds);//�G�̎�ނ��Ƃɓ����̃p�^�[�����Ⴄ�悤�ɐݒ�B
	void update();
	void DrawAmeba();
	void DrawCholesterol();
	void DrawPoisonous();
	void DrawSugikahun();
	void DrawVirus();
	void DrawWorm();
	void draw();
};