#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <bits/stdc++.h>

namespace MyLibrary
{

class Account
{
public:
    Account();
    ~Account();
	
    int _AccountId;
    std::string _Name;
    std::string _Password;
};
}

#endif // ACCOUNT_H
