#ifndef _GET_DATA_H_
#define _GET_DATA_H_
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include "Reader.h"
#include "Constants.h"
using namespace std;

void readReader(const char *filename, Reader readers[], int &countReaders);

#endif