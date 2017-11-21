#include "records.h"
#include <string>
#include <iostream>
#include <strstream>

using namespace std;

void strToLower(string&);

void main()
{
	Records record;
	string command;
	string fullCommand;
	strstream command_stream;

	cout << "Student Record Manager 2017" << endl;
	cout << "type 'help' for help, type 'quit' to quit" << endl << endl;

	//  main program loop, runs until user types quit
	while (command !="quit") {
		command_stream.clear();
		//  prompt user for input, and retreive full line of input, removing case sensitivity
		cout << "SRM> ";

		getline(cin, fullCommand);
		strToLower(fullCommand);
		command_stream << fullCommand;
		command_stream >> command;


		if (command == "addstudent") {


			//  get arguments to pass into functions
			string first_name, last_name;
			command_stream >> first_name >> last_name;
			if (!command_stream) {
				cout << "ERROR: Invalid arguments. Type help to see valid syntax." << endl;
				cin.clear();
			} else {
			int status = record.add_student(first_name, last_name);
			
			//switch error statuses
			switch (status)
			{
			case 0:
				break;
			case 1:
				cout << "ERROR: Records are full." << endl;
				break;
			case 2:
				cout << "ERROR: student record already exists" << endl;
				break;
			default:
				cout << "ERROR: unknown error occured" << endl;
				break;
			}
			}
				
			

		}
		else if (command == "addscore") {
			
			//  get arguments to pass into functions
			string first_name, last_name;
			float score = 0;

			command_stream >> first_name >> last_name >> score;
			if (!command_stream || score < 0) {
				cout << "ERROR: Invalid argument list. type help to see valid syntax" << endl;
				cin.clear();
				continue;
			}
			else {

				//  call method to add score and send error on failure
				bool success = record.add_score(first_name, last_name, score);
				if (!success)
				{
					cout << "ERROR: " << first_name << " " << last_name << " could not be found, or cannot hold more scores" << std::endl;
				}
			}
		}
		else if (command == "print") {
			//  print column headers, then print names and scores for each student on a row
			cout << "First name\tLast name\tScores\n";
			cout << "------------------------------------------" << endl;
			for (int i = 0; i < record.get_count(); i++)
			{
				cout << record[i].firstname << ((record[i].firstname.length() < 8) ? "\t\t" : "\t") 
					<< record[i].lastname << ((record[i].lastname.length() < 8) ? "\t\t" : "\t");

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
			//  save current record object to file specified
			string filename;
			bool status;
			command_stream >> filename;
			status = record.save(filename);

			if (status) {
				cout << "ERROR: there was a problem saving the file" << endl;
			}
		}
		else if (command == "load")
		{
			//  load specified file into current record object
			string filename;
			bool status;
			command_stream >> filename;
			status = record.load(filename);
			if (status)
			{
				cout << "ERROR: there was a problem loading the file" << endl;
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

