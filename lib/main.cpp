#include <bits/stdc++.h>
#include "LibraryContext.h"
using namespace MyLibrary;
using namespace std;

int main(int argc, char **argv)
{
	LibraryContext lib;
	shared_ptr<Manager>tempman;
	lib.readData();
	
	//test get manager
	tempman=lib.getManager("iammanager");
	cout<<"the manager's username is: "<<tempman->Username<<endl;
	
	//test getTitles()
	auto tlist=lib.getTitles();
	for (auto& title:*tlist)
		cout<<"Book Titles are: "<<title.Name<<endl;
		
	//test getFreeCopiesByTitleId
	auto clist=lib.getFreeCopiesByTitleId(61);
	for (auto& copy:*clist)
		cout<<"Free Copies are:"<<copy.Id<<endl;
	
	//test getTitles with patterns
	auto tlist1=lib.getTitles("This is");
	for (auto& title:*tlist1)
		cout<<"The pattern matches: "<<title.Name<<endl;
	
	//test updateCopy
	BookCopy newbcopy;
	newbcopy.Id=71;
	newbcopy.TitleId=63;
	newbcopy.Shelf=55;
	newbcopy.BorrowerId=0;
	newbcopy.StartDate=0;
	newbcopy.DueDate=0;
	lib.updateCopy(newbcopy);
	shared_ptr<BookCopy> bcopy=lib.getCopy(71);
	cout<<"Updated copies are on the shelves: "<<bcopy->Shelf<<endl;
		
	return 0;
}
