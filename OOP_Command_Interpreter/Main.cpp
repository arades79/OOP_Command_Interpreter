#include "records.h"
#include <string>
#include <iostream>

using namespace std;

void main()
{
	string fullCommand;
	Records record;

	cout << "Student Record Manager 2017" << endl;
	cout << "type 'help' for help, type 'quit' to quit" << endl;

	while (true) {
		cout << "SRM>";
		getline(cin, fullCommand);

		string command = fullCommand.substr(0, fullCommand.find_first_of(' '));

		if (command == "addstudent") {
			int *spaces = spaceIndexes(fullCommand);

		}
		else if (command == "addscore") {

		}
		else if (command == "help") {

		}
		else if (command == "quit" || command == "exit") {
			delete &record;
			delete &fullCommand;
			return;
		}
		else {
			cout << "ERROR: invalid command, type 'help' for a list of commands" << endl;
		}
	} 

	
	

	//cout << "ERROR: Records are full." << std::endl;
	//cout << "ERROR: " << firstName << " " << lastName << " cannot hold any more scores." << std::endl;
}

int *spaceIndexes(string fullCommand) {
		int placeHolder[5];
		int count = 0;
		for (int i = 0; i < fullCommand.length(); i++) {
			if (fullCommand[i] == ' ')
			{
				placeHolder[count] = i;
				count++;
			}
		}
		
		return new int[count];
	}

