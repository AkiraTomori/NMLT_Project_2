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
    
    readReader("Files/Reader.txt", readers, countReaders);
    displayAllReaders(readers, countReaders);

    readBook("Files/Book.txt", books, countBook, totalBooks, remainBooks);
    viewBooks(books, countBook);
    cout << "Tong so sach: " << totalBooks << "\n";
    cout << "Tong so sach con lai: " << remainBooks << "\n";

    cout << "Tong so sach sau thong ke: " << countTotalBooks(books, countBook) << "\n";
    countBookByGenres(books, countBook);
    cout << "Tong so doc gia: " << countTotalReaders(readers, countReaders) << "\n";
    countReaderByGenders(readers, countReaders);
    
    return 0;
}