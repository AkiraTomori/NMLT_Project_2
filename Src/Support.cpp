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
    // cout << "--------------------------------------------------------------------------------\n";
    cout << string(148, '=') << "\n";
}
void header2()
{
    cout << "================================================================================\n";
    // cout << string(148, '=') << "\n";
}
void header3()
{
    cout << string(148, '-') << "\n";
}

void displayReaderHeader()
{
    header1();
    header3();
    printf("| %-4s | %-20s | %-10s | %-8s | %-20s | %-20s | %-5s | %-10s | %-10s | %-10s |\n",
           "STT", "Ten doc gia", "ID", "CCCD", "Email", "Dia chi", "Phai", "Ngay sinh", "Ngay cap", "Het han");
    header3();
}

void displayBookHeader()
{
    header1();
    header3();
    printf("| %-4s | %-20s | %-20s | %-20s | %-20s | %-15s | %-6s | %-7s | %-5s |\n",
           "STT", "ISBN", "Tua de", "Tac gia", "NXB", "The loai", "Nam", "Gia", "SL");
    header3();
}

string formatISBN(const string &rawISBN)
{
    if (rawISBN.length() != 13)
    {
        return "ISBN khong hop le.\n";
    }

    string formattedISBN;

    formattedISBN += rawISBN.substr(0, 3);
    formattedISBN += "-";
    formattedISBN += rawISBN.substr(3, 3); // Group: 604
    formattedISBN += "-";
    formattedISBN += rawISBN.substr(6, 2); // Publisher: 96
    formattedISBN += "-";
    formattedISBN += rawISBN.substr(8, 4); // Title: 3817
    formattedISBN += "-";
    formattedISBN += rawISBN.substr(12, 1);

    return formattedISBN;
}

void printBorder(char ch)
{
    printf("+");
    for (int i = 0; i < 62; ++i)
        printf("%c", ch);
    printf("+\n");
}
void printCenteredLine(const char text[])
{
    int len = strlen(text);
    int padding = (61 - len) / 2;
    printf("|%*s%s%*s|\n", padding, "", text, 61 - len - padding, "");
}
void printMenuLine(const char text[])
{
    int len = strlen(text);
    printf("| %-*s |\n", 59, text); // căn trái trong khung
}
void printPromptLine(const char text[])
{
    int len = strlen(text);
    printf("| %-*s |\n", 59, text);
}

void printBookQuantityHeader()
{
    printf("+------------------------------------------+\n");
    printf("| %-30s | %-6s |\n", "TEN SACH", "S.LUONG");
    printf("+------------------------------------------+\n");
}

void printBookQuantityRow(const char title[], int quantity)
{
    printf("| %-30s | %6d |\n", title, quantity);
}

void printBookQuantityFooter()
{
    printf("+------------------------------------------+\n");
}

void printGenreHeader() {
    printf("+------------------------------+\n");
    printf("| %-20s | %-6s |\n", "THE LOAI", "S.LUONG");
    printf("+------------------------------+\n");
}

void printGenreRow(const char genre[], int quantity) {
    printf("| %-20s | %6d |\n", genre, quantity);
}

void printGenreFooter() {
    printf("+------------------------------+\n");
}

void printReaderCardStatHeader() {
    printf("+-------------------------------------------------------------------------------+\n");
    printf("| %-30s | %-10s | %-10s | %-10s |\n", "HO TEN", "NG.SINH", "NG.LAP", "HET HAN");
    printf("+-------------------------------------------------------------------------------+\n");
}

void printReaderCardStatFooter() {
    printf("+---------------------------------------------------------------------------------+\n");
}

void printGenderStatHeader() {
    printf("+------------------------------------------+\n");
    printf("| %-30s | %-6s |\n", "HO TEN", "PHAI");
    printf("+------------------------------------------+\n");
}

void printGenderStatFooter() {
    printf("+------------------------------------------+\n");
}