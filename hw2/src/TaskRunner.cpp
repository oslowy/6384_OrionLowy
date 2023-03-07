#include "TaskRunner.h"

#include "AcceptanceTest.h"
#include "Utilization.h"

TaskRunner::TaskRunner() {
	acceptedIncompleteTasks = new TaskSet;
	currentTime = 0.0f;
}

TaskRunner::~TaskRunner() {
	delete acceptedIncompleteTasks;
}

void TaskRunner::arriveTask(Task &task) {
	int arrivalIndex = AcceptanceTest::putIfAcceptable(
		acceptedIncompleteTasks, task, currentTime);
	
	if(arrivalIndex >= 0) {
		/* Update the speed schedule */
		
		/* Switch the current task if the new task landed in position 0 */
		if(arrivalIndex == 0) {
			//Need a way to read the prior running task information
		}
	}
}

//More methods...