#ifndef BORROWLOG_H
#define BORROWLOG_H

#include <bits/stdc++.h>

#include "Manager.h"
#include "BookCopy.h"
#include "BookTitle.h"
#include "Student.h"

namespace MyLibrary
{

class BorrowLog
{
public:
	BorrowLog();
	~BorrowLog();

	int Id;
	BookTitle Title;
	BookCopy Copy;
	Student Borrower;
	bool Fined;
};
}

#endif // BORROWLOG_H
