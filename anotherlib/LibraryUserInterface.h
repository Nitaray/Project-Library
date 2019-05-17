#ifndef LIBRARYUSERINTERFACE_H
#define LIBRARYUSERINTERFACE_H

#include <bits/stdc++.h>

#include "Manager.h"
#include "BookCopy.h"
#include "BookTitle.h"
#include "BorrowLog.h"
#include "Student.h"
#include "LibraryContext.h"

namespace MyLibrary
{
class LibraryUserInterface
{
public:
	LibraryUserInterface();
	~LibraryUserInterface();
	void printMSG(std::string fileDir);
	void login();
	void run();
};
}

#endif // LIBRARYUSERINTERFACE_H
