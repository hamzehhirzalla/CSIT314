#pragma once
#include<string>
using std::string;
class subject
{
public:
	subject(string name, int code);
	string getName();
	int getCode();
private:
	string name;
	int code;
};
