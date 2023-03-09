#include "TaskRunner.h"

#include "AcceptanceTest.h"
#include "Utilization.h"
#include "SpeedAdjust.h"

TaskRunner::TaskRunner(OutputLogger *outputLogger) {
	acceptedTasks = new TaskSet;
	currentTime = 0.0f;
	
	this->outputLogger = outputLogger;
}

TaskRunner::~TaskRunner() {
	delete acceptedTasks;
}

void TaskRunner::arriveTask(Task &task) {
	/* Pass the new task through the acceptance test */
	int arrivalIndex = AcceptanceTest::putIfAcceptable(
		acceptedTasks, task, currentTime);
	
	/* Switch the current task if the new task landed in position 0 */
	if(arrivalIndex == 0) {
		contextSwitch();
	}
	
	/* Update the speed schedule if the new task was accepted, whatever position
	    in the queue it was placed in */
	if(arrivalIndex >= 0) {
		updateSpeeds();
	}
}

void TaskRunner::runUntilArrival(float nextArrivalTime) { 
	/* Run tasks while there are any running or ready */
	while(acceptedTasks->count() > 0) {
		Task &currentTask = acceptedTasks->get(0);
	
		/* Calculate time until complete at current speed */
		float completeTime = currentTask.computeTime / currentTask.speed;
		bool readyToComplete = completeTime <= nextArrivalTime;
		
		/* Complete the current task if it is finished */
		if(readyToComplete) {
			completeCurrentTask();
			currentTime = completeTime;
		}
		
		/* Execute part of the current task if another task arrives 
		    before it can complete */	
		else {
			float elapsedTime = nextArrivalTime - currentTime;
			currentTask.computeTime -= elapsedTime * currentTask.speed;
			
			/* Stop running tasks for now to let the arrival be processed */
			break;
		}
	}
	
	/* Update the global clock to the next arrival time */
	currentTime = nextArrivalTime;
}

void TaskRunner::completeCurrentTask() 
{
	outputLogger->reportTaskCompleted(acceptedTasks->get(0), currentTime);
	
	/* Advance the ready queue and begin the first waiting task */
	acceptedTasks->removeFirst();
	
	/* Add extra time for context switch to occur */
	contextSwitch();
}

void TaskRunner::contextSwitch() {
	/* Don't add time for context switch if the ready queue is empty */
	if(acceptedTasks->count() > 0) 
	{
		Task &newCurrentTask = acceptedTasks->get(0);
		
		newCurrentTask.computeTime += switchOutTime + newCurrentTask.switchTime;
		switchOutTime = newCurrentTask.switchTime;
		
		outputLogger->reportTaskScheduled(newCurrentTask, currentTime);
	}
}

void TaskRunner::updateSpeeds() {
	SpeedAdjust::updateTaskSpeeds(*acceptedTasks);
	
	outputLogger->reportSpeedChanged(acceptedTasks->get(0), currentTime);
}