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
    printGenreHeader();
    for (int i = 0; i < uniqueGenres; i++)
    {
        printGenreRow(genres[i], genreCount[i]);
    }
    printGenreFooter();
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
        if (!(bookloans[i].loanDates.day == 1 &&
              bookloans[i].loanDates.month == 1 &&
              bookloans[i].loanDates.year == 2000))
        {
            for (int j = 0; j < bookloans[i].loanBookCount; j++)
            {
                totalBorrowedBooks += bookloans[i].loanBookQuantities[j];
            }
        }
    }
    return totalBorrowedBooks;
}

void listOverdueReaders(Reader readers[], int countReader, BookLoan bookLoans[], int countLoan)
{
    printf("+================================================ DANH SACH DOC GIA TRE HEN ===============================================+\n");
    printf("| %-20s | %-30s | %-15s | %-12s | %-12s | %-12s |\n",
           "Ma doc gia", "Ten doc gia", "So ngay tre hen", "Ngay muon", "Ngay tra", "Ngay tra thuc te");
    printf("+--------------------------------------------------------------------------------------------------------------------------+\n");

    for (int i = 0; i < countLoan; i++)
    {
        int overDueDays = bookLoans[i].returnDatesActual - bookLoans[i].returnDates;
        if (overDueDays > 0)
        {
            int readerIndex = FindReaderBasedOnId(readers, countReader, bookLoans[i].loanReaderIds);
            char loanDates[11], returnDates[11], returnDatesActual[11];
            bookLoans[i].loanDates = bookLoans[i].returnDates;
            int ONE_WEEK = 7;
            bookLoans[i].loanDates.minusNDays(ONE_WEEK);
            sprintf(loanDates, "%02d/%02d/%02d", bookLoans[i].loanDates.day, bookLoans[i].loanDates.month, bookLoans[i].loanDates.year);
            sprintf(returnDates, "%02d/%02d/%02d", bookLoans[i].returnDates.day, bookLoans[i].returnDates.month, bookLoans[i].returnDates.year);
            sprintf(returnDatesActual, "%02d/%02d/%02d", bookLoans[i].returnDatesActual.day, bookLoans[i].returnDatesActual.month, bookLoans[i].returnDatesActual.year);
            printf("| %-20s | %-30s | %-15d | %-12s | %-12s | %-12s     |\n", bookLoans[i].loanReaderIds, readers[readerIndex].readerName, overDueDays, loanDates, returnDates, returnDatesActual);
            bookLoans[i].loanDates = Date(1, 1, 2000);
            printf("+--------------------------------------------------------------------------------------------------------------------------+\n");
        }
    }

    printf("+==========================================================================================================================+\n");
}
void countTotalBooksMenu(Book books[], int countBook)
{
    printf("Tong so luong sach trong thu vien: %d \n", countTotalBooks(books, countBook));
    printBookQuantityHeader();
    for (int i = 0; i < countBook; i++)
    {
        printBookQuantityRow(books[i].bookTitles, books[i].bookQuantitites);
    }
    printBookQuantityFooter();
    system("pause");
    system("cls");
}

void countBookByGenresMenu(Book books[], int countBook)
{
    countBookByGenres(books, countBook);
    system("pause");
    system("cls");
}

void countReaderMenu(Reader readers[], int countReader)
{
    printf("Tong so luong doc gia: %d \n", countTotalReaders(readers, countReader));
    printReaderCardStatHeader();
    for (int i = 0; i < countReader; i++)
    {
        char birth[11], card[11], exp[11];
        Reader presentReader = readers[i];
        sprintf(birth, "%02d/%02d/%02d", presentReader.readerBirthday.day, presentReader.readerBirthday.month, presentReader.readerBirthday.year);
        sprintf(card, "%02d/%02d/%02d", presentReader.readerCardDates.day, presentReader.readerCardDates.month, presentReader.readerCardDates.year);
        sprintf(exp, "%02d/%02d/%02d", presentReader.readerExpiryDates.day, presentReader.readerExpiryDates.month, presentReader.readerExpiryDates.year);

        printf("| %-30s | %-10s | %-10s | %-10s |\n", presentReader.readerName, birth, card, exp);
    }
    printReaderCardStatFooter();
    system("pause");
    system("cls");
}

void countReaderByGenderMenu(Reader readers[], int countReader)
{
    countReaderByGenders(readers, countReader);
    printGenderStatHeader();
    for (int i = 0; i < countReader; i++)
    {
        printf("| %-30s | %-6s |\n", readers[i].readerName, readers[i].readerGender);
    }
    printGenderStatFooter();
    system("pause");
    system("cls");
}

void displayActiveLoanReaders(Reader readers[], int countReader, BookLoan bookloans[], int countLoan)
{
    printf("+----------------------+------------------------------+------------------------+--------------+--------------+\n");
    printf("| Ma doc gia           | Ten doc gia                  | So sach dang muon      | Ngay muon    | Ngay phai tra|\n");
    printf("+----------------------+------------------------------+------------------------+--------------+--------------+\n");

    for (int i = 0; i < countLoan; i++)
    {
        if (!(bookloans[i].loanDates.day == 1 && bookloans[i].loanDates.month == 1 && bookloans[i].loanDates.year == 2000))
        {
            int bookCount = 0;
            for (int j = 0; j < bookloans[i].loanBookCount; j++)
            {
                bookCount += bookloans[i].loanBookQuantities[j];
            }
            int readerIndex = FindReaderBasedOnId(readers, countReader, bookloans[i].loanReaderIds);
            if (readerIndex != -1)
            {
                printf("| %-20s | %-28s | %-22d | %02d/%02d/%4d   | %02d/%02d/%4d   |\n",
                       readers[readerIndex].readerId,
                       readers[readerIndex].readerName,
                       bookCount,
                       bookloans[i].loanDates.day,
                       bookloans[i].loanDates.month,
                       bookloans[i].loanDates.year,
                       bookloans[i].returnDates.day,
                       bookloans[i].returnDates.month,
                       bookloans[i].returnDates.year);
            }
        }
    }
    printf("+----------------------+------------------------------+------------------------+--------------+--------------+\n");
}

void countBorrowedBooksMenu(Reader readers[], int countReader, BookLoan bookloans[], int countLoan)
{
    printf("Tong so luong sach dang duoc muon: %d \n", countBorrowedBooks(bookloans, countLoan));
    displayActiveLoanReaders(readers, countReader, bookloans, countLoan);
    system("pause");
    system("cls");
}

void listOverdueReadersMenu(Reader readers[], int countReader, BookLoan bookloans[], int countLoan)
{
    listOverdueReaders(readers, countReader, bookloans, countLoan);
    system("pause");
    system("cls");
}