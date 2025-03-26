#include "getData.h"

void readReader(const char *filename, Reader readers[], int &countReaders)
{
    FILE *file = fopen(filename, "r");
    if (file == nullptr)
    {
        printf("Khong the mo duoc file: %s", filename);
        return;
    }
    const int MAX_LINE = 512;
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, file) != nullptr)
    {
        Reader newReader;
        fscanf(file, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%d/%d/%d-%d/%d/%d-%d/%d/%d", newReader.readerName, newReader.readerId, newReader.readerCCCD, newReader.readerMail, newReader.readerAddress, newReader.readerGender, &newReader.readerBirthday.day, &newReader.readerBirthday.month, &newReader.readerBirthday.year, &newReader.readerCardDates.day, &newReader.readerCardDates.month, &newReader.readerCardDates.year, &newReader.readerExpiryDates.day, &newReader.readerExpiryDates.month, &newReader.readerExpiryDates.year);
        readers[countReaders] = newReader;
        countReaders++;
    }
    fclose(file);
}
void readBook(const char *filename, Book books[], int &countBook, int &totalBooks, int &remainBooks)
{
    FILE *file = fopen(filename, "r");
    if (file == nullptr)
    {
        printf("Khong the mo duoc file: %s", filename);
        return;
    }
    const int MAX_LINE = 512;
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, file) != nullptr)
    {
        Book newBook;
        fscanf(file, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%d-%d-%d", newBook.bookISBN, newBook.bookTitles, newBook.bookAuthor, newBook.bookPublisher, newBook.bookGenres, &newBook.bookPublisherYear, &newBook.bookPrices, &newBook.bookQuantitites);
        totalBooks += newBook.bookQuantitites;
        remainBooks += newBook.bookQuantitites;
        books[countBook] = newBook;
        countBook++;
    }
    fclose(file);
}