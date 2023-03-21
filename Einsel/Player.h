#pragma once
#include "object.h"
#include "Input.h"

class Player :public object {
public:
	Input input;
	int time = 0;
	int hp = 1, physicaldamage = 3, bulletdamage = 5, canbomb = 0;//初期値。
	int shoot_cooldown = 0;//弾発射時ののクールダウン。正確なクールダウンの数値はDatabaseでもらう
	int paralyze_cooldown = 0; //麻痺のクールダウン。正確なクールダウンの数値はHitManagerでもらう
	int barrier_collapse = 0; //バイアの崩壊のエフェクト処理のために用意した補助時間変更
	int xspd = 3, yspd = 3;
	int wall_left = 75, wall_right = 525;//左右の壁はここに設定
	static int img_player[7];// = LoadGraph("graphics\\img_player_normal.png");
	static int img_effect_playerhitted[8];// = LoadDivGraph("graphics\\img_effect_playerhitted.png", 8, 8, 1, 100, 100, Player::img_effect_playerhitted);
	void move();//壁と画面の上下を超えない限り、キーが押されたら動く
	void update();
	void draw();
};