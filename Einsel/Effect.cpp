#include "Effect.h"

void Effect::DrawSmallEffect(int x, int y) {
	//if (time < 7)DrawGraph(x, y, img_effect_small[0], TRUE);
	if (time < 7)DrawGraph(x, y, img_effect_small[1], TRUE);
	else if (time < 14)DrawGraph(x, y, img_effect_small[2], TRUE);
	else if (time < 21)DrawGraph(x, y, img_effect_small[3], TRUE);
	else if (time < 28)DrawGraph(x, y, img_effect_small[4], TRUE);
	else if (time < 35)DrawGraph(x, y, img_effect_small[5], TRUE);
	else if (time < 42)DrawGraph(x, y, img_effect_small[6], TRUE);
	else disappear = true;
}
void Effect::DrawMiddleEffect(int x, int y) {
	if (time < 10)DrawGraph(x, y, img_effect_middle[0], TRUE);
	else if (time < 20)DrawGraph(x, y, img_effect_middle[1], TRUE);
	else if (time < 30)DrawGraph(x, y, img_effect_middle[2], TRUE);
	else if (time < 40)DrawGraph(x, y, img_effect_middle[3], TRUE);
	else if (time < 50)DrawGraph(x, y, img_effect_middle[4], TRUE);
	else if (time < 60)DrawGraph(x, y, img_effect_middle[5], TRUE);
	else if (time < 70)DrawGraph(x, y, img_effect_middle[6], TRUE);
	else if (time < 80)DrawGraph(x, y, img_effect_middle[7], TRUE);
	else if (time < 90) {
		DrawGraph(0, 200, img_effect_clear[0], TRUE);
		se.PlaySE(8);
	}
	else if (time < 100)DrawGraph(0, 200, img_effect_clear[1], TRUE);
	else if (time < 110)DrawGraph(0, 200, img_effect_clear[2], TRUE);
	else if (time < 120)DrawGraph(0, 200, img_effect_clear[3], TRUE);
	else if (time < 130)DrawGraph(0, 200, img_effect_clear[4], TRUE);
	else if (time < 140)DrawGraph(0, 200, img_effect_clear[5], TRUE);
	else if (time < 150)DrawGraph(0, 200, img_effect_clear[0], TRUE);
	else if (time < 160)DrawGraph(0, 200, img_effect_clear[1], TRUE);
	else if (time < 170)DrawGraph(0, 200, img_effect_clear[2], TRUE);
	else if (time < 180)DrawGraph(0, 200, img_effect_clear[3], TRUE);
	else if (time < 190)DrawGraph(0, 200, img_effect_clear[4], TRUE);
	else if (time < 200)DrawGraph(0, 200, img_effect_clear[5], TRUE);
	else disappear = true;
}
void Effect::DrawBigEffect(int x, int y) {
	if (time < 10)DrawGraph(x, y, img_effect_big[0], TRUE);
	else if (time < 20)DrawGraph(x, y, img_effect_big[1], TRUE);
	else if (time < 30)DrawGraph(x, y, img_effect_big[2], TRUE);
	else if (time < 40)DrawGraph(x, y, img_effect_big[3], TRUE);
	else if (time < 50)DrawGraph(x, y, img_effect_big[4], TRUE);
	else if (time < 60)DrawGraph(x, y, img_effect_big[5], TRUE);
	else if (time < 70)DrawGraph(x, y, img_effect_big[6], TRUE);
	else if (time < 80)DrawGraph(x, y, img_effect_big[7], TRUE);
	else if (time < 90)DrawGraph(x, y, img_effect_big[8], TRUE);
	else if (time < 100)DrawGraph(x, y, img_effect_big[9], TRUE);
	else if (time < 110)DrawGraph(x, y, img_effect_big[10], TRUE);
	else if (time < 120)DrawGraph(x, y, img_effect_big[11], TRUE);
	else if (time < 130)DrawGraph(x, y, img_effect_big[12], TRUE);
	else if (time < 140)DrawGraph(x, y, img_effect_big[13], TRUE);
	else if (time < 150)DrawGraph(x, y, img_effect_big[14], TRUE);
	else if (time < 160)DrawGraph(x, y, img_effect_big[15], TRUE);
	else disappear = true;
}
/*void Effect::PlayEffectMusic() {
	if (kinds == 1)sound_effect_small;
	else if (kinds == 2)sound_effect_middle;
	else if (kinds == 3)sound_effect_big;
}*/
void Effect::draw() {
	switch (kinds){
	case 1:
		Effect::DrawSmallEffect(x - 50, y - 50);
		break;
	case 2:
		Effect::DrawMiddleEffect(x - 150, y - 150);
		break;
	case 3:
		Effect::DrawBigEffect(x - 200, y - 200);
		break;
	}
	time++;
}