#include "MainMenu.h"

void showTime(Reader reader[], int &countReaders,
              Book books[], int &countBooks, int &totalBooks, int &remainBooks,
              BookLoan bookloans[], int &countLoan)
{
    while (true)
    {
        cout << "Quan ly thu vien";
        header2();
        cout << "1. Quan ly doc gia.\n";
        cout << "2. Quan ly sach.\n";
        cout << "3. Lap phieu muon sach.\n";
        cout << "4. Lap phieu tra sach.\n";
        cout << "5. Thong ke.\n";
        cout << "0. Thoat chuong trinh.\n";
        header2();
        int choice;
        printf("Nhap vao lua chon yeu cau cua ban: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            ReaderMenu(reader, countReaders);
            break;
        }
        case 2:
        {
            BookMenu(books, countBooks, totalBooks, remainBooks);
            break;
        }
        case 3:
        {
            borrowBooksMenu(reader, countReaders, books, countBooks, remainBooks, bookloans, countLoan);
            break;
        }
        case 4:
        {
            returnBooksMenu(reader, countReaders, books, countBooks, remainBooks, bookloans, countLoan);
            break;
        }
        case 5:
        {
            QueryMenu(reader, countReaders, books, countBooks, bookloans, countLoan);
            break;
        }
        case 0:
        {
            printf("Thoat chuong trinh.\n");
            return;
        }
        default:
        {
            printf("Lua chon khong hop le.\n");
            break;
        }
        }
    }
}

void ReaderMenu(Reader reader[], int countReader)
{
    while (true)
    {
        header2();
        cout << "1. Xem danh sach doc gia.\n";
        cout << "2. Them doc gia.\n";
        cout << "3. Chinh sua thong tin cua mot doc gia.\n";
        cout << "4. Xoa doc gia.\n";
        cout << "5. Tim doc gia theo CCCD.\n";
        cout << "6. Tim doc gia theo ten.\n";
        cout << "0. Quay lai menu chinh.\n";
        header2();
        int readerChoice;
        printf("Nhap lua chon ve doc gia: ");
        scanf("%d", &readerChoice);
        switch (readerChoice)
        {
        case 1:
            displayAllReaders(reader, countReader);
            break;
        case 2:
            addReader(reader, countReader);
            break;
        case 3:
            editReader(reader, countReader);
            break;
        case 4:
            removeReader(reader, countReader);
            break;
        case 5:
            findReaderBaseOnCCCD(reader, countReader);
            break;
        case 6:
            findReaderBaseOnName(reader, countReader);
            break;
        case 0:
            printf("Quay lai menu chinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
            break;
        }
        if (readerChoice == 0)
        {
            break;
        }
    }
}
void BookMenu(Book books[], int countBook, int &totalBooks, int &remainBooks)
{
    while (true)
    {
        header2();
        cout << "1. Xem danh sach cac sach trong thu vien.\n";
        cout << "2. Them sach vao thu vien.\n";
        cout << "3. Chinh sua thong tin cua cuon sach.\n";
        cout << "4. Xoa thong tin sach.\n";
        cout << "5. Tim kiem sach theo ISBN.\n";
        cout << "6. Tim kiem sach theo tua de.\n";
        cout << "0. Quay lai menu chinh.\n";
        header2();
        printf("Nhap vao lua chon voi sach: ");
        int bookChoice;
        scanf("%d", &bookChoice);
        switch (bookChoice)
        {
        case 1:
            viewBooks(books, countBook);
            break;
        case 2:
            addBooks(books, countBook, totalBooks, remainBooks);
            break;
        case 3:
            editBooks(books, countBook, totalBooks, remainBooks);
            break;
        case 4:
            removeBooks(books, countBook, totalBooks, remainBooks);
            break;
        case 5:
            findBookBaseOnISBN(books, countBook);
            break;
        case 6:
            findBookBaseOnTitle(books, countBook);
            break;
        case 0:
            printf("Ve lai menu chinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
            break;
        }
        if (bookChoice == 0)
        {
            break;
        }
    }
}
void borrowBooksMenu(Reader reader[], int countReader, Book books[], int countBook, int &remainBooks, BookLoan bookloans[], int &countLoan)
{
    borrowBooks(reader, countReader, books, countBook, bookloans, countLoan, remainBooks);
}
void returnBooksMenu(Reader reader[], int countReader, Book books[], int countBook, int &remainBooks, BookLoan bookloans[], int countLoan)
{
    returnBooks(reader, countReader, books, countBook, bookloans, countLoan, remainBooks);
}
void QueryMenu(Reader reader[], int countReader, Book books[], int countBook, BookLoan bookloans[], int countLoan)
{
    while (true)
    {
        header2();
        cout << "1. Thong ke so luong sach trong thu vien.\n";
        cout << "2. Thong ke so luong sach theo the loai.\n";
        cout << "3. Thong ke so luong doc gia hien co.\n";
        cout << "4. Thong ke so luong doc gia theo gioi tinh.\n";
        cout << "5. Thong ke so luong sach dang duoc muon.\n";
        cout << "6. Thong ke so luong doc gia tre hen .\n";
        header2();
        printf("Nhap vao lua chon de thong ke: ");
        int QueryChoice;
        scanf("%d", &QueryChoice);
        switch (QueryChoice)
        {
        case 1:
        {
            printf("Tong so luong sach trong thu vien: %d", countTotalBooks(books, countBook));
            break;
        }
        case 2:
        {
            countBookByGenres(books, countBook);
            break;
        }
        case 3:
        {
            printf("Tong so luong doc gia: %d", countTotalReaders(reader, countReader));
            break;
        }
        case 4:
        {
            countReaderByGenders(reader, countReader);
            break;
        }
        case 5:
        {
            printf("Tong so luong sach dang duoc muon: %d", countBorrowedBooks(bookloans, countLoan));
            break;
        }
        case 6:
        {
            listOverdueReaders(bookloans, countLoan);
            break;
        }
        case 0:
        {
            printf("Thoat chuong trinh.\n");
            break;
        }
        default:
        {
            printf("Lua chon khong hop le.\n");
            break;
        }
        }
        if (QueryChoice == 0)
        {
            break;
        }
    }
}