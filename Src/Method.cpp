#include "Method.h"
// Reader.h
int FindReaderBasedOnCCCD(Reader readers[], int countReader, char cccd[])
{
    int index = -1;
    for (int i = 0; i < countReader; i++)
    {
        if (strcmp(readers[i].readerCCCD, cccd) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int FindReaderBasedOnName(Reader readers[], int countReader, char name[])
{
    int index = -1;
    for (int i = 0; i < countReader; i++)
    {
        if (strcmp(readers[i].readerName, name) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int FindReaderBasedOnId(Reader readers[], int countReader, char id[])
{
    int index = -1;
    for (int i = 0; i < countReader; i++)
    {
        if (strcmp(readers[i].readerId, id) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

bool isUniqueID(const Reader readers[], int countReader, char inputID[])
{
    bool isFound = false;
    for (int i = 0; i < countReader; i++){
        Reader presentReader = readers[i];
        // Nếu tìm ra ID trong danh sách thì không được phép, trả về true
        if (strcmp(presentReader.readerId, inputID) == 0){
            isFound = true;
            break;
        }
    }
    return isFound;
}

bool isUniqueCCCD(const Reader readers[], int countReader, char inputCCCD[])
{
    bool isFound = false;
    for (int i = 0; i < countReader; i++){
        Reader presentReader = readers[i];
        // Nếu tìm ra CCCD trong danh sách thì không được phép, trả về true
        if (strcmp(presentReader.readerCCCD, inputCCCD) == 0){
            isFound = true;
            break;
        }
    }
    return isFound;
}
// Book.h

int FindBookBasedOnISBN(Book books[], int countBook, char bookISBN[])
{
    int index = -1;
    for (int i = 0; i < countBook; i++)
    {
        if (strcmp(books[i].bookISBN, bookISBN) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int FindBookBasedOnTitle(Book books[], int countBook, char bookTitle[])
{
    int index = -1;
    for (int i = 0; i < countBook; i++)
    {
        if (strcmp(books[i].bookTitles, bookTitle) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

bool isUniqueISBN(const Book books[], int countBook, char inputISBN[]){
    bool isFound = false;
    for (int i = 0; i < countBook; i++){
        Book presentBook = books[i];
        // Nếu đã tồn tại ISBN trước đó thì không được phép, trả về true
        if (strcmp(presentBook.bookISBN, inputISBN) == 0){
            isFound = true;
            break;
        }
    }
    return isFound;
}

// BookLoan.h
int FindLoanReaderBaseOnID(BookLoan bookloans[], int countLoan, char input[])
{
    int index = -1;
    for (int i = 0; i < countLoan; i++)
    {
        if (strcmp(bookloans[i].loanReaderIds, input) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}