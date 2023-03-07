#pragma once

#include "AcceptanceTest.h"
#include "TaskSet.h"
#include "Utilization.h"

class TaskRunner {
public:
	bool arriveTask(Task &task);
	
private:
	void completeTask(int index);
	void runCurrentTask(float untilTime);
	void switchCurrentTask(Task &task);
	void updateSpeeds();
	void validateNewTask(Task &task);

	TaskSet *acceptedIncompleteTasks;
	float currentTime;
};