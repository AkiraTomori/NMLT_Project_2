#include "Query.h"

int countTotalBooks(Book books[], int countBook)
{
    int totalBooks = 0;
    for (int i = 0; i < countBook; i++)
    {
        totalBooks += books[i].bookQuantitites;
    }
    return totalBooks;
}
void countBookByGenres(Book books[], int countBook)
{
    int genreCount[MAX_BOOKS] = {0};
    int uniqueGenres = 0;
    char genres[MAX_BOOKS][50];
    for (int i = 0; i < countBook; i++)
    {
        bool found = false;
        for (int j = 0; j < uniqueGenres; j++)
        {
            if (strcmp(books[i].bookGenres, genres[j]) == 0)
            {
                genreCount[j] += books[i].bookQuantitites;
                found = true;
                break;
            }
        }
        if (!found)
        {
            strcpy(genres[uniqueGenres], books[i].bookGenres);
            genreCount[uniqueGenres] = books[i].bookQuantitites;
            uniqueGenres++;
        }
    }
    cout << "Thong ke so luong sach theo the loai: \n";
    for (int i = 0; i < uniqueGenres; i++)
    {
        cout << genres[i] << ": " << genreCount[i] << ".\n";
    }
}
int countTotalReaders(Reader readers[], int countReader)
{
    return countReader;
}
void countReaderByGenders(Reader readers[], int countReader)
{
    int male = 0, female = 0;
    for (int i = 0; i < countReader; i++)
    {
        if (strcmp(readers[i].readerGender, "Nam") == 0)
            male++;
        else if (strcmp(readers[i].readerGender, "Nu") == 0)
            female++;
    }
    cout << "So luong doc gia nam: " << male << "\n";
    cout << "So luong doc gia nu: " << female << "\n";
}
int countBorrowedBooks(BookLoan bookloans[], int countLoan)
{
    int totalBorrowedBooks = 0;
    for (int i = 0; i < countLoan; i++)
    {
        for (int j = 0; j < bookloans[i].loanBookCount; j++)
        {
            totalBorrowedBooks += bookloans[i].loanBookQuantities[j];
        }
    }
    return totalBorrowedBooks;
}
void listOverdueReaders(BookLoan bookLoans[], int countLoan)
{
    cout << "Danh sach doc gia bi tre hen: \n";
    for (int i = 0; i < countLoan; i++)
    {
        int overDueDays = bookLoans[i].returnDatesActual - bookLoans[i].returnDates;
        if (overDueDays > 0)
        {
            printf("Doc gia co ma doc gia %s bi tre hen %d ngay", bookLoans[i].loanReaderIds, overDueDays);
        }
    }
}