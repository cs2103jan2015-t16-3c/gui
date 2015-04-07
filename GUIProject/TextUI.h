//this class act as the bridge between Logic and GUI.
//it contains messages that would be displayed to user as feedbacks
//as well as passing the correct feedback message based on the command type
//passes user command to Logic and receive feedback message and display

#pragma once
#ifndef TEXTUI_H_
#define TEXTUI_H_

#include "Logic.h"
#include "Display.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

class TextUI
{
public:
    enum COMMAND_TYPE_FEEDBACK {
        ADD_TASK, DELETE_TASK, EDIT_TASK, DISPLAY, 
        INVALID, HELP, OTHERS
    };

    private:

    static string MESSAGE_WELCOME;
    static string MESSAGE_ADDED;
    static string MESSAGE_DELETED;
    static string MESSAGE_EDITED;

    static string ERROR_UNRECOGNISED_COMMAND_TYPE;
    static string ERROR_INVALID_FORMAT;
    static string ERROR_INVALID_DATE_TIME;
    static string ERROR_OTHERS;
    static string HELP_USER_GUIDE;

    Display displayTask;

	Logic toLogic;
	vector<string>* _feedback;
	string display;

    //string getFirstWord(string userCommand);
    COMMAND_TYPE_FEEDBACK determineCommandType(string commandTypeString);
    void displayResult();
    void displayTaskList();
	string getFeedbackResult();
    void setFeedback(string userCommand);
    void showToUser(string text);
	void displayedFeedback(string message);
	void displayedFeedback();

	void setDisplay();

public:
    TextUI(void);
    ~TextUI(void);
	string showFeedback();
	string showDisplay();
    void processUserInput(string command);

};

#endif
