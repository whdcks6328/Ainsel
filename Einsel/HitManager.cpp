#include "HitManager.h"


	void HitManager::ScanHitPlayerToEnemy() {
		for (i = 0; i < data.zako.size(); i++) {
			if (object::CheckHit(&(data.player), &(data.zako[i])) && !(data.player.paralyze_cooldown)) {
				data.zako[i].hp -= data.player.physicaldamage;
				data.player.paralyze_cooldown = 80;
				if (data.zako[i].hp <= 0 && !data.zako[i].disappear) {
					data.ItemAdd(data.zako[i].x, data.zako[i].y, heal);
					data.se.PlaySE(3);
					effect.push_back(Effect(data.zako[i].x, data.zako[i].y, 1));
					data.zako[i].disappear = true;
					score += 100;
				}
			}
		}
	}

	void HitManager::ScanHitPlayerToBullet() {
		for (i = 0; i < data.bullet.size(); i++) {
			if (object::CheckHit(&(data.player), &(data.bullet[i])) && !(data.bullet[i].who) && !(data.player.paralyze_cooldown)) {
				data.player.paralyze_cooldown = 80;
				data.bullet[i].hp -= 1;
				if (data.bullet[i].hp == 0)data.bullet[i].disappear = true;
			}
		}
	}
	
	void HitManager::ScanHitPlayerToBoss() {
		for (i = 0; i < data.boss.size(); i++) {
			if (object::CheckHit(&(data.player), &(data.boss[0])) && !(data.player.paralyze_cooldown)) {
				//data.boss[0].hp -= data.player.physicaldamage;
				data.player.paralyze_cooldown = 80;
			}
		}
	}

	void HitManager::ScanHitEnemyToBullet() {
		for (i = 0; i < data.zako.size(); i++) {
			for (j = 0; j < data.bullet.size(); j++) {
				if (object::CheckHit(&(data.zako[i]), &(data.bullet[j])) && data.bullet[j].who) {
					data.zako[i].hp -= data.player.bulletdamage;
					data.bullet[j].disappear = true;
				}
				if (data.zako[i].hp <= 0 && !data.zako[i].disappear) {
					data.se.PlaySE(3);
					data.ItemAdd(data.zako[i].x, data.zako[i].y, heal);
					effect.push_back(Effect(data.zako[i].x, data.zako[i].y, 1));
					data.zako[i].disappear = true;
					score += 100;
				}
			}
		}
	}
	
	void HitManager::ScanHitBossToBullet() {
		for (i = 0; i < data.boss.size(); i++) {
			for (j = 0; j < data.bullet.size(); j++) {
				if (object::CheckHit(&(data.boss[i]), &(data.bullet[j])) && data.bullet[j].who && healthgage.can_down) {
					data.bullet[j].disappear = true;
					if(!data.boss[i].localtime){
						data.boss[i].hp -= data.player.bulletdamage;
						data.boss[i].check_hit++;
					}
					if (data.boss[i].check_hit >= 20) {
						if (data.boss[i].number_boss == 4 && data.boss[i].check_once) data.se.PlaySE(7);
						else if (data.boss[i].number_boss == 3 || (data.boss[i].number_boss == 4 && !data.boss[i].check_once))data.se.PlaySE(6);
						else data.se.PlaySE(5);
						data.boss[i].check_hit = 0;
						score += 50;
						data.ItemAdd(data.boss[i].x, data.boss[i].y, 40);
					}
					if (data.boss[i].number_boss == 4 && data.boss[i].hp < 1200 && data.boss[i].check_once) {
						data.boss[i].check_once = FALSE;
						data.boss[i].localtime = 240;
					}
					if (data.boss[i].hp <= 0) {
						data.boss[i].disappear = true;
						healthgage.can_down = false;
						score += 1000 * data.boss[i].number_boss;
						if(data.boss[i].number_boss < 3)effect.push_back(Effect(data.boss[i].x, data.boss[i].y, 2));
						else effect.push_back(Effect(data.boss[i].x, data.boss[i].y, 3));
						stage_clear = true;
					}
				}
			}
		}
	}

	void HitManager::ScanHitPlayerToItem() {
		for (i = 0; i < data.item.size(); i++) {
			if (object::CheckHit(&(data.player), &(data.item[i])) == true) {
				data.se.PlaySE(2);
				score += 100;
				healthgage.CalculateHealth(data.item[i].hp);
				data.item[i].disappear = true;
			}
		}
	}

	void HitManager::ScanHitPlayerToItemArea() {
		for (i = 0; i < data.item.size(); i++) {
			if (object::CheckLength(&(data.player), &(data.item[i])) < 80) {
				data.item[i].spd = 4;
				data.item[i].angle = atan2((data.player.x - data.item[i].x), (data.player.y - data.item[i].y));
			}
		}
	}
	void HitManager::CheckOverScreenObject() {
		for (i = 0; i < data.zako.size(); i++) {
			if (data.zako[i].y > 600 + data.zako[i].range)data.zako[i].disappear = true;
		}
		for (i = 0; i < data.bullet.size(); i++) {
			if (data.bullet[i].y > 600 + data.bullet[i].range || data.bullet[i].y + data.bullet[i].range < 0)data.bullet[i].disappear = true;
			if (data.bullet[i].x < 50 + data.bullet[i].range || data.bullet[i].x + data.bullet[i].range > 550)data.bullet[i].disappear = true;
		}
		for (i = 0; i < data.item.size(); i++) { 
			if (data.item[i].y > 600 + data.item[i].range)data.item[i].disappear = true;
		}
	}
	void HitManager::EraseObject() {
		data.zako.erase(remove_if(data.zako.begin(), data.zako.end(), [](Zako za) {
			return za.disappear;
		}), data.zako.end());
		data.bullet.erase(remove_if(data.bullet.begin(), data.bullet.end(), [](Bullet bu) {
			return bu.disappear;
		}), data.bullet.end());
		data.item.erase(remove_if(data.item.begin(), data.item.end(), [](Item it) {
			return it.disappear;
		}), data.item.end());
		data.boss.erase(remove_if(data.boss.begin(), data.boss.end(), [](Boss bo) {
			return bo.disappear;
		}), data.boss.end());
		effect.erase(remove_if(effect.begin(), effect.end(), [](Effect ef) {
			return ef.disappear;
		}), effect.end());
	}
	void HitManager::update() {
		data.update();
		HitManager::ScanHitPlayerToEnemy();
		HitManager::ScanHitPlayerToBullet();
		HitManager::ScanHitPlayerToBoss();
		HitManager::ScanHitEnemyToBullet();
		HitManager::ScanHitBossToBullet();
		HitManager::ScanHitPlayerToItem();
		HitManager::ScanHitPlayerToItemArea();
		HitManager::CheckOverScreenObject();
		HitManager::EraseObject();
		healthgage.update();
	}
	void HitManager::draw() {
		data.draw();
		for (i = 0; i < effect.size(); i++)effect[i].draw();
	}
