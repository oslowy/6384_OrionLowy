#include "AcceptanceTest.h"
#include "Utilization.h"

bool AcceptanceTest::putIfAcceptable(
	TaskSet *&acceptedIncompleteTasks, Task &newTask, float time) 
{
	/* Create test task set that includes new task */
	TaskSet *testTasks = new TaskSet(*acceptedIncompleteTasks);
	testTasks->put(newTask);
	
	/* Compute max utilization on test set and reject new task if above 1 */
	float u = maxUtilization(*testTasks, time);
	bool newTaskAccepted = u <= 1.0f;
	
	/* Update the active task set according to test result */
	if(newTaskAccepted) {
		delete acceptedIncompleteTasks;
		acceptedIncompleteTasks = testTasks;
	} else {
		delete testTasks;
	}
}

float AcceptanceTest::maxUtilization(const TaskSet &testTasks, float time) {
	float maxSoFar = 0.0f;
	
	int numTasks = testTasks.count();
	for(int i=0; i<numTasks; i++) {
		float u_i = utilization(testTasks, i, time);
		
		if(u_i > maxSoFar) {
			maxSoFar = u_i;
		}
	}
	
	return maxSoFar;
}