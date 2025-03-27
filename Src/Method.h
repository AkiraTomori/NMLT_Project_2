#ifndef _METHOD_H_
#define _METHOD_H_

#include "Object.h"

int FindReaderBasedOnCCCD(Reader readers[], int countReader, char cccd[]);
int FindReaderBasedOnName(Reader readers[], int countReader, char name[]);
int FindReaderBasedOnId(Reader readers[], int countReader, char id[]);

int FindBookBasedOnISBN(Book books[], int countBook, char bookISBN[]);
int FindBookBasedOnTitle(Book books[], int countBook, char bookTitle[]);

int FindLoanReaderBaseOnID(BookLoan bookloans[], int countLoan, char input[]);

#endif