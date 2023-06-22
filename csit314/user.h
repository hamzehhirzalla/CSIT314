#pragma once
#include<string>
#include <iostream>
#include<fstream>
#include <sstream>
#include <iomanip>
class database;
using namespace std;
class user {
protected:
    void ClearScreen();
    
    void Continue();
private:
    int id;
    string name;
    string email;
    string role;
    string password;
public:
    user(int id,const string& name, const string& email, const string& role,string password);
    user() = default;
    string getName() const;
    string getEmail() const;
    string getRole() const;
    string getPassword() const;
    int getID() const;
    void readMessages();
    virtual int assignExam();
    virtual int menu();
    void sendMessage();
    void deleteMessage(int line);
    void changePassword();
    //new
    int numberOfMessages();
    friend ostream& operator<<(ostream& os, const user& userObj) {
        os << "ID: " << userObj.id << endl;
        os << "Name: " << userObj.name << endl;
        os << "Email: " << userObj.email << endl;
        os << "Role: " << userObj.role << endl;

        return os;
    }
    
};
