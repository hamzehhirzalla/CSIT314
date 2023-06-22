#include "database.h"


vector<user> database::allusers;
vector<exam> database::allExams;
vector<subject> database::allSubjects;
vector<student> database::students;

vector<teacher> database::teachers;
vector<parent> database::parents;

vector<admin> database::admins;


// Create student objects
student student1(1, "Hamzeh", "hamzehm2003@gmail.com", "123456");
student student2(2, "Murad", "murad@gmail.com", "123456");
student student3(3, "Ahmed", "ahmed@gmail.com", "123456");
student student4(6, "Sarah", "sarah@gmail.com", "123456");
student student5(7, "Jennifer", "jennifer@gmail.com", "123456");
student student6(10, "Mark", "mark@gmail.com", "123456");

// Create teacher objects
teacher teacher1(4, "Manoj", "manoj@gmail.com", "123456");
teacher teacher2(8, "David", "david@gmail.com", "123456");
teacher teacher3(11, "John", "john@gmail.com", "123456");
teacher teacher4(12, "Lisa", "lisa@gmail.com", "123456");

// Create parent objects
parent parent1(5, "Marwan", "marwan@gmail.com", "123456");
parent parent2(9, "Emily", "emily@gmail.com", "123456");
parent parent3(13, "Rachel", "rachel@gmail.com", "123456");

//create subject opjects
subject subject1("Mathematics", 101);
subject subject2("English", 102);
subject subject3("Science", 103);
subject subject4("History", 104);
subject subject5("Geography", 105);
subject subject6("Physics", 106);
subject subject7("Chemistry", 107);
subject subject8("Biology", 108);
subject subject9("Computer Science", 109);
subject subject10("Art", 110);

//create exam objects
exam exam1("Mathematics", "exam1.txt", 101, "midterm");

admin adm(0, "0");
void database::setRoles() {
	
		//Assign subjects to students
		student1.addSubject(subject1);
		student1.addSubject(subject2);
		student1.addSubject(subject3);
		student1.addSubject(subject4);
		student1.addSubject(subject5);
		student1.addSubject(subject6);
		student1.addSubject(subject7);

		student2.addSubject(subject1);
		student2.addSubject(subject2);
		student2.addSubject(subject3);
		student2.addSubject(subject4);
		student2.addSubject(subject5);
		student2.addSubject(subject6);
		student2.addSubject(subject7);

		student3.addSubject(subject1);
		student3.addSubject(subject2);
		student3.addSubject(subject3);
		student3.addSubject(subject4);
		student3.addSubject(subject5);
		student3.addSubject(subject6);
		student3.addSubject(subject7);

		student4.addSubject(subject1);
		student4.addSubject(subject2);
		student4.addSubject(subject3);
		student4.addSubject(subject4);
		student4.addSubject(subject5);
		student4.addSubject(subject6);
		student4.addSubject(subject7);

		student5.addSubject(subject1);
		student5.addSubject(subject2);
		student5.addSubject(subject3);
		student5.addSubject(subject4);
		student5.addSubject(subject5);
		student5.addSubject(subject6);
		student5.addSubject(subject7);

		student6.addSubject(subject1);
		student6.addSubject(subject2);
		student6.addSubject(subject3);
		student6.addSubject(subject4);
		student6.addSubject(subject5);
		student6.addSubject(subject6);
		student6.addSubject(subject7);

		//Assign students to parents
		parent1.addStudent(student1);
		parent1.addStudent(student2);
		parent1.addStudent(student3);

		parent2.addStudent(student4);
		parent2.addStudent(student5);

		parent3.addStudent(student6);

		//Assign subjects to teachers
		teacher1.addSubject(subject1);
		teacher1.addSubject(subject2);
		teacher2.addSubject(subject1);
		teacher3.addSubject(subject3);
		teacher3.addSubject(subject4);
		teacher4.addSubject(subject2);
		teacher4.addSubject(subject3);
		teacher4.addSubject(subject4);


		
		students.push_back(student1);
		students.push_back(student2);
		students.push_back(student3);
		students.push_back(student4);
		students.push_back(student5);
		students.push_back(student6);

		teachers.push_back(teacher1);
		teachers.push_back(teacher2);
		teachers.push_back(teacher3);
		teachers.push_back(teacher4);

		parents.push_back(parent1);
		parents.push_back(parent2);
		parents.push_back(parent3);

		allusers.push_back(adm);

		allusers.push_back(student1);
		allusers.push_back(student2);
		allusers.push_back(student3);
		allusers.push_back(student4);
		allusers.push_back(student5);
		allusers.push_back(student6);

		allusers.push_back(teacher1);
		allusers.push_back(teacher2);
		allusers.push_back(teacher3);
		allusers.push_back(teacher4);

		allusers.push_back(parent1);
		allusers.push_back(parent2);
		allusers.push_back(parent3);

		allExams.push_back(exam1);
		allusers.push_back(adm);
		admins.push_back(adm);

		allSubjects.push_back(subject1);
		allSubjects.push_back(subject2);
		allSubjects.push_back(subject3);
		allSubjects.push_back(subject4);
		allSubjects.push_back(subject5);
		allSubjects.push_back(subject6);
		allSubjects.push_back(subject7);
		allSubjects.push_back(subject8);
		allSubjects.push_back(subject9);
		allSubjects.push_back(subject10);
		

}