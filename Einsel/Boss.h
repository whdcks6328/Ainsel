#pragma once
#include "object.h"
#include "SE.h"

class Boss : public object{
public:
	SE bose;
	unsigned int time = 0;
	int localtime = 0;
	double angle = 0;//“®‚«‚ÌŠp“x‚Ì’²®
	static int img_boss_leraje[10]; //LoadDivGraph("graphics\\img_boss_leraje.png", 10, 5, 2, 100, 200, Boss::img_boss_reraje);
	static int img_boss_buer[24]; //LoadDivGraph("graphics\\img_boss_buer.png", 24, 8, 3, 150, 150, Boss::img_boss_buer);
	static int img_boss_lime[40];//LoadDivGraph("graphics\\img_boss_lime.png", 40, 8, 5, 150, 120, Boss::img_boss_lime);
	static int img_boss_parasitelime_stay[6];//LoadDivGraph("graphics\\img_boss_parasitelime_stay.png", 6, 6, 1, 300, 300, Boss::img_boss_parasitelime_stay);
	static int img_boss_parasitelime_ivy[6];//LoadDivGraph("graphics\\img_boss_parasitelime_ivy.png", 6, 6, 1, 300, 300, Boss::img_boss_parasitelime_ivy);
	static int img_boss_parasitelime_ex2[5];//LoadDivGraph("graphics\\img_boss_parasitelime_ex2.png", 5, 5, 1, 80, 120, Boss::img_boss_parasitelime_ex2);
	static int img_boss_parasitelime_change[24];//LoadDivGraph("graphics\\img_boss_parasitelime_change.png", 24, 8, 3, 300, 300, Boss::img_boss_parasitelime_change);
	int number_boss,
		spd_leraje = 2,
		xspd_buer = 2, yspd_buer = 0,
		xspd_lime = 2, yspd_lime = 3, spd_lime = 3, 
		spd_parasitelime = 1,
		check_hit = 0;
	int buer_count = 1;
	int lime_count = 1;
	bool check_phase = false;
	bool check_once = TRUE;
	Boss(int x, int y, int hp, int range, int number_boss) {
		this->x = x;
		this->y = y;
		this->hp = hp;
		this->range = range;
		this->number_boss = number_boss;
	}
	void Move_Leraje();
	void Move_Buer();
	void Move_Lime();
	void Move_ParasiteLime();
	void Move_ParasiteLimeFinal();
	void Move(int number_boss);
	void update();
	void Draw_Leraje();
	void Draw_Buer();
	void Draw_Lime();
	void Draw_ParasiteLime();
	void Draw_ParasiteLimeChenge();
	void Draw_ParasiteLimeFinal();
	void draw();
};