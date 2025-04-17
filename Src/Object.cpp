#include "Object.h"
bool ValidDate::isValidDay(int day){
    if (day < 1 || day > 31)
        return false;
    return true;
}
bool ValidDate::isValidMonth(int month){
    if (month < 1 || month > 12){
        return false;
    }
    return true;
}
bool ValidDate::isValidYear(int year){
    if (year < 0){
        return false;
    }
    return true;
}
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
    ValidDate valid;
    do{
        cout << "Ngay: ";
        in >> other.day;
        if (!valid.isValidDay(other.day)){
            cout << "Ngay nhap vao khong hop le. Xin hay nhap lai.\n";
        }
        else{
            break;
        }
    } while (true);

    do{
        cout << "Thang: ";
        in >> other.month;
        if (!valid.isValidMonth(other.month)){
            cout << "Thang nhap vao khong hop le. Xin hay nhap lai.\n";
        }
        else{
            break;
        }
    } while (true);

    do{
        cout << "Nam: ";
        in >> other.year;
        if (!valid.isValidYear(other.year)){
            cout << "Nam nhap vao khong hop le. Xin hay nhap lai.\n";
        }
        else{
            break;
        }
    } while (true);

    return in;
}
ostream &operator<<(ostream &out, const Date &other)
{
    out << other.day << "/" << other.month << "/" << other.year;
    return out;
}
int Date::operator-(const Date& other)
{
    int day = (this->day - other.day);
    int month = (this->month - other.month) * 30;
    int year = (this->year - other.year) * 365;
    int overDueDays = day + month + year;
    return overDueDays;
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
void Date::addOneDays()
{
    int maxDays = getDaysInMonth(month, year);
    this->day++;
    if (this->day > maxDays)
    {
        this->day = 1;
        if (this->month > 12)
        {
            this->month = 1;
            this->year++;
        }
    }
}
void Date::addNDays(int days)
{
    for (int i = 1; i <= days; i++)
        addOneDays();
}
void Date::minusOneDays()
{
    int maxDays = getDaysInMonth(month, year);
    this->day--;
    if (this->day < 1)
    {
        this->day = maxDays;
        if (this->month < 1)
        {
            this->month = 12;
            year--;
        }
    }
}
void Date::minusNDays(int days)
{
    for (int i = 1; i <= days; i++)
        minusOneDays();
}
Date::~Date() {}

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
Book::~Book() {}

BookLoan::BookLoan()
{
    char newLine[11] = " ";
    strcpy(this->loanReaderIds, newLine);
    for (int i = 0; i < MAX_BORROWED_BOOKS; i++)
    {
        strcpy(this->loanBooks[i], newLine);
        loanBookQuantities[i] = 0;
    }
    this->loanBookCount = 0;
}
BookLoan::BookLoan(char loanReaderIds[20], char loanBooks[MAX_BORROWED_BOOKS][20], int loanBookQuantites[MAX_BORROWED_BOOKS], Date loanDates, Date returnDates, Date returnDateActual, int loanBookCount)
{
    strcpy(this->loanReaderIds, loanReaderIds);
    for (int i = 0; i < MAX_BORROWED_BOOKS; i++)
    {
        strcpy(this->loanBooks[i], loanBooks[i]);
        this->loanBookQuantities[i] = loanBookQuantites[i];
    }
    this->loanDates = loanDates;
    this->returnDates = returnDates;
    this->returnDatesActual = returnDateActual;
    this->loanBookCount = loanBookCount;
}
BookLoan::BookLoan(const BookLoan &other)
{
    strcpy(this->loanReaderIds, other.loanReaderIds);
    for (int i = 0; i < MAX_BORROWED_BOOKS; i++)
    {
        strcpy(this->loanBooks[i], other.loanBooks[i]);
        this->loanBookQuantities[i] = other.loanBookQuantities[i];
    }
    this->loanDates = other.loanDates;
    this->returnDates = other.returnDates;
    this->returnDatesActual = other.returnDatesActual;
    this->loanBookCount = other.loanBookCount;
}
BookLoan &BookLoan::operator=(const BookLoan &other)
{
    if (this != &other)
    {
        strcpy(this->loanReaderIds, other.loanReaderIds);
        for (int i = 0; i < MAX_BORROWED_BOOKS; i++)
        {
            strcpy(this->loanBooks[i], other.loanBooks[i]);
            this->loanBookQuantities[i] = other.loanBookQuantities[i];
        }
        this->loanDates = other.loanDates;
        this->returnDates = other.returnDates;
        this->returnDatesActual = other.returnDatesActual;
        this->loanBookCount = other.loanBookCount;
    }
    return *this;
}
BookLoan::~BookLoan(){}