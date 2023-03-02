#pragma once

#include "TaskSet.h"

struct UtilizationResult {
	float value;
	int index;
};

class Utilization {
public:
	static float utilization(const TaskSet &taskSet, int targetIndex, float time);
	static UtilizationResult maxUtilization(const TaskSet &testTasks, float time);
};