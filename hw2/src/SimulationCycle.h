#pragma once

#include "ArrivalTimeline.h"
#include "TaskRunner.h"

class SimulationCycle {
public:
	SimulationCycle(TaskRunner *taskRunner, OutputLogger *outputLogger);
	
	void runArrivalTimeline(ArrivalTimeline &arrivals);

private:
	TaskRunner *taskRunner;
};