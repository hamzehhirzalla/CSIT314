#pragma once
#include<string>
#include<vector>
#include"user.h"
#include"subject.h"
#include"exam.h"
#include"grade.h"
using std::string;
class student :public user
{
public:
    student() = default;
    student(int id,const std::string& name, const std::string& email, string password);
    int menu() override;
    void addSubject(subject s);
    bool checkSubejct(int subjectCode);
    void addExam(exam e);
    void makequiz(exam e);
    void checkExam();
    void addGrade(grade g);
    void checkResults();
private:
    vector<subject> listOfSubjects;
    vector<exam> exams;
    vector<grade> studentGrades;
};