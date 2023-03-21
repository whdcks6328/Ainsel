#include "Bullet.h"

void Bullet::MovePattern_One() {
	if (angle > 3.1416 || angle < -3.1416)angle *= (3.14159265 / 180.0);
	y += (int)(4 * cos(angle));
	x += (int)(4 * sin(angle));
}

void Bullet::MovePattern_Two() {
	if (time % 120 < 30) {
		y += (int)(5 * cos(angle*(3.14159265 / 180.0)));
		x += (int)(5 * sin(angle*(3.14159265 / 180.0)));
	}
	if (time % 120 == 119) disappear = true;
}

void Bullet::MovePattern_Thr() {
	 y += ivy_spd*cos(angle);
	 x += ivy_spd*sin(angle);
}

void Bullet::MovePattern_Fou() {
	if(time%360==359)disappear = TRUE;
}

void Bullet::MovePattern_Fiv() {
	if (angle >3.146 || angle < -3.146)angle *= (3.14159265 / 180.0);
	y += (int)(spd * cos(angle));
	x += (int)(spd * sin(angle));
}

void Bullet::MovePattern_Ten() {
	if (angle > 3.1416 || angle < -3.1416)angle *= (3.14159265 / 180.0);
	y += (int)(8 *cos(angle));
	x += (int)(8 *sin(angle));
}


void Bullet::Move(int pattern) {
	switch (pattern) {
	case 1:
		Bullet::MovePattern_One();
		break;
	case 2:
		Bullet::MovePattern_Two();
		break;
	case 3:
		Bullet::MovePattern_Thr();
		break;
	case 4:
		Bullet::MovePattern_Fou();
		break;
	case 5:
		Bullet::MovePattern_Fiv();
		break;
	case 10:
		Bullet::MovePattern_Ten();
		break;
	default:
		Bullet::MovePattern_One();
		break;
	}
}

void Bullet::update() {
	Bullet::Move(pattern);
	time++;
}
void Bullet::DrawBulletPoisonous(){
	if (time % 40 < 10)DrawGraph(x - range, y - range, img_bullet_poisonous[0], TRUE);
	else if (time % 40 < 20)DrawGraph(x - range, y - range, img_bullet_poisonous[1], TRUE);
	else if (time % 40 < 30)DrawGraph(x - range, y - range, img_bullet_poisonous[2], TRUE);
	else DrawGraph(x - range, y - range, img_bullet_poisonous[3], TRUE);
}

void Bullet::DrawBulletShadow() {
	if (time % 360 < 15)DrawGraph(x - 250, y - 250, img_bullet_shadow[0], TRUE);
	else if (time % 360 < 30)DrawGraph(x - 250, y - 250, img_bullet_shadow[1], TRUE);
	else if (time % 360 < 45)DrawGraph(x - 250, y - 250, img_bullet_shadow[2], TRUE);
	else if (time % 360 < 330)DrawGraph(x - 250, y - 250, img_bullet_shadow[3], TRUE);
	else if (time % 360 < 345)DrawGraph(x - 250, y - 250, img_bullet_shadow[4], TRUE);
	else DrawGraph(x - 250, y - 250, img_bullet_shadow[5], TRUE);
}

void Bullet::DrawBulletMeat() {
	if (time % 60 < 20)DrawGraph(x - range, y - range, img_bullet_meat[0], TRUE);
	else if (time % 60 < 40)DrawGraph(x - range, y - range, img_bullet_meat[1], TRUE);
	else DrawGraph(x - range, y - range, img_bullet_meat[2], TRUE);
}

void Bullet::draw() {
	if (who)DrawGraph(x - range + 10, y - range, img_bullet_player, TRUE);
	else {
		if (kinds == 1)DrawGraph(x - range, y - range, img_bullet_ameba, TRUE);
		if (kinds == 2)DrawGraph(x - range, y - range, img_bullet_cholesterol, TRUE);
		if (kinds == 3)DrawBulletPoisonous();
		if (kinds == 5)DrawGraph(x - range, y - range, img_bullet_virus, TRUE);
		if (kinds == 6)DrawGraph(x - range, y - range, img_bullet_worm, TRUE);
		if (kinds == 10)DrawRotaGraph2(x, y, range, 108, 1.0, M_PI / 6, Bullet::img_bullet_arrow, TRUE);
		if (kinds == 11)DrawGraph(x - range, y - 108, img_bullet_arrow, TRUE);
		if (kinds == 12)DrawRotaGraph2(x, y, range, 108, 1.0, -M_PI / 6, Bullet::img_bullet_arrow, TRUE);
		if (kinds == 13)DrawGraph(x - range, y - range, img_bullet_magic, TRUE);
		if (kinds == 14)DrawBulletShadow();
		if (kinds == 100)DrawRotaGraph2(x,y, range, 125, 1.0, M_PI / 9, Bullet::img_bullet_arrow_ex, TRUE);
		if (kinds == 101)DrawGraph(x - range, y - 125, img_bullet_arrow_ex, TRUE);
		if (kinds == 102)DrawRotaGraph2(x, y, range, 125, 1.0, -M_PI / 9, Bullet::img_bullet_arrow_ex, TRUE);
		if (kinds == 103)DrawRotaGraph2(x, y, range, 125, 1.0, 2*M_PI / 9, Bullet::img_bullet_arrow_ex, TRUE);
		if (kinds == 104)DrawRotaGraph2(x, y, range, 125, 1.0, -2*M_PI / 9, Bullet::img_bullet_arrow_ex, TRUE);
		if (kinds == 105)DrawBulletMeat();
		if (kinds == 200)DrawGraph(x - range, y - range, img_bullet_ivy[0], TRUE);
		else if (kinds == 201)DrawGraph(x - range, y - range, img_bullet_ivy[1], TRUE);
		else if (kinds == 202)DrawGraph(x - range, y - range, img_bullet_ivy[2], TRUE);
		else if (kinds == 203)DrawGraph(x - range, y - range, img_bullet_ivy[3], TRUE);
		else if (kinds == 204)DrawGraph(x - range, y - range, img_bullet_ivy[4], TRUE);
		else if (kinds == 205)DrawGraph(x - range, y - range, img_bullet_ivy[5], TRUE);
		else if (kinds == 206)DrawGraph(x - range, y - range, img_bullet_ivy[6], TRUE);
		else if (kinds == 207)DrawGraph(x - range, y - range, img_bullet_ivy[7], TRUE);
		else if (kinds == 208)DrawGraph(x - range, y - range, img_bullet_ivy[8], TRUE);
		else if (kinds == 209)DrawGraph(x - range, y - range, img_bullet_ivy[9], TRUE);
		else if (kinds == 210)DrawGraph(x - range, y - range, img_bullet_ivy[10], TRUE);
		else if (kinds == 211)DrawGraph(x - range, y - range, img_bullet_ivy[11], TRUE);
		else if (kinds == 212)DrawGraph(x - range, y - range, img_bullet_ivy[12], TRUE);
		else if (kinds == 213)DrawGraph(x - range, y - range, img_bullet_ivy[13], TRUE);
		else if (kinds == 214)DrawGraph(x - range, y - range, img_bullet_ivy[14], TRUE);
		else if (kinds == 215)DrawGraph(x - range, y - range, img_bullet_ivy[15], TRUE);
		else if (kinds == 300)DrawRotaGraph2(x, y,  range,  range, 1.0, M_PI / 6, Bullet::img_bullet_ivy[0], TRUE);
		else if (kinds == 301)DrawRotaGraph2(x, y,  range,  range, 1.0, M_PI / 6, Bullet::img_bullet_ivy[1], TRUE);
		else if (kinds == 302)DrawRotaGraph2(x, y,  range,  range, 1.0, M_PI / 6, Bullet::img_bullet_ivy[2], TRUE);
		else if (kinds == 303)DrawRotaGraph2(x, y,  range,  range, 1.0, M_PI / 6, Bullet::img_bullet_ivy[3], TRUE);
		else if (kinds == 304)DrawRotaGraph2(x, y,  range,  range, 1.0, M_PI / 6, Bullet::img_bullet_ivy[4], TRUE);
		else if (kinds == 305)DrawRotaGraph2(x, y,  range,  range, 1.0, M_PI / 6, Bullet::img_bullet_ivy[5], TRUE);
		else if (kinds == 306)DrawRotaGraph2(x, y,  range,  range, 1.0, M_PI / 6, Bullet::img_bullet_ivy[6], TRUE);
		else if (kinds == 307)DrawRotaGraph2(x, y,  range,  range, 1.0, M_PI / 6, Bullet::img_bullet_ivy[7], TRUE);
		else if (kinds == 308)DrawRotaGraph2(x, y,  range,  range, 1.0, M_PI / 6, Bullet::img_bullet_ivy[8], TRUE);
		else if (kinds == 309)DrawRotaGraph2(x, y,  range,  range, 1.0, M_PI / 6, Bullet::img_bullet_ivy[9], TRUE);
		else if (kinds == 310)DrawRotaGraph2(x, y,  range,  range, 1.0, M_PI / 6, Bullet::img_bullet_ivy[10], TRUE);
		else if (kinds == 311)DrawRotaGraph2(x, y,  range,  range, 1.0, M_PI / 6, Bullet::img_bullet_ivy[11], TRUE);
		else if (kinds == 312)DrawRotaGraph2(x, y,  range,  range, 1.0, M_PI / 6, Bullet::img_bullet_ivy[12], TRUE);
		else if (kinds == 313)DrawRotaGraph2(x, y,  range,  range, 1.0, M_PI / 6, Bullet::img_bullet_ivy[13], TRUE);
		else if (kinds == 314)DrawRotaGraph2(x, y,  range,  range, 1.0, M_PI / 6, Bullet::img_bullet_ivy[14], TRUE);
		else if (kinds == 315)DrawRotaGraph2(x, y,  range,  range, 1.0, M_PI / 6, Bullet::img_bullet_ivy[15], TRUE);
		else if (kinds == 400)DrawRotaGraph2(x, y,  range,  range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy[0], TRUE);
		else if (kinds == 401)DrawRotaGraph2(x, y,  range,  range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy[1], TRUE);
		else if (kinds == 402)DrawRotaGraph2(x, y,  range,  range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy[2], TRUE);
		else if (kinds == 403)DrawRotaGraph2(x, y,  range,  range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy[3], TRUE);
		else if (kinds == 404)DrawRotaGraph2(x, y,  range,  range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy[4], TRUE);
		else if (kinds == 405)DrawRotaGraph2(x, y,  range,  range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy[5], TRUE);
		else if (kinds == 406)DrawRotaGraph2(x, y,  range,  range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy[6], TRUE);
		else if (kinds == 407)DrawRotaGraph2(x, y,  range,  range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy[7], TRUE);
		else if (kinds == 408)DrawRotaGraph2(x, y,  range,  range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy[8], TRUE);
		else if (kinds == 409)DrawRotaGraph2(x, y,  range,  range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy[9], TRUE);
		else if (kinds == 410)DrawRotaGraph2(x, y,  range,  range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy[10], TRUE);
		else if (kinds == 411)DrawRotaGraph2(x, y,  range,  range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy[11], TRUE);
		else if (kinds == 412)DrawRotaGraph2(x, y,  range,  range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy[12], TRUE);
		else if (kinds == 413)DrawRotaGraph2(x, y,  range,  range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy[13], TRUE);
		else if (kinds == 414)DrawRotaGraph2(x, y,  range,  range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy[14], TRUE);
		else if (kinds == 415)DrawRotaGraph2(x, y,  range,  range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy[15], TRUE);
		else if (kinds == 500)DrawRotaGraph2(x, y, range, range, 1.0, 5 * M_PI / 12, Bullet::img_bullet_ivy[0], TRUE);
		else if (kinds == 501)DrawRotaGraph2(x, y, range, range, 1.0, 5 * M_PI / 12, Bullet::img_bullet_ivy[1], TRUE);
		else if (kinds == 502)DrawRotaGraph2(x, y, range, range, 1.0, 5 * M_PI / 12, Bullet::img_bullet_ivy[2], TRUE);
		else if (kinds == 503)DrawRotaGraph2(x, y, range, range, 1.0, 5 * M_PI / 12, Bullet::img_bullet_ivy[3], TRUE);
		else if (kinds == 504)DrawRotaGraph2(x, y, range, range, 1.0, 5 * M_PI / 12, Bullet::img_bullet_ivy[4], TRUE);
		else if (kinds == 505)DrawRotaGraph2(x, y, range, range, 1.0, 5 * M_PI / 12, Bullet::img_bullet_ivy[5], TRUE);
		else if (kinds == 506)DrawRotaGraph2(x, y, range, range, 1.0, 5 * M_PI / 12, Bullet::img_bullet_ivy[6], TRUE);
		else if (kinds == 507)DrawRotaGraph2(x, y, range, range, 1.0, 5 * M_PI / 12, Bullet::img_bullet_ivy[7], TRUE);
		else if (kinds == 508)DrawRotaGraph2(x, y, range, range, 1.0, 5 * M_PI / 12, Bullet::img_bullet_ivy[8], TRUE);
		else if (kinds == 509)DrawRotaGraph2(x, y, range, range, 1.0, 5 * M_PI / 12, Bullet::img_bullet_ivy[9], TRUE);
		else if (kinds == 510)DrawRotaGraph2(x, y, range, range, 1.0, 5 * M_PI / 12, Bullet::img_bullet_ivy[10], TRUE);
		else if (kinds == 511)DrawRotaGraph2(x, y, range, range, 1.0, 5 * M_PI / 12, Bullet::img_bullet_ivy[11], TRUE);
		else if (kinds == 512)DrawRotaGraph2(x, y, range, range, 1.0, M_PI / 2, Bullet::img_bullet_ivy[12], TRUE);
		else if (kinds == 513)DrawRotaGraph2(x, y, range, range, 1.0, 5 * M_PI / 12, Bullet::img_bullet_ivy[13], TRUE);
		else if (kinds == 514)DrawRotaGraph2(x, y, range, range, 1.0, 5 * M_PI / 12, Bullet::img_bullet_ivy[14], TRUE);
		else if (kinds == 515)DrawRotaGraph2(x, y, range, range, 1.0, 5 * M_PI / 12, Bullet::img_bullet_ivy[15], TRUE);
		else if (kinds == 600)DrawRotaGraph2(x, y, range, range, 1.0, -5 * M_PI / 12, Bullet::img_bullet_ivy[0], TRUE);
		else if (kinds == 601)DrawRotaGraph2(x, y, range, range, 1.0, -5 * M_PI / 12, Bullet::img_bullet_ivy[1], TRUE);
		else if (kinds == 602)DrawRotaGraph2(x, y, range, range, 1.0, -5 * M_PI / 12, Bullet::img_bullet_ivy[2], TRUE);
		else if (kinds == 603)DrawRotaGraph2(x, y, range, range, 1.0, -5 * M_PI / 12, Bullet::img_bullet_ivy[3], TRUE);
		else if (kinds == 604)DrawRotaGraph2(x, y, range, range, 1.0, -5 * M_PI / 12, Bullet::img_bullet_ivy[4], TRUE);
		else if (kinds == 605)DrawRotaGraph2(x, y, range, range, 1.0, -5 * M_PI / 12, Bullet::img_bullet_ivy[5], TRUE);
		else if (kinds == 606)DrawRotaGraph2(x, y, range, range, 1.0, -5 * M_PI / 12, Bullet::img_bullet_ivy[6], TRUE);
		else if (kinds == 607)DrawRotaGraph2(x, y, range, range, 1.0, -5 * M_PI / 12, Bullet::img_bullet_ivy[7], TRUE);
		else if (kinds == 608)DrawRotaGraph2(x, y, range, range, 1.0, -5 * M_PI / 12, Bullet::img_bullet_ivy[8], TRUE);
		else if (kinds == 609)DrawRotaGraph2(x, y, range, range, 1.0, -5 * M_PI / 12, Bullet::img_bullet_ivy[9], TRUE);
		else if (kinds == 610)DrawRotaGraph2(x, y, range, range, 1.0, -5 * M_PI / 12, Bullet::img_bullet_ivy[10], TRUE);
		else if (kinds == 611)DrawRotaGraph2(x, y, range, range, 1.0, -5 * M_PI / 12, Bullet::img_bullet_ivy[11], TRUE);
		else if (kinds == 612)DrawRotaGraph2(x, y, range, range, 1.0, -5 * M_PI / 12, Bullet::img_bullet_ivy[12], TRUE);
		else if (kinds == 613)DrawRotaGraph2(x, y, range, range, 1.0, -5 * M_PI / 12, Bullet::img_bullet_ivy[13], TRUE);
		else if (kinds == 614)DrawRotaGraph2(x, y, range, range, 1.0, -5 * M_PI / 12, Bullet::img_bullet_ivy[14], TRUE);
		else if (kinds == 615)DrawRotaGraph2(x, y, range, range, 1.0, -5 * M_PI / 12, Bullet::img_bullet_ivy[15], TRUE);
		 if (kinds == 1000)DrawGraph(x - range, y - range, img_bullet_ivy_ex[0], TRUE);
		else if (kinds == 1001)DrawGraph(x - range, y - range, img_bullet_ivy_ex[1], TRUE);
		else if (kinds == 1002)DrawGraph(x - range, y - range, img_bullet_ivy_ex[2], TRUE);
		else if (kinds == 1003)DrawGraph(x - range, y - range, img_bullet_ivy_ex[3], TRUE);
		else if (kinds == 1004)DrawGraph(x - range, y - range, img_bullet_ivy_ex[4], TRUE);
		else if (kinds == 1005)DrawGraph(x - range, y - range, img_bullet_ivy_ex[5], TRUE);
		else if (kinds == 1006)DrawGraph(x - range, y - range, img_bullet_ivy_ex[6], TRUE);
		else if (kinds == 1007)DrawGraph(x - range, y - range, img_bullet_ivy_ex[7], TRUE);
		else if (kinds == 1008)DrawGraph(x - range, y - range, img_bullet_ivy_ex[8], TRUE);
		else if (kinds == 1009)DrawGraph(x - range, y - range, img_bullet_ivy_ex[9], TRUE);
		else if (kinds == 1010)DrawGraph(x - range, y - range, img_bullet_ivy_ex[10], TRUE);
		else if (kinds == 1011)DrawGraph(x - range, y - range, img_bullet_ivy_ex[11], TRUE);
		else if (kinds == 1100)DrawRotaGraph2(x, y,  range, range, 1.0, M_PI / 6, Bullet::img_bullet_ivy_ex[0], TRUE);
		else if (kinds == 1101)DrawRotaGraph2(x, y,  range, range, 1.0, M_PI / 6, Bullet::img_bullet_ivy_ex[1], TRUE);
		else if (kinds == 1102)DrawRotaGraph2(x, y,  range, range, 1.0, M_PI / 6, Bullet::img_bullet_ivy_ex[2], TRUE);
		else if (kinds == 1103)DrawRotaGraph2(x, y,  range, range, 1.0, M_PI / 6, Bullet::img_bullet_ivy_ex[3], TRUE);
		else if (kinds == 1104)DrawRotaGraph2(x, y,  range, range, 1.0, M_PI / 6, Bullet::img_bullet_ivy_ex[4], TRUE);
		else if (kinds == 1105)DrawRotaGraph2(x, y,  range, range, 1.0, M_PI / 6, Bullet::img_bullet_ivy_ex[5], TRUE);
		else if (kinds == 1106)DrawRotaGraph2(x, y,  range, range, 1.0, M_PI / 6, Bullet::img_bullet_ivy_ex[6], TRUE);
		else if (kinds == 1107)DrawRotaGraph2(x, y,  range, range, 1.0, M_PI / 6, Bullet::img_bullet_ivy_ex[7], TRUE);
		else if (kinds == 1108)DrawRotaGraph2(x, y,  range, range, 1.0, M_PI / 6, Bullet::img_bullet_ivy_ex[8], TRUE);
		else if (kinds == 1109)DrawRotaGraph2(x, y,  range, range, 1.0, M_PI / 6, Bullet::img_bullet_ivy_ex[9], TRUE);
		else if (kinds == 1110)DrawRotaGraph2(x, y,  range, range, 1.0, M_PI / 6, Bullet::img_bullet_ivy_ex[10], TRUE);
		else if (kinds == 1111)DrawRotaGraph2(x, y,  range, range, 1.0, M_PI / 6, Bullet::img_bullet_ivy_ex[11], TRUE);
		else if (kinds == 1200)DrawRotaGraph2(x, y,  range, range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy_ex[0], TRUE);
		else if (kinds == 1201)DrawRotaGraph2(x, y,  range, range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy_ex[1], TRUE);
		else if (kinds == 1202)DrawRotaGraph2(x, y,  range, range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy_ex[2], TRUE);
		else if (kinds == 1203)DrawRotaGraph2(x, y,  range, range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy_ex[3], TRUE);
		else if (kinds == 1204)DrawRotaGraph2(x, y,  range, range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy_ex[4], TRUE);
		else if (kinds == 1205)DrawRotaGraph2(x, y,  range, range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy_ex[5], TRUE);
		else if (kinds == 1206)DrawRotaGraph2(x, y,  range, range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy_ex[6], TRUE);
		else if (kinds == 1207)DrawRotaGraph2(x, y,  range, range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy_ex[7], TRUE);
		else if (kinds == 1208)DrawRotaGraph2(x, y,  range, range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy_ex[8], TRUE);
		else if (kinds == 1209)DrawRotaGraph2(x, y,  range, range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy_ex[9], TRUE);
		else if (kinds == 1210)DrawRotaGraph2(x, y,  range, range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy_ex[10], TRUE);
		else if (kinds == 1211)DrawRotaGraph2(x, y,  range, range, 1.0, -M_PI / 6, Bullet::img_bullet_ivy_ex[11], TRUE);
		else if (kinds == 1300)DrawRotaGraph2(x, y, range, range, 1.0, M_PI / 3, Bullet::img_bullet_ivy_ex[0], TRUE);
		else if (kinds == 1301)DrawRotaGraph2(x, y, range, range, 1.0, M_PI / 3, Bullet::img_bullet_ivy_ex[1], TRUE);
		else if (kinds == 1302)DrawRotaGraph2(x, y, range, range, 1.0, M_PI / 3, Bullet::img_bullet_ivy_ex[2], TRUE);
		else if (kinds == 1303)DrawRotaGraph2(x, y, range, range, 1.0, M_PI / 3, Bullet::img_bullet_ivy_ex[3], TRUE);
		else if (kinds == 1304)DrawRotaGraph2(x, y, range, range, 1.0, M_PI / 3, Bullet::img_bullet_ivy_ex[4], TRUE);
		else if (kinds == 1305)DrawRotaGraph2(x, y, range, range, 1.0, M_PI / 3, Bullet::img_bullet_ivy_ex[5], TRUE);
		else if (kinds == 1306)DrawRotaGraph2(x, y, range, range, 1.0, M_PI / 3, Bullet::img_bullet_ivy_ex[6], TRUE);
		else if (kinds == 1307)DrawRotaGraph2(x, y, range, range, 1.0, M_PI / 3, Bullet::img_bullet_ivy_ex[7], TRUE);
		else if (kinds == 1308)DrawRotaGraph2(x, y, range, range, 1.0, M_PI / 3, Bullet::img_bullet_ivy_ex[8], TRUE);
		else if (kinds == 1309)DrawRotaGraph2(x, y, range, range, 1.0, M_PI / 3, Bullet::img_bullet_ivy_ex[9], TRUE);
		else if (kinds == 1310)DrawRotaGraph2(x, y, range, range, 1.0, M_PI / 3, Bullet::img_bullet_ivy_ex[10], TRUE);
		else if (kinds == 1311)DrawRotaGraph2(x, y, range, range, 1.0, M_PI / 3, Bullet::img_bullet_ivy_ex[11], TRUE);
		else if (kinds == 1400)DrawRotaGraph2(x, y, range, range, 1.0, -M_PI / 3, Bullet::img_bullet_ivy_ex[0], TRUE);
		else if (kinds == 1401)DrawRotaGraph2(x, y, range, range, 1.0, -M_PI / 3, Bullet::img_bullet_ivy_ex[1], TRUE);
		else if (kinds == 1402)DrawRotaGraph2(x, y, range, range, 1.0, -M_PI / 3, Bullet::img_bullet_ivy_ex[2], TRUE);
		else if (kinds == 1403)DrawRotaGraph2(x, y, range, range, 1.0, -M_PI / 3, Bullet::img_bullet_ivy_ex[3], TRUE);
		else if (kinds == 1404)DrawRotaGraph2(x, y, range, range, 1.0, -M_PI / 3, Bullet::img_bullet_ivy_ex[4], TRUE);
		else if (kinds == 1405)DrawRotaGraph2(x, y, range, range, 1.0, -M_PI / 3, Bullet::img_bullet_ivy_ex[5], TRUE);
		else if (kinds == 1406)DrawRotaGraph2(x, y, range, range, 1.0, -M_PI / 3, Bullet::img_bullet_ivy_ex[6], TRUE);
		else if (kinds == 1407)DrawRotaGraph2(x, y, range, range, 1.0, -M_PI / 3, Bullet::img_bullet_ivy_ex[7], TRUE);
		else if (kinds == 1408)DrawRotaGraph2(x, y, range, range, 1.0, -M_PI / 3, Bullet::img_bullet_ivy_ex[8], TRUE);
		else if (kinds == 1409)DrawRotaGraph2(x, y, range, range, 1.0, -M_PI / 3, Bullet::img_bullet_ivy_ex[9], TRUE);
		else if (kinds == 1410)DrawRotaGraph2(x, y, range, range, 1.0, -M_PI / 3, Bullet::img_bullet_ivy_ex[10], TRUE);
		else if (kinds == 1411)DrawRotaGraph2(x, y, range, range, 1.0, -M_PI / 3, Bullet::img_bullet_ivy_ex[11], TRUE);
	}
}