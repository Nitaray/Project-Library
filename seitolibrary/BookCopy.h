#ifndef BOOKCOPY_H
#define BOOKCOPY_H

namespace MyLibrary
{

class BookCopy
{
public:
    BookCopy();
    ~BookCopy();

    int _CopyId;
    int _TitleId;
    int _Shelf;
    int _AccountId;
	std::time_t _StartDate;
	std::time_t _DueDate;
};
}

#endif // BOOKCOPY_H
