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
    // displayAllReaders(readers, countReaders);

    readBook("Files/Book.txt", books, countBook, totalBooks, remainBooks);
    for (int i = 0; i < countBook; i++){
        // Book presentBook = books[i];
        string ISBNformat = formatISBN(string(books[i].bookISBN));
        strcpy(books[i].bookISBN, ISBNformat.c_str());
    }
    // viewBooks(books, countBook);
    // cout << "Tong so sach: " << totalBooks << "\n";
    // cout << "Tong so sach con lai: " << remainBooks << "\n";

    // cout << "Tong so sach sau thong ke: " << countTotalBooks(books, countBook) << "\n";
    // countBookByGenres(books, countBook);
    // cout << "Tong so doc gia: " << countTotalReaders(readers, countReaders) << "\n";
    // countReaderByGenders(readers, countReaders);
    
    showTime(readers, countReaders, books, countBook, totalBooks, remainBooks, bookLoans, countBookLoan);
    return 0;
}