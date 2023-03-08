#pragma once

#include "OutputLogger.h"
#include "TaskSet.h"

class TaskRunner {
public:
	TaskRunner(OutputLogger *outputLogger);
	~TaskRunner();
	
	void arriveTask(Task &task);
	void runUntilArrival(float nextArrivalTime);
	
private:
	void completeCurrentTask();
	void contextSwitch();
	void updateSpeeds();

	TaskSet *acceptedIncompleteTasks;
	float currentTime;
	
	/* The time for the currently running task to context switch out. */
	float switchOutTime;
	
	/* Record the events to generate a schedule result */
	/** Need to record actual schedule when tasks started/preempted/completed */
	OutputLogger *outputLogger;
};