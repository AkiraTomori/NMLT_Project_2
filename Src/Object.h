#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Constants.h"
#include "Support.h"

#include <string.h>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;

    Date();
    Date(int day, int month, int year);
    Date(const Date& other);
    Date &operator = (const Date& other);
    ~Date();
    friend istream& operator >> (istream& in, Date& date);
    friend ostream& operator << (ostream& os, const Date &other);
    int operator-(const Date& other);

    void addMonths(int months);
    void addOneDays();
    void addNDays(int days);
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

    Reader();
    Reader(char readerName[100], char readerId[20], char readerCCCD[100], char readerMail[100], char readerAddress[100], char readerGender[10], Date readerBirtday, Date readerCardDates, Date readerExpiryDates);
    Reader(const Reader& other);
    Reader &operator = (const Reader& other);
    ~Reader();
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

    Book();
    Book(char bookISBN[20], char bookTitles[100], char bookAuthor[100], char bookPulisher[100], char bookGenres[50], int bookPublisherYear, int bookPrices, int bookQuantites);
    Book(const Book& other);
    Book &operator=(const Book &other);
    ~Book();
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

    BookLoan();
    BookLoan(char loanReaderIds[20], char loanBooks[MAX_BORROWED_BOOKS][20], int loanBookQuantites[MAX_BORROWED_BOOKS], Date loanDates, Date returnDates, Date returnDateActual, int loanBookCount);
    BookLoan(const BookLoan& other);
    BookLoan &operator=(const BookLoan& other);
    ~BookLoan();
};
#endif