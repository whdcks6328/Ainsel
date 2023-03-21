#pragma once
#include <deque>
#include "Player.h"
#include "Zako.h"
#include "Bullet.h"
#include "Item.h"
#include "Boss.h"
#include "SE.h"
using namespace std;

class Database{
	int cooldown_player_shoot = 15, //�e�̔��˂̃N�[���_�E���B
		cooldown_ameba_shoot = 90,
		cooldown_cholesterol_shoot = 70,
		cooldown_poisonous_shoot = 90,
		cooldown_virus_shoot = 60,
		cooldown_worm_shoot = 60;
	int ivy_draw = 0;
	int ivy_count = 1;
	double homing;
	int time = 0;//�����̎��ԕύX
	int i;
public:
	Player player;//���@�A�G�A�e�A�A�C�e���̎���
	std::deque<Zako> zako;
	std::deque<Bullet> bullet;
	std::deque<Item> item;
	std::deque<Boss> boss;
	SE se;

	double GetRadian(double num);
	void ZakoAdd(int x, int y, int hp, int range, int kinds, double angle);//���̃N���X�ŃU�R��push_back����ۂɎg���֐�
	void BulletAdd(int x, int y, int hp, int range, int kinds, int pattern, double angle, bool who);//���̃N���X�Łi�ȉ����j
	void ItemAdd(int x, int y, int hp);
	void BossAdd(int x, int hp, int range, int number_boss);
	void PlayerShoot();//Z���������玩�@���e�����֐�
	void ZakoShoot();//�G���e�����֐��B�p�^�[���̒ǉ����ۑ�
	void BossShoot();
	void update();
	void draw();
};