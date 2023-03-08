#include "SimulationCycle.h"

SimulationCycle::SimulationCycle(
	TaskRunner *taskRunner, OutputLogger *outputLogger) 
{
	this->taskRunner = taskRunner;
	this->outputLogger = outputLogger;
}

void SimulationCycle::runArrivalTimeline(ArrivalTimeline &arrivals) {
	while(arrivals.size() > 0) {
		/* Load the next task arrival from the timeline */
		Task nextArrival = arrivals.front();
		float nextArrivalTime = nextArrival.arrival;
		
		/* Run the simulation for the time beforehand 
		    and activate the arrival event for the task */
		taskRunner->runUntilArrival(nextArrivalTime);
		taskRunner->arriveTask(nextArrival);
		
		/* Advance the arrival timeline */
		arrivals.pop();
	}
}