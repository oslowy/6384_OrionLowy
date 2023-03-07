#pragma once

#include "TaskSet.h"

class TaskRunner {
public:
	TaskRunner();
	~TaskRunner();
	
	void arriveTask(Task &task);
	void runUntilArrival(float nextArrivalTime);
	
private:
	void completeCurrentTask();
	void contextSwitch();
	void updateSpeeds();

	TaskSet *acceptedIncompleteTasks;
	float currentTime;
	float switchOutTime;
	
	/* Need to record actual schedule when tasks started/preempted/completed */
};