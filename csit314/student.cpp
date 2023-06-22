#include "student.h"

student::student(int id, const std::string& name, const std::string& email, string password)
	: user(id, name, email, "Student", password) {
}
int student::menu() {

	int choice;
	while (true) {
		cout << "please choose your option" << endl;
		cout << "***********************" << endl;
		cout << "* 0. log out          *" << endl;
		cout << "* 1. view messages    *" << endl;
		cout << "* 2. send messages    *" << endl;
		cout << "* 3. check exams      *" << endl;
		cout << "* 4. check results    *" << endl;
		cout << "* 5. change password  *" << endl;
		cout << "***********************" << endl;
		if (!(cin >> choice)) {
			ClearScreen();
			cout << "Invalid input. Please enter a valid integer " << endl;;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			menu();
		}

		switch (choice)
		{
		case 0:
			ClearScreen();
			return 0;
		case 1:
			ClearScreen();
			readMessages();

			Continue();
			break;
		case 2:
			ClearScreen();
			sendMessage();

			break;
		case 3:
			checkExam();

			break;
		case 4:
			ClearScreen();
			checkResults();
			Continue();
			break;
		case 5:
			ClearScreen();
			changePassword();
			break;
		default:
			ClearScreen();
			cout << "please enter a number between 0 and 5" << endl;
			break;
		}
	}

}
void student::addSubject(subject s) {
	listOfSubjects.push_back(s);
}

bool student::checkSubejct(int subjeccode)
{
	for (int i = 0; i < listOfSubjects.size(); i++)
	{
		if (listOfSubjects[i].getCode() == subjeccode)return true;
	}
	return false;
}

void student::addExam(exam e)
{
	exams.push_back(e);
}

void student::makequiz(exam e) {

	std::ifstream quizFile(e.getFilename());
	if (!quizFile) {
		std::cout << "file not opening." << std::endl;

	}

	int counter = 0;
	int result = 0;
	std::string questionHeader;
	std::string question;
	std::string optionA;
	std::string optionB;
	std::string optionC;
	std::string optionD;
	string answer;

	while (std::getline(quizFile, questionHeader) && std::getline(quizFile, question) &&
		std::getline(quizFile, optionA) && std::getline(quizFile, optionB) &&
		std::getline(quizFile, optionC) && std::getline(quizFile, optionD) && std::getline(quizFile, answer)) {
		counter++;
		// Display the current question
		std::cout << questionHeader << std::endl;
		std::cout << question << std::endl;
		std::cout << optionA << std::endl;
		std::cout << optionB << std::endl;
		std::cout << optionC << std::endl;
		std::cout << optionD << std::endl;

		char userAnswer;
		std::cout << "Enter your answer (A, B, C, or D): ";
		std::cin >> userAnswer;
		std::cout << std::endl;

		userAnswer = std::tolower(userAnswer);


		if (userAnswer == answer[0]) {
			std::cout << "Correct!" << std::endl;
			result++;
		}
		else {
			std::cout << "Incorrect! The correct answer is " << answer << "." << std::endl;
		}

		std::cout << std::endl;
	}

	this->addGrade(grade(e.getExamType(), e.getSubjectName(), e.getSubjectcode(),
		(((double)result / (double)counter) * 10)));
	quizFile.close();
	cout << "you have finished your exam " << endl;
	Continue();
	ClearScreen();

}

void student::checkExam()
{

	int counter = 1;
	int choice;
	ClearScreen();
	std::cout << "You have " << exams.size() << " exams." << std::endl;
	for (int i = 0; i < exams.size(); i++)
	{
		std::cout << counter << " " << exams[i].getExamType() << " " << exams[i].getSubjectName() << std::endl;
		counter++;
	}



	if (counter > 1) {
		std::cout << "Which one do you want to make? ";

		if (!(cin >> choice)) {
			cout << "Invalid input. Please enter a valid integer " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			while (!(cin >> choice)) {
				cout << "Invalid input. Please enter a valid integer " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		if (choice <= 0 || choice > counter - 1) {
			std::cout << "Invalid choice. Please enter a number between 1 and " << counter - 1 << "." << std::endl;
			while (!(cin >> choice)) {
				std::cout << "Invalid choice. Please enter a number between 1 and " << counter - 1 << "." << std::endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		ClearScreen();
		makequiz(exams[choice - 1]);
		exams.erase(exams.begin() + (choice - 1));
	}

	else
	{
		ClearScreen();
		cout << "you have no exams to do" << endl;
	}


}

void student::addGrade(grade g)
{
	studentGrades.push_back(g);
}

void student::checkResults()
{
	int counter = 0;
	std::cout << std::left << std::setw(10) << "Quiz" << std::setw(10) << "Subject" << "Result" << std::endl;
	for (const auto& g : studentGrades) {
		std::cout << std::setw(10) << g.getQuizName() << std::setw(10) << g.getSubjectName() << g.getResult()
			<< "/10" << std::endl;
		counter++;
	}
	if (counter == 0) {
		cout << "there is no results to display" << endl;
	}
}
