#include "SceneManager.h"	

void SceneManager::TitleProcess() {
	if (!(cooldown_input)) {
		switch (recentmenu)
		{
		case SceneManager::MAIN:
			if (scene_input.GetKey(KEY_INPUT_DOWN)) {
				recentmenu = EXTRA;
				cooldown_input = 7;
			}
			break;
		case SceneManager::EXTRA:
			if (scene_input.GetKey(KEY_INPUT_UP)) {
				recentmenu = MAIN;
				cooldown_input = 7;
			}
			else if (scene_input.GetKey(KEY_INPUT_DOWN)) {
				recentmenu = QUIT;
				cooldown_input = 7;
			}
			break;
		case SceneManager::QUIT:
			if (scene_input.GetKey(KEY_INPUT_UP)) {
				recentmenu = EXTRA;
				cooldown_input = 7;
			}
			if (scene_input.GetKey(KEY_INPUT_RETURN) || scene_input.GetKey(KEY_INPUT_Z))gamequit = true;
			break;
		}
		if (scene_input.GetKey(KEY_INPUT_RETURN) || scene_input.GetKey(KEY_INPUT_Z)) {
			decide = true;
			stage.hitmanager.data.se.PlaySE(0);
			cooldown_input = 20;
		}
	}
}
//void SceneManager::CGProcess() {}
void SceneManager::GameProcess() {
	if ((recentmenu == MAIN || recentmenu == EXTRA) && decide) {
		if (recentmenu == EXTRA && check_once) {
			stage.hitmanager.stage_clear = true;
			stage.StageNumber = 9;
			check_once = false;
			if (!(stage.hitmanager.data.boss.empty()))stage.hitmanager.data.boss[0].disappear = true;
		}
		else if (recentmenu == MAIN && check_once) {
			stage.StageNumber = 0;
			stage.hitmanager.stage_clear = true;
			check_once = false;
			//stage.hitmanager.healthgage.RecentHealth = 130;
			if (!(stage.hitmanager.data.boss.empty()))stage.hitmanager.data.boss[0].disappear = true;
		}
		if (stage.StageNumber == 1 && stage.time == 1 && !(cg.finish)) {
			stage.stm.SetNewMusic(1, 0, false);
			if (!(cooldown_input)) {
				cg.SinarioProcess(1, scene_input.GetKey(KEY_INPUT_RETURN) || scene_input.GetKey(KEY_INPUT_Z));
				cooldown_input = 15;
			}
			else cooldown_input--;
		}
		else if (stage.StageNumber == 3 && stage.local_time == 209 && !cg.finish) {
			stage.stm.SetNewMusic(1, 3, false);
			if (!(cooldown_input)) {
				cg.SinarioProcess(2, scene_input.GetKey(KEY_INPUT_RETURN) || scene_input.GetKey(KEY_INPUT_Z));
				cooldown_input = 15;
			}
			else cooldown_input--;
		}
		else if (stage.StageNumber == 3 && stage.hitmanager.stage_clear && stage.hitmanager.effect.empty() && !cg.finish) {
			stage.stm.SetNewMusic(1, 6, false);
			if (!(cooldown_input)) {
				cg.SinarioProcess(3, scene_input.GetKey(KEY_INPUT_RETURN) || scene_input.GetKey(KEY_INPUT_Z));
				cooldown_input = 15;
			}
			else cooldown_input--;
		}
		else if (stage.StageNumber == 3 && stage.hitmanager.stage_clear && cg.finish) {
			decide = false;
			check_once = true;
			check_pause = false;
			cooldown_input = 15;
			stage.EraseAllObject();
			stage.hitmanager.score = 0;
			stage.hitmanager.healthgage.RecentHealth = 130;
			stage.local_time = 0;
			ret = no;
		}
		else if (stage.StageNumber == 10 && stage.time == 1 && !(cg.finish)) {
			stage.stm.SetNewMusic(1, 6, false);
			if (!(cooldown_input)) {
				cg.SinarioProcess(4, scene_input.GetKey(KEY_INPUT_RETURN) || scene_input.GetKey(KEY_INPUT_Z));
				cooldown_input = 15;
			}
			else cooldown_input--;
		}
		else if (stage.StageNumber == 10 && stage.local_time == 209 && !cg.finish) {
			stage.stm.SetNewMusic(1, 3, false);
			if (!(cooldown_input)) {
				cg.SinarioProcess(5, scene_input.GetKey(KEY_INPUT_RETURN) || scene_input.GetKey(KEY_INPUT_Z));
				cooldown_input = 15;
			}
			else cooldown_input--;
		}
		else if (stage.StageNumber == 10 && stage.hitmanager.stage_clear && stage.hitmanager.effect.empty() && !cg.finish) {
			if (!(cooldown_input)) {
				if(cg.check_sinario < 7)stage.stm.SetNewMusic(1, 1, false);
				if (cg.check_sinario > 7)stage.stm.SetNewMusic(1, 2, false);
				cg.SinarioProcess(6, (scene_input.GetKey(KEY_INPUT_RETURN) || scene_input.GetKey(KEY_INPUT_Z)) && !CheckSoundMem(cg.cgse.final_broken));
				cooldown_input = 15;
			}
			else cooldown_input--;
		}
		else if (stage.StageNumber == 10 && stage.hitmanager.stage_clear && cg.finish) {
			decide = false;
			check_once = true;
			check_pause = false;
			cooldown_input = 15;
			stage.EraseAllObject();
			stage.hitmanager.score = 0;
			stage.hitmanager.healthgage.RecentHealth = 130;
			stage.local_time = 0;
			ret = no;
		}
		else {
			stage.update();
			cg.finish = false;
		}
	}
}
void SceneManager::PauseProcess() {
	switch (ret)
	{
	case SceneManager::yes:
		if (scene_input.GetKey(KEY_INPUT_DOWN))ret = no;
		if ((scene_input.GetKey(KEY_INPUT_Z) || scene_input.GetKey(KEY_INPUT_RETURN)) && !(cooldown_input)) {
			stage.hitmanager.data.se.PlaySE(0);
			decide = false;
			check_once = true;
			check_pause = false;
			cooldown_input = 15;
			stage.EraseAllObject();
			cg.check_sinario = 0;
			stage.hitmanager.score = 0;
			stage.hitmanager.healthgage.RecentHealth = 130;
			stage.local_time = 0;
			ret = no;
		}
		break;
	case SceneManager::no:
		if (scene_input.GetKey(KEY_INPUT_UP))ret = yes;
		if ((scene_input.GetKey(KEY_INPUT_Z) || scene_input.GetKey(KEY_INPUT_RETURN)) && !(cooldown_input)) {
			check_pause = false;
			cooldown_input = 5;
		}
		break;
	}
}
void SceneManager::update() {
	if (!(decide)) {
		stage.stm.SetNewMusic(0, -1, false);
		SceneManager::TitleProcess();
	}
	else {
		if (check_pause || !(stage.hitmanager.healthgage.RecentHealth))SceneManager::PauseProcess();
		else SceneManager::GameProcess();
		if (scene_input.GetKey(KEY_INPUT_ESCAPE) && !(check_pause)) {
			check_pause = true;
			cooldown_input = 7;
		}
	}
	scene_input.update();
	if (cooldown_input)cooldown_input--;
	time++;
}

void SceneManager::TitleDraw() {
	DrawGraph(0, 0, img_title, TRUE);
	switch (recentmenu)
	{
	case SceneManager::MAIN:
		DrawStringToHandle(450, 310, ">Game  Start", color_yellow, font40);
		DrawStringToHandle(470, 350, "Extra Start", color_white, font40);
		DrawStringToHandle(535, 390, "Quit", color_white, font40);
		break;
	case SceneManager::EXTRA:
		DrawStringToHandle(470, 310, "Game  Start", color_white, font40);
		DrawStringToHandle(450, 350, ">Extra Start", color_yellow, font40);
		DrawStringToHandle(535, 390, "Quit", color_white, font40);
		break;
	case SceneManager::QUIT:
		DrawStringToHandle(470, 310, "Game  Start", color_white, font40);
		DrawStringToHandle(470, 350, "Extra Start", color_white, font40);
		DrawStringToHandle(515, 390, ">Quit", color_yellow, font40);
		break;
	}
}
void SceneManager::StatusDraw() {
	stage.hitmanager.healthgage.draw();
	if (stage.StageNumber == 1) {
		DrawStringToHandle(650, 20, "Stage 1", color_white, font20);
		DrawStringToHandle(640, 45, "Shoku-do", color_white, font20);
	}
	else if (stage.StageNumber == 2) {
		DrawStringToHandle(650, 20, "Stage 2", color_white, font20);
		DrawStringToHandle(650, 45, "Sho-cho", color_white, font20);
	}
	else if (stage.StageNumber == 3) {
		DrawStringToHandle(650, 20, "Stage 3", color_white, font20);
		DrawStringToHandle(650, 45, "Kek-kan", color_white, font20);
	}
	else if (stage.StageNumber == 10) {
		DrawStringToHandle(650, 20, "Extra Stage", color_white, font20);
		DrawStringToHandle(675, 45, "Chu-su", color_white, font20);
	}
	DrawStringToHandle(660, 170, "SCORE", color_white, font20);
	DrawFormatStringToHandle(680, 210, color_white, font20, "%d", stage.hitmanager.score);
	DrawStringToHandle(610, 294, "Boss : ", color_white, font20);
	if (stage.can_boss) {
		for (i = 0; i < 100; i++)DrawGraph(604 + 2 * i, 327, img_health_boss[i], TRUE);
	}
	else if(!(stage.hitmanager.stage_clear)) {
		if (stage.StageNumber == 1) {
			DrawStringToHandle(680, 294, "Leraje", color_white, font20);
			for (i = 0; i < stage.hitmanager.data.boss[0].hp / 3; i++)DrawGraph(604 + 2 * i, 327, img_health_boss[i], TRUE);
		}
		if (stage.StageNumber == 2) {
			DrawStringToHandle(680, 294, "Buer", color_white, font20);
			for (i = 0; i < stage.hitmanager.data.boss[0].hp / 10; i++)DrawGraph(604 + 2 * i, 327, img_health_boss[i], TRUE);
		}
		if (stage.StageNumber == 3) {
			DrawStringToHandle(680, 294, "Lime", color_white, font20);
			for (i = 0; i < stage.hitmanager.data.boss[0].hp / 20; i++)DrawGraph(604 + 2 * i, 327, img_health_boss[i], TRUE);
		}
		if (stage.StageNumber == 10) {
			DrawStringToHandle(680, 296, "Parasite Lime", color_white, font17);
			if (stage.hitmanager.data.boss[0].number_boss == 4) {
				if (stage.hitmanager.data.boss[0].check_once)for (i = 0; i < (stage.hitmanager.data.boss[0].hp-1200) / 28; i++)DrawGraph(604 + 2 * i, 327, img_health_boss[i], TRUE);
				else for (i = 0; i < stage.hitmanager.data.boss[0].hp / 12; i++)DrawGraph(604 + 2 * i, 327, img_health_boss_final[i], TRUE);
			}
		}
	}
}
void SceneManager::GameDraw() {
	if (stage.StageNumber == 1 && stage.time == 1 && !(cg.finish)) {
		cg.SinarioDraw(1);
	}
	else if (stage.StageNumber == 3 && stage.local_time == 209 && !cg.finish) {
		DrawGraph(0, 0, stage.img_stage_outline, TRUE);
		StatusDraw();
		cg.SinarioDraw(2);
	}
	else if (stage.StageNumber == 3 && stage.hitmanager.stage_clear && stage.hitmanager.effect.empty() && !cg.finish) {
		DrawGraph(0, 0, stage.img_stage_outline, TRUE);
		StatusDraw();
		cg.SinarioDraw(3);
	}
	else if (stage.StageNumber == 10 && stage.time == 1 && !(cg.finish)) {
		cg.SinarioDraw(4);
	}
	else if (stage.StageNumber == 10 && stage.local_time == 209 && !cg.finish) {
		DrawGraph(0, 0, stage.img_stage_outline, TRUE);
		StatusDraw();
		cg.SinarioDraw(5);
	}
	else if (stage.StageNumber == 10 && stage.hitmanager.stage_clear && stage.hitmanager.effect.empty() && !cg.finish) {
		cg.SinarioDraw(6);
	}
	else {
		stage.draw();
		SceneManager::StatusDraw();
	}
}
void SceneManager::PauseDraw() {
	DrawStringToHandle(140, 250, "Return to Title?", color_white, font40);
	switch (ret)
	{
	case SceneManager::yes:
		DrawStringToHandle(250, 300, ">YES", color_yellow, font40);
		DrawStringToHandle(280, 350, "NO", color_white, font40);
		break;
	case SceneManager::no:
		DrawStringToHandle(270, 300, "YES", color_white, font40);
		DrawStringToHandle(260, 350, ">NO", color_yellow, font40);
		break;
	}
}
void SceneManager::GameoverDraw() {
	if (time % 60 < 10)DrawGraph(0, 80, img_gameover[0], TRUE);
	else if (time % 60 < 20)DrawGraph(0, 80, img_gameover[1], TRUE);
	else if (time % 60 < 30)DrawGraph(0, 80, img_gameover[2], TRUE);
	else if (time % 60 < 40)DrawGraph(0, 80, img_gameover[3], TRUE);
	else if (time % 60 < 50)DrawGraph(0, 80, img_gameover[4], TRUE);
	else DrawGraph(0, 80, img_gameover[5], TRUE);
}
void SceneManager::draw() {
	if ((recentmenu == MAIN || recentmenu == EXTRA) && decide) {
		SceneManager::GameDraw();
		if (check_pause || !(stage.hitmanager.healthgage.RecentHealth))SceneManager::PauseDraw();
		if (!(stage.hitmanager.healthgage.RecentHealth))SceneManager::GameoverDraw();
	}
	else {
		SceneManager::TitleDraw();
	}
}
void SceneManager::playMusic() {

}
