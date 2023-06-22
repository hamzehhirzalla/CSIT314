#pragma once
#include<string>
using std::string;
class grade
{
public:
	grade(string quizName,string subjectName,int subjectCode,double result);
	string getQuizName() const;
	string getSubjectName() const;
	int getSubjectCode() const;
	double getResult() const;

private:
	string quizName;
	string subjectName;
	int subjectCode;
	double result;

};


