#pragma once
#include "DxLib.h"

class Music {
public:
	static int  sound_title,// =  LoadSoundMem("Music\\Ainsel.ogg");
				sound_story_start,// =  LoadSoundMem("Music\\Begining_of_Adventure.ogg");
				sound_stage_one,// =  LoadSoundMem("Music\\Stage_1.ogg");
				sound_stage_boss,// =  LoadSoundMem("Music\\Boss_1_2.ogg");
				sound_stage_two,// =  LoadSoundMem("Music\\Stage_2.ogg");
				sound_stage_three,// =  LoadSoundMem("Music\\Stage_3.ogg");
				sound_stage_three_boss,// =  LoadSoundMem("Music\\Boss_3.ogg");
				sound_game_over,// =  LoadSoundMem("Music\\GameOver.ogg");
				sound_stage_extra,// =  LoadSoundMem("Music\\Go_Through_Deeper_Pool.ogg");
				sound_stage_extra_boss_one,// =  LoadSoundMem("Music\\Ex_Boss_1.ogg");
				sound_stage_extra_boss_two;// =  LoadSoundMem("Music\\Ex_Boss_2.ogg");
	static int  sound_story_lime,// = LoadSoundMem("Music\\Lime_on_Stage.ogg");
				sound_story_ED,// =  LoadSoundMem("Music\\The_End_of_Lime.ogg");
				sound_story_End;// =  LoadSoundMem("Music\\Yourselves.ogg");
	int i;
	bool story[5] = { false, false, false, false, false },
		stage[5] = {true, false, false, false, false}, //0 = title, 1~3 = stage 1~3, 4 = extra
		 boss[5] = {false, false, false, false, false}, // 0 ~1 = stage 1~3, 2~3 = extra
		 ckeck_once = false;
	void SetNewMusic(int map, int story, bool existboss);
	void PlayMusic();
};