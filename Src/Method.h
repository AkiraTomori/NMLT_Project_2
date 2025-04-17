#ifndef _METHOD_H_
#define _METHOD_H_

#include "Object.h"

// Reader.h
/**
 * @brief Tìm chỉ số của độc giả dựa trên CCCD.
 * 
 * @param readers Mảng độc giả.
 * @param countReader Số lượng độc giả.
 * @param cccd CCCD cần tìm.
 * @return int Chỉ số trong mảng nếu tìm thấy, -1 nếu không.
 */
int FindReaderBasedOnCCCD(Reader readers[], int countReader, char cccd[]);

/**
 * @brief Tìm chỉ số của độc giả dựa trên tên.
 * 
 * @param readers Mảng độc giả.
 * @param countReader Số lượng độc giả.
 * @param name Tên cần tìm.
 * @return int Chỉ số trong mảng nếu tìm thấy, -1 nếu không.
 */
int FindReaderBasedOnName(Reader readers[], int countReader, char name[]);

/**
 * @brief Tìm chỉ số của độc giả dựa trên mã ID.
 * 
 * @param readers Mảng độc giả.
 * @param countReader Số lượng độc giả.
 * @param id ID cần tìm.
 * @return int Chỉ số trong mảng nếu tìm thấy, -1 nếu không.
 */
int FindReaderBasedOnId(Reader readers[], int countReader, char id[]);

/**
 * @brief Kiểm tra tính duy nhất của ID độc giả.
 * 
 * @param readers Mảng độc giả.
 * @param countReader Số lượng độc giả.
 * @param inputID ID cần kiểm tra.
 * @return false Nếu ID là duy nhất.
 * @return true Nếu ID đã tồn tại.
 */
bool isUniqueID(const Reader readers[], int countReader, char inputID[]);

/**
 * @brief Kiểm tra tính duy nhất của CCCD độc giả.
 * 
 * @param readers Mảng độc giả.
 * @param countReader Số lượng độc giả.
 * @param inputCCCD CCCD cần kiểm tra.
 * @return false Nếu CCCD là duy nhất.
 * @return true Nếu CCCD đã tồn tại.
 */
bool isUniqueCCCD(const Reader readers[], int countReader, char inputCCCD[]);

// Book.h
/**
 * @brief Tìm chỉ số sách dựa trên ISBN.
 * 
 * @param books Mảng sách.
 * @param countBook Số lượng sách.
 * @param bookISBN ISBN cần tìm.
 * @return int Chỉ số trong mảng nếu tìm thấy, -1 nếu không.
 */
int FindBookBasedOnISBN(Book books[], int countBook, char bookISBN[]);

/**
 * @brief Tìm chỉ số sách dựa trên tiêu đề.
 * 
 * @param books Mảng sách.
 * @param countBook Số lượng sách.
 * @param bookTitle Tựa đề sách cần tìm.
 * @return int Chỉ số trong mảng nếu tìm thấy, -1 nếu không.
 */
int FindBookBasedOnTitle(Book books[], int countBook, char bookTitle[]);

/**
 * @brief Kiểm tra tính duy nhất của ISBN sách.
 * 
 * @param books Mảng sách.
 * @param countBook Số lượng sách.
 * @param inputISBN ISBN cần kiểm tra.
 * @return false Nếu ISBN là duy nhất.
 * @return true Nếu ISBN đã tồn tại.
 */
bool isUniqueISBN(const Book books[], int countBook, char inputISBN[]);

// BookLoan.h
/**
 * @brief Tìm chỉ số phiếu mượn sách dựa trên mã độc giả.
 * 
 * @param bookloans Mảng phiếu mượn.
 * @param countLoan Số lượng phiếu mượn.
 * @param input ID độc giả cần tìm.
 * @return int Chỉ số trong mảng nếu tìm thấy, -1 nếu không.
 */
int FindLoanReaderBaseOnID(BookLoan bookloans[], int countLoan, char input[]);

#endif