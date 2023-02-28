#pragma once

#include <algorithm>
#include "TaskSet.h"

float utilization(TaskSet taskSet, int index, float time) {
	float remainCompTimeSum = 0.0f;
	
	for(int i=0; i < index; i++) {
		remainCompTimeSum += taskSet.get(i).compTime;
	}
	
	float untilDeadline = taskSet.get(index).deadline - time;
	
	return remainCompTimeSum / untilDeadline;
}

/* Store computed utilization values in a vector and get max and 
    argmax in calling context */