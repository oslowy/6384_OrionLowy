#include "Utilization.h"

float Utilization::utilization(const TaskSet &taskSet, int targetIndex, float time) {
	/* Sum the computation times of tasks in order up to the target task */
	float remainCompTimeSum = 0.0f;
	for(int i=0; i < targetIndex; i++) {
		remainCompTimeSum += taskSet.get(i).compTime;
	}
	
	/* Time left until the deadline of the target task */
	float untilDeadline = taskSet.get(targetIndex).deadline - time;

	return remainCompTimeSum / untilDeadline;
}

UtilizationResult Utilization::maxUtilization(const TaskSet &testTasks, float time) {
	UtilizationResult maxSoFar = {0.0f, 0};
	
	int numTasks = testTasks.count();
	for(int i=0; i<numTasks; i++) {
		float nextUtilization = utilization(testTasks, i, time);
		
		if(nextUtilization >= maxSoFar.value) {
			maxSoFar = {nextUtilization, i};
		}
	}
	
	return maxSoFar;
}