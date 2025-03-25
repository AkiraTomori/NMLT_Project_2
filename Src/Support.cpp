#include "Support.h"

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
    out << other.day << "/" << other.month << "/" << other.year << "\n";
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
bool isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
int getDaysInMonth(int month, int year)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
    {
        return (isLeapYear(year) ? 29 : 28);
    }
    default:
        return 0;
    }
}
void header1()
{
    cout << "--------------------------------------------------------------------------------\n";
}
void header2()
{
    cout << "================================================================================\n";
}