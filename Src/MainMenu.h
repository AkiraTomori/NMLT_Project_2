#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_
#include "Reader.h"
#include "Book.h"
#include "BookLoan.h"
#include "Query.h"
#include "getData.h"

void showTime(Reader reader[], int &countReaders, Book books[], int &countBooks, int &totalBooks, int &remainBooks, BookLoan bookloans[], int &countLoan);
void ReaderMenu(Reader reader[], int countReader);
void BookMenu(Book books[], int countBook, int &totalBooks, int &remainBooks);
void loanMenu(Reader reader[], int countReader, Book books[], int countBook, int &remainBooks, BookLoan bookloans[], int &countLoan);
void borrowBooksMenu(Reader reader[], int countReader, Book books[], int countBook, int &remainBooks, BookLoan bookloans[], int &countLoan);
void returnBooksMenu(Reader reader[], int countReader, Book books[], int countBook, int &remainBooks, BookLoan bookloans[], int countLoan);
void QueryMenu(Reader reader[], int countReader, Book books[], int countBook, BookLoan bookloans[], int countLoan);


#endif