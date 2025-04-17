#ifndef _QUERY_H_
#define _QUERY_H_

#include "Method.h"
/**
 * @brief Đếm số lượng sách ở trong thư viện (theo lý thuyết)
 * @param books Mảng lưu trữ chứa danh sách của sách
 * @param countBook số lượng sách
 * @return trả về số lượng sách sau khi thống kê lại
 */
int countTotalBooks(Book books[], int countBook);
/**
 * @brief Đếm số lượng sách theo thể loại
 * @param books Mảng lưu trữ chứa danh sách của sách
 * @param countBook số lượng sách
 */
void countBookByGenres(Book books[], int countBook);
/**
 * @brief Đếm số lượng độc giả hiện có
 * @param readers Mảng lưu trữ danh sách độc giả
 * @param countReader số lượng độc giả
 * @return trả về số lượng độc giả hiện có 
 */
int countTotalReaders(Reader readers[], int countReader);
/**
 * @brief Đếm số lượng độc giả theo giới tính
 * @param readers Mảng lưu trữ danh sách độc giả
 * @param countReader số lượng độc giả
 */
void countReaderByGenders(Reader readers[], int countReader);
/**
 * @brief Đếm số lượng sách đang được độc giả mượn
 * @param bookloans Mảng lưu trữ các phiếu mượn sách của độc giả
 * @param countLoan số lượng phiếu mượn sách
 * @return trả về số lượng sách đang được mượn
 */
int countBorrowedBooks(BookLoan bookloans[], int countLoan);
/**
 * @brief Thống kê số lượng độc giả bị trễ hẹn
 * @param bookloans Mảng lưu trữ các phiếu mượn sách của độc giả
 * @param countLoan số lượng phiếu mượn sách
 */
void listOverdueReaders(Reader readers[], int countReader, BookLoan bookLoans[], int countLoan);

/**
 * @brief Hiển thị tổng số lượng sách trong thư viện.
 * @param books Mảng sách.
 * @param countBook Số lượng sách.
 */
void countTotalBooksMenu(Book books[], int countBook);

/**
 * @brief Hiển thị số lượng sách theo từng thể loại.
 * @param books Mảng sách.
 * @param countBook Số lượng sách.
 */
void countBookByGenresMenu(Book books[], int countBook);

/**
 * @brief Hiển thị số lượng độc giả theo giới tính.
 * @param readers Mảng độc giả.
 * @param countReader Số lượng độc giả.
 */
void countReaderMenu(Reader readers[], int countReader);

/**
 * @brief Hiển thị số lượng độc giả theo giới tính.
 * @param readers Mảng độc giả.
 * @param countReader Số lượng độc giả.
 */
void countReaderByGenderMenu(Reader readers[], int countReader);

/**
 * @brief Hiển thị số lượng sách đang được mượn.
 * @param readers Mảng độc giả.
 * @param countReader Số lượng độc giả.
 * @param bookloans Mảng phiếu mượn sách.
 * @param countLoan Số lượng phiếu mượn.
 */
void countBorrowedBooksMenu(Reader readers[], int countReader, BookLoan bookloans[], int countLoan);

/**
 * @brief Hiển thị danh sách độc giả bị trễ hẹn trả sách.
 * @param readers Mảng độc giả.
 * @param countReader Số lượng độc giả.
 * @param bookloans Mảng phiếu mượn sách.
 * @param countLoan Số lượng phiếu mượn.
 */
void listOverdueReadersMenu(Reader readers[], int countReader, BookLoan bookloans[], int countLoan);

/**
 * @brief Hiển thị các độc giả đang có phiếu mượn sách chưa trả.
 * @param readers Mảng độc giả.
 * @param countReader Số lượng độc giả.
 * @param bookloans Mảng phiếu mượn sách.
 * @param countLoan Số lượng phiếu mượn.
 */
void displayActiveLoanReaders(Reader readers[], int countReader, BookLoan bookloans[], int countLoan);
#endif