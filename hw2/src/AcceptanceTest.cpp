#include "AcceptanceTest.h"
#include "Utilization.h"

int AcceptanceTest::putIfAcceptable(
	TaskSet *&acceptedTasks, Task &newTask, float time) 
{
	/* Create test task set that includes new task */
	TaskSet *testTasks = new TaskSet(*acceptedTasks);
	int arrivalIndex = testTasks->put(newTask);
	
	/* Compute max utilization on test set and reject new task if above 1 */
	bool acceptable = isAcceptable(testTasks, time);
	
	/* Update the active task set according to test result */
	if(acceptable) {
		delete acceptedTasks;
		acceptedTasks = testTasks;
	} else {
		delete testTasks;
		arrivalIndex = -1;
	}
	
	return arrivalIndex;
}

bool AcceptanceTest::isAcceptable(TaskSet *testTasks, float time) {
	UtilizationResult u = Utilization::maxUtilization(*testTasks, time);
	return u.value <= 1.0f;
}