#ifndef BOOKCOPY_H
#define BOOKCOPY_H

#include <bits/stdc++.h>

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
	std::time_t StartDate;
	std::time_t DueDate;
};
}

#endif // BOOKCOPY_H
