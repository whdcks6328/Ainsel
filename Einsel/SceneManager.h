#pragma once
#include "CG.h"
#include "Stage.h"
#include "Music.h"

class SceneManager {
private:
	static enum scene {MAIN, EXTRA, QUIT};
	static enum retire {yes, no};
	bool decide = false,
		check_once = true,
		check_pause = false;
	unsigned int time = 0,
		color_white = GetColor(255, 255, 255),
		color_yellow = GetColor(255, 255, 0);
	int i, cooldown_input = 0,
		font20 = CreateFontToHandle(NULL, 20, 3, -1),
		font17 = CreateFontToHandle(NULL, 17, 3, -1),
		font40 = CreateFontToHandle(NULL, 40, 4, -1);
public:
	bool gamequit = false;
	retire ret = no;
	scene recentmenu = MAIN;
	Input scene_input;
	Stage stage;
	CG cg;
	static int  img_gameover[6],
				img_health_boss[100],//LoadDivGraph("graphics\\img_health_boss.png", 100, 100, 1, 2, 36,0 SceneManager::img_health_boss);
				img_health_boss_final[100],//LoadDivGraph("graphics\\img_health_boss_final.png", 100, 100, 1, 2, 36, img_health_boss_final);
				img_title; // = LoadGraph("graphics\\img_title.png");
	void TitleProcess();
	void CGProcess();
	void GameProcess();
	void PauseProcess();
	void update();
	void TitleDraw();
	void StatusDraw();
	void GameDraw();
	void PauseDraw();
	void GameoverDraw();
	void draw();
	void playMusic();
};
