#include "MainMenu.h"

void showTime(Reader reader[], int &countReaders,
              Book books[], int &countBooks, int &totalBooks, int &remainBooks,
              BookLoan bookloans[], int &countLoan)
{
    while (true)
    {
        printBorder('=');
        printCenteredLine("QUAN LY THU VIEN");
        printBorder('=');
        printMenuLine("1. Quan ly doc gia.");
        printMenuLine("2. Quan ly sach.");
        printMenuLine("3. Quan ly phieu muon.");
        printMenuLine("4. Thong ke.");
        printMenuLine("0. Thoat chuong trinh.");
        printBorder('=');
        int choice;
        printPromptLine("Nhap vao lua chon yeu cau cua ban: ");
        printf(">> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            system("cls");
            ReaderMenu(reader, countReaders);
            break;
        }
        case 2:
        {
            system("cls");
            BookMenu(books, countBooks, totalBooks, remainBooks);
            break;
        }
        case 3:
        {
            system("cls");
            loanMenu(reader, countReaders, books, countBooks, remainBooks, bookloans, countLoan);
            break;
        }
        case 4:
        {
            system("cls");
            QueryMenu(reader, countReaders, books, countBooks, bookloans, countLoan);
            break;
        }
        case 0:
        {
            system("cls");
            printf("Thoat chuong trinh.\n");
            return;
        }
        default:
        {
            printf("Lua chon khong hop le.\n");
            system("pause");
            system("cls");
            break;
        }
        }
    }
}

void ReaderMenu(Reader reader[], int countReader)
{
    while (true)
    {
        printBorder('=');
        printCenteredLine("QUAN LY DOC GIA");
        printBorder('=');
        printMenuLine("1. Xem danh sach doc gia.");
        printMenuLine("2. Them doc gia.");
        printMenuLine("3. Chinh sua thong tin doc gia.");
        printMenuLine("4. Xoa doc gia.");
        printMenuLine("5. Tim doc gia theo CCCD.");
        printMenuLine("6. Tim doc gia theo ten.");
        printMenuLine("0. Ve lai menu chinh");
        printBorder('=');
        int readerChoice;
        printPromptLine("Nhap vao lua chon yeu cau cua ban: ");
        printf(">> ");
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
            system("pause");
            system("cls");
            break;
        }
        if (readerChoice == 0)
        {
            system("cls");
            break;
        }
    }
}
void BookMenu(Book books[], int countBook, int &totalBooks, int &remainBooks)
{
    while (true)
    {
        printBorder('=');
        printCenteredLine("QUAN LY SACH");
        printBorder('=');
        printMenuLine("1. Xem danh sach cac sach.");
        printMenuLine("2. Them sach.");
        printMenuLine("3. Chinh sua thong tin sach.");
        printMenuLine("4. Xoa sach");
        printMenuLine("5. Tim sach theo ISBN.");
        printMenuLine("6. Tim sach theo tua de.");
        printMenuLine("0. Ve lai menu chinh.");
        printBorder('=');

        printPromptLine("Nhap vao lua chon yeu cau cua ban: ");
        int bookChoice;
        printf(">> ");
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
            system("pause");
            system("cls");
            break;
        }
        if (bookChoice == 0)
        {
            system("cls");
            break;
        }
    }
}
void loanMenu(Reader reader[], int countReader, Book books[], int countBook, int &remainBooks, BookLoan bookloans[], int &countLoan)
{
    while (true)
    {
        printBorder('=');
        printCenteredLine("QUAN LY PHIEU MUON SACH");
        printBorder('=');
        printMenuLine("1. Lap phieu muon sach.");
        printMenuLine("2. Lap phieu tra sach.");
        printMenuLine("0. Ve lai menu chinh.");
        printBorder('=');
        int choice;
        printPromptLine("Nhap vao lua chon yeu cau cua ban: ");
        printf(">> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            system("cls");
            borrowBooksMenu(reader, countReader, books, countBook, remainBooks, bookloans, countLoan);
            break;
        }
        case 2:
        {
            system("cls");
            returnBooksMenu(reader, countReader, books, countBook, remainBooks, bookloans, countLoan);
            break;
        }
        case 0:
        {
            printf("Quay lai menu chinh.\n");
            break;
        }
        default:
        {
            printf("Lua chon khong hop le.\n");
            break;
        }
        }
        if (choice == 0)
        {
            system("cls");
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
        printBorder('=');
        printCenteredLine("THONG KE");
        printBorder('=');
        printMenuLine("1. Thong ke so luong sach trong thu vien.");
        printMenuLine("2. Thong ke so luong sach theo the loai.");
        printMenuLine("3. Thong ke so luong doc gia hien co.");
        printMenuLine("4. Thong ke so luong doc gia theo gioi tinh.");
        printMenuLine("5. Thong ke so luong sach dang duoc muon.");
        printMenuLine("6. Thong ke so luong doc gia tre hen.");
        printMenuLine("0. Ve lai menu chinh.");
        printBorder('=');
        int QueryChoice;
        printPromptLine("Nhap vao lua chon yeu cau cua ban: ");
        printf(">> ");
        scanf("%d", &QueryChoice);
        switch (QueryChoice)
        {
        case 1:
        {
            system("cls");
            countTotalBooksMenu(books, countBook);
            break;
        }
        case 2:
        {
            system("cls");
            countBookByGenresMenu(books, countBook);
            break;
        }
        case 3:
        {
            system("cls");
            countReaderMenu(reader, countReader);
            break;
        }
        case 4:
        {
            system("cls");
            countReaderByGenderMenu(reader, countReader);
            break;
        }
        case 5:
        {
            system("cls");
            countBorrowedBooksMenu(reader, countReader, bookloans, countLoan);
            break;
        }
        case 6:
        {
            system("cls");
            listOverdueReadersMenu(reader, countReader, bookloans, countLoan);
            break;
        }
        case 0:
        {
            printf("Quay lai menu chinh.\n");
            break;
        }
        default:
        {
            printf("Lua chon khong hop le.\n");
            system("pause");
            system("cls");
            break;
        }
        }
        if (QueryChoice == 0)
        {
            system("cls");
            break;
        }
    }
}