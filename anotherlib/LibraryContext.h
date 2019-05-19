#ifndef LIBRARYCONTEXT_H
#define LIBRARYCONTEXT_H

#include <bits/stdc++.h>

#include "Manager.h"
#include "BookCopy.h"
#include "BookTitle.h"
#include "BorrowLog.h"
#include "Student.h"

namespace MyLibrary
{

class LibraryContext
{
private:
    std::map<int,Student> _StudentStorage;
	std::map<int,Manager> _ManagerStorage;
	std::map<int,BookTitle> _TitleStorage;
	std::map<int,BookCopy> _CopyStorage;
	std::map<int,BorrowLog> _LogStorage;
	
	std::map<std::string, Student> _StudentUsernameIndex;
	std::map<std::string, Manager> _ManagerUsernameIndex;
	std::set<std::string> _UsernameIndex;
	
	std::set<std::tuple<std::string, int>> _TitleNameIndex;
	std::set<std::tuple<std::string, int>> _TitleAuthorIndex;
	std::set<std::tuple<int, int>> _CopyTitleIdIndex;
	std::set<std::tuple<int, int>> _CopyBorrowerIdIndex;

public:
    LibraryContext();
    ~LibraryContext();

    void readData();
    void writeData();

    bool addManager(Manager manager);
    bool addStudent(Student student);
    bool addTitle(BookTitle title);
    bool addCopy(BookCopy bcopy);
    bool addLog(BorrowLog brlog);
	
    void removeTitle(int id);
	void removeCopy(int id);
	
	bool updateCopy(BookCopy bcopy);

    int makeBorrow(int sid, int cid);
    int releaseBorrow(int sid, int cid);
	std::string getDate(int cid, bool type);
	
    std::shared_ptr<Student> getStudent(int id);
    std::shared_ptr<BookTitle> getTitle(int id);
    std::shared_ptr<BookCopy> getCopy(int id);

    std::shared_ptr<Manager> getManager(std::string username);
    std::shared_ptr<Student> getStudent(std::string username);

    std::shared_ptr<std::list<BookTitle>> getTitles();
    std::shared_ptr<std::list<BookTitle>> getTitles(std::string pattern);
	std::shared_ptr<std::list<int>> getCopyIdsByTitleId(int id);
    std::shared_ptr<std::list<BookCopy>> getFreeCopiesByTitleId(int id);
    std::shared_ptr<std::list<BookCopy>> getCopiesByBorrowerId(int id); 

};
}

#endif // LIBRARYCONTEXT_H
