#include "LibraryContext.h"
#include <chrono>
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
	filename = "Resources/Managers.txt";
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

	inputfile.close();
	filename.clear();

	// add student
	filename = "Resources/Students.txt";
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

	inputfile.close();
	filename.clear();

	// add Book title
	filename = "Resources/BookTitles.txt";
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

	inputfile.close();
	filename.clear();

	// add Book Copy
	filename = "Resources/BookCopies.txt";
	inputfile.open(filename);
	BookCopy recentCopy;
	long long Start, Due;


	while(!inputfile.eof()) {
		inputfile >> recentCopy.Id;
		inputfile >> recentCopy.TitleId;
		inputfile >> recentCopy.Shelf;
		inputfile >> recentCopy.BorrowerId;
		inputfile >> Start;
		inputfile >> Due;

		chrono::duration<int> StartDur (Start * 1000000), DueDur (Due * 1000000);
		chrono::system_clock::time_point StartPoint (StartDur);
		chrono::system_clock::time_point DuePoint (DueDur);

		recentCopy.StartDate = StartPoint;
		recentCopy.DueDate = DuePoint;

		addCopy(recentCopy);
		getline(inputfile, emptyline);
	}

	inputfile.close();
	filename.clear();

	// add BorrowLog

	filename = "Resources/BorrowLogs.txt";
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

		//fined
		string line;
		getline(inputfile,line);
		if (line=="FINED")
			recentLog.Fined=true;
		else recentLog.Fined=false;

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

bool MyLibrary::LibraryContext::makeBorrow(int sid, int cid)
{
	if (_CopyStorage[cid].BorrowerId)
	{	
		cout << "This copy has already been borrowed by someone else!" << endl;
		return false;
	}

	shared_ptr<list<BookCopy>> borrowed = getCopiesByBorrowerId(sid);

	for (auto bcopy : *borrowed)
	{
		if (chrono::system_clock::now().time_since_epoch().count() - bcopy.DueDate.time_since_epoch().count() > 0)
		{
			cout << "You have an copy overdue for return! Return to borrow a new book!" << endl;
			return false;
		}
	}

	BorrowLog newBorrow;
	BookCopy bcopy = _CopyStorage[cid];
	Student stu = _StudentStorage[sid];

	newBorrow.Id = _LogStorage.rbegin()->second.Id + 1;
	
	newBorrow.Title.Id = bcopy.TitleId;
	newBorrow.Title.Name = _TitleStorage[bcopy.TitleId].Name;
	newBorrow.Title.Author = _TitleStorage[bcopy.TitleId].Author;

	newBorrow.Copy.Id = bcopy.Id;
	newBorrow.Copy.TitleId = bcopy.TitleId;
	newBorrow.Copy.Shelf =bcopy.Shelf;
	newBorrow.Copy.BorrowerId = stu.Id;

	newBorrow.Borrower.Id = stu.Id;
	newBorrow.Borrower.Fullname = stu.Fullname;
	newBorrow.Borrower.Username = stu.Username;

	newBorrow.Fined = false;

	addLog(newBorrow);

	chrono::duration<int> DueTime (60*60*24*14);
	bcopy.StartDate = chrono::time_point_cast<chrono::milliseconds>(chrono::system_clock::now());
	bcopy.DueDate = bcopy.StartDate + DueTime;
	bcopy.BorrowerId = stu.Id;

	updateCopy(bcopy);
	return true;
}

bool MyLibrary::LibraryContext::releaseBorrow(int sid, int cid)
{
	if (_CopyStorage[cid].BorrowerId)
	{
		cout << "No one is borrowing this copy!" << endl;
		return false;
	}

	BookCopy bcopy = _CopyStorage[cid];
	Student stu = _StudentStorage[sid];
	BorrowLog releaseLog;
	bool Fined = false;

	if (chrono::system_clock::now().time_since_epoch().count() - bcopy.DueDate.time_since_epoch().count() > 0)
	{
		cout << "You've returned an overdue book! Please pay the fine at the librarian!" << endl;
		Fined = true;
	}

	releaseLog.Id = _LogStorage.rbegin()->second.Id + 1;

	releaseLog.Title.Id = bcopy.TitleId;
	releaseLog.Title.Name = _TitleStorage[bcopy.TitleId].Name;
	releaseLog.Title.Author = _TitleStorage[bcopy.TitleId].Author;

	releaseLog.Copy.Id = bcopy.Id;
	releaseLog.Copy.TitleId = bcopy.TitleId;
	releaseLog.Copy.Shelf =bcopy.Shelf;
	releaseLog.Copy.BorrowerId = stu.Id;

	releaseLog.Borrower.Id = stu.Id;
	releaseLog.Borrower.Fullname = stu.Fullname;
	releaseLog.Borrower.Username = stu.Username;

	releaseLog.Fined = Fined;

	addLog(releaseLog);

	bcopy.BorrowerId = 0;

	updateCopy(bcopy);
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
	ofstream outputfile;
	string filename;

	//write manager
	filename = "Output/Managers.out";
	outputfile.open (filename);

	Manager recentManager;
	for (auto it : _ManagerStorage) {
		recentManager=it.second;
		outputfile<<recentManager.Id<<endl;
		outputfile<<recentManager.Fullname<<endl;
		outputfile<<recentManager.Username<<endl;
		outputfile<<recentManager.Password<<endl<<endl;
	}
	outputfile.close();
	filename.clear();

	//write student
	filename = "Output/Students.out";
	outputfile.open(filename);

	Student recentStudent;
	for(auto it: _StudentStorage) {
		recentStudent=it.second;
		outputfile<<recentStudent.Id<<endl;
		outputfile<<recentStudent.Fullname<<endl;
		outputfile<<recentStudent.Username<<endl<<endl;

	}
	outputfile.close();
	filename.clear();

	//write BookTitle
	filename="Output/BookTitles.out";
	outputfile.open(filename);

	BookTitle recentTitle;
	for (auto it: _TitleStorage) {
		recentTitle=it.second;
		outputfile<<recentTitle.Id<<endl;
		outputfile<<recentTitle.Name<<endl;
		outputfile<<recentTitle.Author<<endl<<endl;
	}
	outputfile.close();
	filename.clear();

	//write bookcopy
	filename="Output/BookCopies.out";
	outputfile.open (filename);

	BookCopy  recentCopy;
	for (auto it : _CopyStorage) {
		recentCopy=it.second;
		outputfile<<recentCopy.Id<<endl;
		outputfile<<recentCopy.TitleId<<endl;
		outputfile<<recentCopy.Shelf<<endl;
		outputfile<<recentCopy.BorrowerId<<endl;
		outputfile<<chrono::duration_cast<chrono::milliseconds>
		(recentCopy.StartDate.time_since_epoch()).count()<<endl;
		outputfile<<chrono::duration_cast<chrono::milliseconds>
		(recentCopy.DueDate.time_since_epoch()).count()<<endl<<endl;
	}
	outputfile.close();
	filename.clear();

	//write borrowlog
	filename="Output/BorrowLogs.out";
	outputfile.open(filename);

	BorrowLog recentLog;
	for (auto it:_LogStorage) {
		recentLog=it.second;

		outputfile<<recentLog.Id<<endl;

		outputfile<<recentLog.Title.Id<<endl;
		outputfile<<recentLog.Title.Name<<endl;
		outputfile<<recentLog.Title.Author<<endl;

		outputfile<<recentLog.Copy.Id<<endl;
		outputfile<<recentLog.Copy.TitleId<<endl;
		outputfile<<recentLog.Copy.Shelf<<endl;
		outputfile<<recentLog.Copy.BorrowerId<<endl;

		outputfile<<recentLog.Borrower.Id<<endl;
		outputfile<<recentLog.Borrower.Fullname<<endl;
		outputfile<<recentLog.Borrower.Username<<endl;

		if (recentLog.Fined)
			outputfile<<"FINED.\n"<<endl;
		else outputfile<<"NOT FINED.\n"<<endl;
	}
	outputfile.close();
	filename.clear();
}