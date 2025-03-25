#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <conio.h>
#include "Constants.h"
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

struct Reader
{
    char readerName[100];
    char readerId[20];
    char readerCCCD[100];
    char readerMail[100];
    char readerAddress[100];
    char readerGender[10];
    Date readerBirthday;
    Date readerCardDates;
    Date readerExpiryDates;
};

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

    return 0;
}