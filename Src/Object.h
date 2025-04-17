#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Constants.h"
#include "Support.h"

#include <string.h>
using namespace std;

/**
 * @brief struct kiểm lỗi cho ngày được nhập vào
 */
struct ValidDate{
    /**
     * @brief Kiểm tra ngày có hợp lệ không 
     * @param day ngày được nhập vào
     * 
     * @return trả về true nếu hợp lệ, false nếu không hợp lệ
     * @details xét theo ngày dương lịch, 1 tháng có 30-31 ngày, kiểm tra ngày có nắm trong [1,31]
     */
    bool isValidDay(int day);

    /**
     * @brief Kiểm tra tháng có hợp lệ không 
     * @param month tháng được nhập vào
     * 
     * @return trả về true nếu hợp lệ, false nếu không hợp lệ
     * @details 1 năm chỉ có 12 tháng, từ tháng 1 đến tháng 12
     */
    bool isValidMonth(int month);

    /**
     * @brief Kiểm tra năm có hợp lệ không 
     * @param year năm được nhập vào
     * 
     * @return trả về true nếu hợp lệ, false nếu không hợp lệ
     * @details Chỉ xử lý ngoại lệ nếu nhập vào năm âm
     */
    bool isValidYear(int year);
};
/**
 * @brief Struct lưu trữ thông tin ngày tháng
 */
struct Date
{
    int day; /**< Ngày trong tháng */
    int month; /**< Tháng trong năm */
    int year; /**< Năm */

    /**
     * @brief Hàm tạo mặc định
     */
    Date();
    /**
     * @brief Hàm tạo chứa 3 tham số 
     * @param day Ngày trong tháng
     * @param month Tháng trong năm
     * @param year Năm
     */
    Date(int day, int month, int year);
    /**
     * @brief Hàm tạo sao chép
     * @param other lưu trữ thông tin khác của Date
     */
    Date(const Date& other);
    /**
     * @brief Chỉnh sửa toán tử bằng (Assignment operator)
     */
    Date &operator = (const Date& other);
    /**
     * @brief Hàm hủy
     */
    ~Date();
    /**
     * @brief nạp chồng toán tử nhập và xuất
     */
    friend istream& operator >> (istream& in, Date& date);
    friend ostream& operator << (ostream& os, const Date &other);
    /**
     * @brief Chỉnh sửa phép trừ giữa hai ngày
     */
    int operator-(const Date& other);

    /**
     * @brief Thêm tháng trong năm
     * @param months số tháng cộng thêm
     */
    void addMonths(int months);
    /**
     * @brief Thêm 1 ngày
     */
    void addOneDays();
    /**
     * @brief Thêm n ngày
     * @param days số ngày cộng thêm vào
     */
    void addNDays(int days);

    /**
     * @brief trừ đi 1 ngày
     */
    void minusOneDays();

    /**
     * @brief trừ đi n ngày
     * @param days số ngày trừ đi
     */
    void minusNDays(int days);
};

struct Reader
{
    char readerName[100]; /**<Tên độc giả */
    char readerId[20]; /**<Mã độc giả */
    char readerCCCD[100]; /**<CCCD độc giả */
    char readerMail[100]; /**<Emai; độc giả */
    char readerAddress[100]; /**<Địa chỉ độc giả */
    char readerGender[10]; /**<Giới tính độc giả */
    Date readerBirthday; /**<Ngày sinh độc giả */
    Date readerCardDates; /**<Ngày lập thẻ độc giả */
    Date readerExpiryDates; /**<Ngày hết hạn thẻ độc giả */

    /**
     * @brief Constructor mặc định.
     */

    Reader();
    /**
     * @brief Constructor có tham số.
     * @param readerName Tên độc giả.
     * @param readerId Mã độc giả.
     * @param readerCCCD CCCD của độc giả.
     * @param readerMail Email của độc giả.
     * @param readerAddress Địa chỉ của độc giả.
     * @param readerGender Giới tính của độc giả.
     * @param readerBirthday Ngày sinh của độc giả.
     * @param readerCardDates Ngày lập thẻ của độc giả.
     * @param readerExpiryDates Ngày hết hạn của thẻ độc giả.
     */

    Reader(char readerName[100], char readerId[20], char readerCCCD[100], char readerMail[100], char readerAddress[100], char readerGender[10], Date readerBirtday, Date readerCardDates, Date readerExpiryDates);
    /**
     * @brief Hàm tạo sao chép 
     * @param other Biến khác có kiểu Reader
     */
    Reader(const Reader& other);
    /**
     * @brief Chỉnh sửa toán tử gán
     */
    Reader &operator = (const Reader& other);
    /**
     * @brief Hàm hủy
     */
    ~Reader();
};

struct Book
{
    char bookISBN[20]; /**<ISBN của sách */
    char bookTitles[100]; /**<Tựa đề của sách */
    char bookAuthor[100]; /**<Tác giả của sách */
    char bookPublisher[100]; /**<Nhà xuất bản của sách */
    char bookGenres[50]; /**<Thể loại của sách */
    int bookPublisherYear; /**<Năm xuất bản của sách */
    int bookPrices; /**<Giá của sách */
    int bookQuantitites; /**<Số lượng của sách */

    Book();
    Book(char bookISBN[20], char bookTitles[100], char bookAuthor[100], char bookPulisher[100], char bookGenres[50], int bookPublisherYear, int bookPrices, int bookQuantites);
    Book(const Book& other);
    Book &operator=(const Book &other);
    ~Book();
};

struct BookLoan
{
    char loanReaderIds[20]; /**<ID độc giả trong phiếu mượn */
    char loanBooks[MAX_BORROWED_BOOKS][20]; /**<Mảng chứa các ISBN độc giả mượn */
    int loanBookQuantities[MAX_BORROWED_BOOKS]; /**<Số lượng của từng cuốn sách */
    Date loanDates; /**<Ngày mượn */
    Date returnDates; /**<Ngày trả dự kiến */
    Date returnDatesActual; /**<Ngày trả thực tế */
    int loanBookCount; /**<Số sách mượn */

    BookLoan();
    BookLoan(char loanReaderIds[20], char loanBooks[MAX_BORROWED_BOOKS][20], int loanBookQuantites[MAX_BORROWED_BOOKS], Date loanDates, Date returnDates, Date returnDateActual, int loanBookCount);
    BookLoan(const BookLoan& other);
    BookLoan &operator=(const BookLoan& other);
    ~BookLoan();
};
#endif