#include "TaskRunner.h"

#include "AcceptanceTest.h"
#include "Utilization.h"
#include "SpeedAdjust.h"

TaskRunner::TaskRunner() {
	acceptedIncompleteTasks = new TaskSet;
	currentTime = 0.0f;
}

TaskRunner::~TaskRunner() {
	delete acceptedIncompleteTasks;
}

void TaskRunner::arriveTask(Task &task) {
	/* Pass the new task through the acceptance test */
	int arrivalIndex = AcceptanceTest::putIfAcceptable(
		acceptedIncompleteTasks, task, currentTime);
		
	/* Update the speed schedule if the new task was accepted */
	if(arrivalIndex >= 0) {
		updateSpeeds();
	}
	
	/* Switch the current task if the new task landed in position 0 */
	if(arrivalIndex == 0) {
		//Context switch time: Need a way to read the prior running task information
	}
}

void TaskRunner::runUntilArrival(float nextArrivalTime) { 
	/* Run tasks while there are any running or ready */
	while(acceptedIncompleteTasks->count() > 0) {
		Task currentTask = acceptedIncompleteTasks->get(0);
	
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

void TaskRunner::completeCurrentTask() {
	acceptedIncompleteTasks->removeFirst();
	
	//Report the task completed somehow...
}

void TaskRunner::updateSpeeds() {
	SpeedAdjust::updateTaskSpeeds(*acceptedIncompleteTasks);
}