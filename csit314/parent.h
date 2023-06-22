#pragma once
#include<string>
#include<vector>
#include"student.h"
#include"user.h"

using std::string;
using std::vector;
class parent :public user
{
public:
	parent() = default;
	parent(int id,const std::string& name, const std::string& email, string password);
	int menu() override;
	void addStudent(student s);
	void printChildrens();
	void checkStudent();
private:
	vector<student>listOfStudents;
};

