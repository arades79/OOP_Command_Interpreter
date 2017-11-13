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
	delete this;
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
	for (int i = 0; i < count; i++) {
		delete &student[i];
	}
	delete this;
}

bool Records::add_student(std::string firstName, std::string lastName)
{
	if (count < NUM_STUDENTS) {
		student[count] = Student(firstName, lastName);
		count++;
		return true;
	} else {
		return false;
	}

}

bool Records::add_score(std::string firstName, std::string lastName, float score)
{
	for (int i = 0; i < count; i++) {
		if (firstName == student[i].firstname && lastName == student[i].lastname) {

			if (student[i].add_score(score)) {
				return true;
			} else {
				return false;
			}
		}
	}
}

Student& Records::operator[](int index)
{
	return student[index];
}