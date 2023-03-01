#pragma once

#include "TaskSet.h"

class AcceptanceTest {
public:
	static bool testAccept(TaskSet &priorIncompleteTasks, Task &newTask, float time);
	
private:
	/* Update remaining compTime of the running task outside this 
	    context before calling testAccept. */
	
	float maxUtilization(TaskSet &testTasks, float time);
};