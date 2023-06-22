#include "teacher.h"
#include"database.h"
teacher::teacher(int id,const string& name, const string& email, string password)
    : user(id,name, email, "Teacher",password) {
}
int teacher::menu() {
    
    int choice;
    while (true) {
        cout << "***********************" << endl;
        cout << "* 0. log out          *" << endl;
        cout << "* 1. view messages    *" << endl;
        cout << "* 2. send messages    *" << endl;
        cout << "* 3. assign exam      *" << endl;
        cout << "* 4. change password  *" << endl;
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
            ClearScreen();
            assignExam();
            break;
        case 4:
            ClearScreen();
            changePassword();
            break;
        default:
            ClearScreen();
            cout << "plase enter a number between 0 and 4" << endl;
            break;
        }
    }
    return choice;
}
void teacher::addSubject(subject s) {
    listOfSubjects.push_back(s);
}

int teacher::assignExam()
{
    if (listOfSubjects.size() == 0) {
        ClearScreen();
        cout << "you are not enrolled in any subject" << endl;
        return 0;
    }
    int counter=1;
    cout << "for which subject" << endl;
    cout << left << setw(7) << "ID"
        << setw(15) << "Name"
        << setw(15) << "Code" << endl;
    for (int i = 0; i < this->listOfSubjects.size(); i++)
    {
        cout << left << setw(7) << counter
            << setw(15) << listOfSubjects[i].getName()
            << setw(15) << listOfSubjects[i].getCode() << endl;
        counter++;
    }
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
        bool status = true;
        while (status == true)
        {
            if (choice <= 0 || choice > counter - 1) {
                cout << "please enter the correct ID " << endl;
                cin >> choice;
            }
            else {
                status = false;
            }
        }
    }
    bool status = true;
    while (status == true)
    {
        if (choice <= 0 || choice > counter - 1) {
            cout << "please enter the correct ID " << endl;
            cin >> choice;
        }
        else {
            status = false;
        }
    }
    
    ClearScreen();


    cout << "choose the exam ID" << endl;
    cout << left << setw(8) << "ID"
        << setw(15) << "Type"
        << setw(15) << "subject code" << endl;
    counter = 1;
    vector<exam>exams;
    for (exam& e : database::allExams) {
        if (e.getSubjectcode() == listOfSubjects[choice - 1].getCode()) {
            cout << left << setw(8) << counter
                << setw(15) << e.getExamType()
                << setw(15) << e.getSubjectcode() << endl;
            exams.push_back(e);
            counter++;
        }

    }

    if (counter == 1) {
        ClearScreen();
        cout << "there are no exams in the system" << endl;
        cout << "please contact the id deprtment" << endl;
        return 0;
    }
    if(!(cin >> choice)) {
        cout << "Invalid input. Please enter a valid integer " << endl;;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a valid integer " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    status = true;
    while (status==true)
    {
        if (choice <= 0 || choice > counter - 1) {
            cout << "please enter the correct ID " << endl;
            cin >> choice;
        }
        else 
        {
            status = false;
        }
    }
    
    for ( student& s : database::students) {
        {
            bool status =s.checkSubejct(listOfSubjects[choice - 1].getCode());
            if (status == true) {
                s.addExam(exams[choice - 1]);
                
            }
        }
    }
    ClearScreen();
    cout << "the exam has been assigned to the students assignes in the subject" << endl;
    
    
}

void teacher::printSubjects()
{
    for (int i = 0; i < listOfSubjects.size(); i++)
    {
        cout << listOfSubjects[i].getName() << endl;
    }
}

