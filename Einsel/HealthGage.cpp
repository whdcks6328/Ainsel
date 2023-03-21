#include "HealthGage.h"

void HealthGage::CalculateHealth(int i) {
	RecentHealth += i;
	if (RecentHealth > 130)RecentHealth = 130;
}

void HealthGage::update() {
	if (!(time % 12)&& RecentHealth && can_down)RecentHealth--;
	time++;
}

void HealthGage::draw() {
	for (i = 0; i < RecentHealth; i++) {
		DrawGraph(600, 524 - i, img_HealthGage[129 - i], TRUE);
	}
}