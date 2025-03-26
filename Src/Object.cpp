#include "Object.h"

Date::Date()
{
    this->day = 1;
    this->month = 1;
    this->year = 2000;
}
Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
Date::Date(const Date &other)
{
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}
Date &Date::operator=(const Date &other)
{
    if (this != &other)
    {
        this->day = other.day;
        this->month = other.month;
        this->year = other.year;
    }
    return *this;
}
istream &operator>>(istream &in, Date &other)
{
    cout << "Ngay: ";
    in >> other.day;
    cout << "Thang: ";
    in >> other.month;
    cout << "Nam: ";
    in >> other.year;
    return in;
}
ostream &operator<<(ostream& out, const Date& other)
{
    out << other.day << "/" << other.month << "/" << other.year;
    return out;
}
void Date::addMonths(int months)
{
    this->month += months;
    while (this->month > 12)
    {
        this->month -= 12;
        this->year++;
    }
}
Date::~Date(){}

Reader::Reader()
{
    char newLine[11] = " ";
    strcpy(this->readerName, newLine);
    strcpy(this->readerId, newLine);
    strcpy(this->readerCCCD, newLine);
    strcpy(this->readerMail, newLine);
    strcpy(this->readerAddress, newLine);
    strcpy(this->readerGender, newLine);
}
Reader::Reader(char readerName[100], char readerId[20], char readerCCCD[100], char readerMail[100], char readerAddress[100], char readerGender[10], Date readerBirtday, Date readerCardDates, Date readerExpiryDates)
{
    strcpy(this->readerName, readerName);
    strcpy(this->readerId, readerId);
    strcpy(this->readerCCCD, readerCCCD);
    strcpy(this->readerMail, readerMail);
    strcpy(this->readerAddress, readerAddress);
    strcpy(this->readerGender, readerGender);
    this->readerBirthday = readerBirthday;
    this->readerCardDates = readerCardDates;
    this->readerExpiryDates = readerExpiryDates;
}
Reader::Reader(const Reader &other)
{
    strcpy(this->readerName, other.readerName);
    strcpy(this->readerId, other.readerId);
    strcpy(this->readerCCCD, other.readerCCCD);
    strcpy(this->readerMail, other.readerMail);
    strcpy(this->readerAddress, other.readerAddress);
    strcpy(this->readerGender, other.readerGender);
    this->readerBirthday = other.readerBirthday;
    this->readerCardDates = other.readerCardDates;
    this->readerExpiryDates = other.readerExpiryDates;
}
Reader &Reader::operator=(const Reader &other)
{
    if (this != &other)
    {
        strcpy(this->readerName, other.readerName);
        strcpy(this->readerId, other.readerId);
        strcpy(this->readerCCCD, other.readerCCCD);
        strcpy(this->readerMail, other.readerMail);
        strcpy(this->readerAddress, other.readerAddress);
        strcpy(this->readerGender, other.readerGender);
        this->readerBirthday = other.readerBirthday;
        this->readerCardDates = other.readerCardDates;
        this->readerExpiryDates = other.readerExpiryDates;
    }
    return *this;
}
Reader::~Reader() {}

Book::Book()
{
    char newLine[11] = " ";
    strcpy(this->bookISBN, newLine);
    strcpy(this->bookTitles, newLine);
    strcpy(this->bookAuthor, newLine);
    strcpy(this->bookPublisher, newLine);
    strcpy(this->bookGenres, newLine);
    this->bookPublisherYear = 0;
    this->bookPrices = 0;
    this->bookQuantitites = 0;
}
Book::Book(char bookISBN[20], char bookTitles[100], char bookAuthor[100], char bookPulisher[100], char bookGenres[50], int bookPublisherYear, int bookPrices, int bookQuantites)
{
    strcpy(this->bookISBN, bookISBN);
    strcpy(this->bookTitles, bookTitles);
    strcpy(this->bookAuthor, bookAuthor);
    strcpy(this->bookPublisher, bookPulisher);
    strcpy(this->bookGenres, bookGenres);
    this->bookPublisherYear = bookPublisherYear;
    this->bookPrices = bookPrices;
    this->bookQuantitites = bookQuantites;
}
Book::Book(const Book &other)
{
    strcpy(this->bookISBN, other.bookISBN);
    strcpy(this->bookTitles, other.bookTitles);
    strcpy(this->bookAuthor, other.bookAuthor);
    strcpy(this->bookPublisher, other.bookPublisher);
    strcpy(this->bookGenres, other.bookGenres);
    this->bookPublisherYear = other.bookPublisherYear;
    this->bookPrices = other.bookPrices;
    this->bookQuantitites = other.bookQuantitites;
}
Book &Book::operator=(const Book &other)
{
    if (this != &other)
    {
        strcpy(this->bookISBN, other.bookISBN);
        strcpy(this->bookTitles, other.bookTitles);
        strcpy(this->bookAuthor, other.bookAuthor);
        strcpy(this->bookPublisher, other.bookPublisher);
        strcpy(this->bookGenres, other.bookGenres);
        this->bookPublisherYear = other.bookPublisherYear;
        this->bookPrices = other.bookPrices;
        this->bookQuantitites = other.bookQuantitites;
    }
    return *this;
}
Book::~Book(){}