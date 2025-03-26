#ifndef _READER_H_
#define _READER_H_

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include "Constants.h"
#include "Support.h"

using namespace std;

struct Reader
{
    char readerName[100];
    char readerId[20];
    char readerCCCD[100];
    char readerMail[100];
    char readerAddress[100];
    char readerGender[10];
    Date readerBirthday;
    Date readerCardDates;
    Date readerExpiryDates;

    Reader();
    Reader(char readerName[100], char readerId[20], char readerCCCD[100], char readerMail[100], char readerAddress[100], char readerGender[10], Date readerBirtday, Date readerCardDates, Date readerExpiryDates);
    Reader(const Reader& other);
    Reader &operator = (const Reader& other);
    ~Reader();
};

void displayReader(Reader readers[], int ReaderIndex);
void addReader(Reader readers[], int &countReader);
void displayAllReaders(Reader readers[], int countReader);
void editReader(Reader readers[], int countReader);
void removeReader(Reader readers[], int &countReader);
void findReaderBaseOnCCCD(Reader readers[], int countReader);
void findReaderBaseOnName(Reader readers[], int countReader);
Reader createReader();

int FindReaderBasedOnCCCD(Reader readers[], int countReader, char cccd[]);
int FindReaderBasedOnName(Reader readers[], int countReader, char name[]);
int FindReaderBasedOnId(Reader readers[], int countReader, char id[]);
#endif