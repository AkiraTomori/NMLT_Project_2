#ifndef _BOOK_H_
#define _BOOK_H_

#include "Object.h"

void displayBookInfo(Book books[], int bookIndex);
void viewBooks(Book books[], int countBooks);
void addBooks(Book books[], int &countBooks, int &totalBooks, int &remainBooks);
void editBooks(Book books[], int countBooks, int &totalBooks, int &remainBooks);
void removeBooks(Book books[], int &countBooks, int &totalBooks, int &remainBooks);
void findBookBaseOnISBN(Book books[], int countBook);
void findBookBaseOnTitle(Book books[], int countBook);
Book createBook();

int FindBookBasedOnISBN(Book books[], int countBook, char bookISBN[]);
int FindBookBasedOnTitle(Book books[], int countBook, char bookTitle[]);
#endif