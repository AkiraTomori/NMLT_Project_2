#ifndef _READER_H_
#define _READER_H_

#include "Method.h"
#include <sstream>

void displayReader(Reader readers[], int ReaderIndex);
void addReader(Reader readers[], int &countReader);
void displayAllReaders(Reader readers[], int countReader);
void editReader(Reader readers[], int countReader);
void removeReader(Reader readers[], int &countReader);
void findReaderBaseOnCCCD(Reader readers[], int countReader);
void findReaderBaseOnName(Reader readers[], int countReader);
Reader createReader(const Reader readers[], int countReader);

#endif