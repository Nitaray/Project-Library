#ifndef BORROWLOG_H
#define BORROWLOG_H

namespace MyLibrary
{

class BorrowLog
{
public:
	BorrowLog();
	~BorrowLog();
	
	int _CopyId;
	int _AccountId;
	std::time_t _ReturnDate;
	
};

}

#endif // BORROWLOG_H
