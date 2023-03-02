#pragma once

#include "TaskSet.h"

class AcceptanceTest {
public:
	static bool putIfAcceptable(TaskSet *&acceptedIncompleteTasks, Task &newTask, float time);
};