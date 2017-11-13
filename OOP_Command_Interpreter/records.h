#ifndef RECORDS_H
#define RECORDS_H

#define NUM_SCORES 5
#define NUM_STUDENTS 30

#include <string>

class Student {
public:
	int count;
	std::string firstname;
	std::string lastname;
	float scores[NUM_SCORES];
	Student();
	~Student();
	bool add_score(float);
};


class Records {
	Student student[NUM_STUDENTS];
	int count;
public:
	Records();
	~Records();
	bool add_student(std::string, std::string);
	bool add_score(std::string, std::string, float);
	int get_count() { return count; }
	Student& operator[](int);
};
#endif

