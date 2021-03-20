#include "Client.h"

Client::Client(int code, string name)
{
	this->code = code;
	this->name = name;
}

string Client::GetName()
{
	return this->name;
}

int Client::GetCode()
{
	return this->code;
}
