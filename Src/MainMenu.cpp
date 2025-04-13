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
        // printf("1. Quan ly doc gia.\n");
        // printf("2. Quan ly sach.\n");
        // printf("3. Lap phieu muon sach.\n");
        // printf("4. Tra sach.\n");
        // printf("5. Thong ke.\n");
        // printf("0. Thoat chuong trinh.\n");
        printMenuLine("1. Quan ly doc gia.");
        printMenuLine("2. Quan ly sach.");
        printMenuLine("3. Quan ly phieu muon.");
        printMenuLine("4. Thong ke.");
        printMenuLine("0. Thoat chuong trinh.");
        printBorder('=');
        // header2();
        int choice;
        printPromptLine("Nhap vao lua chon yeu cau cua ban: ");
        // printf("|\n");
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
        // case 3:
        // {
        //     system("cls");
        //     borrowBooksMenu(reader, countReaders, books, countBooks, remainBooks, bookloans, countLoan);
        //     break;
        // }
        // case 4:
        // {
        //     system("cls");
        //     returnBooksMenu(reader, countReaders, books, countBooks, remainBooks, bookloans, countLoan);
        //     break;
        // }
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
        // cout << "1. Xem danh sach doc gia.\n";
        // cout << "2. Them doc gia.\n";
        // cout << "3. Chinh sua thong tin cua mot doc gia.\n";
        // cout << "4. Xoa doc gia.\n";
        // cout << "5. Tim doc gia theo CCCD.\n";
        // cout << "6. Tim doc gia theo ten.\n";
        // cout << "0. Quay lai menu chinh.\n";
        // header2();
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
        // header2();
        // cout << "1. Xem danh sach cac sach trong thu vien.\n";
        // cout << "2. Them sach vao thu vien.\n";
        // cout << "3. Chinh sua thong tin cua cuon sach.\n";
        // cout << "4. Xoa thong tin sach.\n";
        // cout << "5. Tim kiem sach theo ISBN.\n";
        // cout << "6. Tim kiem sach theo tua de.\n";
        // cout << "0. Quay lai menu chinh.\n";
        // header2();
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
        // printf("Nhap vao lua chon voi sach: ");
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
        // header2();
        // cout << "1. Thong ke so luong sach trong thu vien.\n";
        // cout << "2. Thong ke so luong sach theo the loai.\n";
        // cout << "3. Thong ke so luong doc gia hien co.\n";
        // cout << "4. Thong ke so luong doc gia theo gioi tinh.\n";
        // cout << "5. Thong ke so luong sach dang duoc muon.\n";
        // cout << "6. Thong ke so luong doc gia tre hen .\n";
        // header2();
        // printf("Nhap vao lua chon de thong ke: ");
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
            // printf("Tong so luong sach trong thu vien: %d \n", countTotalBooks(books, countBook));
            // printBookQuantityHeader();
            // for (int i = 0; i < countBook; i++){
            //     printBookQuantityRow(books[i].bookTitles, books[i].bookQuantitites);
            // }
            // printBookQuantityFooter();
            // system("pause");
            // system("cls");
            countTotalBooksMenu(books, countBook);
            break;
        }
        case 2:
        {
            system("cls");
            // countBookByGenres(books, countBook);
            countBookByGenresMenu(books, countBook);
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            system("cls");
            // printf("Tong so luong doc gia: %d \n", countTotalReaders(reader, countReader));
            // printReaderCardStatHeader();
            // for (int i = 0; i < countReader; i++)
            // {
            //     char birth[11], card[11], exp[11];
            //     Reader presentReader = reader[i];
            //     sprintf(birth, "%02d/%02d/%02d", presentReader.readerBirthday.day, presentReader.readerBirthday.month, presentReader.readerBirthday.year);
            //     sprintf(card, "%02d/%02d/%02d", presentReader.readerCardDates.day, presentReader.readerCardDates.month, presentReader.readerCardDates.year);
            //     sprintf(exp, "%02d/%02d/%02d", presentReader.readerExpiryDates.day, presentReader.readerExpiryDates.month, presentReader.readerExpiryDates.year);

            //     printf("| %-30s | %-10s | %-10s | %-10s |\n", presentReader.readerName, birth, card, exp);
            // }
            // printReaderCardStatFooter();
            // system("pause");
            // system("cls");
            countReaderMenu(reader, countReader);
            break;
        }
        case 4:
        {
            system("cls");
            // countReaderByGenders(reader, countReader);
            // printGenderStatHeader();
            // for (int i = 0; i < countReader; i++){
            //     printf("| %-30s | %-6s |\n", reader[i].readerName, reader[i].readerGender);
            // }
            // printGenderStatFooter();
            // system("pause");
            // system("cls");
            countReaderByGenderMenu(reader, countReader);
            break;
        }
        case 5:
        {
            system("cls");
            printf("Tong so luong sach dang duoc muon: %d \n", countBorrowedBooks(bookloans, countLoan));
            system("pause");
            system("cls");
            break;
        }
        case 6:
        {
            system("cls");
            listOverdueReaders(bookloans, countLoan);
            system("pause");
            system("cls");
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
        if (QueryChoice == 0)
        {
            system("cls");
            break;
        }
    }
}