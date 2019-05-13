#include <bits/stdc++.h>
#include "LibraryContext.h"
using namespace MyLibrary;
using namespace std;

LibraryContext lib;


int main(int argc, char **argv)
{

	LibraryContext lib;
	shared_ptr<Manager>tempman;
	lib.readData();
	lib.makeBorrow(51,71);
	lib.makeBorrow(51,73);
	string in_username, in_password;

	cout << "Please input to log in.\n";
	cout << "Username: ";
	cin >> in_username;

	//check if in_username is valid
	while (!lib.getManager(in_username)) { //getManager is the function to get manager by his username, and return a null pointer if the username is false.
		cout << "Invalid Username. Please input username again: ";
		cin >> in_username;
		cout << endl;
	}

	//now the user input the right username, we ask him to input the password
	cout << "Password: ";
	cin >> in_password;
	cout << endl;

	//now we check if the password is valid
	tempman = lib.getManager(in_username); //we get the valid manager by his username
	//tempman is the manager we got
	//it is present as a shared pointer

	if (tempman -> Password != in_password) {
		cout << "Wrong Password. Please input password again: ";
		cin >> in_password;
		cout << endl;
	}

	cout << "You are logged in.\n";
loop:
	cout << "1. Enter '1' to remove book. \n"
	     << "2. Enter '2' to get student information.\n"
	     << "3. Enter '3' to list all book titles. \n"
	     << "4. Enter '4' to get book by Id. \n"
	     << "5. Enter '5' to get books by patterns. \n"
	     << "6. Enter '6' to get copies by titles' Id. \n"
	     << "7. Enter '7' to get free copies by titles' Id.\n"
	     << "8. Enter '8' to get books currently being borrowed. \n"
	     << "9. Enter '9' to make borrow. \n"
	     << "10. Enter '10' to release borrow. \n"
	     << "11. Enter '11' to write data. \n"
		 << "12. Enter any other numbers to exit. \n";
	int options;
	cin >> options;
	int ID;
	string patterns;
	shared_ptr<Student> students;
	shared_ptr<BookTitle> books;
	bool status = true;

	//while (status) {
	switch (options) {
	case 1: {
		auto book_list = lib.getTitles();
		for (auto &titles: *book_list) cout << titles.Id<<"-"<< titles.Name << "\n";
		cout << "Please enter the book ID to remove the book: ";
		cin >> ID;
		lib.removeTitle(ID);
		book_list = lib.getTitles();
		for (auto &titles: *book_list) cout << titles.Name << "\n";
		goto loop;
		//trả về kiểu bool, nếu true in ra được, nếu false in ra không được.
		// nếu true, in ra các titles còn lại.
		break;
	}
	case 2: {
		cout << "Please enter student ID: ";
		cin >> ID;
		students = lib.getStudent(ID);
		if (students == nullptr) cout << "Student ID not found.\n";
		//trả về shared_ptr, nếu == null in ra kh được, nếu có thì in ra Username và Fullname.
		else cout << "Username: " << students -> Username << "\nFullname: " << students -> Fullname << "\n";
		goto loop;
		break;
	}
	case 3: {
		auto book_titles = lib.getTitles();
		for (auto &title: *book_titles)
			cout << title.Name << "\n";
		goto loop;
		break;
	}
	case 4: {
		cout << "Please enter book ID: ";
		cin >> ID;
		books = lib.getTitle(ID);
		if (books == nullptr) cout << "Book ID is not found.\n";
		//trả về shared_ptr, nếu == null in ra kh được, nếu có thì in ra Username và Fullname.
		else cout << "Name: " << books -> Name << "\nAuthor: " << books -> Author << "\n";
		goto loop;
		break;
	}
	case 5: {
		cout << "Please enter book name: ";
		cin >> patterns;
		auto title_list = lib.getTitles(patterns);
		if (title_list == nullptr) cout << "Book " << patterns << " is not found.\n";
		//trả về shared_ptr, nếu == null in ra kh được, nếu có thì in ra Username và Fullname.
		for (auto &book: *title_list)
			cout <<book.Name << " - " << book.Author << "\n";
		goto loop;
		break;
	}
	case 6: {
		cout << "Please enter book ID: ";
		cin >> ID;
		auto book_copy = lib.getCopyIdsByTitleId(ID);
		if (!book_copy) {
			cout << "Book ID is not found.\n";
			break;
		}
		//trả về shared_ptr, nếu == null in ra kh được, nếu có thì in ra Username và Fullname.
		for (auto &copyId: *book_copy)
			cout<<"Id: "<<copyId<<"\n";
		goto loop;
		break;
	}
	case 7: {
		cout << "Please enter book ID: ";
		cin >> ID;
		auto book_free = lib.getFreeCopiesByTitleId(ID);
		if (book_free == nullptr) cout << "Book ID is not found.\n";
		//trả về shared_ptr, nếu == null in ra kh được, nếu có thì in ra Username và Fullname.
		for (auto &free: *book_free)
			cout <<"ID: "<<free.Id<<" Shelf: "<<free.Shelf<< "\n";
		goto loop;
		break;
	}
	case 8: {
		cout << "Please enter borrower ID: ";
		cin >> ID;
		auto book_borrow = lib.getCopiesByBorrowerId(ID);
		if (book_borrow==nullptr) cout << "Borrower ID is not found.\n";
		//trả về shared_ptr, nếu == null in ra kh được, nếu có thì in ra Username và Fullname.
		cout << "This person is currently borrowing: \n";
		for (auto &borrow : *book_borrow)
			cout<<borrow.Id <<" - "<<lib.getTitle(borrow.TitleId) -> Name<< "\n";
		goto loop;
		break;
	}
	case 9: {
		cout << "Please enter borrower's ID and book copy's ID to lend book: ";
		int cid, sid;
		cin >> sid >> cid;
		int returnvals = lib.makeBorrow(sid,cid);
		if (returnvals==1) {
			cout<<"This copy has already been borrowed by someone else! \n";
			goto loop;
		}
		if (returnvals==2) {
			cout<<"Borrower has an copy overdue for return! Return to borrow a new book! \n";
			goto loop;
		}
		if (returnvals==0) {
			cout<<"Lent successfully!\n";
			goto loop;
		}
		break;
	}
	case 10: {
		cout<<"Please enter borrower's ID and book copy's ID to release borrow: ";
		int cid, sid;
		cin >> sid >> cid;
		int returnvals=lib.releaseBorrow(sid,cid);
		if (returnvals==1) {
			cout<<"No one is borrowing this copy! \n";
			goto loop;
		}
		if (returnvals==2) {
			cout<<"Borrower's returned an overdue book! Please tell him or her to pay the fine at the librarian! \n";
			goto loop;
		}
		if (returnvals==0) {
			cout<<"Book returned!\n";
			goto loop;
		}
		break;
	}
	case 11: {
		lib.writeData();
		cout<<"Data written in output file."<<endl;
		goto loop;
		break;
	}

	default: {
		status = false;
		break;
	}
	}
	lib.writeData();
	return 0;
}
