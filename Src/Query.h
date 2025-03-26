#ifndef _QUERY_H_
#define _QUERY_H_

#include "Object.h"
using namespace std;

int countTotalBooks(Book books[], int countBook);
void countBookByGenres(Book books[], int countBook);
int countTotalReaders(Reader readers[], int countReader);
void countReaderByGenders(Reader readers[], int countReader);

#endif