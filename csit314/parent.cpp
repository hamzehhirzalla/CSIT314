#include "parent.h"
#include"database.h"

parent::parent(int id,const std::string& name, const std::string& email, string password)
    : user(id,name, email, "Parent",password) {
}

int parent::menu() {
    
    int choice;
    while (true) {
        cout << "***********************" << endl;
        cout << "* 0. log out          *" << endl;
        cout << "* 1. view messages    *" << endl;
        cout << "* 2. send messages    *" << endl;
        cout << "* 3. check student    *" << endl;
        cout << "* 4. change password  *" << endl;
        cout << "***********************" << endl;
        cout << "Enter an integer: ";
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
            this->readMessages();
            Continue();
            break;
        case 2:
            ClearScreen();
            this->sendMessage();
            break;
        case 3:
            ClearScreen();
            this->checkStudent();
            break;
        case 4:
            ClearScreen();
            changePassword();
            break;
        default:
            ClearScreen();
            cout << "please enter a number between 0 and 4" << endl;
            break;
        }
        
    }


}
void parent::addStudent(student s) {
    listOfStudents.push_back(s);
}

void parent::printChildrens()
{
    for (int i = 0; i < listOfStudents.size(); i++)
    {
        cout << i + 1 << " " << listOfStudents[i].getName() << " " << listOfStudents[i].getID() << endl;
    }
}

void parent::checkStudent()
{
    int counter = 1;
    int choice;
    int status = false;
    std::cout << std::left  << std::setw(20) << "Student ID" << "Student Name" << std::endl;
    for (int i = 0; i < listOfStudents.size(); i++) {
        std::cout << std::setw(20) << listOfStudents[i].getID() << listOfStudents[i].getName() << std::endl;
    }
    cout << "enter your child ID" << endl;
    while (!(cin >> choice)) {
        ClearScreen();
        cout << "Invalid input. Please enter a valid integer " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    bool found = false;
    int index = -1;

    for (int i = 0; i < listOfStudents.size(); i++) {
        if (choice == listOfStudents[i].getID()) {
            found = true;
            index = i;
            break;
        }
    }
    student child;
    if (found == true) 
    {
        for (int i = 0; i < database::students.size(); i++)
        {
            if (database::students[i].getID() == listOfStudents[index].getID()) 
            {
                child = database::students[i];
            }
        }
    }
    if (!found) {
        ClearScreen();
        cout << "Wrong ID" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        checkStudent();
    }
    else {
        ClearScreen();
        cout << "The results of your child: " << endl;
        child.checkResults();
        cout << endl << endl;
        cout << "The messages that your child has: " << endl;
        child.readMessages();
        Continue();
    }
}


