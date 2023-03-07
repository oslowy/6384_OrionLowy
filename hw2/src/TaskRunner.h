#pragma once

#include "TaskSet.h"

class TaskRunner {
public:
	TaskRunner();
	~TaskRunner();
	
	void arriveTask(Task &task);
	void runCurrentTask(float untilTime);
	
private:
	void completeTask(int index);
	int selectCurrentTask();
	void switchCurrentTask(int index);
	void updateSpeeds();

	TaskSet *acceptedIncompleteTasks;
	float currentTime;
	
	/* Need to record actual schedule when tasks started/preempted/completed */
};