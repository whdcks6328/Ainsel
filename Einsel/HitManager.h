#pragma once
#include <deque>
#include<algorithm>
#include "Database.h"
#include "Effect.h"
#include "HealthGage.h"

class HitManager {
public:
	bool stage_clear = true;
	int heal = 15;
	Database data;//�f�[�^�x�[�X�̃N���X
	HealthGage healthgage;//�̒��Q�[�W�̃N���X
	std::deque<Effect> effect;//�G�t�F�N�g�����̂��߂̃N���X�z��
	int i, j; //for�����񂷂��߂̕ϐ��B
	unsigned int score = 0;
	void ScanHitPlayerToEnemy();   //���@�ƓG�����ڏՓ˂����ꍇ�̓����蔻��
	void ScanHitPlayerToBullet();  //���@�ƓG�̒e�̓����蔻��
	void ScanHitPlayerToBoss();  //���@�ƃ{�X�����ڏՓ˂����ꍇ�̓����蔻��
	void ScanHitEnemyToBullet();  //�G�Ǝ��@�̒e�̓����蔻��
	void ScanHitBossToBullet();  //�{�X�Ǝ��@�̒e�̓����蔻��
	void ScanHitPlayerToItem();  //���@�ƃA�C�e���̓����蔻��
	void ScanHitPlayerToItemArea();  //���@�ƃA�C�e���̋������߂��ƃA�C�e�����U�������悤�ɓ�����ύX
	void CheckOverScreenObject();  //��ʂ���������I�u�W�F�N�g�̏���
	void EraseObject();//�����蔻��ɂ��폜�����I�u�W�F�N�g�̈ꊇ�폜
	void update();//�����̂܂Ƃ߁B�̒��Q�[�W��update���ǉ�
	void draw();//Database��Draw�ƃG�t�F�N�g����
};