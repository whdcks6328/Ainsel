#pragma once
#ifndef DEF_MANAGER_H
#define DEF_MANAGER_H
#include <deque>
#include<memory>
#include "object.h"
#include "Database.h"

class Manager {
	object* obj;
    static std::shared_ptr<Database> data;

public:
	void ScanHitPlayerToEnemy();
	void ScanHitPlayerToBullet();
	void ScanHitPlayerToBoss();
	void ScanHitEnemyToBullet();
	void ScanHitBossToBullet();
	void ScanHitPlayerToItem();
	void update();
};

#endif // !DEF_MANAGER_H
