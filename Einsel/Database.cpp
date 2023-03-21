#include "Database.h"

double Database::GetRadian(double num) {
	return num * (3.14159265 / 180.0);
}
void Database::ZakoAdd(int x, int y, int hp, int range, int kinds, double angle) {
	zako.push_back(Zako(x, y, hp, range, kinds, angle));
}
void Database::BulletAdd(int x, int y, int hp, int range, int kinds, int pattern, double angle, bool who) {
	bullet.push_back(Bullet(x, y, hp, range, kinds, pattern, angle, who));
}
void Database::ItemAdd(int x, int y, int hp) {
	item.push_back(Item(x, y, hp));
}
void Database::BossAdd(int x, int hp, int range, int number_boss) {
	boss.push_back(Boss(x, 0, hp, range, number_boss));
}
void Database::PlayerShoot() {
	if (player.input.GetKey(KEY_INPUT_Z)) {
		if (!(player.shoot_cooldown) && !(player.paralyze_cooldown)) {
			Database::BulletAdd(player.x - 10, player.y - 25, 1, 15, 1, 10, 180.0, true);
			player.shoot_cooldown = cooldown_player_shoot;
			se.PlaySE(1);
		}
	}
}
void Database::ZakoShoot() {
	for (i = 0; i < zako.size(); i++) {
		switch (zako[i].kinds) {
		case 1: //アメーバの弾
			if (time % cooldown_ameba_shoot == 0) {
				for (int j = 0; j < 3; j++)Database::BulletAdd(zako[i].x, zako[i].y, 1, 13, 1, 1, -30.0 + 30.0 * j, false);
			}
				break;
		case 2://悪玉コレステロールの弾
			if (time % cooldown_cholesterol_shoot == 0) {
				for (int j = 0; j < 6; j++)Database::BulletAdd(zako[i].x, zako[i].y, 1, 13, 2, 1, -180.0 + 60.0 * j, false);
			}
				break;
		case 3://ポイズナス・バクテリアの弾
			if (time % cooldown_poisonous_shoot == 0) {
				Database::BulletAdd(zako[i].x, zako[i].y, 1, 16, 3, 2, rand() % 180 - 90 , false);
			}
				break;
		case 5://ビールスの弾
			if (time % cooldown_virus_shoot == 0) {
				Database::BulletAdd(zako[i].x, zako[i].y, 1, 10, 5, 1, 0, false);
			}
				break;
		case 6://ワームの弾
			if (time % cooldown_worm_shoot == 0) {
				Database::BulletAdd(zako[i].x, zako[i].y, 1, 23, 6, 1, atan2(player.x - zako[i].x,player.y - zako[i].y), false);
			}
				break;
		default:
			break;
		}
	}
}
void Database::BossShoot() {
	for (i = 0; i < boss.size(); i++) {
		switch (boss[i].number_boss)
		{
		case 1://Lerajeの弾
			if (boss[i].time % 420 == 350 || boss[i].time % 420 == 410) {
				Database::BulletAdd(boss[i].x - 40, boss[i].y + 80, 1, 12, 10, 1, -30.0, false);
				Database::BulletAdd(boss[i].x, boss[i].y + 80, 1, 12, 11, 1, 0, false);
				Database::BulletAdd(boss[i].x + 40, boss[i].y + 80, 1, 12, 12, 1, 30.0, false);
			}
			break;
		case 2://Buerの弾
			if (boss[i].hp > 350) {
				if (boss[i].time % 600 < 420)	ivy_count = 2;
				else ivy_count = 1;
				switch (ivy_count) {
				case 1:
					if (boss[i].time % 2 == 1) {
						Database::BulletAdd(boss[i].x, boss[i].y, 100, 15, 215 - ivy_draw, 3, 0, false);
						Database::BulletAdd(boss[i].x, boss[i].y, 100, 15, 315 - ivy_draw, 3, -M_PI / 6, false);
						Database::BulletAdd(boss[i].x, boss[i].y, 100, 15, 415 - ivy_draw, 3, M_PI / 6, false);
						Database::BulletAdd(boss[i].x, boss[i].y, 100, 15, 515 - ivy_draw, 3, -5*M_PI / 12, false);
						Database::BulletAdd(boss[i].x, boss[i].y, 100, 15, 615 - ivy_draw, 3, 5*M_PI / 12, false);
						ivy_draw += 1;
						for (int j = 0; j < bullet.size(); j++) {
							if (bullet[j].y > 600) {
								for (int j = 0; j < bullet.size(); j++) bullet[j].ivy_spd = 0;
								break;
							}
						}
					}
					break;
				case 2:
					if (boss[i].time % 2 == 1) {
						ivy_draw = 0;
						for (int j = 0; j < bullet.size(); j++) {
							bullet[j].ivy_spd = -15;
							if (bullet[j].who==FALSE && bullet[j].y < boss[i].y) bullet[j].disappear = TRUE;
						}
					}
					break;
				default:
					break;
				}
			}
			else {
				for (int j = 0; j < bullet.size(); j++) {
					bullet[j].ivy_spd = -15;
					if (bullet[j].who == FALSE && bullet[j].y < boss[i].y) bullet[j].disappear = TRUE;
				}
				if (boss[i].time % 300 == 250) {
					for (int j = 0; j < 5; j++)Database::ZakoAdd(boss[i].x, boss[i].y, 1, 25, 4, 0);
				}
			}
			break;
		case 3://Limeの弾
			if (boss[i].hp > 1600) {
				if (boss[i].time % 420 == 350) {//ランダムにするか？
					Database::ZakoAdd(boss[i].x, boss[i].y, 1, 30, 1, 0);
					Database::ZakoAdd(boss[i].x, boss[i].y, 1, 35, 2, 0);
					Database::ZakoAdd(boss[i].x, boss[i].y, 1, 50, 6, 0);
				}
			}
			else if (boss[i].hp > 800 && boss[i].hp <= 1600) {
				if (boss[i].time % 48 == 0) {
					Database::BulletAdd(boss[i].x, boss[i].y, 100, 25, 13, 1, atan2(player.x - boss[i].x, player.y - boss[i].y), false);
				}
			}
			else {
				if (boss[i].check_phase) {
					if (boss[i].time % 360 == 240) {
						Database::BulletAdd(boss[i].x, boss[i].y, 100, 0, 14, 4, 0, false);
					}
					if (boss[i].time % 720 > 600) {
						for (int j = 0; j < 7; j++)Database::BulletAdd(boss[i].x, boss[i].y, 1, 25, 0, 5, -180.0 + 60.0 * j, false);
						for (int k = 0; k < bullet.size(); k++) {
							if (bullet[k].y > 550) {
								for (int k = 0; k < bullet.size(); k++) bullet[k].spd = 0;
							}
						}
					}
				}
				else {
					if (boss[i].time % 360 == 240) {
						for (int j = 0; j < bullet.size(); j++)  bullet[j].disappear = TRUE;
					}
				}
			}
			break;
		case 4://ParasiteLimeの弾
			if (boss[i].hp > 3400) {
				for(int j=0;j<5;j++)if (boss[i].time % 360 == 50+60*j) {
					Database::BulletAdd(boss[i].x -	40, boss[i].y + 80, 1, 25, 100 , 1, -20.0 , false);
					Database::BulletAdd(boss[i].x, boss[i].y + 80, 1, 25, 101, 1, 0, false);
					Database::BulletAdd(boss[i].x +	40, boss[i].y + 80, 1, 25, 102, 1, 20.0, false);
					Database::BulletAdd(boss[i].x - 80, boss[i].y + 80, 1, 25, 103, 1, -40.0, false);
					Database::BulletAdd(boss[i].x + 80, boss[i].y + 80, 1, 25, 104, 1, 40.0, false);
				}
			}
			else if (boss[i].hp > 2800) {
				if (boss[i].time % 250 < 170)	ivy_count = 2;
				else ivy_count = 1;
				switch (ivy_count) {
				case 1:
					if (boss[i].time % 2 == 1) {
						Database::BulletAdd(boss[i].x, boss[i].y, 100, 20, 1011 - ivy_draw, 3, 0, false);
						Database::BulletAdd(boss[i].x, boss[i].y, 100, 20, 1111 - ivy_draw, 3, -M_PI / 6, false);
						Database::BulletAdd(boss[i].x, boss[i].y, 100, 20, 1211 - ivy_draw, 3, M_PI / 6, false);
						Database::BulletAdd(boss[i].x, boss[i].y, 100, 20, 1311 - ivy_draw, 3, -M_PI / 3, false);
						Database::BulletAdd(boss[i].x, boss[i].y, 100, 20, 1411 - ivy_draw, 3, M_PI / 3, false);
						ivy_draw += 1;
						for (int j = 0; j < bullet.size(); j++) {
							if (bullet[j].y > 560) {
								for (int j = 0; j < bullet.size(); j++) bullet[j].ivy_spd = 0;
								break;
							}
						}
					}
					break;
				case 2:
					if (boss[i].time % 2 == 1) {
						ivy_draw = 0;
						for (int j = 0; j < bullet.size(); j++) {
							bullet[j].ivy_spd = -15;
							if (bullet[j].y < boss[i].y) bullet[j].disappear = TRUE;
						}
					}
					break;
				default:
					break;
				}
			}
			else if (boss[i].hp > 2200) {
				for (int j = 0; j < bullet.size(); j++) {
					bullet[j].ivy_spd = -15;
					if (bullet[j].who == FALSE && bullet[j].y < boss[i].y) bullet[j].disappear = TRUE;
				}
				if (boss[i].time % 420 == 350) {
					Database::ZakoAdd(boss[i].x+50, boss[i].y+50, 1, 30, 1, 0);
					Database::ZakoAdd(boss[i].x+50, boss[i].y-50, 1, 35, 2, 0);
					Database::ZakoAdd(boss[i].x-50, boss[i].y, 1, 40, 3, 0);
					Database::ZakoAdd(boss[i].x-50, boss[i].y+50, 1, 25, 4, 0);
					Database::ZakoAdd(boss[i].x-50, boss[i].y-50, 1, 45, 5, 0);
					Database::ZakoAdd(boss[i].x+50, boss[i].y, 1, 50, 6, 0);
				}
			}
			else if (boss[i].hp > 1200) {
				for (int j = 0; j < 5; j++)if (boss[i].time % 360 == 50 + 60 * j) {
					for (int j = 0; j < 3; j++)Database::BulletAdd(boss[i].x, boss[i].y + 80, 1, 50, 105, 1, -45.0+45.0*j, false);
				}
			}
			else {
				for (int j = 0; j < 3; j++)if (boss[i].time % 360 == 50 + 100 * j) {
					for (int k = 0; k < 3; k++)Database::BulletAdd(boss[i].x, boss[i].y + 80, 1, 50, 105, 1, -45.0 + 45.0*k, false);
					Database::BulletAdd(boss[i].x, boss[i].y, 100, 25, 13, 1, atan2(player.x - boss[i].x, player.y - boss[i].y), false);
				}
			}
			break;
		default:
			break;
		}
	}
}

void Database::update() {
	player.update();
	for (int i = 0; i < zako.size(); i++)zako[i].update();
	for (int i = 0; i < bullet.size(); i++)bullet[i].update();
	for (int i = 0; i < item.size(); i++)item[i].update();
	for (int i = 0; i < boss.size(); i++)boss[i].update();
	PlayerShoot();
	ZakoShoot();
	BossShoot();
	time++;
}
void Database::draw() {
	for (int i = 0; i < bullet.size(); i++)bullet[i].draw();
	player.draw();
	for (int i = 0; i < zako.size(); i++)zako[i].draw();
	for (int i = 0; i < item.size(); i++)item[i].draw();
	for (int i = 0; i < boss.size(); i++)boss[i].draw();
}