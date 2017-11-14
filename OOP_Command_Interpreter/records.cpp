#include "records.h"

Student::Student()
{
	firstname = "";
	lastname = "";
	count = 0;
}

Student::Student(std::string firstName, std::string lastName)
{
	firstname = firstName;
	lastname = lastName;
	count = 0;
}

Student::~Student()
{
	
}

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


Records::Records()
{
	count = 0;
}

Records::~Records()
{

}

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
