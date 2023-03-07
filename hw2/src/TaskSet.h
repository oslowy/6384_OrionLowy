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
	TaskSet(const TaskSet &other);

	int count() const;
	Task &get(int index) const;
	
	/* The return value signals where the new item was placed. */
	int put(Task &newTask);
	
	void removeFirst();

private:
	vector<Task> tasks;
};