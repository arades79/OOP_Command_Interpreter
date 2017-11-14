#include "records.h"

//  default constructor
Student::Student()
{
	firstname = "";
	lastname = "";
	count = 0;
}

//  alternate constructor for immediately inputting names
Student::Student(std::string firstName, std::string lastName)
{
	firstname = firstName;
	lastname = lastName;
	count = 0;
}

Student::~Student()
{
	
}

//  add score to score array and return success status
bool Student::add_score(float score)
{
	if (count < NUM_SCORES) {
		scores[count] = score;
		count++;
		return true;
	}
	else {
		return false;
	}
}

//  default constructor
Records::Records()
{
	count = 0;
}

Records::~Records()
{

}

//  add student to the student array with firstname and lastname if there's space and return the success status
bool Records::add_student(std::string firstName, std::string lastName)
{
	if (count < NUM_STUDENTS) {
		students[count] = Student(firstName, lastName);
		count++;
		return true;
	} else {
		return false;
	}

}

//  add score to student score array given a student full name
bool Records::add_score(std::string firstName, std::string lastName, float score)
{
	bool result = false;

	for (int i = 0; i < count; i++) {

		if (firstName == students[i].firstname && lastName == students[i].lastname) {

			result = students[i].add_score(score);
			break;

		}
	}
	return result;
}

bool Records::save(std::string filename)
{
	std::ofstream record_file;
	record_file.open(filename, std::ios::out);

	for (int i = 0; i < count; i++)
	{
		record_file << students[i].firstname << ' ' << students[i].lastname;
		for (int j = 0; j < students[i].count; j++)
		{
			record_file << ' ' << students[i].scores[j];
		}
		record_file << std::endl;
	}
	record_file.close();
}

bool Records::load(std::string filename)
{
	std::ifstream record_file;
	record_file.open(filename, std::ios::in);
}
