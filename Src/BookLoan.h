#ifndef _BOOK_LOAN_H_
#define _BOOK_LOAN_H_

#include "Method.h"

/**
 * @brief Thực hiện chức năng mượn sách cho độc giả.
 * @param readers Mảng độc giả.
 * @param countReader Số lượng độc giả.
 * @param books Mảng sách.
 * @param countBook Số lượng sách.
 * @param bookloans Mảng phiếu mượn sách.
 * @param countLoan Số lượng phiếu mượn, sẽ tăng lên sau khi mượn.
 * @param remainBooks Tổng số sách còn lại sau khi mượn.
 */
void borrowBooks(Reader readers[], int countReader, Book books[], int countBook, BookLoan bookloans[], int &countLoan, int &reaminBooks);

/**
 * @brief Thực hiện chức năng trả sách cho độc giả.
 * @param readers Mảng độc giả.
 * @param countReader Số lượng độc giả.
 * @param books Mảng sách.
 * @param countBook Số lượng sách.
 * @param bookloans Mảng phiếu mượn sách.
 * @param countLoan Số lượng phiếu mượn.
 * @param remainBooks Tổng sách còn lại sau khi trả.
 */
void returnBooks(Reader readers[], int countReader, Book books[], int countBook, BookLoan bookloans[], int countLoan, int &remainBooks);

#endif