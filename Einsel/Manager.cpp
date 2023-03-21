#include "Manager.h"
#include <deque>
#include <memory>
#include "object.h"
#include "Database.h"

class Manager {
	object* obj;
	static std::shared_ptr<Database> data;

public:
	void ScanHitPlayerToEnemy() {
		for (int i = 0; i < data->zako.size(); i++) {
			if (obj->CheckHit(data->player, data->zako[i])) {

				data->zako[i].hp -= data->player.physicaldamage;

				if (data->zako[i].hp <= 0) {
					data->zako[i].DropItem();
					data->ZakoErase(i);
				}

			}
		}
	}

	void ScanHitPlayerToBullet() {
		for (int i = 0; i < data->bullet.size(); i++) {
			if (obj->CheckHit(data->player, data->bullet[i]) && data->bullet[i].who == false) {
				data->BulletErase(i);
				//player paralysised
			}
		}
	}

	void ScanHitPlayerToBoss() {
		if (obj->CheckHit(data->player, data->boss)) {
			data->boss.hp -= data->player.physicaldamage;
			//player paralysised
		}
	}

	void ScanHitEnemyToBullet() {
		for (int i = 0; i < data->zako.size(); i++) {
			for (int j = 0; j < data->bullet.size(); j++) {
				if (obj->CheckHit(data->zako[i], data->bullet[j]) && data->bullet[j].who == 1) {
					data->BulletErase(i);
					data->zako[i].hp -= data->player.bulletdamage;

					if (data->zako[i].hp <= 0) {
						data->zako[i].DropItem();
						data->ZakoErase(i);
					}
				}
			}
		}
	}

	void ScanHitBossToBullet() {
		for (int i = 0; i < data->bullet.size(); i++) {
			if (obj->CheckHit(data->boss, data->bullet[i]) && data->bullet[i].who == 1) {
				data->BulletErase(i);
				data->boss.hp -= data->player.bulletdamage;

				if (data->boss.hp <= 0) {
					data->BossDead();
				}
			}
		}
	}

	void ScanHitPlayerToItem() {
		for (int i = 0; i < data->item.size(); i++) {
			if (obj->CheckHit(data->player, data->item[i])) {
				data->player.canbomb += 1;
				//Healthgage plused
				data->ItemErase(i);
			}
		}

	}

	void update() {
		ScanHitPlayerToEnemy();
		ScanHitPlayerToBullet();
		ScanHitPlayerToBoss();
		ScanHitEnemyToBullet();
		ScanHitBossToBullet();
		ScanHitPlayerToItem();
	}


};
