#pragma once
#include "DxLib.h"

class HealthGage {
public:
	static int img_HealthGage[130]; //= LoadDivGraph("graphics\\img_health.png", 130, 1, 130, 200, 1, img_HealthGage);
	unsigned int time = 1; //ŠÔ•ÏX
	bool can_down = true;
	int RecentHealth = 130; //ÀÛ‚Ì‘Ì’²ƒQ[ƒW
	int i; //for draw function
	void CalculateHealth(int i); //plus or minus RecentHealth
	void update(); //every 2 frame, minus RecentHealth 1
	void draw(); //draw img_healthgage using for();
};