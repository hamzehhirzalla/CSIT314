#pragma once

#include "student.h"
#include "teacher.h"
#include "parent.h"
#include"exam.h";
#include"subject.h"
#include "admin.h"
class admin;
class database {
public:
    static vector<user> allusers;
    static vector<exam> allExams;
    static vector<student> students;
    static vector<teacher> teachers;
    static vector<parent> parents;
    static vector<admin> admins;
    static vector<subject> allSubjects;
    static void setRoles();
};





extern student student1;
extern student student2;
extern student student3;
extern teacher teacher1;
extern parent parent1;
extern student student4;
extern student student5;
extern teacher teacher2;
extern parent parent2;
extern student student6;
extern teacher teacher3;
extern teacher teacher4;
extern parent parent3;

extern subject subject1;
extern subject subject2;
extern subject subject3;
extern subject subject4;
extern subject subject5;
extern subject subject6;
extern subject subject7;
extern subject subject8;
extern subject subject9;
extern subject subject10;