#ifndef _GET_DATA_H_
#define _GET_DATA_H_

#include <fstream>
#include "Method.h"

void readReader(const char *filename, Reader readers[], int &countReaders);
void readBook(const char *filename, Book books[], int &countBook, int &totalBooks, int &remainBooks);
#endif