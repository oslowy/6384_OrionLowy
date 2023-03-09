#pragma once

#include "Task.h"
#include <string>

using namespace std;

class OutputLogger {
public:
	void reportTaskScheduled(Task &task, float time);
	void reportTaskCompleted(Task &task, float time);
	void reportSpeedChanged(Task &task, float time);
	
private:
	void reportEvent(Task &task, float time, string eventInfo);

	string outputLogs;
};