#include "SpeedAdjust.h"

void SpeedAdjust::updateTaskSpeeds(const TaskSet &tasks, float time) {
	/* Skip recursion if tasks is empty */
	if(!tasks.empty()) {
		UtilizationResult maxUtil = maxUtilization(tasks, time);
		
		/* Calculate speeds for tasks in order up  
		    to the task with the max utilization */
		int maxUtilIndex = maxUtil.index;
		for(int i=0; i <= maxUtilIndex; i++) {
			tasks.get(i).speed = maxUtil.value;
		}
		
		/* Recursively call for the tasks after the last task in this round */
		TaskSet laterTasks = getTasksAfterMaxUtil(tasks, maxUtilIndex);
		float lastTaskDeadline = tasks.get(maxUtilIndex).deadline;
		
		updateTaskSpeeds(laterTasks, lastTaskDeadline);
		
		/* Merge in the speeds from the later tasks */
		int firstLaterTaskIndex = maxUtilIndex + 1;
		int numLaterTasks = tasks.count() - firstLaterTaskIndex;
		
		for(int i=0; i < numLaterTasks; i++) {
			int offsetI = i + firstLaterTaskIndex;
			
			tasks.get(offsetI).speed = laterTasks.get(i).speed;
		}
	}
	
	return speeds;
}

TaskSet SpeedAdjust::getTasksAfterMaxUtil(const TaskSet &tasks, int maxUtilIndex) {
	TaskSet laterTasks(tasks);
	
	for(int i = 0; i <= maxUtilIndex; i++) {
		laterTasks.removeFirst();
	}
	
	return laterTasks;
}