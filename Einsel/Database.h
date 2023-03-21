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
	int cooldown_player_shoot = 15, //弾の発射のクールダウン。
		cooldown_ameba_shoot = 90,
		cooldown_cholesterol_shoot = 70,
		cooldown_poisonous_shoot = 90,
		cooldown_virus_shoot = 60,
		cooldown_worm_shoot = 60;
	int ivy_draw = 0;
	int ivy_count = 1;
	double homing;
	int time = 0;//いつもの時間変更
	int i;
public:
	Player player;//自機、敵、弾、アイテムの実態
	std::deque<Zako> zako;
	std::deque<Bullet> bullet;
	std::deque<Item> item;
	std::deque<Boss> boss;
	SE se;

	double GetRadian(double num);
	void ZakoAdd(int x, int y, int hp, int range, int kinds, double angle);//他のクラスでザコをpush_backする際に使う関数
	void BulletAdd(int x, int y, int hp, int range, int kinds, int pattern, double angle, bool who);//他のクラスで（以下略）
	void ItemAdd(int x, int y, int hp);
	void BossAdd(int x, int hp, int range, int number_boss);
	void PlayerShoot();//Zを押したら自機が弾を撃つ関数
	void ZakoShoot();//敵が弾を撃つ関数。パターンの追加が課題
	void BossShoot();
	void update();
	void draw();
};