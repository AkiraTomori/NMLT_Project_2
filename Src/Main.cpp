#include "getData.h"
#include "Book.h"
#include "Reader.h"
#include "BookLoan.h"

struct BookLoan
{
    char loanReaderIds[20];
    char loanBooks[MAX_BORROWED_BOOKS][20];
    int loanBookQuantities[MAX_BORROWED_BOOKS];
    Date loanDates;
    Date returnDates;
    Date returnDatesActual;
    int loanBookCount;
};


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
    return 0;
}