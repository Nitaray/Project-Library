#ifndef MANAGER_H
#define MANAGER_H

#include <bits/stdc++.h>

namespace MyLibrary
{

class Manager
{
public:
	Manager();
	~Manager();

	int Id;
	std::string Username;
	std::string Fullname;
	std::string Password;
};

}

#endif // MANAGER_H
