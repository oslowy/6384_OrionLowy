#include "AcceptanceTest.h"
#include "Utilization.h"

bool AcceptanceTest::putIfAcceptable(
	TaskSet *&acceptedIncompleteTasks, Task &newTask, float time) 
{
	/* Create test task set that includes new task */
	TaskSet *testTasks = new TaskSet(*acceptedIncompleteTasks);
	testTasks->put(newTask);
	
	/* Compute max utilization on test set and reject new task if above 1 */
	UtilizationResult u = maxUtilization(*testTasks, time);
	bool newTaskAccepted = u.value <= 1.0f;
	
	/* Update the active task set according to test result */
	if(newTaskAccepted) {
		delete acceptedIncompleteTasks;
		acceptedIncompleteTasks = testTasks;
	} else {
		delete testTasks;
	}
}