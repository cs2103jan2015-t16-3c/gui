#include "TextUITest.h"

void TextUITest::processUserInput(string command){
	display = command;
}

string TextUITest::showDisplay(){
	return "Create proposal]01/03/2015]1200]02/03/2015]1159]done]Cook]NULL]NULL]NULL]NULL]undone]eat lunch]NULL]NULL]02/03/2015]1200]undone]Do tutorial]04/03/2015]1200]04/03/2015]1400]undone]Go Shopping]05/03/2015]1100]05/03/2015]1900]undone]task]NULL]NULL]01/03/2015]1400]undone]Meet prof]03/02/2015]1200]03/02/2015]1400]undone]create GUI]14/03/2015]1000]15/03/2015]1500]undone]";
}

string TextUITest::showFeedback(){
	return display + " feedback";
}

int TextUITest::getNoOfTask() {
	return 8;
}

TextUITest::TextUITest(void)
{
}
