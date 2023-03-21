#pragma once
#include "object.h"
#include <stdlib.h>

class Zako :public object {
	int time = 0;
public:
	int wall_left = 75, wall_right = 525;//左右の壁はここに設定
	int spd_ameba = 1;//各ザコキャラのスピードは主にここで指定（またはcpp)
	int	spd_cholesterol = 3;
	int	spd_poisonous = 2; 
	int poisonous_count = 0;
	int	xspd_sugikahun = 0, yspd_sugikahun = 0;
	int r = 20, xspd_virus = 2, yspd_virus = 2;
	int	spd_worm= 1;
	double angle = 0 ;
	int kinds;//初期値はDatabase（Stage）でもらう。
	static int img_ameba[5]; // LoadDivGraph("graphics\\img_ameba.png", 5, 5, 1, 60, 60, Zako::img_ameba);
	static int img_cholesterol[8]; //LoadDivGraph("graphics\\img_cholestirol.png", 8, 8, 1, 70, 70, Zako::img_poisonous);
	static int img_poisonous[4]; //LoadDivGraph("graphics\\img_poisonous.png", 4, 4, 1, 45, 80, Zako::img_poisonous);
	static int img_sugikahun[4];// = LoadDivGraph("graphics\\img_sugikahun.png", 4, 4, 1, 50, 50, img_sugikahun);
	static int img_virus[4];//LoadDivGraph("graphics\\img_virus.png", 4, 4, 1, 90, 90, Zako::img_virus);
	static int img_worm[6];//LoadDivGraph("graphics\\img_worm.png", 6, 6, 1, 65, 100, Zako::img_worm);
	Zako(int x, int y, int hp, int range, int kinds, double angle) {//クラスのオーバーローディング。Databaseでこの形で実体を呼ぶ
		this->x = x;
		this->y = y;	
		this->hp = hp;
		this->range = range;
		this->kinds = kinds;
		this->angle = angle;
	}
	void MovePattern_Ameba();//アメーバーの動くパターン
	void MovePattern_Cholesterol();//悪玉コレステロールの動くパターン
	void MovePattern_Poisonous();//ポイズナス・バクテリアの動くパターン
	void MovePattern_Sugikahun();//スギカフンの動くパターン
	void MovePattern_Virus();//ビールスの動くパターン
	void MovePattern_Worm();//ワームの動くパターン
	void Move(int kinds);//敵の種類ごとに動きのパターンが違うように設定。
	void update();
	void DrawAmeba();
	void DrawCholesterol();
	void DrawPoisonous();
	void DrawSugikahun();
	void DrawVirus();
	void DrawWorm();
	void draw();
};