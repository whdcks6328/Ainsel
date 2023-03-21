#pragma once
#include "HitManager.h"
#include "Music.h"

class Stage {
	int i,
		stage_y = 0;
public:
	bool can_boss = true;
	int local_time = 0;
	HitManager hitmanager;
	Music stm;
	FILE* fp_stage;
	static int img_stage_one[2]; //LoadDivGraph("graphics\\img_stage_one.png", 2, 1, 2, 600, 600, Stage::img_stage_one);
	static int img_stage_two[2]; ///LoadDivGraph("graphics\\img_stage_two.png", 2, 1, 2, 600, 600, Stage::img_stage_two);
	static int img_stage_three_a[2]; ///LoadDivGraph("graphics\\img_stage_three_a.png", 2, 1, 2, 600, 600, Stage::img_stage_three_a);
	static int img_stage_extra[2];//LoadDivGraph("graphics\\img_stage_three_a.png", 2, 1, 2, 600, 600, Stage::img_stage_extra);
	static int img_stage_one_boss; //  = LoadGraph("graphics\\img_stage_one_boss.png");
	static int img_stage_two_boss; //= LoadGraph("graphics\\img_stage_two_boss.png");
	static int img_stage_three_boss; //= LoadGraph("graphics\\img_stage_three_boss.png");
	static int img_stage_extra_boss;//= LoadGraph("graphics\\img_stage_extra_boss.png");
	static int img_stage_outline,
			   img_warning[6]; //LoadDivGraph("graphics\\img_warning.png", 6, 6, 1, 600, 160, Stage::img_warning);
	int Enemy_time, Enemy_x, Enemy_kind;
	std::deque<int> Enemy_appear;
	std::deque<int> Enemy_x_save;
	std::deque<int> Enemy_kind_save;
	int StageNumber = 0,
		time = 0;

	void EraseAllObject();
	void SampleStage();
	void StageLoad();
	void BossSet();
	void StageSet();
	void StageClear();
	void StageProgress();
	void update();
	void EnemyMapDraw(int StageNum);
	void BossMapDraw(int StageNum);
	void WarningDraw();
	void draw();
};