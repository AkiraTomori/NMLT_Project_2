#ifndef _BOOK_H_
#define _BOOK_H_

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "Constants.h"
#include "Support.h"
using namespace std;

struct Book
{
    char bookISBN[20];
    char bookTitles[100];
    char bookAuthor[100];
    char bookPublisher[100];
    char bookGenres[50];
    int bookPublisherYear;
    int bookPrices;
    int bookQuantitites;

    Book();
    Book(char bookISBN[20], char bookTitles[100], char bookAuthor[100], char bookPulisher[100], char bookGenres[50], int bookPublisherYear, int bookPrices, int bookQuantites);
    Book(const Book& other);
    Book &operator=(const Book &other);
};

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