#pragma once

#include "TaskSet.h"
#include "Utilization.h"

class SpeedAdjust {
public:
	static void updateTaskSpeeds(const TaskSet &tasks, float time);
	
private:
	static TaskSet getTasksAfterMaxUtil(const TaskSet &tasks, int maxUtilIndex);
};