#include "SceneManager.h"
#include "DxLib.h"
int Player::img_player[7];
int Player::img_effect_playerhitted[8];
int Zako::img_ameba[5];
int Zako::img_cholesterol[8];
int Zako::img_poisonous[4];
int Zako::img_sugikahun[4];
int Zako::img_virus[4];
int Zako::img_worm[6];
int Bullet::img_bullet_ameba;
int Bullet::img_bullet_cholesterol;
int Bullet::img_bullet_player;
int Bullet::img_bullet_poisonous[4];
int Bullet::img_bullet_virus;
int Bullet::img_bullet_worm;
int Bullet::img_bullet_arrow;
int Bullet::img_bullet_ivy[16];
int Bullet::img_bullet_magic;
int Bullet::img_bullet_shadow[6];
int Bullet::img_bullet_arrow_ex;
int Bullet::img_bullet_ivy_ex[12];
int Bullet::img_bullet_meat[3];
int Item::img_item[4];
int Boss::img_boss_leraje[10];
int Boss::img_boss_buer[24];
int Boss::img_boss_lime[40];
int Boss::img_boss_parasitelime_stay[6];
int Boss::img_boss_parasitelime_ivy[6];
int Boss::img_boss_parasitelime_change[24];
int Boss::img_boss_parasitelime_ex2[5];
int Effect::img_effect_small[7];
int Effect::img_effect_middle[8];
int Effect::img_effect_big[16];
int Effect::img_effect_clear[6];
int HealthGage::img_HealthGage[130];
int Stage::img_stage_one[2];
int Stage::img_stage_two[2];
int Stage::img_stage_three_a[2];
int Stage::img_stage_extra[2];
int Stage::img_stage_one_boss;
int Stage::img_stage_two_boss;
int Stage::img_stage_three_boss;
int Stage::img_stage_extra_boss;
int Stage::img_stage_outline;
int Stage::img_warning[6];
int SceneManager::img_gameover[6];
int SceneManager::img_health_boss[100];
int SceneManager::img_health_boss_final[100];
int SceneManager::img_title;
int CG::CG_one;
int CG::CG_two;
int CG::CG_three;
int CG::CG_four;
int CG::CG_talkbox;
int CG::SCG_ainsel;
int CG::SCG_lime;

int SE::boss_clear;
int SE::boss_damaged;
int SE::decide;
int SE::enemy_broken;
int SE::final_broken;
int SE::heal;
int SE::lime_damaged;
int SE::palime_broken;
int SE::palime_damaged;
int SE::shoot;
int SE::warning;

int Music::sound_title;
int Music::sound_story_start;
int Music::sound_stage_one;
int Music::sound_stage_boss;
int Music::sound_stage_two;
int Music::sound_stage_three;
int Music::sound_stage_three_boss;
int Music::sound_game_over;
int Music::sound_stage_extra;
int Music::sound_stage_extra_boss_one;
int Music::sound_stage_extra_boss_two;
int Music::sound_story_ED;
int Music::sound_story_End;
int Music::sound_story_lime;

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpc, int nC) {
	SetUseDXArchiveFlag(true);
	SetDXArchiveExtension("dxa");
	int wid = 800, hei = 600;
	
	ChangeWindowMode(true);
	SetGraphMode(wid, hei, 16);
	
	if (DxLib_Init())return -1;
	
	SetDrawScreen(DX_SCREEN_BACK);

	//call class Stage
	SceneManager scenemanager;

	SetFontSize(20);
	
	scenemanager.cg.SinarioRead();

	//Define Image
	LoadDivGraph("graphics\\img_player.png", 7, 7, 1, 75, 75, Player::img_player);
	LoadDivGraph("graphics\\img_effect_playerhitted.png", 8, 8, 1, 100, 100, Player::img_effect_playerhitted);
	LoadDivGraph("graphics\\img_ameba.png", 5, 5, 1, 60, 60, Zako::img_ameba);
	LoadDivGraph("graphics\\img_cholesterol.png", 8, 8, 1, 70, 70, Zako::img_cholesterol);
	LoadDivGraph("graphics\\img_poisonous.png", 4, 4, 1, 45, 80, Zako::img_poisonous);
	LoadDivGraph("graphics\\img_sugikahun.png", 4, 4, 1, 50, 50, Zako::img_sugikahun);
	LoadDivGraph("graphics\\img_virus.png", 4, 4, 1, 90, 90, Zako::img_virus);
	LoadDivGraph("graphics\\img_worm.png", 6, 6, 1, 65, 100, Zako::img_worm);
	Bullet::img_bullet_ameba = LoadGraph("graphics\\img_bullet_ameba.png");
	Bullet::img_bullet_cholesterol = LoadGraph("graphics\\img_bullet_cholesterol.png");
	Bullet::img_bullet_player = LoadGraph("graphics\\img_bullet_player.png");
	LoadDivGraph("graphics\\img_bullet_poisonous.png", 4, 4, 1, 35, 35, Bullet::img_bullet_poisonous);
	Bullet::img_bullet_virus = LoadGraph("graphics\\img_bullet_virus.png");
	Bullet::img_bullet_worm = LoadGraph("graphics\\img_bullet_worm.png");
	Bullet::img_bullet_arrow = LoadGraph("graphics\\img_bullet_arrow.png");
	LoadDivGraph("graphics\\img_bullet_ivy.png", 16, 1, 16, 30, 30, Bullet::img_bullet_ivy);
	Bullet::img_bullet_magic = LoadGraph("graphics\\img_bullet_magic.png");
	LoadDivGraph("graphics\\img_bullet_shadow.png", 6, 6, 1, 500, 500, Bullet::img_bullet_shadow);
	Bullet::img_bullet_arrow_ex = LoadGraph("graphics\\img_bullet_arrow_ex.png");
	LoadDivGraph("graphics\\img_bullet_ivy_ex.png", 12, 1, 12, 40, 40, Bullet::img_bullet_ivy_ex);
	LoadDivGraph("graphics\\img_bullet_meat.png", 3, 3, 1, 100, 100,Bullet::img_bullet_meat);
	LoadDivGraph("graphics\\img_item.png", 4, 4, 1, 45, 45, Item::img_item);
	LoadDivGraph("graphics\\img_effect_small.png", 7, 7, 1, 100, 100, Effect::img_effect_small);
	LoadDivGraph("graphics\\img_effect_middle.png", 8, 8, 1, 300, 300, Effect::img_effect_middle);
	LoadDivGraph("graphics\\img_effect_big.png", 16, 8, 2, 400, 400, Effect::img_effect_big);
	LoadDivGraph("graphics\\img_clear.png", 6, 6, 1, 600, 140, Effect::img_effect_clear);
	LoadDivGraph("graphics\\img_health.png", 130, 1, 130, 200, 1, HealthGage::img_HealthGage);
	LoadDivGraph("graphics\\img_boss_leraje.png", 10, 5, 2, 96, 192, Boss::img_boss_leraje);
	LoadDivGraph("graphics\\img_boss_buer.png", 24, 8, 3, 150, 150, Boss::img_boss_buer);
	LoadDivGraph("graphics\\img_boss_lime.png", 40, 8, 5, 150, 120, Boss::img_boss_lime);
	LoadDivGraph("graphics\\img_boss_parasitelime_stay.png", 6, 6, 1, 300, 300, Boss::img_boss_parasitelime_stay);
	LoadDivGraph("graphics\\img_boss_parasitelime_ivy.png", 6, 6, 1, 300, 300, Boss::img_boss_parasitelime_ivy);
	LoadDivGraph("graphics\\img_boss_parasitelime_change.png", 24, 8, 3, 300, 300, Boss::img_boss_parasitelime_change);
	LoadDivGraph("graphics\\img_boss_parasitelime_ex2.png", 5, 5, 1, 80, 120, Boss::img_boss_parasitelime_ex2);
	LoadDivGraph("graphics\\img_stage_one.png", 2, 1, 2, 600, 600, Stage::img_stage_one);
	LoadDivGraph("graphics\\img_stage_two.png", 2, 1, 2, 600, 600, Stage::img_stage_two);
	LoadDivGraph("graphics\\img_stage_three_a.png", 2, 1, 2, 600, 600, Stage::img_stage_three_a);
	LoadDivGraph("graphics\\img_stage_extra.png", 2, 1, 2, 600, 600, Stage::img_stage_extra);
	Stage::img_stage_one_boss = LoadGraph("graphics\\img_stage_one_boss.png");
	Stage::img_stage_two_boss = LoadGraph("graphics\\img_stage_two_boss.png");
	Stage::img_stage_three_boss = LoadGraph("graphics\\img_stage_three_boss.png");
	Stage::img_stage_extra_boss = LoadGraph("graphics\\img_stage_extra_boss.png");
	Stage::img_stage_outline = LoadGraph("graphics\\img_stage_outline.png");
	LoadDivGraph("graphics\\img_warning.png", 6, 6, 1, 600, 160, Stage::img_warning);
	LoadDivGraph("graphics\\img_gameover.png", 6, 6, 1, 600, 160, SceneManager::img_gameover);
	LoadDivGraph("graphics\\img_health_boss.png", 100, 100, 1, 2, 36, SceneManager::img_health_boss);
	LoadDivGraph("graphics\\img_health_boss_final.png", 100, 100, 1, 2, 36, SceneManager::img_health_boss_final);
	SceneManager::img_title = LoadGraph("graphics\\img_title.png");
	CG::CG_one = LoadGraph("Graphics\\img_CG_one.png");
	CG::CG_two = LoadGraph("Graphics\\img_CG_two.png");
	CG::CG_three = LoadGraph("Graphics\\img_CG_three.png");
	CG::CG_four = LoadGraph("Graphics\\img_CG_four.png");
	CG::SCG_ainsel = LoadGraph("Graphics\\img_SCG_ainsel.png");
	CG::SCG_lime = LoadGraph("Graphics\\img_SCG_lime.png");
	CG::CG_talkbox = LoadGraph("Graphics\\img_box.png");

	SE::boss_clear = LoadSoundMem("Music\\boss_clear.wav");
	SE::boss_damaged = LoadSoundMem("Music\\boss_damaged.wav");
	SE::decide = LoadSoundMem("Music\\decide.wav");
	SE::enemy_broken = LoadSoundMem("Music\\enemy_broken.wav");
	SE::final_broken = LoadSoundMem("Music\\final_broken.wav");
	SE::heal = LoadSoundMem("Music\\heal.wav");
	SE::lime_damaged = LoadSoundMem("Music\\lime_damaged.wav");
	SE::palime_broken = LoadSoundMem("Music\\palime_broken.wav");
	SE::palime_damaged = LoadSoundMem("Music\\palime_damaged.wav");
	SE::shoot = LoadSoundMem("Music\\shoot.wav");
	SE::warning = LoadSoundMem("Music\\boss_comming.wav");
	Music::sound_title = LoadSoundMem("Music\\Ainsel.ogg");
	Music::sound_story_start = LoadSoundMem("Music\\Begining_of_Adventure.ogg");
	Music::sound_stage_one = LoadSoundMem("Music\\Stage_1.ogg");
	Music::sound_stage_boss = LoadSoundMem("Music\\Boss_1_2.ogg");
	Music::sound_stage_two = LoadSoundMem("Music\\Stage_2.ogg");
	Music::sound_stage_three = LoadSoundMem("Music\\Stage_3.ogg");
	Music::sound_stage_three_boss = LoadSoundMem("Music\\Boss_3.ogg");
	Music::sound_game_over = LoadSoundMem("Music\\GameOver.ogg");
	Music::sound_stage_extra = LoadSoundMem("Music\\Go_Through_Deeper_Pool.ogg");
	Music::sound_stage_extra_boss_one = LoadSoundMem("Music\\Ex_Boss_1.ogg");
	Music::sound_stage_extra_boss_two = LoadSoundMem("Music\\Ex_Boss_2.ogg");
	Music::sound_story_ED = LoadSoundMem("Music\\The_End_of_Lime.ogg");
	Music::sound_story_End = LoadSoundMem("Music\\Yourselves.ogg");
	Music::sound_story_lime = LoadSoundMem("Music\\Lime_on_Stage.ogg");

	//PlaySoundMem(scenemanager.stage.stm.sound_title, DX_PLAYTYPE_LOOP);
	while (!(ProcessMessage() || scenemanager.gamequit)) {
		//Update function
		scenemanager.update();
		//Draw function
		ClearDrawScreen();
		scenemanager.draw();
		ScreenFlip();
	}

	DxLib_End();
	return 0;
}