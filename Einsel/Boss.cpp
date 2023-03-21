#include "Boss.h"

void Boss::Move_Leraje() {
	if (!(check_phase)) {
		if (y < 150) {
			y += spd_leraje;
		}
		else {
			if (x < 100 || x > 500)spd_leraje *= -1;
			x += spd_leraje;
		}
	}
	if (time % 420 < 300)check_phase = false;
	else check_phase = true;
}

void Boss::Move_Buer(){
	if (hp > 350) {
		if (y < 200) {
			y += 2;
			time = 15;
		}
		if (time % 600 < 420 && time%600 >15) {
			x += xspd_buer;
			if (x <= 200 || x + 2 * range >= 500) xspd_buer = -xspd_buer;
		}
	}
	else{
		if (time > 100) {
			if (time % 90 == 0) {
				xspd_buer = rand() % 5 - 2;
				yspd_buer = rand() % 5 - 2;
			}
			if (x <= 100)xspd_buer = 2;
			if (x >= 500)xspd_buer = -2;
			if (y <= 0) yspd_buer = 2;
			if (y >= 300) yspd_buer = -2;
			x += xspd_buer; y += yspd_buer;
		}
		if (time % 420 < 300)check_phase = false;
		else check_phase = true;
	}
}

void Boss::Move_Lime() {
	if (hp > 800) {
		if (!(check_phase)) {
			if (y < 100) {
				y += yspd_lime;
			}
			x += xspd_lime;
			if (x <= 100 || x + 2 * range >= 600) xspd_lime = -xspd_lime;
		}
		if (time % 420 < 300)check_phase = false;
		else check_phase = true;
	}
	else {
		switch (lime_count) {
		case 1:
			if (y < 300) y += yspd_lime;
			else if (x < 300) x += 2;
			else if (x > 300) x -= 2;
		    else if (x == 300 && y == 300) lime_count = 2;
			time = 0;
			break;
		case 2:
			if (!(check_phase)) {
				if (time % 720 < 45) x += spd_lime;
				else if (time % 720 < 90) y += spd_lime;
				else if (time % 720 < 135) x -= spd_lime;
				else if (time % 720 < 180) y -= spd_lime;
				else if (time % 720 < 225) x -= spd_lime;
				else if (time % 720 < 270) y += spd_lime;
				else if (time % 720 < 315) x += spd_lime;
				else if (time % 720 < 360) y -= spd_lime;
			}
			if (time % 720 >= 360) {
				check_phase = true;
				if (time % 720 == 719) check_phase = false;
			}
			break;
		}
	}
}

void Boss::Move_ParasiteLime() {
	if (hp > 3400) {
		if (y < 150) {
			y += 2;
		}
		x += spd_parasitelime;
		if (x <= 100 || x >= 500) spd_parasitelime = -spd_parasitelime;
	}
	else if (hp > 2800) {
		if (y < 160) {
			y += 2;
			time = 20;
		}
		if (time % 250 < 170 && time % 250 > 15) {
			x += spd_parasitelime;
			if (x <= 100 || x >= 500) spd_parasitelime = -spd_parasitelime;
		}
	}
	else if (hp > 2200) {
		x += spd_parasitelime;
		if (x <= 100 || x >= 500) spd_parasitelime = -spd_parasitelime;
		if (time % 360 < 240)check_phase = false;
		else check_phase = true;
	}
	else if(hp>1200){
		x += spd_parasitelime;
		if (x <= 100 || x >= 500) spd_parasitelime = -spd_parasitelime;
	}
	else if (localtime);
	else {
		if (time % 90 == 0) {
			xspd_buer = rand() % 5 - 2;
			yspd_buer = rand() % 5 - 2;
		}
		if (x <= 100)xspd_buer = 2;
		if (x >= 500)xspd_buer = -2;
		if (y <= 0) yspd_buer = 2;
		if (y >= 300) yspd_buer = -2;
		x += xspd_buer; y += yspd_buer;
	}
}

void Boss::Move_ParasiteLimeFinal() {
	if (time % 90 == 0) {
		xspd_buer = rand() % 9 - 4;
		yspd_buer = rand() % 9 - 4;
	}
	if (x <= 100)xspd_buer = 5;
	if (x >= 500)xspd_buer = -5;
	if (y <= 0) yspd_buer = 5;
	if (y >= 300) yspd_buer = -5;
}

void Boss::Move(int number_boss) {
	switch (number_boss)
	{
	case 1:
		Boss::Move_Leraje();
		break;
	case 2:
		Boss::Move_Buer();
		break;
	case 3:
		Boss::Move_Lime();
		break;
	case 4:
	    Boss::Move_ParasiteLime();
		break;
	default:
		break;
	}
}

void Boss::update() {
	Boss::Move(number_boss);
	time++;
	if (localtime)localtime--;
}

void Boss::Draw_Leraje() {
	if (check_phase) {
		if(time % 60 < 12)DrawGraph(x - range, y - 96, img_boss_leraje[5], TRUE);
		else if (time % 60 < 24)DrawGraph(x - range, y - 96, img_boss_leraje[6], TRUE);
		else if (time % 60 < 36)DrawGraph(x - range, y - 96, img_boss_leraje[7], TRUE);
		else if (time % 60 < 48)DrawGraph(x - range, y - 96, img_boss_leraje[8], TRUE);
		else DrawGraph(x - range, y - 96, img_boss_leraje[9], TRUE);
	}
	else {
		if (time % 60 < 12)DrawGraph(x - range, y - 96, img_boss_leraje[0], TRUE);
		else if (time % 60 < 24)DrawGraph(x - range, y - 96, img_boss_leraje[1], TRUE);
		else if (time % 60 < 36)DrawGraph(x - range, y - 96, img_boss_leraje[2], TRUE);
		else if (time % 60 < 48)DrawGraph(x - range, y - 96, img_boss_leraje[3], TRUE);
		else DrawGraph(x - range, y - 96, img_boss_leraje[4], TRUE);
	}
}

void Boss::Draw_Buer() {
	if (hp > 350) {
		if (time % 600 < 3)DrawGraph(x - range, y - range, img_boss_buer[5], TRUE);
		else if (time % 600 < 6)DrawGraph(x - range, y - range, img_boss_buer[4], TRUE);
		else if (time % 600 < 9)DrawGraph(x - range, y - range, img_boss_buer[3], TRUE);
		else if (time % 600 < 12)DrawGraph(x - range, y - range, img_boss_buer[2], TRUE);
		else if (time % 600 < 15)DrawGraph(x - range, y - range, img_boss_buer[1], TRUE);
	    else if(time % 600 < 360)DrawGraph(x - range, y - range, img_boss_buer[0], TRUE);
		else if (time % 600 < 370)DrawGraph(x - range, y - range, img_boss_buer[1], TRUE);
		else if (time % 600 < 380)DrawGraph(x - range, y - range, img_boss_buer[2], TRUE);
		else if (time % 600 < 390)DrawGraph(x - range, y - range, img_boss_buer[3], TRUE);
		else if (time % 600 < 400)DrawGraph(x - range, y - range, img_boss_buer[4], TRUE);
		else if (time % 600 < 410)DrawGraph(x - range, y - range, img_boss_buer[5], TRUE);
		else DrawGraph(x - range, y - range, img_boss_buer[6], TRUE);
	}
	else {
		switch (buer_count) {
		case 1:
			if (time % 220 < 10)DrawGraph(x - range, y - range, img_boss_buer[1], TRUE);
			else if (time % 220 < 20)DrawGraph(x - range, y - range, img_boss_buer[2], TRUE);
			else if (time % 220 < 30)DrawGraph(x - range, y - range, img_boss_buer[3], TRUE);
			else if (time % 220 < 40)DrawGraph(x - range, y - range, img_boss_buer[4], TRUE);
			else if (time % 220 < 50)DrawGraph(x - range, y - range, img_boss_buer[5], TRUE);
			else if (time % 220 < 60)DrawGraph(x - range, y - range, img_boss_buer[6], TRUE);
			else if (time % 220 < 70)DrawGraph(x - range, y - range, img_boss_buer[8], TRUE);
			else if (time % 220 < 80)DrawGraph(x - range, y - range, img_boss_buer[9], TRUE);
			else if (time % 220 < 90)DrawGraph(x - range, y - range, img_boss_buer[10], TRUE);
			else if (time % 220 < 100)DrawGraph(x - range, y - range, img_boss_buer[11], TRUE);
			else if (time % 220 < 110)DrawGraph(x - range, y - range, img_boss_buer[12], TRUE);
			else if (time % 220 < 120)DrawGraph(x - range, y - range, img_boss_buer[13], TRUE);
			else if (time % 220 < 130)DrawGraph(x - range, y - range, img_boss_buer[14], TRUE);
			else if (time % 220 < 140)DrawGraph(x - range, y - range, img_boss_buer[15], TRUE);
			else if (time % 220 < 150)DrawGraph(x - range, y - range, img_boss_buer[16], TRUE);
			else if (time % 220 < 160)DrawGraph(x - range, y - range, img_boss_buer[17], TRUE);
			else if (time % 220 < 170)DrawGraph(x - range, y - range, img_boss_buer[18], TRUE);
			else if (time % 220 < 180)DrawGraph(x - range, y - range, img_boss_buer[19], TRUE);
			else if (time % 220 < 190)DrawGraph(x - range, y - range, img_boss_buer[20], TRUE);
			else if (time % 220 < 200)DrawGraph(x - range, y - range, img_boss_buer[21], TRUE);
			else if (time % 220 < 210)DrawGraph(x - range, y - range, img_boss_buer[22], TRUE);
			else {
				DrawGraph(x - range, y - range, img_boss_buer[23], TRUE);
				buer_count = 2;
			}
			break;
		case 2:
			 if (time % 40 < 10)DrawGraph(x - range, y - range, img_boss_buer[20], TRUE);
			else if (time % 40 < 20)DrawGraph(x - range, y - range, img_boss_buer[21], TRUE);
			else if (time % 40 < 30)DrawGraph(x - range, y - range, img_boss_buer[22], TRUE);
			else DrawGraph(x - range, y - range, img_boss_buer[23], TRUE);
			break;
		}
	}
}

void Boss::Draw_Lime() {
	if (hp > 1600 && !check_phase) {
		if (time % 60 < 12)DrawGraph(x - range, y - 60, img_boss_lime[0], TRUE);
		else if (time % 60 < 24)DrawGraph(x - range, y - 60, img_boss_lime[1], TRUE);
		else if (time % 60 < 36)DrawGraph(x - range, y - 60, img_boss_lime[2], TRUE);
		else if (time % 60 < 48)DrawGraph(x - range, y - 60, img_boss_lime[3], TRUE);
		else DrawGraph(x - range, y - 60, img_boss_lime[4], TRUE);
	}
	else if (hp > 1600 && check_phase) {
		if (time % 60 < 15)DrawGraph(x - range, y - 60, img_boss_lime[8], TRUE);
		else if (time % 60 < 30)DrawGraph(x - range, y - 60, img_boss_lime[9], TRUE);
		else if (time % 60 < 45)DrawGraph(x - range, y - 60, img_boss_lime[10], TRUE);
		else DrawGraph(x - range, y - 60, img_boss_lime[11], TRUE);
	}
	else if (hp > 800 && hp <= 1600) {
		if (time % 48 < 12)DrawGraph(x - range, y - 60, img_boss_lime[24], TRUE);
		else if (time % 48 < 24)DrawGraph(x - range, y - 60, img_boss_lime[25], TRUE);
		else if (time % 48 < 36)DrawGraph(x - range, y - 60, img_boss_lime[26], TRUE);
		else DrawGraph(x - range, y - 60, img_boss_lime[27], TRUE);
	}
	else if (hp <= 800 && !check_phase) {
		if (time % 720 < 45) DrawGraph(x - range, y - 60, img_boss_lime[19], TRUE);
		else if (time % 720 < 90) DrawGraph(x - range, y - 60, img_boss_lime[17], TRUE);
		else if (time % 720 < 135) DrawGraph(x - range, y - 60, img_boss_lime[18], TRUE);
		else if (time % 720 < 180) DrawGraph(x - range, y - 60, img_boss_lime[16], TRUE);
		else if (time % 720 < 225) DrawGraph(x - range, y - 60, img_boss_lime[18], TRUE);
		else if (time % 720 < 270) DrawGraph(x - range, y - 60, img_boss_lime[17], TRUE);
		else if (time % 720 < 315) DrawGraph(x - range, y - 60, img_boss_lime[19], TRUE);
		else if (time % 720 < 360) DrawGraph(x - range, y - 60, img_boss_lime[16], TRUE);
		else DrawGraph(x - range, y - 60, img_boss_lime[0], TRUE);
	}
	else {
		if (time % 360 < 45)DrawGraph(x - range, y - 60, img_boss_lime[32], TRUE);
		else if (time % 360 < 90)DrawGraph(x - range, y - 60, img_boss_lime[33], TRUE);
		else if (time % 360 < 135)DrawGraph(x - range, y - 60, img_boss_lime[34], TRUE);
		else if (time % 360 < 180)DrawGraph(x - range, y - 60, img_boss_lime[35], TRUE);
		else if (time % 360 < 215)DrawGraph(x - range, y - 60, img_boss_lime[36], TRUE);
		else if (time % 360 < 240)DrawGraph(x - range, y - 60, img_boss_lime[37], TRUE);
		else if (time % 360 < 275)DrawGraph(x - range, y - 60, img_boss_lime[38], TRUE);
		else DrawGraph(x - range, y - 60, img_boss_lime[39], TRUE);
	}
}

void Boss::Draw_ParasiteLime() {
	if (hp > 3400) {
		if (time % 60 < 10)DrawGraph(x - range, y - range, img_boss_parasitelime_stay[0], TRUE);
		else if (time % 60 < 20)DrawGraph(x - range, y - range, img_boss_parasitelime_stay[1], TRUE);
		else if (time % 60 < 30)DrawGraph(x - range, y - range, img_boss_parasitelime_stay[2], TRUE);
		else if (time % 60 < 40)DrawGraph(x - range, y - range, img_boss_parasitelime_stay[3], TRUE);
		else if (time % 60 < 50)DrawGraph(x - range, y - range, img_boss_parasitelime_stay[4], TRUE);
		else DrawGraph(x - range, y - range, img_boss_parasitelime_stay[5], TRUE);

	}
	else if (hp > 2800 && !check_phase) {
		if (time % 250 < 5)DrawGraph(x - range, y - range, img_boss_parasitelime_ivy[4], TRUE);
		else if (time % 250 < 10)DrawGraph(x - range, y - range, img_boss_parasitelime_ivy[3], TRUE);
		else if (time % 250 < 15)DrawGraph(x - range, y - range, img_boss_parasitelime_ivy[2], TRUE);
		else if (time % 250 < 20)DrawGraph(x - range, y - range, img_boss_parasitelime_ivy[1], TRUE);
		else if (time % 250 < 170)DrawGraph(x - range, y - range, img_boss_parasitelime_ivy[0], TRUE);
		else if (time % 250 < 175)DrawGraph(x - range, y - range, img_boss_parasitelime_ivy[1], TRUE);
		else if (time % 250 < 180)DrawGraph(x - range, y - range, img_boss_parasitelime_ivy[2], TRUE);
		else if (time % 250 < 185)DrawGraph(x - range, y - range, img_boss_parasitelime_ivy[3], TRUE);
		else if (time % 250 < 190)DrawGraph(x - range, y - range, img_boss_parasitelime_ivy[4], TRUE);
		else DrawGraph(x - range, y - range, img_boss_parasitelime_ivy[5], TRUE);
	}
	else if (hp > 1200 && hp <= 2800) {
		if (time % 60 < 10)DrawGraph(x - range, y - range, img_boss_parasitelime_stay[0], TRUE);
		else if (time % 60 < 20)DrawGraph(x - range, y - range, img_boss_parasitelime_stay[1], TRUE);
		else if (time % 60 < 30)DrawGraph(x - range, y - range, img_boss_parasitelime_stay[2], TRUE);
		else if (time % 60 < 40)DrawGraph(x - range, y - range, img_boss_parasitelime_stay[3], TRUE);
		else if (time % 60 < 50)DrawGraph(x - range, y - range, img_boss_parasitelime_stay[4], TRUE);
		else DrawGraph(x - range, y - range, img_boss_parasitelime_stay[5], TRUE);
	}
	else if (hp <=1200) {
		if (time % 50 < 10) DrawGraph(x - 60, y - 60, img_boss_parasitelime_ex2[0], TRUE);
		else if (time % 50 < 20) DrawGraph(x - 60, y - 60, img_boss_parasitelime_ex2[1], TRUE);
		else if (time % 50 < 30) DrawGraph(x - 60, y - 60, img_boss_parasitelime_ex2[2], TRUE);
		else if (time % 50 < 40) DrawGraph(x - 60, y - 60, img_boss_parasitelime_ex2[3], TRUE);
		else  DrawGraph(x - 60, y - 60, img_boss_parasitelime_ex2[4], TRUE);
	}
}

void Boss::Draw_ParasiteLimeChenge() {
	if (localtime > 230) DrawGraph(x - range, y - range, img_boss_parasitelime_change[0], TRUE);
	else if (localtime > 220) { 
		DrawGraph(x - range, y - range, img_boss_parasitelime_change[1], TRUE); 
		bose.PlaySE(9);
	}
	else if (localtime >210) DrawGraph(x - range, y - range, img_boss_parasitelime_change[2], TRUE);
	else if(localtime >200) DrawGraph(x - range, y - range, img_boss_parasitelime_change[3], TRUE);
	else if (localtime >190) DrawGraph(x - range, y - range, img_boss_parasitelime_change[4], TRUE);
	else if (localtime >180) DrawGraph(x - range, y - range, img_boss_parasitelime_change[5], TRUE);
	else if (localtime >170) DrawGraph(x - range, y - range, img_boss_parasitelime_change[6], TRUE);
	else if (localtime >160) DrawGraph(x - range, y - range, img_boss_parasitelime_change[7], TRUE);
	else if (localtime >150) DrawGraph(x - range, y - range, img_boss_parasitelime_change[8], TRUE);
	else if (localtime >140) DrawGraph(x - range, y - range, img_boss_parasitelime_change[9], TRUE);
	else if (localtime >130) DrawGraph(x - range, y - range, img_boss_parasitelime_change[10], TRUE);
	else if (localtime >120) DrawGraph(x - range, y - range, img_boss_parasitelime_change[11], TRUE);
	else if (localtime >110) DrawGraph(x - range, y - range, img_boss_parasitelime_change[12], TRUE);
	else if (localtime > 100) {
		DrawGraph(x - range, y - range, img_boss_parasitelime_change[13], TRUE);
		bose.PlaySE(9);
	}
	else if (localtime >90) DrawGraph(x - range, y - range, img_boss_parasitelime_change[14], TRUE);
	else if (localtime >80) DrawGraph(x - range, y - range, img_boss_parasitelime_change[15], TRUE);
	else if (localtime >70) DrawGraph(x - range, y - range, img_boss_parasitelime_change[16], TRUE);
	else if (localtime >60) DrawGraph(x - range, y - range, img_boss_parasitelime_change[17], TRUE);
	else if (localtime >50) DrawGraph(x - range, y - range, img_boss_parasitelime_change[18], TRUE);
	else if (localtime >40) DrawGraph(x - range, y - range, img_boss_parasitelime_change[19], TRUE);
	else if (localtime >30) DrawGraph(x - range, y - range, img_boss_parasitelime_change[20], TRUE);
	else if (localtime >20) DrawGraph(x - range, y - range, img_boss_parasitelime_change[21], TRUE);
	else if (localtime >10) DrawGraph(x - range, y - range, img_boss_parasitelime_change[22], TRUE);
	else {
		check_once = false;
		DrawGraph(x - range, y - range, img_boss_parasitelime_change[23], TRUE);
		range = 60;
	}
}

void Boss::Draw_ParasiteLimeFinal() {
	if (time % 60 < 12)DrawGraph(x - range, y - range, img_boss_parasitelime_ex2[0], TRUE);
	else if (time % 60 < 24)DrawGraph(x - range, y - range, img_boss_parasitelime_ex2[1], TRUE);
	else if (time % 60 < 36)DrawGraph(x - range, y - range, img_boss_parasitelime_ex2[2], TRUE);
	else if (time % 60 < 48)DrawGraph(x - range, y - range, img_boss_parasitelime_ex2[3], TRUE);
	else DrawGraph(x - range, y - range, img_boss_parasitelime_ex2[4], TRUE);
}

void Boss::draw() {
	if (localtime) Boss::Draw_ParasiteLimeChenge();
	else {
		switch (number_boss)
		{
		case 1:
			Boss::Draw_Leraje();
			break;
		case 2:
			Boss::Draw_Buer();
			break;
		case 3:
			Boss::Draw_Lime();
			break;
		case 4:
			Boss::Draw_ParasiteLime();
			break;
		case 5:
			Boss::Draw_ParasiteLimeFinal();
			break;
		default:
			break;
		}
	}
}