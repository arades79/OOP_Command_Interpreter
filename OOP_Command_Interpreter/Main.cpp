#include "records.h"
#include <string>
#include <iostream>

using namespace std;

void strToLower(string&);

void main()
{
	Records record;
	string command;

	cout << "Student Record Manager 2017" << endl;
	cout << "type 'help' for help, type 'quit' to quit" << endl << endl;

	//  main program loop, runs until user types quit
	while (command !="quit") {
		//  prompt user for input, and retreive full line of input, removing case sensitivity
		cout << "SRM> ";

		cin >> command;
		strToLower(command);


		if (command == "addstudent") {

			//  split arguments up to pass into functions
			string first_name, last_name;
			cin >> first_name >> last_name;
			bool success = record.add_student(first_name, last_name);
			
			//call method to add student and send error on failure
			if (!success) {
				cout << "ERROR: Records are full." << std::endl;
			}

		}
		else if (command == "addscore") {
			
			//  split arguments up to pass into functions
			string first_name, last_name;
			float score;

			cin >> first_name >> last_name >> score;

			//  call method to add score and send error on failure
			bool success = record.add_score(first_name, last_name, score);
			if (!success)
			{
				cout << "ERROR: " << first_name << " " << last_name << " could not be found, or cannot hold more scores" << std::endl;
			}
		}
		else if (command == "print") {
			//  print column headers, then print names and scores for each student on a row
			cout << "First name\tLast name\tScores\n";
			cout << "------------------------------------------" << endl;
			for (int i = 0; i < record.get_count(); i++)
			{
				cout << record[i].firstname << ((record[i].firstname.length() < 8) ? "\t\t" : "\t") << record[i].lastname << ((record[i].lastname.length() < 8) ? "\t\t" : "\t");
				if (!(record[i].count == 0))
				{
					for (int j = 0; j < record[i].count; j++)
					{
						cout << record[i].scores[j] << "\t";
					}
				}
				cout << endl;
			}
			cout << endl;
		}
		else if (command == "save")
		{
			string filename;
			cin >> filename;
			record.save(filename);
		}
		else if (command == "load")
		{
			string filename;
			cin >> filename;
			if (!record.load(filename))
			{
				cout << "ERROR: file contained duplicate entries" << endl;
			}
		}
		else if (command == "help") {

			//  display help dialog including commands, syntax, and purpose
			cout << endl;
			cout << "addstudent firstname lastname\ncreates a new student entry in the database\n\n";
			cout << "addscore firstname lastname score\ncreates a new score entry for the matching student\n\n";
			cout << "print\nprint out the contents of the database tab separeted row by row\n\n";
			cout << "save filename\nsave current record to a file\n\n";
			cout << "load filename\nload file into current record\n\n";
		}
		else if (command.empty());
		else {
			cout << "invalid command, type 'help' for a list of commands" << endl;
		}
	}
}


//  function to convert full string to lower case to remove case sensitivity
void strToLower(string& input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}
}

