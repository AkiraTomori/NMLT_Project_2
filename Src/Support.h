#ifndef _SUPPORT_H_
#define _SUPPORT_H_
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

/**
 * @brief Kiểm tra xem một năm có phải là năm nhuận không
 * 
 * @param year Giá trị năm
 * 
 * @return true nếu là năm nhuận
 * @return false nếu không phải năm nhuận
 */
bool isLeapYear(int year);
/**
 * @brief Lấy ra những ngày trong tháng 
 * 
 * @param month giá trị tháng trong năm
 * @param year giá trị năm
 * @return trả về số ngày trong một tháng
 * 
 * @details Nếu là tháng 1, 3, 5, 7, 8, 10, 12 thì trả 31 ngày
 *          Nếu là tháng 4, 6, 9, 11 thì trả 30 ngày
 *          Nếu là tháng 2, kiểm tra xem có phải năm nhuận không, nếu năm nhuận thì trả 29 ngày, không phải thì 28 ngày
 */
int getDaysInMonth(int month, int year);

/**
 * @brief Khung viền trang trí số 1
 */
void header1();

/**
 * @brief Khung viền trang trí số 2
 */
void header2();

void header3();

void displayReaderHeader();

void displayBookHeader();

string formatISBN(const string& rawISBN);

void printBorder(char ch);

void printCenteredLine(const char text[]);

void printMenuLine(const char text[]);

void printPromptLine(const char text[]);
#endif