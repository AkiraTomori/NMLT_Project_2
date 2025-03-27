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
void listOverdueReaders(BookLoan bookLoans[], int countLoan);

#endif