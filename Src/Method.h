#ifndef _METHOD_H_
#define _METHOD_H_

#include "Object.h"

// Reader.h
int FindReaderBasedOnCCCD(Reader readers[], int countReader, char cccd[]);
int FindReaderBasedOnName(Reader readers[], int countReader, char name[]);
int FindReaderBasedOnId(Reader readers[], int countReader, char id[]);
bool isUniqueID(const Reader readers[], int countReader, char inputID[]);
bool isUniqueCCCD(const Reader readers[], int countReader, char inputCCCD[]);

// Book.h
int FindBookBasedOnISBN(Book books[], int countBook, char bookISBN[]);
int FindBookBasedOnTitle(Book books[], int countBook, char bookTitle[]);
bool isUniqueISBN(const Book books[], int countBook, char inputISBN[]);

// BookLoan.h
int FindLoanReaderBaseOnID(BookLoan bookloans[], int countLoan, char input[]);

#endif