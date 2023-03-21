#pragma once
#include "object.h"
#include "Input.h"

class Player :public object {
public:
	Input input;
	int time = 0;
	int hp = 1, physicaldamage = 3, bulletdamage = 5, canbomb = 0;//�����l�B
	int shoot_cooldown = 0;//�e���ˎ��̂̃N�[���_�E���B���m�ȃN�[���_�E���̐��l��Database�ł��炤
	int paralyze_cooldown = 0; //��Ⴢ̃N�[���_�E���B���m�ȃN�[���_�E���̐��l��HitManager�ł��炤
	int barrier_collapse = 0; //�o�C�A�̕���̃G�t�F�N�g�����̂��߂ɗp�ӂ����⏕���ԕύX
	int xspd = 3, yspd = 3;
	int wall_left = 75, wall_right = 525;//���E�̕ǂ͂����ɐݒ�
	static int img_player[7];// = LoadGraph("graphics\\img_player_normal.png");
	static int img_effect_playerhitted[8];// = LoadDivGraph("graphics\\img_effect_playerhitted.png", 8, 8, 1, 100, 100, Player::img_effect_playerhitted);
	void move();//�ǂƉ�ʂ̏㉺�𒴂��Ȃ�����A�L�[�������ꂽ�瓮��
	void update();
	void draw();
};