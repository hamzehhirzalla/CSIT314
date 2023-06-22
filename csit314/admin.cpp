#include"admin.h"

admin::admin(int ID, string Password) : user(ID, "admin", "admin@example.com", "Admin", Password)
{
}
void admin::registerNewUSer()
{
    bool status = false;
    int id = database::allusers.size() + 2;
    string name;
    string email;
    string role;
    string password;
    int choice;
    cout << "enter the name:";
    cin >> name;
    cout << "enter the email:";
    cin >> email;
    cout << "enter the password:";
    cin >> password;
    cout << "select the role:" << endl;
    cout << "1.student" << endl;
    cout << "2.teacher" << endl;
    cout << "3.parent" << endl;
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
    if (choice <= 0 || choice > 3) {
        cout << "please enter a number between 1 and 3" << endl;
    }
    switch (choice) 
    {
    case 1:
        database::students.push_back(student(id, name, email, password));
        database::allusers.push_back(student(id, name, email, password));
        status = true;
        break;
    case 2:
        database::teachers.push_back(teacher(id, name, email, password));
        database::allusers.push_back(teacher(id, name, email, password));
        status = true;
        break;
    case 3:
        database::parents.push_back(parent(id, name, email, password));
        database::allusers.push_back(parent(id, name, email, password));
        status = true;
        break;
    default:
        ClearScreen();
        cout << "please enter a number between 1 and 3" << endl;
    }
    if (status == true) 
    {
        ClearScreen();
        cout << "user has been added to the system" << endl;
        cout << "the ID of the user is " << id << endl;
    }
    
}
int admin::menu()
{
    bool status = true;
    int choice;
    while (status==true) {
        cout << "**************************" << endl;
        cout << "* 0. log out             *" << endl;
        cout << "* 1. view messages       *" << endl;
        cout << "* 2. send messages       *" << endl;
        cout << "* 3. add user            *" << endl;
        cout << "* 4. add subject         *" << endl;
        cout << "* 5. print all students  *" << endl;
        cout << "* 6. print all teachers  *" << endl;
        cout << "* 7. print all parents   *" << endl;
        cout << "**************************" << endl;
        if (!(cin >> choice)) {
            ClearScreen();
            cout << "Invalid input. Please enter a valid integer " << endl;;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            while (!(cin >> choice)) {
                ClearScreen();
                cout << "Invalid input. Please enter a valid integer " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        
        switch (choice)
        {
        case 0:
            
            ClearScreen();
            cout << "Logged out" << endl;
            status = false;
            return 0;
            break;
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
            registerNewUSer();
            break;
        case 4:
            ClearScreen();
            addNewSubject();
            break;
        case 5:
            ClearScreen();
            viewStudents();
            break;
        case 6:
            ClearScreen();
            viewTeahers();
            break;
        case 7:
            ClearScreen();
            viewParents();
            break;
        default:
            ClearScreen();
            cout << "plase enter a number between 0 and 7" << endl;
            break;
        }
    }
    return choice;
}

void admin::addNewSubject()
{
    string name;
    int code;
    cout << "enter the subject name" << endl;
    cin >> name;
    cout << "enter the subject code" << endl;
    if (!(cin >> code)) {
        cout << "Invalid input. Please enter a valid integer " << endl;;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (!(cin >> code)) {
            cout << "Invalid input. Please enter a valid integer " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    bool status = true;
    for (int i = 0; i < database::allSubjects.size(); i++)
    {
        while (status == true) {
            if (database::allSubjects[i].getCode() == code) {
                ClearScreen();
                cout << "please choose another code" << endl;
                cin >> code;
            }
            else
            {
                status = false;
            }
        }
        
    }
    database::allSubjects.push_back(subject(name, code));
    ClearScreen();
    cout << "subject has been added successfully" << endl;

}

void admin::viewStudents() 
{
    for (int i = 0; i < database::students.size(); i++)
    {
        cout << database::students[i];
    }
    Continue();
}
void admin::viewTeahers()
{
    for (int i = 0; i < database::teachers.size(); i++)
    {
        cout << database::teachers[i];
    }
    Continue();
}
void admin::viewParents()
{
    for (int i = 0; i < database::parents.size(); i++)
    {
        cout << database::parents[i];
    }
    Continue();
}