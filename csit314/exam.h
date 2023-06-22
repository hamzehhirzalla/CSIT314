#pragma once
#include<string>
using std::string;
class exam
{
public:
	exam(string subjectName, string filename,int subjectcode,string examType);
	string getFilename();
	int getSubjectcode();
	string getExamType();
	string getSubjectName();

private:
	string subjectName;
	string filename;
	string examType;
	int subjectcode;
};


