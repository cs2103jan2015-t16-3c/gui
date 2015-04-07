#pragma once
#include <string>
#include <iostream>

using namespace std;

class TextUITest
{
public:
	void processUserInput(string command);
	string showDisplay();
	string display;
	string showFeedback();
	int getNoOfTask();
	TextUITest(void);
};

