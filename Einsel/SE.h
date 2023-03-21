#pragma once
#include<DxLib.h>

class SE {
public:
	bool check_once = false;
	static int warning, // =  LoadSoundMem("Music\\boss_comming.wav");
				boss_damaged,// =  LoadSoundMem("Music\\boss_damaged.wav");
				lime_damaged,// =  LoadSoundMem("Music\\lime_damaged.wav");
				palime_damaged,// =  LoadSoundMem("Music\\palime_damaged.wav");
				enemy_broken,// =  LoadSoundMem("Music\\enemy_broken.wav");
				palime_broken,// =  LoadSoundMem("Music\\palime_broken.wav");
				final_broken,// =  LoadSoundMem("Music\\final_broken.wav");
				boss_clear,// =  LoadSoundMem("Music\\boss_clear.wav");
				shoot,// =  LoadSoundMem("Music\\shoot.wav");
				heal,// =  LoadSoundMem("Music\\heal.wav");
				decide;// =  LoadSoundMem("Music\\decide.wav");
	void PlaySE(int num);
	/*
	decide = 0;
	shoot = 1;
	heal = 2;
	enemy_broken = 3
	warning = 4
	boss_damaged = 5
	lime_damaged = 6;
	palime_damaged = 7;
	boss_clear = 8;
	palime_broken = 9;
	final_broken = 10;
	*/
};