#include "user.h"
#include <string>
#include"database.h"

user::user(int id, const std::string& name, const std::string& email, const std::string& role, string password)
	: id(id), name(name), email(email), role(role), password(password) {
}

std::string user::getName() const {
	return name;
}

std::string user::getEmail() const {
	return email;
}

std::string user::getRole() const {
	return role;
}
std::string user::getPassword() const {
	return password;
}

int user::getID() const
{
	return id;
}
void user::Continue() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string user_input;
	cout << "Please press anything to continue: ";
	getline(std::cin, user_input);
	system("cls");
}
void user::ClearScreen() {
	system("cls");
}
int user::numberOfMessages()
{
	string line;
	int counter = 0;
	ifstream inputFile("messages.txt");
	if (inputFile.is_open()) {

		while (getline(inputFile, line)) {
			istringstream iss(line);
			string name;
			int id;
			string senderName;
			string senderID;
			string message;

			iss >> name >> id >> senderName >> senderID;
			getline(iss, message);
			if (id == this->id) {
				counter++;

			}
		}
	}
	return counter;
}


void user::deleteMessage(int line)
{
	int lines = 0;
	std::ifstream inputFile("messages.txt");
	std::ofstream outputFile("temp.txt");

	std::string text;
	int lineNumber = 1;

	while (std::getline(inputFile, text)) {

		if (lineNumber != line) {
			outputFile << text << std::endl;
		}
		lineNumber++;
	}


	inputFile.close();
	outputFile.close();

	std::remove("messages.txt");
	std::rename("temp.txt", "messages.txt");
	ClearScreen();
	cout << "your message has been deleted" << endl;
}

void user::changePassword()
{
	string password;
	cout << "enter your current Password" << endl;
	cin >> password;
	if (this->password == password) {
		ClearScreen();
		cout << "enter your new password" << endl;
		cin >> password;
		this->password = password;
		ClearScreen();
		cout << "your password has been changed successfully" << endl;
		Continue();
	}
	else {
		ClearScreen();
		cout << "the password you entered doesnt match your current password" << endl;
	}

}

void user::readMessages() {
	ifstream inputFile("messages.txt");
	bool status = false;
	int lines = 0;
	vector<int> location;
	if (inputFile.is_open()) {
		string line;
		int counter = 0;
		while (getline(inputFile, line)) {
			lines++;
			istringstream iss(line);
			string name;
			int id;
			string senderName;
			string senderID;
			string message;

			iss >> name >> id >> senderName >> senderID;
			getline(iss, message);
			if (id == this->id) {
				counter++;
				location.push_back(lines);
				cout << "message " << counter << endl;
				cout << "senderName: " << senderName << std::endl;
				cout << "senderID: " << senderID << std::endl;
				cout << "Message: " << message << std::endl;
				cout << "************************" << endl;
				status = true;
			}
		}
	}
	else {
		cout << "Unable to open the file." << std::endl;
	}
	inputFile.close();
	if (status == true)
	{
		cout << "do you want to delete a message" << endl;
		cout << "1. yes" << endl;
		cout << "2. no" << endl;
		int choice;
		if (!(cin >> choice)) {

			cout << "Invalid input. Please enter a valid integer " << endl;;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			while (!(cin >> choice)) {
				cout << "Invalid input. Please enter a valid integer " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		while (status == true)
		{
			if (choice <= 0 || choice > 2) {

				cout << "please enter a number between 1 and 2" << endl;
				menu();
			}
			else
			{
				break;
			}
		}
		if (choice == 1) {
			cout << "enter the message number" << endl;
			if (!(cin >> choice)) {

				cout << "Invalid input. Please enter a valid integer " << endl;;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				while (!(cin >> choice)) {

					cout << "Invalid input. Please enter a valid integer " << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			if (choice <= 0 || choice > numberOfMessages()) {
				ClearScreen();
				cout << "please enter a number between 1 and " << numberOfMessages() << endl;
				menu();
			}
			else
			{

				deleteMessage(location[choice - 1]);
			}

		}
	}
	if (status == false) {
		cout << "you have no messages" << endl;
	}
}

int user::assignExam()
{
	cout << "this is the user class" << endl;
	return 0;
}

int user::menu()
{
	cout << "this is the user class" << endl;
	return 0;
}

void user::sendMessage() {


	cout << "who do you want to send your message to " << endl;
	cout << setw(5) << left << "ID" << setw(10) << "Name" << "Role" << endl; // Header row

	for (int i = 0; i < database::allusers.size(); i++)
	{
		cout << setw(5) << left << database::allusers[i].getID() << setw(10) << database::allusers[i].getName() << database::allusers[i].getRole() << endl;
	}


	cout << "enter the reciever id" << endl;
	int id;
	if (!(cin >> id)) {
		cout << "Invalid input. Please enter a valid integer: " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while (!(cin >> id)) {
			cout << "Invalid input. Please enter a valid integer " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

	}
	auto it = find_if(database::allusers.begin(), database::allusers.end(), [&](const user& user) {
		return user.getID() == id;
		});

	if (it != database::allusers.end()) {
		ClearScreen();
		cout << "User found! Name: " << it->getName() << endl;
		cout << "write your message " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string message;
		getline(cin, message);


		ofstream outputFile("messages.txt", std::ios::app);

		if (outputFile.is_open()) {
			string content = it->getName() + " " + std::to_string(it->getID()) + " " + this->name + " " + std::to_string(this->id) + " " + message;

			outputFile << content << endl;
			outputFile.close();  // Close the file
			ClearScreen();
			std::cout << "your message has been sent." << std::endl;
		}
		else {
			std::cout << "Unable to open the file." << std::endl;
		}
	}
	else {
		ClearScreen();
		cout << "User not found!" << endl;
	}

}



