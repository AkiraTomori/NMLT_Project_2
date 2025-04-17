#ifndef _READER_H_
#define _READER_H_

#include "Method.h"
#include <sstream>

/**
 * @brief Hiển thị thông tin của một độc giả.
 * @param readers Mảng độc giả.
 * @param ReaderIndex Vị trí của độc giả cần hiển thị.
 */
void displayReader(Reader readers[], int ReaderIndex);

/**
 * @brief Thêm một độc giả mới vào hệ thống.
 * @param readers Mảng độc giả.
 * @param countReader Biến lưu số lượng độc giả, sẽ được cập nhật sau khi thêm.
 */
void addReader(Reader readers[], int &countReader);

/**
 * @brief Hiển thị danh sách toàn bộ độc giả.
 * @param readers Mảng độc giả.
 * @param countReader Số lượng độc giả hiện có.
 */
void displayAllReaders(Reader readers[], int countReader);

/**
 * @brief Chỉnh sửa thông tin của một độc giả.
 * @param readers Mảng độc giả.
 * @param countReader Số lượng độc giả.
 */
void editReader(Reader readers[], int countReader);

/**
 * @brief Xóa một độc giả khỏi hệ thống.
 * @param readers Mảng độc giả.
 * @param countReader Số lượng độc giả, sẽ giảm sau khi xóa.
 */
void removeReader(Reader readers[], int &countReader);

/**
 * @brief Tìm độc giả dựa vào CCCD.
 * @param readers Mảng độc giả.
 * @param countReader Số lượng độc giả.
 */
void findReaderBaseOnCCCD(Reader readers[], int countReader);

/**
 * @brief Tìm độc giả dựa vào tên.
 * @param readers Mảng độc giả.
 * @param countReader Số lượng độc giả.
 */
void findReaderBaseOnName(Reader readers[], int countReader);

/**
 * @brief Tạo một độc giả mới với dữ liệu hợp lệ.
 * @param readers Mảng độc giả hiện tại.
 * @param countReader Số lượng độc giả.
 * @return Độc giả vừa tạo.
 */
Reader createReader(const Reader readers[], int countReader);

#endif