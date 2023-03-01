#pragma once

#include "TaskSet.h"

class AcceptanceTest {
public:
	static bool testAccept(TaskSet *&acceptedIncompleteTasks, Task &newTask, float time);
	
private:
	/* Update remaining compTime of the running task outside this 
	    context before calling testAccept. */
	
	static float maxUtilization(const TaskSet &testTasks, float time);
};