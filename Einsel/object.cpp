#include "object.h"


	double object::CheckLength(object* obj1, object* obj2) {
		return std::sqrt((obj1->x - obj2->x)*(obj1->x - obj2->x) + (obj1->y - obj2->y)*(obj1->y - obj2->y));
	}
	bool object::CheckHit(object* obj1, object* obj2) {
		if (CheckLength(obj1, obj2) < (double)(obj1->range + obj2->range)) {
			return true;
		}else {
			return false;
		}
	}