#include "Support.h"

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