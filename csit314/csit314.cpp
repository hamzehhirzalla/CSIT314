// csit314.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "user.h"
#include "student.h"
#include "teacher.h"
#include "parent.h"
#include"subject.h"
#include "database.h"

using namespace std;

//global variable

user *loggeduser;



void login() {
    int ID;
    string password;

    
    cout << endl << endl;
    bool status = true;
    while (status == true) {
        cout << "********************************" << endl;
        cout << "* welcome to our system        *" << endl;
        cout << "* please login to your account *" << endl;
        cout << "********************************" << endl;
        cout << "ID: ";
        while (!(cin >> ID)) {

            cout << "Invalid input. Please enter a valid integer ID: " << endl;;
            cout << "ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        cout << "password: ";
        cin >> password;
        
        for (int i = 0; i < database::students.size(); i++)
        {
            if (database::students[i].getID() == ID && database::students[i].getPassword() == password) {
                loggeduser = &database::students[i];
                status = false;
                break;
            }
        }
        for (int i = 0; i < database::teachers.size(); i++)
        {
            if (database::teachers[i].getID() == ID && database::teachers[i].getPassword() == password) {
                loggeduser = &database::teachers[i];
                status = false;
                break;
            }
        }
        for (int i = 0; i < database::parents.size(); i++)
        {
            if (database::parents[i].getID() == ID && database::parents[i].getPassword() == password) {
                loggeduser = &database::parents[i];
                status = false;
                break;
            }
        }
        for (int i = 0; i < database::admins.size(); i++)
        {
            if (database::admins[i].getID() == ID && database::admins[i].getPassword() == password) {
                loggeduser = &database::admins[i];
                status = false;
                break;
            }
        }
        if (status == true) {
            system("cls");
            cout << "wrong username or password please try again" << endl;
        }
              
    }
    system("cls");
    cout << "welcome " << loggeduser->getName() << endl;
    cout << "you have " << loggeduser->numberOfMessages() << " messages in your inbox" << endl;
}


void configurations() {
   
    database::setRoles();
}


int main()
{
    //configuration
    configurations();
    while (true)
    {    
        login();

        loggeduser->menu();
        
        

    }
    
    delete loggeduser;

}
