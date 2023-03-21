#include "object.h"
#include "item.h"

void Item::update() {
	if (angle > 3.1416 || angle < -3.1416)angle *= (3.14159265 / 180.0);
	y += (int)(spd * cos(angle));
	x += (int)(spd * sin(angle));
	time++;
}
void Item::draw() {
	if(time % 40 < 10)DrawGraph(x - range, y - range, img_item[0], true);
	else if (time % 40 < 20)DrawGraph(x - range, y - range, img_item[1], true);
	else if (time % 40 < 30)DrawGraph(x - range, y - range, img_item[2], true);
	else DrawGraph(x - range, y - range, img_item[3], true);
}