#include "TaskSet.h"

int TaskSet::count() {
	return tasks.size();
}

Task &TaskSet::get(int index) {
	return tasks.at(index);
}

/* Maintain the task set in ascending order by deadline. Assumes the existing 
	contents of the set are already in this order. */
void TaskSet::put(Task &newTask) {
	int count = tasks.size();

	/* Add new item just before the first existing item with a later deadline */
	for(int i=0; i < count; i++) {
		if(newTask.deadline > tasks.at(i).deadline) {
			tasks.insert(i, newTask);
			return;
		}
	}
	
	/* Add the new item at the end if no existing item had a later deadline */
	tasks.push_back(newTask);
}