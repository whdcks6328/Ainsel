#define _CRT_SECURE_NO_WARNINGS
#include "Stage.h"

void Stage::EraseAllObject() {
	if(!(hitmanager.data.bullet.empty()))for (i = 0; i < hitmanager.data.bullet.size(); i++) hitmanager.data.bullet[i].disappear = true;
	if(!(hitmanager.data.zako.empty()))for (i = 0; i < hitmanager.data.zako.size(); i++) hitmanager.data.zako[i].disappear = true;
	if(!(hitmanager.data.item.empty()))for (i = 0; i < hitmanager.data.item.size(); i++) hitmanager.data.item[i].disappear = true;
}

void Stage::SampleStage() {
	if (time % 60 == 59) {
		for (i = 0; i < 3; i++) {
			hitmanager.data.ZakoAdd(100 + 100 * i, 0, 15, 20, 3, 0);
		}
	}
}

void Stage::StageLoad() {
	hitmanager.data.player.x = 300;
	hitmanager.data.player.y = 500;
	hitmanager.data.player.range = 17;
	if(StageNumber == 1)fp_stage = fopen("Setfile\\Stage_One.txt", "r");
	if (StageNumber == 2)fp_stage = fopen("Setfile\\Stage_Two.txt", "r");
	if (StageNumber == 3)fp_stage = fopen("Setfile\\Stage_Three.txt", "r");
	if (StageNumber == 10)fp_stage = fopen("Setfile\\Stage_Extra.txt", "r");
	if (fp_stage == 0)printfDx("error!");
	//Read txt file
	while (!feof(fp_stage)) {
		fscanf(fp_stage, "%d, %d, %d\n", &Enemy_time, &Enemy_x, &Enemy_kind);
		Enemy_appear.push_back(Enemy_time);
		Enemy_x_save.push_back(Enemy_x);
		Enemy_kind_save.push_back(Enemy_kind);
	}
	for (i = 1; i < Enemy_appear.size(); i++)Enemy_appear[i] += Enemy_appear[i - 1];
	fclose(fp_stage);
}

void Stage::BossSet() {
	if (local_time == 210) {
		if (StageNumber < 3)stm.SetNewMusic(0, -1, true);
		else if (StageNumber == 3)stm.SetNewMusic(1, -1, true);
		else if (StageNumber == 10)stm.SetNewMusic(2, -1, true);
		if (StageNumber == 1)hitmanager.data.BossAdd(300, 300, 48, 1);
		if (StageNumber == 2)hitmanager.data.BossAdd(300, 1000, 75, 2);
		if (StageNumber == 3)hitmanager.data.BossAdd(300, 2000, 75, 3);
		if (StageNumber == 10)hitmanager.data.BossAdd(300, 4000, 150, 4);
		if(StageNumber == 3 || StageNumber == 10)hitmanager.healthgage.RecentHealth = 130;
		can_boss = false;
		local_time = 0;
	}
	else {
		if (local_time == 31) {
			stm.SetNewMusic(6, 6, false);
			hitmanager.data.se.PlaySE(4);
		}
		local_time++;
	}
	
}
void Stage::StageSet() {
	if (StageNumber != 10) {
		if(time == 1)stm.SetNewMusic(StageNumber, -1, false);
	}
	else {
		if (time == 1)stm.SetNewMusic(4, -1, false);
	}
	for (i = 0; i < Enemy_appear.size(); i++) {
		if (time == Enemy_appear[i]) {
			hitmanager.data.ZakoAdd(Enemy_x_save[i], 0, 15, 20, Enemy_kind_save[i], 0);
		}
	}

	if (time > Enemy_appear[Enemy_appear.size() - 1] && can_boss && hitmanager.data.zako.empty()) {
		Stage::EraseAllObject();
		Stage::BossSet();
	}
	if (StageNumber == 10 && hitmanager.effect.empty()) {
		for (i = 0; i < hitmanager.effect.size(); i++) {
			if (hitmanager.effect[i].kinds == 4 && hitmanager.effect[i].time == 230) {
				hitmanager.data.boss.push_back(Boss(hitmanager.effect[i].x, hitmanager.effect[i].y, 1200, 60, 5));
				hitmanager.healthgage.can_down = TRUE;
			}
		}
	}
}

void Stage::StageClear() {
	if (!(Enemy_appear.empty())) {
		Enemy_appear.erase(Enemy_appear.begin(), Enemy_appear.end());
		Enemy_x_save.erase(Enemy_x_save.begin(), Enemy_x_save.end());
		Enemy_kind_save.erase(Enemy_kind_save.begin(), Enemy_kind_save.end());
	}
	Stage::EraseAllObject();
	StageNumber++;
	Stage::StageLoad();
	time = 0;
	hitmanager.stage_clear = false;
	hitmanager.healthgage.RecentHealth = 130;
	can_boss = true;
}

void Stage::StageProgress() {
	if (hitmanager.healthgage.RecentHealth) {
		if (StageNumber == 1)hitmanager.heal = 25;
		else hitmanager.heal = 15;
		Stage::StageSet();
		if (local_time || hitmanager.stage_clear)hitmanager.healthgage.can_down = false;
		else hitmanager.healthgage.can_down = true;
		Stage::hitmanager.update();

		time++;
		stage_y = time % 1200;
	}
}

void Stage::update(){
	if (hitmanager.stage_clear && !hitmanager.effect.empty()) {
		if (hitmanager.effect[0].time)stm.SetNewMusic(6, 6, false);
		Stage::StageProgress();
	}
	else if (hitmanager.stage_clear && (StageNumber != 3 || StageNumber != 10) && hitmanager.effect.empty()) {
		Stage::StageClear();
	}
	else {
		Stage::StageProgress();
		if (StageNumber == 10 && !hitmanager.data.boss.empty()) {
			if (hitmanager.data.boss[0].hp <= 1200 && !hitmanager.data.boss[0].check_once)stm.SetNewMusic(3, -1, true);
		}
	}
}

void Stage::EnemyMapDraw(int StageNum) {
	switch (StageNum) {
	case 1:
		if (stage_y <= 600) {
			DrawGraph(0, stage_y - 600, img_stage_one[0], TRUE);
			DrawGraph(0, stage_y, img_stage_one[1], TRUE);
		}
		else {
			DrawGraph(0, stage_y - 600, img_stage_one[0], TRUE);
			DrawGraph(0, stage_y - 1200, img_stage_one[1], TRUE);
		}
		break;
	case 2:
		if (stage_y <= 600) {
			DrawGraph(0, stage_y - 600, img_stage_two[0], TRUE);
			DrawGraph(0, stage_y, img_stage_two[1], TRUE);
		}
		else {
			DrawGraph(0, stage_y - 600, img_stage_two[0], TRUE);
			DrawGraph(0, stage_y - 1200, img_stage_two[1], TRUE);
		}
		break;
	case 3:
		if (stage_y <= 600) {
			DrawGraph(0, stage_y - 600, img_stage_three_a[0], TRUE);
			DrawGraph(0, stage_y, img_stage_three_a[1], TRUE);
		}
		else {
			DrawGraph(0, stage_y - 600, img_stage_three_a[0], TRUE);
			DrawGraph(0, stage_y - 1200, img_stage_three_a[1], TRUE);
		}
		break;
	case 10:
		if (stage_y <= 600) {
			DrawGraph(0, stage_y - 600, img_stage_extra[0], TRUE);
			DrawGraph(0, stage_y, img_stage_extra[1], TRUE);
		}
		else {
			DrawGraph(0, stage_y - 600, img_stage_extra[0], TRUE);
			DrawGraph(0, stage_y - 1200, img_stage_extra[1], TRUE);
		}
		break;
	}
}

 void Stage::BossMapDraw(int StageNum) {
	if (StageNum == 1)DrawGraph(0, 0, img_stage_one_boss, TRUE);
	if (StageNum == 2)DrawGraph(0, 0, img_stage_two_boss, TRUE);
	if (StageNum == 3)DrawGraph(0, 0, img_stage_three_boss, TRUE);
	if (StageNum == 10)DrawGraph(0, 0, img_stage_extra_boss, TRUE);
}

 void Stage::WarningDraw() {
	 if((local_time - 30) % 60 < 10)DrawGraph(0, 100, img_warning[0], TRUE);
	 else if ((local_time - 30) % 60 < 20)DrawGraph(0, 100, img_warning[1], TRUE);
	 else if ((local_time - 30) % 60 < 30)DrawGraph(0, 100, img_warning[2], TRUE);
	 else if ((local_time - 30) % 60 < 40)DrawGraph(0, 100, img_warning[3], TRUE);
	 else if ((local_time - 30) % 60 < 50)DrawGraph(0, 100, img_warning[4], TRUE);
	 else DrawGraph(0, 100, img_warning[5], TRUE);
 }

void Stage::draw() {
	if (can_boss && local_time < 30) {
		Stage::EnemyMapDraw(StageNumber);
	}
	else if (local_time) {
		Stage::WarningDraw();
	}
	else if(!(local_time)) {
		Stage::BossMapDraw(StageNumber);
	}
	if (hitmanager.healthgage.RecentHealth && local_time < 30) Stage::hitmanager.draw();
	DrawGraph(0, 0, img_stage_outline, TRUE);
	Stage::hitmanager.healthgage.draw();
}