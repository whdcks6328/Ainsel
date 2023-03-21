#include "Zako.h"

void Zako::MovePattern_Ameba() {
	x += spd_ameba;
	if(x <= wall_left || x+2*range >= wall_right) spd_ameba = -spd_ameba;
	y += 1;
	}

void Zako::MovePattern_Cholesterol() {
	y += spd_cholesterol;
}

void Zako::MovePattern_Poisonous() {
	y += spd_poisonous;
	if (y <= 0 || y >= 525 && poisonous_count < 5) {
		spd_poisonous = -spd_poisonous;
		poisonous_count++;
		if (poisonous_count >= 5) y += spd_poisonous;
	}
}

void Zako::MovePattern_Sugikahun(){
	if (time % 90 == 0 ) {
		xspd_sugikahun = rand() % 5 - 2;
		yspd_sugikahun = rand() % 5 - 1;
	}
	if (x <= 100)xspd_sugikahun = 2;
	if (x >= 500)xspd_sugikahun = -2;
	if (y <= 0) yspd_sugikahun = 2;
	if (y >= 525) yspd_sugikahun = -2;
	x += xspd_sugikahun; y += yspd_sugikahun;
}

void Zako::MovePattern_Virus() {
	if (time % 240 < 120) {
		x = x + (double)1/2 + 2 * sin((double)time / 60 * M_PI);
		y = y + 1 + 4 * cos((double)time / 60 * M_PI);
	}
	else{
		x = x + (double)1/2 - 2 * sin((double)time / 60 * M_PI);
		y = y +1 + 4 * cos((double)time / 60 * M_PI);
	}
}

void Zako::MovePattern_Worm() {
	if(time % 3 == 0) y += spd_worm;
}

void Zako::Move(int kinds) {
	switch (kinds){
	case 1:
		Zako::MovePattern_Ameba();
		break;
	case 2:
		Zako::MovePattern_Cholesterol();
		break;
	case 3:
		Zako::MovePattern_Poisonous();
		break;
	case 4:
		Zako::MovePattern_Sugikahun();
		break;
	case 5:
		Zako::MovePattern_Virus();
		break;
	case 6:
		Zako::MovePattern_Worm();
		break;
	default:
		Zako::MovePattern_Ameba();
		break;
	}
}

void Zako::update() {
	Zako::Move(kinds);
	time++;
}

void Zako::DrawAmeba() {
	if(time % 50 < 10)DrawGraph(x - range, y - range, img_ameba[0], TRUE);
	else if (time % 50 < 20)DrawGraph(x - range, y - range, img_ameba[1], TRUE);
	else if (time % 50 < 30)DrawGraph(x - range, y - range, img_ameba[2], TRUE);
	else if (time % 50 < 40)DrawGraph(x - range, y - range, img_ameba[3], TRUE);
	else DrawGraph(x - range, y - range, img_ameba[4], TRUE);
}
void Zako::DrawCholesterol() {
	if (time % 80 < 10)DrawGraph(x - range, y - range, img_cholesterol[0], TRUE);
	else if (time % 80 < 20)DrawGraph(x - range, y - range, img_cholesterol[1], TRUE);
	else if (time % 80 < 30)DrawGraph(x - range, y - range, img_cholesterol[2], TRUE);
	else if (time % 80 < 40)DrawGraph(x - range, y - range, img_cholesterol[3], TRUE);
	else if (time % 80 < 50)DrawGraph(x - range, y - range, img_cholesterol[4], TRUE);
	else if (time % 80 < 60)DrawGraph(x - range, y - range, img_cholesterol[5], TRUE);
	else if (time % 80 < 70)DrawGraph(x - range, y - range, img_cholesterol[6], TRUE);
	else DrawGraph(x - range, y - range, img_cholesterol[7], TRUE);
}
void Zako::DrawPoisonous() {
	if (time % 40 < 10)DrawGraph(x - range, y - 70, img_poisonous[0], TRUE);
	else if (time % 40 < 20)DrawGraph(x - range, y - 70, img_poisonous[1], TRUE);
	else if (time % 40 < 30)DrawGraph(x - range, y - 70, img_poisonous[2], TRUE);
	else DrawGraph(x - range, y - 70, img_poisonous[3], TRUE);
}
void Zako::DrawSugikahun() {
	if (time % 40 < 10)DrawGraph(x - range, y - range, img_sugikahun[0], TRUE);
	else if (time % 40 < 20)DrawGraph(x - range, y - range, img_sugikahun[1], TRUE);
	else if (time % 40 < 30)DrawGraph(x - range, y - range, img_sugikahun[2], TRUE);
	else DrawGraph(x - range, y - range, img_sugikahun[3], TRUE);
}
void Zako::DrawVirus() {
	if (time % 40 < 10)DrawGraph(x - range, y - range, img_virus[0], TRUE);
	else if (time % 40 < 20)DrawGraph(x - range, y - range, img_virus[1], TRUE);
	else if (time % 40 < 30)DrawGraph(x - range, y - range, img_virus[2], TRUE);
	else DrawGraph(x - range, y - range, img_virus[3], TRUE);
}
void Zako::DrawWorm() {
	if (time % 60 < 10)DrawGraph(x - range, y - 66, img_worm[0], TRUE);
	else if (time % 60 < 20)DrawGraph(x - range, y - 66, img_worm[1], TRUE);
	else if (time % 60 < 30)DrawGraph(x - range, y - 66, img_worm[2], TRUE);
	else if (time % 60 < 40)DrawGraph(x - range, y - 66, img_worm[3], TRUE);
	else if (time % 60 < 50)DrawGraph(x - range, y - 66, img_worm[4], TRUE);
	else DrawGraph(x - range, y - 66, img_worm[5], TRUE);
}

void Zako::draw() {
	switch (kinds){
	case 1:
		DrawAmeba();
		break;
	case 2:
		DrawCholesterol();
		break;
	case 3:
		DrawPoisonous();
		break;
	case 4:
		DrawSugikahun();
		break;
	case 5:
		DrawVirus();
		break;
	case 6:
		DrawWorm();
		break;
	default:
		DrawAmeba();
		break;
	}
}