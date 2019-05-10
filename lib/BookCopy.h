#ifndef BOOKCOPY_H
#define BOOKCOPY_H

#include <bits/stdc++.h>
#include <chrono>

namespace MyLibrary
{

class BookCopy
{
public:
    BookCopy();
    ~BookCopy();

    int Id;
    int TitleId;
    int Shelf;
    int BorrowerId;
	std::chrono::system_clock::time_point StartDate;
	std::chrono::system_clock::time_point DueDate;
};
}

#endif // BOOKCOPY_H
