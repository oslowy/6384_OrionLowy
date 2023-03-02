#include "SpeedAdjust.h"

SpeedVector SpeedAdjust::taskSpeeds(const TaskSet &tasks, float time) {
	SpeedVector speeds;
	
	/* Skip recursion if tasks is empty */
	if(!tasks.empty()) {
		UtilizationResult u = maxUtilization(tasks, time);
		
		/* Calculate speeds for tasks in order up  
		    to the task with the max utilization */
		int lastTaskIndex = u.index;
		for(int i=0; i<=lastTaskIndex; i++) {
			speeds.push_back(u.value);
		}
		
		/* Recursively call for the tasks after the last task in this round */
		TaskSet laterTasks = getLaterTasks(tasks, lastTaskIndex);
		float lastTaskDeadline = tasks.get(lastTaskIndex).deadline;
		
		SpeedVector laterTaskSpeeds = taskSpeeds(laterTasks, lastTaskDeadline);
		
		/* Concatenate the speeds from the later tasks */
		speeds.insert(speeds.end(), laterTaskSpeeds.begin(), 
			laterTaskSpeeds.end());
	}
	
	return speeds;
}

TaskSet SpeedAdjust::getLaterTasks(const TaskSet &tasks, int lastTaskIndexSoFar) {
	TaskSet laterTasks = tasks;
	
	for(int i = 0; i <= lastTaskIndexSoFar; i++) {
		laterTasks.removeFirst();
	}
	
	return laterTasks;
}