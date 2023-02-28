#pragma once

#include <vector>

using namespace std;

struct Task {
	int arrival;
	float compTime;
	int deadline;
	int switchTime;
};

class TaskSet {
public:
	int count();
	Task &get(int index);
	void put(Task &newTask);

private:
	vector<Task> tasks;
};