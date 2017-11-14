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
	Student(std::string, std::string);
	~Student();
	bool add_score(float);
};


class Records {
	Student students[NUM_STUDENTS];
	int count;
public:
	Records();
	~Records();
	bool add_student(std::string, std::string);
	bool add_score(std::string, std::string, float);
	inline int get_count() { return count; };
	inline Student& operator[](int index) { return students[index]; };
};
#endif

