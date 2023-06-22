#include"exam.h"
exam::exam(string subjectname,string filename,int subjectcode,string examtype)
{
	this->filename = filename;
	this->subjectName = subjectname;
	this->subjectcode = subjectcode;
	this->examType = examtype;
}



string exam::getFilename()
{
	return filename;
}

int exam::getSubjectcode()
{
	return subjectcode;
}

string exam::getExamType()
{
	return examType;
}

string exam::getSubjectName()
{
	return subjectName;
}
