#ifndef _GET_DATA_H_
#define _GET_DATA_H_

#include <fstream>
#include "Method.h"

/**
 * @brief Đọc thông tin độc giả trong file Reader.txt
 * @param filename tên file (Files/Reader.txt)
 * @param readers Mảng lưu trữ danh sách độc giả
 * @param countReaders Số lượng độc giả
 */
void readReader(const char *filename, Reader readers[], int &countReaders);

/**
 * @brief Đọc thông tin sách trong file Book.txt
 * @param filename tên file (Files/Book.txt)
 * @param books Mảng lưu trữ danh sách sách
 * @param countBook Số lượng sách
 * @param totalBooks Tổng số sách theo lý thuyết
 * @param remainBooks Tổng số sách theo thực tế
 * 
 * @details totalBooks sẽ đếm những sách của thư viện, remainBooks sử dụng để đếm những sách sau khi được độc giả mượn
 */
void readBook(const char *filename, Book books[], int &countBook, int &totalBooks, int &remainBooks);
#endif