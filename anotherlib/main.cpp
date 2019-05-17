#include <bits/stdc++.h>
#include "LibraryContext.h"
using namespace MyLibrary;
using namespace std;

LibraryContext lib;


int main(int argc, char **argv)
{

	LibraryContext lib;
	lib.readData();
	lib.printMSG("Resources/Hello_Message.txt");
	lib.login();
	system("PAUSE");
loop:
	lib.printMSG("Resources/Options.txt");
	cout << "Please enter the option ID: ";
	int options = lib.getInput();
	cout << endl;
	int ID;
	string patterns;
	shared_ptr<Student> students;
	shared_ptr<BookTitle> books;

	switch (options) 
	{
		case 1: {
			system("CLS");
			cout << "Books in storage: " << endl;
			auto book_list = lib.getTitles();
			for (auto &titles: *book_list) cout << titles.Id<<" - "<< titles.Name << "\n";
			cout << "Please enter the book ID to remove the book: ";
			ID = lib.getInput();
			lib.removeTitle(ID);
			book_list = lib.getTitles();
			for (auto &titles: *book_list) cout << titles.Name << "\n";
			system("PAUSE");
			goto loop;
			//trả về kiểu bool, nếu true in ra được, nếu false in ra không được.
			// nếu true, in ra các titles còn lại.
			break;
		}
		case 2: {
			system("CLS");
			cout << "Please enter student ID: ";
			ID = lib.getInput();
			students = lib.getStudent(ID);
			if (students == nullptr) cout << "Student ID not found.\n";
			//trả về shared_ptr, nếu == null in ra kh được, nếu có thì in ra Username và Fullname.
			else cout << "Username: " << students -> Username << "\nFullname: " << students -> Fullname << "\n";
			system("PAUSE");
			goto loop;
			break;
		}
		case 3: {
			system("CLS");
			auto book_titles = lib.getTitles();
			for (auto &title: *book_titles)
				cout << title.Name << "\n";
			system("PAUSE");
			goto loop;
			break;
		}
		case 4: {
			system("CLS");
			cout << "Please enter book ID: ";
			ID = lib.getInput();
			books = lib.getTitle(ID);
			if (books == nullptr) cout << "Book ID is not found.\n";
			//trả về shared_ptr, nếu == null in ra kh được, nếu có thì in ra Username và Fullname.
			else cout << "Name: " << books -> Name << "\nAuthor: " << books -> Author << "\n";
			system("PAUSE");
			goto loop;
			break;
		}
		case 5: {
			system("CLS");
			cout << "Please enter book name: ";
			cin >> patterns;
			auto title_list = lib.getTitles(patterns);
			if (!title_list->size()) cout << "Book " << patterns << " is not found.\n";
			//trả về shared_ptr, nếu == null in ra kh được, nếu có thì in ra Username và Fullname.
			for (auto &book: *title_list)
				cout <<book.Name << " - " << book.Author << "\n";
			system("PAUSE");
			goto loop;
			break;
		}
		case 6: {
			system("CLS");
			cout << "Please enter book ID: ";
			ID = lib.getInput();
			auto book_copy = lib.getCopyIdsByTitleId(ID);
			if (!book_copy->size()) {
				cout << "This title does not have any copies.\n";
			}
			//trả về shared_ptr, nếu == null in ra kh được, nếu có thì in ra Username và Fullname.
			for (auto &copyId: *book_copy)
				cout<<"Id: "<<copyId<<"\n";
			system("PAUSE");
			goto loop;
			break;
		}
		case 7: {
			system("CLS");
			cout << "Please enter book ID: ";
			ID = lib.getInput();
			auto book_free = lib.getFreeCopiesByTitleId(ID);
			if (!book_free->size()) cout << "There are no available books with this ID.\n";
			//trả về shared_ptr, nếu == null in ra kh được, nếu có thì in ra Username và Fullname.
			for (auto &free: *book_free)
				cout <<"ID: "<<free.Id<<" Shelf: "<<free.Shelf<< "\n";
			system("PAUSE");
			goto loop;
			break;
		}
		case 8: {
			system("CLS");
			cout << "Please enter borrower ID: ";
			ID = lib.getInput();
			auto book_borrow = lib.getCopiesByBorrowerId(ID);
			if (!book_borrow->size()) cout << "This ID is not borrowing any books.\n";
			//trả về shared_ptr, nếu == null in ra kh được, nếu có thì in ra Username và Fullname.
			cout << "This person is currently borrowing: \n";
			for (auto &borrow : *book_borrow)
				cout<<borrow.Id <<" - "<<lib.getTitle(borrow.TitleId) -> Name<< "\n";
			system("PAUSE");
			goto loop;
			break;
		}
		case 9: {
			system("CLS");
			int cid, sid;
			cout << "Please enter borrower's ID: ";
			sid = lib.getInput();
			cout << endl;
			cout << "Please enter copy's ID: ";
			cid = lib.getInput();
			cout << endl;
			int returnvals = lib.makeBorrow(sid,cid);
			if (returnvals==1) {
				cout<<"This copy has already been borrowed by someone else! \n";
				system("PAUSE");
				goto loop;
			}
			if (returnvals==2) {
				cout<<"Borrower has an copy overdue for return! Return to borrow a new book! \n";
				system("PAUSE");
				goto loop;
			}
			if (returnvals==0) {
				cout <<"Lent successfully! Borrowed on ";
				cout << lib.getDate(cid, 1) << endl;
				cout << "Due date for return: " << lib.getDate(cid, 0) << endl;
				system("PAUSE");
				goto loop;
			}
			break;
		}
		case 10: {
			system("CLS");
			int sid, cid;
			cout << "Please enter borrower's ID: ";
			sid = lib.getInput();
			cout << endl;
			cout << "Please enter copy's ID: ";
			cid = lib.getInput();
			cout << endl;
			int returnvals=lib.releaseBorrow(sid,cid);
			if (returnvals==1) {
				cout<<"No one is borrowing this copy! \n";
				system("PAUSE");
				goto loop;
			}
			if (returnvals==2) {
				cout<<"Borrower's returned an overdue book! Please tell him or her to pay the fine at the librarian! \n";
				system("PAUSE");
				goto loop;
			}
			if (returnvals==0) {
				cout<<"Book returned!\n";
				system("PAUSE");
				goto loop;
			}
			break;
		}
		case 11: {
			system("CLS");
			lib.writeData();
			cout<<"Data written in output file."<<endl;
			system("PAUSE");
			goto loop;
			break;
		}

		default: {
			break;
		}
	}
	lib.writeData();
	return 0;
}
