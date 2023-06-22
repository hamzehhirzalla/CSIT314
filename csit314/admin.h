#pragma once
#include"user.h"
#include"database.h"
class admin :public user
{
private:
	int ID;
	string password;

public:
	admin() = default;
	admin(int ID,string Password);

	void registerNewUSer();
	int menu() override;
    void addNewSubject();
	void viewStudents();
	void viewTeahers();
	void viewParents();
	
};



