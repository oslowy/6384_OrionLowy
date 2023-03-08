#pragma once

#include "ArrivalQueue.h"
#include "OutputLogger.h"
#include "TaskRunner.h"

class SimulationCycle {
public:
	SimulationCycle(TaskRunner *taskRunner, OutputLogger *outputLogger);
	
	void runArrivalQueue(ArrivalQueue &arrivals);

private:
	TaskRunner *taskRunner;
	OutputLogger *outputLogger;
};