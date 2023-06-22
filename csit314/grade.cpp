#include"grade.h"
grade::grade(string quizName, string subjectName, int subjectCode, double result)
{
	this->quizName = quizName;
	this->subjectCode = subjectCode;
	this->subjectName = subjectName;
	this->result = result;
}
string grade::getQuizName() const {
	return quizName;
}

string grade::getSubjectName() const {
	return subjectName;
}

int grade::getSubjectCode() const {
	return subjectCode;
}

double grade::getResult() const {
	return result;
}