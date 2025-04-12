#ifndef _BOOK_H_
#define _BOOK_H_

#include "Method.h"

void displayBookInfo(Book books[], int bookIndex);
void viewBooks(Book books[], int countBooks);
void addBooks(Book books[], int &countBooks, int &totalBooks, int &remainBooks);
void editBooks(Book books[], int countBooks, int &totalBooks, int &remainBooks);
void removeBooks(Book books[], int &countBooks, int &totalBooks, int &remainBooks);
void findBookBaseOnISBN(Book books[], int countBook);
void findBookBaseOnTitle(Book books[], int countBook);
Book createBook(const Book books[], int countBook);

#endif