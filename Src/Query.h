#ifndef _QUERY_H_
#define _QUERY_H_

#include "Method.h"
using namespace std;

int countTotalBooks(Book books[], int countBook);
void countBookByGenres(Book books[], int countBook);
int countTotalReaders(Reader readers[], int countReader);
void countReaderByGenders(Reader readers[], int countReader);
int countBorrowedBooks(BookLoan bookloans[], int countLoan);
void listOverdueReaders(BookLoan bookLoans[], int countLoan);

#endif