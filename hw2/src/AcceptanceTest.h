#pragma once

#include "TaskSet.h"

class AcceptanceTest {
public:
	static int putIfAcceptable(TaskSet *&acceptedTasks, Task &newTask, float time);

private:
	static bool isAcceptable(TaskSet *testTasks, float time);
};