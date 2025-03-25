#ifndef _SUPPORT_H_
#define _SUPPORT_H_
#include <iostream>
#include <stdio.h>
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

    void addMonths(int months);
};

bool isLeapYear(int year);
int getDaysInMonth(int month, int year);
void header1();
void header2();
#endif