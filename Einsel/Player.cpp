#include "Player.h"

void Player::move() {
	if (paralyze_cooldown < 40) {
		if (input.GetKey(KEY_INPUT_UP) && y >= 25)y -= yspd;
		if (input.GetKey(KEY_INPUT_DOWN) && y <= 575)y += yspd;
		if (input.GetKey(KEY_INPUT_LEFT) && x >= wall_left)x -= xspd;
		if (input.GetKey(KEY_INPUT_RIGHT) && x <= wall_right)x += xspd;
	}
}

void Player::update() {
	input.update();
	Player::move();
	if (shoot_cooldown > 0)shoot_cooldown--;
	if (paralyze_cooldown > 0)paralyze_cooldown--;
	time++;
}

void Player::draw() {
	if (paralyze_cooldown < 40) {
		if (!(paralyze_cooldown)) {
			if (input.GetKey(KEY_INPUT_LEFT) && input.GetKey(KEY_INPUT_RIGHT))DrawGraph(x - 37, y - 37, img_player[1], TRUE);
			else if (input.GetKey(KEY_INPUT_LEFT))DrawGraph(x - 37, y - 37, img_player[0], TRUE);
			else if (input.GetKey(KEY_INPUT_RIGHT))DrawGraph(x - 37, y - 37, img_player[2], TRUE);
			else DrawGraph(x - 37, y - 37, img_player[1], TRUE);
		}
		else {
			if (time % 20 < 10) {
				if (input.GetKey(KEY_INPUT_LEFT) && input.GetKey(KEY_INPUT_RIGHT))DrawGraph(x - 37, y - 37, img_player[1], TRUE);
				else if (input.GetKey(KEY_INPUT_LEFT))DrawGraph(x - 37, y - 37, img_player[0], TRUE);
				else if (input.GetKey(KEY_INPUT_RIGHT))DrawGraph(x - 37, y - 37, img_player[2], TRUE);
				else DrawGraph(x - 37, y - 37, img_player[1], TRUE);
			}
		}
	}
	else {
		if(time % 20 < 10)DrawGraph(x - 37, y - 37, img_player[1], TRUE);
	}
	if (!(paralyze_cooldown)) {
		if (time % 50 < 10)DrawGraph(x - 38, y - 38, img_player[3], TRUE);
		else if (time % 50 < 25)DrawGraph(x - 38, y - 38, img_player[4], TRUE);
		else if (time % 50 < 35)DrawGraph(x - 38, y - 38, img_player[5], TRUE);
		else DrawGraph(x - 38, y - 38, img_player[6], TRUE);
		barrier_collapse = 0;
	}
	else {
		if(barrier_collapse < 10) DrawGraph(x - 50, y - 50, img_effect_playerhitted[0], TRUE);
		else if (barrier_collapse < 20) DrawGraph(x - 50, y - 50, img_effect_playerhitted[1], TRUE);
		else if (barrier_collapse < 30) DrawGraph(x - 50, y - 50, img_effect_playerhitted[2], TRUE);
		else if (barrier_collapse < 40) DrawGraph(x - 50, y - 50, img_effect_playerhitted[3], TRUE);
		else if (barrier_collapse < 50) DrawGraph(x - 50, y - 50, img_effect_playerhitted[4], TRUE);
		else if (barrier_collapse < 60) DrawGraph(x - 50, y - 50, img_effect_playerhitted[5], TRUE);
		else if (barrier_collapse < 70) DrawGraph(x - 50, y - 50, img_effect_playerhitted[6], TRUE);
		else DrawGraph(x - 50, y - 50, img_effect_playerhitted[7], TRUE);
		barrier_collapse++;
	}
}