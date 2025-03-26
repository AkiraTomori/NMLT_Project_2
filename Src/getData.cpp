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
    // fgets(line, MAX_LINE, file);
    // bool isFirstRow = true;
    while (fgets(line, MAX_LINE, file) != nullptr)
    {
        // if (isFirstRow)
        // {
        //     isFirstRow = false;
        //     continue;
        // }
        Reader newReader;
        fscanf(file, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%d/%d/%d-%d/%d/%d-%d/%d/%d", newReader.readerName, newReader.readerId, newReader.readerCCCD, newReader.readerMail, newReader.readerAddress, newReader.readerGender, &newReader.readerBirthday.day, &newReader.readerBirthday.month, &newReader.readerBirthday.year, &newReader.readerCardDates.day, &newReader.readerCardDates.month, &newReader.readerCardDates.year, &newReader.readerExpiryDates.day, &newReader.readerExpiryDates.month, &newReader.readerExpiryDates.year);
        readers[countReaders] = newReader;
        countReaders++;
    }
    fclose(file);
}