#include "OutputLogger.h"

using namespace std;

void OutputLogger::reportTaskScheduled(Task &task, float time) {
	string eventInfo = "was scheduled at speed " + to_string(task.speed);
	
	reportEvent(task, time, eventInfo);
}

void OutputLogger::reportTaskCompleted(Task &task, float time) {
	string eventInfo = "completed";
	
	reportEvent(task, time, eventInfo);
}

void OutputLogger::reportSpeedChanged(Task &task, float time) {
	string eventInfo "changed its speed to " + to_string(task.speed);
	
	reportEvent(task, time, eventInfo);
}

void OutputLogger::reportEvent(Task &task, float time, string eventInfo) {
	string timeStamp = "Time=" + to_string(time);
	string taskIdStamp = "Task " + to_string(task.id);
	
	outputLogs += timeStamp + " " + taskIdStamp + " " + eventInfo + "\n";
}