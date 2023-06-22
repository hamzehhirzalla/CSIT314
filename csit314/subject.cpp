#include"subject.h"
subject::subject(string name, int code) {
	this->name = name;
	this->code = code;
}

int subject::getCode()
{
	return code;
}
string subject::getName() {
	return name;
}
