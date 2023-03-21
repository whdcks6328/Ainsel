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
	Database data;//データベースのクラス
	HealthGage healthgage;//体調ゲージのクラス
	std::deque<Effect> effect;//エフェクト実装のためのクラス配列
	int i, j; //for文を回すための変数。
	unsigned int score = 0;
	void ScanHitPlayerToEnemy();   //自機と敵が直接衝突した場合の当たり判定
	void ScanHitPlayerToBullet();  //自機と敵の弾の当たり判定
	void ScanHitPlayerToBoss();  //自機とボスが直接衝突した場合の当たり判定
	void ScanHitEnemyToBullet();  //敵と自機の弾の当たり判定
	void ScanHitBossToBullet();  //ボスと自機の弾の当たり判定
	void ScanHitPlayerToItem();  //自機とアイテムの当たり判定
	void ScanHitPlayerToItemArea();  //自機とアイテムの距離が近いとアイテムが誘導されるように動きを変更
	void CheckOverScreenObject();  //画面から消えたオブジェクトの消去
	void EraseObject();//当たり判定により削除されるオブジェクトの一括削除
	void update();//いつものまとめ。体調ゲージのupdateも追加
	void draw();//DatabaseのDrawとエフェクト処理
};