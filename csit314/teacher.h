#pragma once
#include<string>
#include <vector>
#include"user.h"
#include"subject.h";
using std::string;
using std::vector;

class teacher :public user
{
public:

	teacher(int id,const std::string& name, const std::string& email,string password);
	int menu() override;
	void addSubject(subject s);
	int assignExam() override;
	void printSubjects();
private:
	vector<subject> listOfSubjects;

};

