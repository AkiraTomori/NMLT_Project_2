#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_
#include "Reader.h"
#include "Book.h"
#include "BookLoan.h"
#include "Query.h"
#include "getData.h"

/**
 * @brief Thực thi chương trình chính .
 * 
 * @param reader Mảng độc giả.
 * @param countReaders Số lượng độc giả.
 * @param books Mảng sách.
 * @param countBooks Số lượng sách.
 * @param totalBooks Tổng số sách.
 * @param remainBooks Số sách còn lại.
 * @param bookloans Mảng phiếu mượn sách.
 * @param countLoan Số lượng phiếu mượn.
 */
void showTime(Reader reader[], int &countReaders, Book books[], int &countBooks, int &totalBooks, int &remainBooks, BookLoan bookloans[], int &countLoan);

/**
 * @brief Menu điều hướng quản lý độc giả.
 * 
 * @param reader Mảng độc giả.
 * @param countReader Số lượng độc giả.
 */
void ReaderMenu(Reader reader[], int countReader);

/**
 * @brief Menu điều hướng quản lý sách.
 * 
 * @param books Mảng sách.
 * @param countBook Số lượng sách.
 * @param totalBooks Tổng số sách.
 * @param remainBooks Số sách còn lại.
 */
void BookMenu(Book books[], int countBook, int &totalBooks, int &remainBooks);

/**
 * @brief Menu điều hướng cho chức năng mượn/trả sách.
 * 
 * @param reader Mảng độc giả.
 * @param countReader Số lượng độc giả.
 * @param books Mảng sách.
 * @param countBook Số lượng sách.
 * @param remainBooks Số sách còn lại.
 * @param bookloans Mảng phiếu mượn sách.
 * @param countLoan Số lượng phiếu mượn.
 */
void loanMenu(Reader reader[], int countReader, Book books[], int countBook, int &remainBooks, BookLoan bookloans[], int &countLoan);

/**
 * @brief Giao diện mượn sách từ menu chính.
 * 
 * @param reader Mảng độc giả.
 * @param countReader Số lượng độc giả.
 * @param books Mảng sách.
 * @param countBook Số lượng sách.
 * @param remainBooks Số sách còn lại.
 * @param bookloans Mảng phiếu mượn sách.
 * @param countLoan Số lượng phiếu mượn.
 */
void borrowBooksMenu(Reader reader[], int countReader, Book books[], int countBook, int &remainBooks, BookLoan bookloans[], int &countLoan);

/**
 * @brief Giao diện trả sách từ menu chính.
 * 
 * @param reader Mảng độc giả.
 * @param countReader Số lượng độc giả.
 * @param books Mảng sách.
 * @param countBook Số lượng sách.
 * @param remainBooks Số sách còn lại.
 * @param bookloans Mảng phiếu mượn sách.
 * @param countLoan Số lượng phiếu mượn.
 */
void returnBooksMenu(Reader reader[], int countReader, Book books[], int countBook, int &remainBooks, BookLoan bookloans[], int countLoan);

/**
 * @brief Menu thống kê và truy vấn thông tin (sách, độc giả, mượn/trả).
 * 
 * @param reader Mảng độc giả.
 * @param countReader Số lượng độc giả.
 * @param books Mảng sách.
 * @param countBook Số lượng sách.
 * @param bookloans Mảng phiếu mượn sách.
 * @param countLoan Số lượng phiếu mượn.
 */
void QueryMenu(Reader reader[], int countReader, Book books[], int countBook, BookLoan bookloans[], int countLoan);


#endif