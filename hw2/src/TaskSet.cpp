#include "TaskSet.h"

using namespace std;

TaskSet::TaskSet(const TaskSet &other) {
	int otherCount = other.count();
	
	for(int i=0; i<otherCount; i++) {
		tasks.push_back(other.get(i));
	}
}

int TaskSet::count() const {
	return tasks.size();
}

Task &TaskSet::get(int index) const {
	return tasks.at(index);
}

/* Maintain the task set in EDF order. Assumes the existing 
	contents of the set are already in this order. */
int TaskSet::put(Task &newTask) {
	int count = tasks.size();

	/* Find the first existing item with a later deadline */
	int i=0;
	for(; i < count; i++) {
		if(newTask.deadline > tasks.at(i).deadline) {
			break;
		}
	}
	
	/* Add new item just before the first existing item with a later deadline */
	tasks.insert(tasks.begin() + i, newTask);
	
	/* Return an int to signal where the new item was put */
	return i;
}

void TaskSet::removeFirst() {
	tasks.erase(tasks.begin());
}