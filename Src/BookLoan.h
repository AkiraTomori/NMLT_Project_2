#ifndef _BOOK_LOAN_H_
#define _BOOK_LOAN_H_

#include "Object.h"
#include "Reader.h"
#include "Book.h"
void borrowBooks(Reader readers[], int countReader, Book books[], int countBook, BookLoan bookloans[], int &countLoan, int &reaminBooks);
void returnBooks(Reader readers[], int countReader, Book books[], int countBook, BookLoan bookloans[], int countLoan, int &remainBooks);

int FindLoanReaderBaseOnID(BookLoan bookloans[], int countLoan, char input[]);
#endif