#include "LibraryContext.h"
using namespace std;
using namespace MyLibrary;
MyLibrary::LibraryContext::LibraryContext()
{
}

MyLibrary::LibraryContext::~LibraryContext()
{
}

void MyLibrary::LibraryContext::readData()
{
	fstream inputfile;
	string filename;
	string emptyline;

	// add manager
	filename = "Resources\Managers.txt";
	inputfile.open(filename);

	Manager recentManager;

	while(!inputfile.eof()) {
		inputfile >> recentManager.Id;
		getline(inputfile, emptyline);
		getline(inputfile, recentManager.Fullname);
		getline(inputfile, recentManager.Username);
		getline(inputfile, recentManager.Password);

		addManager(recentManager);
		getline(inputfile, emptyline);
	}
	cout<<"You've finished reading Manager.txt"<<endl;
	inputfile.close();
	filename.clear();

	// add student
	filename = "Resouces\Students.txt";
	inputfile.open(filename);
	Student recentStudent;

	while(!inputfile.eof()) {
		inputfile >> recentStudent.Id;
		getline(inputfile, emptyline);
		getline(inputfile, recentStudent.Fullname);
		getline(inputfile, recentStudent.Username);
		addStudent(recentStudent);
		getline(inputfile, emptyline);
	}
	cout<<"You've finished reading Students.txt"<<endl;
	inputfile.close();
	filename.clear();

	// add Book title
	filename = "Resources\BookTitles.txt";
	inputfile.open(filename);
	BookTitle recentTitle;

	while(!inputfile.eof()) {
		inputfile >> recentTitle.Id;
		getline(inputfile, emptyline);
		getline(inputfile, recentTitle.Name);
		getline(inputfile, recentTitle.Author);
		addTitle(recentTitle);
		getline(inputfile, emptyline);
	}
	cout<<"You've finished reading BookTitles.txt"<<endl;
	inputfile.close();
	filename.clear();

	// add Book Copy
	filename = "Resources\BookCopies.txt";
	inputfile.open(filename);
	BookCopy recentCopy;

	while(!inputfile.eof()) {
		inputfile >> recentCopy.Id;
		inputfile >> recentCopy.TitleId;
		inputfile >> recentCopy.Shelf;
		inputfile >> recentCopy.BorrowerId;
		inputfile >> recentCopy.StartDate;
		inputfile >> recentCopy.DueDate;

		addCopy(recentCopy);
		getline(inputfile, emptyline);
	}
	cout<<"You've finished reading BookCopies.txt"<<endl;
	inputfile.close();
	filename.clear();

	// add BorrowLog

	filename = "Resources\BorrowLogs.txt";
	inputfile.open(filename);

	BorrowLog recentLog;

	while(!inputfile.eof()) {
		inputfile >> recentLog.Id;
		// title

		inputfile >> recentLog.Title.Id;
		getline(inputfile, emptyline);
		getline(inputfile, recentLog.Title.Name);
		getline(inputfile, recentLog.Title.Author);

		// copy
		inputfile >> recentLog.Copy.Id;
		inputfile >> recentLog.Copy.TitleId;
		inputfile >> recentLog.Copy.Shelf;
		inputfile >> recentLog.Copy.BorrowerId;

		// borrower

		inputfile >> recentLog.Borrower.Id;
		getline(inputfile, emptyline);
		getline(inputfile, recentLog.Borrower.Fullname);
		getline(inputfile, recentLog.Borrower.Username);

		addLog(recentLog);

		getline(inputfile, emptyline);
	}

	inputfile.close();
	filename.clear();
}

bool MyLibrary::LibraryContext::addManager(Manager manager)
{
	if(_ManagerStorage.count(manager.Id) || _UsernameIndex.count(manager.Username))
		return false;

	_ManagerStorage[manager.Id] = manager;
	_UsernameIndex.insert(manager.Username);
	_ManagerUsernameIndex[manager.Username] = manager;

	return true;
}

bool MyLibrary::LibraryContext::addStudent(Student student)
{
	if(_StudentStorage.count(student.Id) || _UsernameIndex.count(student.Username))
		return false;

	_StudentStorage[student.Id] = student;
	_StudentUsernameIndex[student.Username] = student;
	_UsernameIndex.insert(student.Username);

	return true;
}

bool MyLibrary::LibraryContext::addTitle(BookTitle title)
{
	auto titleindexpair = make_tuple(title.Name, title.Id);
	auto authorindexpair = make_tuple(title.Author, title.Id);

	if(_TitleNameIndex.count(titleindexpair)
	   || _TitleAuthorIndex.count(authorindexpair) || _TitleStorage.count(title.Id) )
		return false;

	_TitleStorage[title.Id] = title;
	_TitleNameIndex.insert(titleindexpair);
	_TitleAuthorIndex.insert(authorindexpair);

	return true;
}

bool MyLibrary::LibraryContext::addCopy(BookCopy bcopy)
{
	auto titleindexpair = make_tuple(bcopy.TitleId, bcopy.Id);
	auto borrowerindexpair = make_tuple(bcopy.BorrowerId, bcopy.Id);

	if(_CopyStorage.count(bcopy.Id) || _CopyTitleIdIndex.count(titleindexpair) ||
	   _CopyBorrowerIdIndex.count(borrowerindexpair))
		return false;

	_CopyStorage[bcopy.Id] = bcopy;
	_CopyTitleIdIndex.insert(titleindexpair);
	_CopyBorrowerIdIndex.insert(borrowerindexpair);

	return true;
}

bool MyLibrary::LibraryContext::addLog(BorrowLog brlog)
{
	if(_LogStorage.count(brlog.Id))
		return false;

	_LogStorage[brlog.Id] = brlog;

	return true;
}

void MyLibrary::LibraryContext::removeTitle(int id)
{
	if(!_TitleStorage.count(id))
		return;

	BookTitle& current = _TitleStorage[id];

	auto nameindexpair = make_tuple(current.Name, id);
	auto authorindexpair = make_tuple(current.Author, id);

	_TitleNameIndex.erase(nameindexpair);
	_TitleAuthorIndex.erase(authorindexpair);

	_TitleStorage.erase(id);

	auto plist = getCopyIdsByTitleId(id);

	for(auto& cid :* plist)
		removeCopy(cid);
}

void MyLibrary::LibraryContext::removeCopy(int id)
{
	if(!_CopyStorage.count(id))
		return;

	BookCopy& copy = _CopyStorage[id];

	auto titleindexpair = make_tuple(copy.TitleId, id);
	auto borrowerindexpair = make_tuple(copy.BorrowerId, id);

	_CopyTitleIdIndex.erase(titleindexpair);
	_CopyBorrowerIdIndex.erase(borrowerindexpair);

	_CopyStorage.erase(id);
}

bool MyLibrary::LibraryContext::updateCopy(BookCopy bcopy)
{
	if(!_CopyStorage.count(bcopy.Id))
		return false;

	removeCopy(bcopy.Id);
	addCopy(bcopy);

	return true;
}

shared_ptr<Student> MyLibrary::LibraryContext::getStudent(int id)
{
	shared_ptr<Student> result; //empty

	if (!_StudentStorage.count(id))
		return result;

	result.reset(new Student); //take ownership
	*result=_StudentStorage[id];
	return result;
}

shared_ptr<BookTitle> MyLibrary::LibraryContext::getTitle(int id)
{
	shared_ptr<BookTitle> result;

	if (!_TitleStorage.count(id))
		return result;

	result.reset(new BookTitle);
	*result=_TitleStorage[id];
	return result;
}

shared_ptr<BookCopy> MyLibrary::LibraryContext::getCopy(int id)
{
	shared_ptr<BookCopy> result;
	if (!_CopyStorage.count(id))
		return result;

	result.reset(new BookCopy);
	*result=_CopyStorage[id];
	return result;
}

shared_ptr<Manager> MyLibrary::LibraryContext::getManager(string username)
{
	shared_ptr<Manager> result;

	if(!_ManagerUsernameIndex.count(username))
		return result;

	result.reset(new Manager);
	*result= _ManagerUsernameIndex[username];
	return result;
}

shared_ptr<Student> MyLibrary::LibraryContext::getStudent(string username)
{
	shared_ptr<Student> result;

	if(!_StudentUsernameIndex.count(username))
		return result;

	result.reset(new Student);
	*result= _StudentUsernameIndex[username];
	return result;
}

shared_ptr<list<BookTitle>> MyLibrary::LibraryContext::getTitles()
{
	shared_ptr<list<BookTitle>> result (new list<BookTitle>);

	for (auto& pair: _TitleStorage)
		result-> push_back(pair.second);
	//-> : access mem through pointer
	return result;
}

shared_ptr<list<BookTitle>> MyLibrary::LibraryContext::getTitles(string pattern)
{
	shared_ptr<list<BookTitle>> result (new list<BookTitle>);

	auto lb=_TitleNameIndex.lower_bound(make_tuple(pattern,-1));
	pattern[pattern.size()-1]++;
	auto ub=_TitleNameIndex.upper_bound(make_tuple(pattern,-1));

	for (auto& it=lb; it!=ub; it++) {
		auto id=get<1> (*it);//remember parenthesis tells the range of tuple
		result->push_back(_TitleStorage[id]);
	}

	return result;
}

shared_ptr<list<int>> MyLibrary::LibraryContext::getCopyIdsByTitleId(int id)
{
	shared_ptr<list<int>> result (new list<int>);

	auto lb=_CopyTitleIdIndex.lower_bound(make_tuple(id,-1));
	auto ub=_CopyTitleIdIndex.upper_bound(make_tuple(++id,-1));

	for (auto& it=lb; it!=ub; it++) {
		auto cid=get<1> (*it);
		result-> push_back(cid);
	}
	return result;
}

shared_ptr<list<BookCopy>> MyLibrary::LibraryContext::getFreeCopiesByTitleId(int id)
{
	shared_ptr<list<BookCopy>> result (new list<BookCopy>);
	shared_ptr<list<int>> tempCopy=getCopyIdsByTitleId(id);
	for (auto& cid:*tempCopy) {
		BookCopy bcopy=_CopyStorage[cid];
		if (bcopy.BorrowerId==0)
			result-> push_back(bcopy);
	}
	return result;
}

shared_ptr<list<BookCopy>> MyLibrary::LibraryContext::getCopiesByBorrowerId(int id)
{
	shared_ptr<list<BookCopy>> result (new list<BookCopy>);

	auto lb=_CopyBorrowerIdIndex.lower_bound(make_tuple(id,-1));
	auto ub=_CopyBorrowerIdIndex.upper_bound(make_tuple(++id,-1));

	for (auto& it=lb; it!=ub; it++) {
		auto cid=get<1> (*it);
		result->push_back(_CopyStorage[cid]);
	}
	return result;
}

void MyLibrary::LibraryContext::writeData()
{
	
}