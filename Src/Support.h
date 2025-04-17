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

/**
 * @brief Khung viền trang trí số 3
 */
void header3();

/**
 * @brief Header cho hiển thị thông tin độc giả
 */
void displayReaderHeader();

/**
 * @brief Header cho hiển thị thông tin sách
 */
void displayBookHeader();

/**
 * @brief Chuẩn hóa ISBN
 * @param rawISBN Chuỗi ISBN thô
 * 
 * @return trả về chuỗi ISBN theo quốc tế
 */
string formatISBN(const string& rawISBN);

/**
 * @brief In khung viền
 * @param ch kí tự để in
 */
void printBorder(char ch);

/**
 * @brief In chữ để giữa
 * @param text Nội dung chữ
 */
void printCenteredLine(const char text[]);

/**
 * @brief In một dòng menu căn trái có định dạng rõ ràng.
 * 
 * @param text Văn bản của dòng menu.
 */
void printMenuLine(const char text[]);

/**
 * @brief In dòng gợi ý nhập dữ liệu, định dạng đẹp.
 * 
 * @param text Văn bản hướng dẫn hoặc thông báo.
 */
void printPromptLine(const char text[]);

/**
 * @brief Hiển thị tiêu đề bảng thống kê số lượng sách theo tựa đề.
 */
void printBookQuantityHeader();

/**
 * @brief In một dòng thông tin sách và số lượng tương ứng.
 * 
 * @param title Tựa đề sách.
 * @param quantity Số lượng sách.
 */
void printBookQuantityRow(const char title[], int quantity);

/**
 * @brief Hiển thị dòng kết thúc bảng thống kê số lượng sách.
 */
void printBookQuantityFooter();

/**
 * @brief Hiển thị tiêu đề bảng thống kê thể loại sách.
 */
void printGenreHeader();

/**
 * @brief In một dòng thông tin về thể loại sách và số lượng tương ứng.
 * 
 * @param genre Tên thể loại sách.
 * @param quantity Số lượng sách thuộc thể loại đó.
 */
void printGenreRow(const char genre[], int quantity);

/**
 * @brief Hiển thị dòng kết thúc bảng thể loại sách.
 */
void printGenreFooter();

/**
 * @brief Hiển thị tiêu đề bảng thống kê thẻ độc giả (còn hạn/hết hạn).
 */
void printReaderCardStatHeader();

/**
 * @brief Hiển thị dòng kết thúc bảng thống kê thẻ độc giả.
 */
void printReaderCardStatFooter();

/**
 * @brief Hiển thị tiêu đề bảng thống kê giới tính độc giả.
 */
void printGenderStatHeader();

/**
 * @brief Hiển thị dòng kết thúc bảng thống kê giới tính độc giả.
 */
void printGenderStatFooter();

#endif