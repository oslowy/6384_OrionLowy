#pragma once

#include "TaskSet.h"

float utilization(const TaskSet &taskSet, int targetIndex, float time) {
	float remainCompTimeSum = 0.0f;
	
	for(int i=0; i < targetIndex; i++) {
		remainCompTimeSum += taskSet.get(i).compTime;
	}
	
	float untilDeadline = taskSet.get(targetIndex).deadline - time;
	
	return remainCompTimeSum / untilDeadline;
}

/* Store computed utilization values in a vector and get max and 
    argmax in calling context */