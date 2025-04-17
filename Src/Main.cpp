#include "MainMenu.h"

int main()
{
    Reader readers[MAX_READERS];
    int countReaders = 0;
    Book books[MAX_BOOKS];
    int countBook = 0;
    BookLoan bookLoans[MAX_BOOK_LOANS];
    int countBookLoan = 0;

    int totalBooks = 0;
    int remainBooks = 0;
    // Đọc dữ liệu độc giả
    readReader("Files/Reader.txt", readers, countReaders);
    // Đọc dữ liệu sách
    readBook("Files/Book.txt", books, countBook, totalBooks, remainBooks);
    for (int i = 0; i < countBook; i++){
        // Book presentBook = books[i];
        // Chuẩn hóa ISBN theo quốc tế
        string ISBNformat = formatISBN(string(books[i].bookISBN));
        strcpy(books[i].bookISBN, ISBNformat.c_str());
    }
    
    // Thực thi chương trình chính
    showTime(readers, countReaders, books, countBook, totalBooks, remainBooks, bookLoans, countBookLoan);
    return 0;
}