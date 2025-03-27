#include "BookLoan.h"

void borrowBooks(Reader readers[], int countReader, Book books[], int countBook, BookLoan bookloans[], int &countLoan, int &remainBooks)
{
    cout << "Nhap vao ma doc gia: ";
    cin.ignore();
    char inputID[20];
    cin.getline(inputID, 20);
    int readerIndex = FindReaderBasedOnId(readers, countReader, inputID);
    BookLoan newBookLoan;
    while (readerIndex == -1)
    {
        cout << "Doc gia chua duoc them vao thu vien !\n";
        cout << "Hay nhap lai id de tim lai.\n";
        cout << "1. Nhap lai.\n";
        cout << "2. Khong nhap.\n";
        int choice = 0;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Nhap lai ma doc gia: ";
            cin.ignore();
            cin.getline(inputID, 20);
            readerIndex = FindReaderBasedOnId(readers, countReader, inputID);
        }
        else{
            cout << "Roi khoa cua so quan ly phieu muon sach thu vien.\n";
            return;
        }
    }
    if (readerIndex != -1)
    {
        cout << "Da tim thay ten doc gia: " << readers[readerIndex].readerName << "\n";
        strcpy(newBookLoan.loanReaderIds, readers[readerIndex].readerId);
    }
    int BorrowedBooks = 0;
    cout << "So sach ma doc gia muon muon la: ";
    cin >> BorrowedBooks;

    while (BorrowedBooks > MAX_BORROWED_BOOKS)
    {
        cout << "Moi doc gia chi co the muon toi da 10 cuon sach !\n";
        cout << "Hay nhap lai.\n";
        cin >> BorrowedBooks;
    }
    newBookLoan.loanBookCount = BorrowedBooks;
    for (int j = 0; j < BorrowedBooks; j++)
    {
        int bookIndex = -1;
        cout << "Sach ma doc gia muon muon (Nhap isbn hoac tua de): ";
        char isbnOrName[100];
        cin.ignore();
        cin.getline(isbnOrName, 100);
        while (bookIndex == -1)
        {
            bookIndex = FindBookBasedOnISBN(books, countBook, isbnOrName);
            if (bookIndex == -1)
            {
                bookIndex = FindBookBasedOnTitle(books, countBook, isbnOrName);
                if (bookIndex == -1)
                {
                    cout << "Sach khong ton tai.\n";
                    cout << "Hay nhap lai ISNB hoac ten.\n";
                    cin.getline(isbnOrName, 100);
                }
            }
        }
        cout << "Da tim thay sach: " << books[bookIndex].bookTitles << "\n";
        cout << "So luong cua sach nay muon muon: ";
        int quantity;
        while (quantity > books[bookIndex].bookQuantitites)
        {
            cout << "So luong sach trong kho khong du.\n";
            cout << "Hay nhap lai so luong: ";
            cin >> quantity;
        }
        strcpy(newBookLoan.loanBooks[j], books[bookIndex].bookISBN);
        newBookLoan.loanBookQuantities[j] = quantity;
        books[bookIndex].bookQuantitites -= quantity;
        remainBooks -= quantity;

        cout << "\n";
    }

    cout << "Ngay tao the (theo dd/mm/yyyy): \n";
    cin >> newBookLoan.loanDates;

    newBookLoan.returnDates = newBookLoan.loanDates;
    int OneWeek = 7;
    newBookLoan.returnDates.addNDays(OneWeek);

    cout << "Muon sach thanh cong.\n";
    bookloans[countLoan] = newBookLoan;
    countLoan++;

}
void returnBooks(Reader readers[], int countReader, Book books[], int countBook, BookLoan bookloans[], int countLoan, int &remainBooks)
{
    cout << "Nhap id cua doc gia: ";
    cin.ignore();
    char inputID[20];
    cin.getline(inputID, 20);
    int loanIndex = FindLoanReaderBaseOnID(bookloans, countLoan, inputID);
    int readerIndex = FindReaderBasedOnId(readers, countReader, inputID);

    if (loanIndex == -1)
    {
        cout << "Khong tim thay doc gia nay trong danh sach phieu muon sach.\n";
        return;
    } 

    cout << "Da tim thay ma cua doc gia: " << bookloans[loanIndex].loanReaderIds << "\n";
    cout << "Ten cua doc gia: " << readers[readerIndex].readerName << "\n";
    cout << "Nhap ngay tra thuc te (theo dd/mm/yyyy): ";
    cin >> bookloans[loanIndex].returnDatesActual;

    int overDueDays = bookloans[loanIndex].returnDatesActual - bookloans[loanIndex].returnDates;
    int totalFine = 0;
    int fine = 0;
    if (overDueDays > 0)
    {
        fine = overDueDays * 5000;
        totalFine += fine;
        printf("Doc gia bi phat %d dong vi tra sach qua han %d ngay", fine, overDueDays);
    }
    for (int j = 0; j < bookloans[loanIndex].loanBookCount; j++)
    {
        printf("Sach %s co bi mat khong ? (1: co, 2. Khong)", bookloans[loanIndex].loanBooks[j]);
        int lost;
        scanf("%d", &lost);
        if (lost == 1)
        {
            int bookIndex = FindBookBasedOnISBN(books, countBook, bookloans[loanIndex].loanBooks[j]);
            printf("So luong sach bi mat la: ");
            int lostbook = 0;
            scanf("%d", &lostbook);
            int fine = books[bookIndex].bookPrices * 2 * lostbook;
            totalFine += fine;
            printf("Doc gia bi phat: %d vi lam mat sach", fine);
            bookloans[loanIndex].loanBookQuantities[j] -= lostbook;
            remainBooks += bookloans[loanIndex].loanBookQuantities[j];
            books[bookIndex].bookQuantitites += bookloans[loanIndex].loanBookQuantities[j];
        }
        else
        {
            int bookIndex = FindBookBasedOnISBN(books, countBook, bookloans[loanIndex].loanBooks[j]);
            remainBooks += bookloans[loanIndex].loanBookQuantities[j];
            books[bookIndex].bookQuantitites += bookloans[loanIndex].loanBookQuantities[j];
        }
    }
    cout << "Tong tien phat: " << totalFine << " dong.\n";
    bookloans[loanIndex].loanDates = ::Date();
    for (int j = 0; j < bookloans[loanIndex].loanBookCount; j++)
    {
        bookloans[loanIndex].loanBookQuantities[j] = 0;
        strcpy(bookloans[loanIndex].loanBooks[j], " ");
    }
    bookloans[loanIndex].loanBookCount = 0;

    cout << "Tra sach thanh cong.\n";
}

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