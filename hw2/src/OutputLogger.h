#pragma once

class OutputLogger {
public:
	void reportTaskScheduled(Task &task, float time);
	void reportTaskCompleted(Task &task, float time);
	void reportSpeedChanged(Task &task, float time);
	
private:
	/** String storing the output logs */
};