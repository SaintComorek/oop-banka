#pragma once
#include <string>

using namespace std;
class Client
{
public:
	Client(int code, string name);

	string GetName();
	int GetCode();

private:
	int code;
	string name;
};

