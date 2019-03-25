#ifndef LIBRARYCONTEXT_H
#define LIBRARYCONTEXT_H

#include <bits/stdc++.h>

#include "Account.h"
#include "BookCopy.h"
#include "BookTitle.h"
#include "BorrowLog.h"

namespace MyLibrary
{

class LibraryContext
{
private:
    std::list<Account> _Accounts;
    std::list<BookTitle> _BookTitles;
    std::list<BookCopy> _BookCopies;
    std::list<BorrowLog> _BorrowLogs;

public:
    LibraryContext();
    ~LibraryContext();
    void addAccount(Account account);
    void addBookTitle(BookTitle booktitle);
    void removeBookTitle(BookTitle booktitle);
    void addBookCopy(BookCopy bookcopy);
    void borrowBook(int accountId, int copyId);
    void returnBook(int accountId, int copyId);
    // void findBorrowing(std::list<BookCopy>& result);
    // std::list<BookCopy> findBorrowing();
    // std::list<BookCopy>* findBorrowing();
    std::shared_ptr < std::list<BookCopy> findBorrowing();

    void writeData(Writer<Account> writer);
    void writeData(Writer<BookTitle> writer);
    void writeData(Writer<BookCopy> writer);
    void writeData(Writer<BorrowLog> writer);
};
}

#endif // LIBRARYCONTEXT_H
