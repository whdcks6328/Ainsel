#pragma once
#define _USE_MATH_DEFINES
#include<cmath>
#include"DxLib.h"
#define M_PI       3.14159265358979323846

class object {
public:
	int x, y, hp, range;
	bool disappear = false;
	static double CheckLength(object* obj1, object* obj2);//二つのオブジェクトの距離を測る関数
	static bool CheckHit(object* obj1, object* obj2);//二つのオブジェクトの距離が各自の半径の和より大きいか小さいかを判別
	//ゲ??に出現するオブジェクトは全部このクラスを継承するため、オブジェクト?のクラスで?介変数をもらえる
	//ちなみに、この二つの関数があんまり動いてくれる気がしないので、変更もしくは削除の可?性あり。
	virtual void draw() = 0;//いつものまとめ。面?くさいため他の所には説明省略
	virtual void update() = 0;//いつものDraw関数。面?くさいため（以下略）
};