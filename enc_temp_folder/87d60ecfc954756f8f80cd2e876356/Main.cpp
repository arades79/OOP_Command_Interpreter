#include "records.h"
#include <string>
#include <iostream>

using namespace std;

void strToLower(string&);

void main()
{
	string full_command;
	Records record;

	cout << "Student Record Manager 2017" << endl;
	cout << "type 'help' for help, type 'quit' to quit" << endl;

	while (true) {
		cout << "SRM>";
		getline(cin, full_command);
		strToLower(full_command);

		string command = full_command.substr(0, full_command.find_first_of(' '));


		if (command == "addstudent") {
			string args = full_command.substr(full_command.find_first_of(' ') + 1, full_command.length() - 1);
			int first_space = args.find_first_of(' ');
			string first_name = args.substr(0, first_space);
			string last_name = args.substr(first_space + 1, args.length() - 1);
			bool success = record.add_student(first_name, last_name);
			
			if (!success) {
				cout << "ERROR: Records are full." << std::endl;
			}

		}
		else if (command == "addscore") {
			
			string args = full_command.substr(full_command.find_first_of(' ') + 1, full_command.length() - 1);
			int first_space = args.find_first_of(' ');
			int last_space = args.find_last_of(' ');
			string first_name = args.substr(0, first_space);
			string last_name = args.substr(first_space + 1, last_space);
			string score_str = args.substr(last_space + 1, args.length() - 1);
			float score = stof(score_str);

			bool success = record.add_score(first_name, last_name, score);
			if (!success)
			{
				cout << "ERROR: " << first_name << " " << last_name << " could not be found, or cannot hold more scores" << std::endl;
			}
		}
		else if (command == "print") {
			for (int i = 0; i < record.get_count(); i++)
			{
				Student student = record[i];
				cout << student.firstname << "\t" << student.lastname << "\t";
				if (!student.count == 0)
				{
					for (int j = 0; j < student.count; j++)
					{
						cout << student.scores[i] << "\t";
					}
				}
				cout << endl;
			}
		}
		else if (command == "help") {

		}
		else if (command == "quit" || command == "exit") {
			return;
		}
		else if (command.empty());
		else {
			cout << "ERROR: invalid command, type 'help' for a list of commands" << endl;
		}
	}
}


void strToLower(string& input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		tolower(input[i]);
	}
}

