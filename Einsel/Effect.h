#pragma once
#include "DxLib.h"
#include "SE.h"
class Effect {
public:
	int time = 0;
	SE se;
	int x, y, kinds;
	bool disappear = false;
	static int img_effect_small[7];// LoadDivGraph("graphics\\img_effect_small.png", 7, 7, 1, 100, 100, Effect::img_effect_small);
	static int img_effect_middle[8];// LoadDivGraph("graphics\\img_effect_middle.png", 8, 8, 1, 300, 300, Effect::img_effect_middle);
	static int img_effect_big[16];// LoadDivGraph("graphics\\img_effect_big.png", 16, 8, 2, 400, 400, Effect::img_effect_big);
	static int img_effect_clear[6];// LoadDivGraph("graphics\\img_effect_clear.png", 6, 6, 1, 600, 140, Effect::img_clear);
	//static int sound_effect_small,	//SoundEffect of Enemy(zako)
	//			sound_effect_middle,	//SoundEffect of Boss(1, 2stage)
	//			sound_effect_big;	//SoundEffect of Lime
	Effect(int x, int y, int kinds) {
		this->x = x;
		this->y = y;
		this->kinds = kinds;
	}
	void DrawSmallEffect(int x, int y);
	void DrawMiddleEffect(int x, int y);
	void DrawBigEffect(int x, int y);
	void PlayEffectMusic();
	void draw();
};