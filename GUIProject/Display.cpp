#include "Display.h"


const string Display::TITLE_DEADLINE = "Deadlines:\n";
const string Display::TITLE_TIMED = "Scheduled Tasks:\n";
const string Display::TITLE_FLOATING = "Tasks To-Do:\n";
const string Display::LINE_BREAK = "\n";

void Display::createDisplay() {
	
	getTaskVectors();
	unparseTaskVector();

}

void Display::getTaskVectors() { 

	toLogic.getTaskVector(taskVector);

}

void Display::unparseTaskVector() {
	
	for (int i=0 ; i<taskVector->size() ; i++) {

		string taskName = taskVector->at(i).getTaskName();
		taskName = convertToCorrectFormat(taskName);
		string startDate = taskVector->at(i).getStartDate();
		string startTime = taskVector->at(i).getStartTime();
		string endDate = taskVector->at(i).getendDate();
		string endTime = taskVector->at(i).getEndTime();
		string status = taskVector->at(i).getStatus();
		display = taskName + "]" + startDate + "]" + startTime + "]" + endDate + "]" + endTime + "]" + status + "]";
	}
}

/*Capitalize first letter, lowercase the rest*/ //might not be necessary
string Display::convertToCorrectFormat(string taskName) {

	if( !taskName.empty() ) {

    taskName[0] = toupper(taskName[0]);

    for( int i=1 ; i < taskName.length() ; i++ )
        taskName[i] = tolower(taskName[i]);
	}

	return taskName;

}

string Display::getDisplay() {

	return display;
}


Display::Display(void) {

	createDisplay();
}


Display::~Display(void) {
}


//funtions of UI before GUI implemented
/*
void Display::print(string DisplayType) {
	getTaskVectors(DisplayType);
	printAccordingToType(DisplayType);

}


void Display::printAccordingToType(string DisplayType) {
	if (DisplayType == "all") {
		showAllTask();
	}
	if (DisplayType == "today") {
		showTodayTask();
	}
	if (DisplayType == "deadline") {
		showDeadlineTask();
	}
	if (DisplayType == "timed") {
		showTimedTask();
	}
	if (DisplayType == "floating") {
		showFloatingTask();
	}
}


void Display::showAllTask() {
	vector<Task>::iterator iter;

	int index = 1;

	showToUser(TITLE_DEADLINE);
	for (iter= deadlineTask->begin() ; iter != deadlineTask->end(); iter++) {
		cout << index << ". " << (*iter) << endl;
		index++;
	}
	showToUser(LINE_BREAK);

	showToUser(TITLE_TIMED);
	for (iter= timedTask->begin() ; iter != timedTask->end() ; iter++) {
		cout << index << ". " << (*iter) << endl;
		index++;
	}
	showToUser(LINE_BREAK);

	showToUser(TITLE_FLOATING);
	for (iter= floatingTask->begin() ; iter != floatingTask->end(); iter++) {
		cout << index << ". " << (*iter) << endl;
		index++;
	}
	
}

void Display::showTodayTask() {
	vector<Task>* todayTask;
	mergeTask(todayTask);
	printTodayTask(todayTask);
}

void Display::showDeadlineTask() {
	int index = 1;
	vector<Task>::iterator iter;

	showToUser(TITLE_DEADLINE);
	for (iter= deadlineTask->begin() ; iter != deadlineTask->end(); iter++) {
		cout << index << ". " << (*iter) << endl;
		index++;
	}

}

void Display::showTimedTask() {
	int index = 1;
	vector<Task>::iterator iter;

	showToUser(TITLE_TIMED);
	for (iter= timedTask->begin() ; iter != timedTask->end() ; iter++) {
		cout << index << ". " << (*iter) << endl;
		index++;
	}
}

void Display::showFloatingTask() {
	int index = 1;
	vector<Task>::iterator iter;

	showToUser(TITLE_FLOATING);
	for (iter= floatingTask->begin() ; iter != floatingTask->end(); iter++) {
		cout << index << ". " << (*iter) << endl;
		index++;
	}
}

void Display::mergeTask(vector<Task>* todayTask) {
	vector<Task>::iterator timedTaskBegin = timedTask->begin();
	vector<Task>::iterator deadlineTaskBegin = deadlineTask->begin();
	vector<Task>::iterator timedTaskLast = timedTaskBegin + timedTask->size();
	vector<Task>::iterator deadlineTaskLast = deadlineTaskBegin + deadlineTask->size();

	merge(timedTaskBegin,timedTaskLast, deadlineTaskBegin,deadlineTaskLast,todayTask->begin());
}
*/
/*
void Display::printTodayTask(vector<Task>* todayTask) {
	vector<Task>::iterator todayTaskIter;
	int index = 1;

	for (todayTaskIter= todayTask->begin() ; todayTaskIter != todayTask->end(); todayTaskIter++)
	{
		cout << index << ". ";
		if (todayTaskIter->getType() == "deadline")
			cout << "[deadline] ";
		if (todayTaskIter->getType() == "timed") 
			cout << "[schedule] ";

		cout << (*todayTaskIter) << endl;
		index++;
	}

} 

void Display::showToUser(string text) {
	cout << text << endl;
}
*/

