#include "BookLoan.h"

void borrowBooks(Reader readers[], int countReader, Book books[], int countBook, BookLoan bookloans[], int &countLoan, int &remainBooks)
{
    cout << "Nhap vao ma doc gia: ";
    cin.ignore();
    char inputID[20];
    cin.getline(inputID, 20);

    int readerIndex = FindReaderBasedOnId(readers, countReader, inputID);
    while (readerIndex == -1)
    {
        cout << "Doc gia chua duoc them vao thu vien !\n";
        cout << "1. Nhap lai\n2. Thoat\nNhap lua chon: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Nhap lai ma doc gia: ";
            cin.ignore();
            cin.getline(inputID, 20);
            readerIndex = FindReaderBasedOnId(readers, countReader, inputID);
        }
        else return;
    }

    int loanIndex = FindLoanReaderBaseOnID(bookloans, countLoan, inputID);

    // Nếu có phiếu mượn và chưa trả sách
    if (loanIndex != -1 &&
        !(bookloans[loanIndex].loanDates.day == 1 &&
          bookloans[loanIndex].loanDates.month == 1 &&
          bookloans[loanIndex].loanDates.year == 2000))
    {
        cout << "Doc gia nay dang co sach chua tra. Khong the muon them.\n";
        system("pause");
        system("cls");
        return;
    }

    // Nếu không có phiếu mượn -> tạo mới
    BookLoan newLoan;
    cout << "Ten doc gia: " << readers[readerIndex].readerName << "\n";
    strcpy(newLoan.loanReaderIds, inputID);
    cout << "Nhap ngay muon sach (dd/mm/yyyy): \n";
    cin >> newLoan.loanDates;
    newLoan.returnDates = newLoan.loanDates;
    int ONE_WEEK = 7;
    newLoan.returnDates.addNDays(ONE_WEEK);
    newLoan.loanBookCount = 0;

    if (loanIndex == -1)
    {
        loanIndex = countLoan;
        bookloans[loanIndex] = newLoan;
        countLoan++;
    }
    else
    {
        bookloans[loanIndex] = newLoan;
    }

    int BorrowedBooks;
    do {
        cout << "So sach muon (toi da 10): ";
        cin >> BorrowedBooks;
    } while (BorrowedBooks > MAX_BORROWED_BOOKS);

    for (int i = 0; i < BorrowedBooks; i++)
    {
        char isbnOrTitle[100];
        int bookIndex = -1;
        cout << "Nhap ISBN hoac ten sach: ";
        cin.ignore();
        cin.getline(isbnOrTitle, 100);

        while ((bookIndex = FindBookBasedOnISBN(books, countBook, isbnOrTitle)) == -1 &&
               (bookIndex = FindBookBasedOnTitle(books, countBook, isbnOrTitle)) == -1)
        {
            cout << "Sach khong ton tai. Nhap lai: ";
            cin.getline(isbnOrTitle, 100);
        }

        cout << "Da tim thay sach can tim: " << books[bookIndex].bookTitles << "\n";
        cout << "So luong muon: ";
        int quantity;
        cin >> quantity;
        while (quantity > books[bookIndex].bookQuantitites)
        {
            cout << "Khong du sach. Nhap lai: ";
            cin >> quantity;
        }

        strcpy(bookloans[loanIndex].loanBooks[i], books[bookIndex].bookISBN);
        bookloans[loanIndex].loanBookQuantities[i] = quantity;
        books[bookIndex].bookQuantitites -= quantity;
        remainBooks -= quantity;
        bookloans[loanIndex].loanBookCount++;
    }

    cout << "Muon sach thanh cong.\n";
    system("pause");
    system("cls");
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
        system("pause");
        system("cls");
        return;
    } 

    cout << "Da tim thay ma cua doc gia: " << bookloans[loanIndex].loanReaderIds << "\n";
    cout << "Ten cua doc gia: " << readers[readerIndex].readerName << "\n";
    cout << "Nhap ngay tra thuc te (theo dd/mm/yyyy): \n";
    cin >> bookloans[loanIndex].returnDatesActual;

    int overDueDays = bookloans[loanIndex].returnDatesActual - bookloans[loanIndex].returnDates;
    int totalFine = 0;
    int fine = 0;
    if (overDueDays > 0)
    {
        fine = overDueDays * 5000;
        totalFine += fine;
        printf("Doc gia bi phat %d dong vi tra sach qua han %d ngay. \n", fine, overDueDays);
    }
    for (int j = 0; j < bookloans[loanIndex].loanBookCount; j++)
    {
        int bookIndexForName = FindBookBasedOnISBN(books, countBook, bookloans[loanIndex].loanBooks[j]);
        printf("Sach '%s' co bi mat khong ? (1: co, 0. Khong) ", books[bookIndexForName].bookTitles);
        int lost;
        cin >> lost;
        int bookIndex = FindBookBasedOnISBN(books, countBook, bookloans[loanIndex].loanBooks[j]);
        if (lost == 1)
        {
            printf("So luong sach bi mat la: ");
            int lostbook = 0;
            scanf("%d", &lostbook);
            int fine = books[bookIndex].bookPrices * 2 * lostbook;
            totalFine += fine;
            printf("Doc gia bi phat: %d vi lam mat sach. \n", fine);
            int returnAmount = bookloans[loanIndex].loanBookQuantities[j] - lostbook;
            books[bookIndex].bookQuantitites += returnAmount;
            remainBooks += returnAmount;
        }
        else
        {
            remainBooks += bookloans[loanIndex].loanBookQuantities[j];
            books[bookIndex].bookQuantitites += bookloans[loanIndex].loanBookQuantities[j];
        }
    }
    cout << "Tong tien phat: " << totalFine << " dong.\n";

    bookloans[loanIndex].loanDates = Date(1, 1, 2000);
    cout << "Tra sach thanh cong.\n";
    system("pause");
    system("cls");
}