#include "records.h"
#include <string>
#include <iostream>

using namespace std;

int *spaceIndexes(string);

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
			string firstName = fullCommand.substr(spaces[0], spaces[1]);
			string lastName = fullCommand.substr(spaces[1], fullCommand.length());
			record.add_student(firstName, lastName);
		}
		else if (command == "addscore") {
			int *spaces = spaceIndexes(fullCommand);
			string firstName = fullCommand.substr(spaces[0], spaces[1]);
			string lastName = fullCommand.substr(spaces[1], spaces[2]);
			float score = ::atof(fullCommand.substr(spaces[2], fullCommand.length()).c_str());
			record.add_score(firstName, lastName, score);
		}
		else if (command == "print") {

		}
		else if (command == "help") {

		}
		else if (command == "quit" || command == "exit") {
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

