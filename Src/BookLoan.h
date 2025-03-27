#ifndef _BOOK_LOAN_H_
#define _BOOK_LOAN_H_

#include "Object.h"
void borrowBooks(Reader readers[], int countReader, Book books[], int countBook, BookLoan bookloans[], int &countLoan);
void returnBooks(Reader readers[], int countReader, Book books[], int countBook, BookLoan bookloans[], int countLoan);

#endif