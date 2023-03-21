#pragma once
#include "object.h"

class Item:public object {
public:
	int bigrange = 40, spd = 2;//残りの初期値はDatabaseでもらう
	double angle = 0.0;
	int time = 0;
	static int img_item[4]; // LoadGraph("graphics\\item.png");
	Item(int x, int y, int hp) {//クラスのオーバーローディング。Databaseでこの形で実体を呼ぶ
		this->x = x;
		this->y = y;
		this->range = 10;
		this->hp = hp;//体調ゲージの増加量
	}
	void update();//別にmoveの関数を作らずここに設定
	void draw();
};