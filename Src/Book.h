#ifndef _BOOK_H_
#define _BOOK_H_

#include "Method.h"

/**
 * @brief Hiển thị thông tin chi tiết của một cuốn sách.
 * @param books Mảng sách.
 * @param bookIndex Vị trí sách cần hiển thị.
 */
void displayBookInfo(Book books[], int bookIndex);

/**
 * @brief Hiển thị toàn bộ danh sách sách.
 * @param books Mảng sách.
 * @param countBooks Số lượng sách.
 */
void viewBooks(Book books[], int countBooks);

/**
 * @brief Thêm một hoặc nhiều sách mới vào hệ thống.
 * @param books Mảng sách.
 * @param countBooks Số lượng sách hiện có.
 * @param totalBooks Tổng số lượng sách trong thư viện.
 * @param remainBooks Tổng số lượng sách còn lại (chưa cho mượn).
 */
void addBooks(Book books[], int &countBooks, int &totalBooks, int &remainBooks);

/**
 * @brief Chỉnh sửa thông tin của sách.
 * @param books Mảng sách.
 * @param countBooks Số lượng sách.
 * @param totalBooks Tổng số sách.
 * @param remainBooks Số lượng sách chưa được mượn.
 */
void editBooks(Book books[], int countBooks, int &totalBooks, int &remainBooks);

/**
 * @brief Xóa sách khỏi thư viện.
 * @param books Mảng sách.
 * @param countBooks Số lượng sách, sẽ giảm sau khi xóa.
 * @param totalBooks Tổng số sách.
 * @param remainBooks Tổng sách còn lại sau khi xóa.
 */
void removeBooks(Book books[], int &countBooks, int &totalBooks, int &remainBooks);

/**
 * @brief Tìm kiếm sách dựa vào ISBN.
 * @param books Mảng sách.
 * @param countBook Số lượng sách.
 */
void findBookBaseOnISBN(Book books[], int countBook);

/**
 * @brief Tìm kiếm sách dựa vào tiêu đề.
 * @param books Mảng sách.
 * @param countBook Số lượng sách.
 */
void findBookBaseOnTitle(Book books[], int countBook);

/**
 * @brief Tạo một sách mới với dữ liệu hợp lệ.
 * @param books Mảng sách hiện tại.
 * @param countBook Số lượng sách.
 * @return Sách vừa tạo.
 */
Book createBook(const Book books[], int countBook);

#endif