#include "TextUI.h"

string TextUI::MESSAGE_WELCOME = "Hello. Welcome to CONSTAN!";
string TextUI::MESSAGE_ADDED = "Task added: ";
string TextUI::MESSAGE_DELETED = "Task deleted: ";
string TextUI::MESSAGE_EDITED = "Task edited: ";
string TextUI::MESSAGE_DISPLAYED = "Task displayed: ";

string TextUI::ERROR_UNRECOGNISED_COMMAND_TYPE = "ERROR: Unrecognised command type.\nEnter \"help\" for list of valid command type in CONSTAN!";
string TextUI::ERROR_INVALID_FORMAT = "ERROR: Invalid format.\nEnter \"help\" for list of valid formatting in CONSTAN!";
string TextUI::ERROR_INVALID_DATE_TIME = "ERROR: Invalid date or time.";
string TextUI::ERROR_OTHERS = "ERROR.";

string TextUI::HELP_USER_GUIDE = "General Command: \n1. Undo : \"undo\" \n2. Redo : \"redo\" \n3. Search : \"search [keyword(s)]\" \n\nTask Manipulation Commands: \n1. Creating/Adding task : \"add [task name] -s [start time] -e [end time]\" \n2. Displaying task : \"display\" \n3. Deleting task : \"delete [task index]\" \n4. Editing task : \"edit [task number] [task name] -s [start time] -e [end time]\" \n5. Mark task as done : \"mark [task index]\" \n6. Unmark \'done\' task : \"unmark [task index]\" ";

void TextUI::processUserInput(string userCommand) {

	//showToUser(MESSAGE_WELCOME);

	//pass user input as a string to Logic
	toLogic.processCommand(userCommand);
		/*
		if(TRUE //valid formatting, command succesfully executed) 
			printCommand();
		else 
			showToUser(ERROR_INVALID_FORMAT);	
		*/
	setFeedback(userCommand);
	setDisplay(userCommand);

}


TextUI::COMMAND_TYPE_FEEDBACK TextUI::determineCommandType(string commandTypeString) {

	if(commandTypeString == "add")
		return COMMAND_TYPE_FEEDBACK::ADD_TASK;

	if (commandTypeString == "delete")
		return COMMAND_TYPE_FEEDBACK::DELETE_TASK;

	if (commandTypeString == "edit")
		return COMMAND_TYPE_FEEDBACK::EDIT_TASK;

	if (commandTypeString == "help")
		return COMMAND_TYPE_FEEDBACK::HELP;

	if (commandTypeString == "display")
		return COMMAND_TYPE_FEEDBACK::DISPLAY;

	if (commandTypeString == "mark" || "unmark" || "search" || "undo" || "redo" )
		return COMMAND_TYPE_FEEDBACK::OTHERS;

	else {
		return COMMAND_TYPE_FEEDBACK::INVALID;
	}
}

void TextUI::setFeedback(string userCommand) {
	if(userCommand == "") {                                      
		showToUser(ERROR_UNRECOGNISED_COMMAND_TYPE);
	}

	toLogic.getFeedback(_feedback);
	string commandTypeString = _feedback->front();
		
	COMMAND_TYPE_FEEDBACK commandType = determineCommandType(commandTypeString);

	switch (commandType) {
	case ADD_TASK: 
		displayedFeedback(MESSAGE_ADDED);
		return;
	case DELETE_TASK:
		displayedFeedback(MESSAGE_DELETED);
		return;
	case EDIT_TASK:
		displayedFeedback(MESSAGE_EDITED);
		return;
	case HELP:
		showToUser(HELP_USER_GUIDE);
		return;
	case DISPLAY:
		displayedFeedback(MESSAGE_DISPLAYED);
		return;
	case OTHERS:
		displayedFeedback();
		return;
	case INVALID:             
		showToUser(ERROR_UNRECOGNISED_COMMAND_TYPE);
		return;
	default:
		return;
	}

}

/*
string TextUI::getFirstWord(string userCommand){

	userCommandTemp = userCommand;
	string commandTypeString = userCommandTemp.substr(0, userCommand.find(' '));
	//string commandTypeString = toLogic.getCommandType();

	return commandTypeString;
}
*/


//combine feedback message with feedback result
void TextUI::displayedFeedback(string message) {

	feedback = message + getFeedbackResult();
}

//create feedback for commands who don't require messages
void TextUI::displayedFeedback() {

	feedback = getFeedbackResult();
}

//get feedback result from Logic CLASS
string TextUI::getFeedbackResult() {
	
	return _feedback->at(1);
}

//pass the string of feedback to GUI
string TextUI::showFeedback() {

	return feedback;
}

//set the content of the display going to be printed 
void TextUI::setDisplay() {

	display = displayTask.getDisplay();
}

//return ONE string of display for GUI class
string TextUI::showDisplay() {

	return display;
}

/*
void TextUI::showToUser(string text) {
	cout << text << endl;
}
*/


TextUI::TextUI(void) {
}


TextUI::~TextUI(void) {
}

