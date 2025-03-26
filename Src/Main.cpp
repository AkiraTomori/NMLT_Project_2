#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <conio.h>

#include "getData.h"
#include "Book.h"
#include "Reader.h"
#include "BookLoan.h"
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
};

struct BookLoan
{
    char loanReaderIds[20];
    char loanBooks[MAX_BORROWED_BOOKS][20];
    int loanBookQuantities[MAX_BORROWED_BOOKS];
    Date loanDates;
    Date returnDates;
    Date returnDatesActual;
    int loanBookCount;
};


int main()
{
    Reader readers[MAX_READERS];
    int countReaders = 0;
    Book books[MAX_BOOKS];
    int countBook = 0;
    BookLoan bookLoans[MAX_BOOK_LOANS];
    int countBookLoan = 0;

    readReader("Files/Reader.txt", readers, countReaders);
    displayAllReaders(readers, countReaders);
    return 0;
}