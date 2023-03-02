#pragma once

#include "TaskSet.h"
#include "Utilization.h"
#include <vector>

typedef vector<float> SpeedVector;

class SpeedAdjust {
public:
	static SpeedVector taskSpeeds(const TaskSet &tasks, float time);
	
private:
	static TaskSet getLaterTasks(const TaskSet &tasks, int lastTaskIndexSoFar);
};