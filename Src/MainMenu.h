#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_
#include "Reader.h"
#include "Book.h"
#include "BookLoan.h"
#include "Query.h"
#include "getData.h"

void showTime(Reader reader[], int &countReaders, Book books[], int &countBooks, int &totalBooks, int &remainBooks, BookLoan bookloans[], int &countLoan);


#endif