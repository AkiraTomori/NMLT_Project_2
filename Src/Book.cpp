#include "Book.h"

void displayBookInfo(Book books[], int bookIndex)
{
    header3();
    printf("| %-4d | %-20s | %-20s | %-20s | %-20s | %-15s | %-6d | %-7d | %-5d |\n",
        bookIndex + 1, books[bookIndex].bookISBN, books[bookIndex].bookTitles, books[bookIndex].bookAuthor, books[bookIndex].bookPublisher, books[bookIndex].bookGenres, books[bookIndex].bookPublisherYear, books[bookIndex].bookPrices, books[bookIndex].bookQuantitites);
    header3();
}
void viewBooks(Book books[], int countBooks)
{
    system("cls");
    cout << "Danh sach sach hien co o trong thu vien: \n";
    displayBookHeader();
    for (int i = 0; i < countBooks; i++)
        displayBookInfo(books, i);
    header1();
    system("pause");
    system("cls");
}
Book createBook(const Book books[], int countBook)
{
    Book newBook;
    cout << "Nhap thong tin cua sach moi: \n";
    cin.ignore();
    do
    {
        cout << "ISBN: ";
        cin.getline(newBook.bookISBN, 20);
        string ISBNformat = formatISBN(string(newBook.bookISBN));
        strcpy(newBook.bookISBN, ISBNformat.c_str());
        if (isUniqueISBN(books, countBook, newBook.bookISBN))
        {
            cout << "Ma ISBN nay da ton tai. Xin hay nhap lai.\n";
        }
        else
        {
            break;
        }
    } while (true);

    cout << "Tua de: ";
    cin.getline(newBook.bookTitles, 100);

    cout << "Tac gia: ";
    cin.getline(newBook.bookAuthor, 100);

    cout << "Nha xuat ban: ";
    cin.getline(newBook.bookPublisher, 100);

    cout << "The loai: ";
    cin.getline(newBook.bookGenres, 50);

    cout << "Nam xuat ban: ";
    cin >> newBook.bookPublisherYear;

    cout << "Gia sach: ";
    cin >> newBook.bookPrices;

    cout << "So luong: ";
    cin >> newBook.bookQuantitites;

    return newBook;
}
void addBooks(Book books[], int &countBooks, int &totalBooks, int &remainBooks)
{
    system("cls");
    if (countBooks >= MAX_BOOKS)
    {
        cout << "So luong sach da du.\n";
        system("pause");
        system("cls");
        return;
    }
    Book newBook = createBook(books, countBooks);
    totalBooks += newBook.bookQuantitites;
    remainBooks += newBook.bookQuantitites;
    books[countBooks] = newBook;
    countBooks++;
    cout << "Them sach thanh cong.\n";
    system("pause");
    system("cls");
    return;
}
void editBooks(Book books[], int countBooks, int &totalBooks, int &remainBooks)
{
    system("cls");
    char inputISBN[20];
    cin.ignore();
    cout << "Nhap vao ISBN cua sach can duoc chinh sua: ";
    cin.getline(inputISBN, 20);
    int bookIndex = -1;
    bookIndex = FindBookBasedOnISBN(books, countBooks, inputISBN);
    if (bookIndex != -1)
    {
        cout << "Da tim thay sach theo yeu cau.\n";
        displayBookInfo(books, bookIndex);
        int choice;
        do
        {
            printBorder('=');
            printCenteredLine("CHINH SUA THONG TIN");
            printBorder('=');
            printMenuLine("1. ISBN.");
            printMenuLine("2. Tua de sach.");
            printMenuLine("3. Tac gia.");
            printMenuLine("4. Nha xuat ban.");
            printMenuLine("5. The loai.");
            printMenuLine("6. Nam xuat ban.");
            printMenuLine("7. Gia sach.");
            printMenuLine("8. So luong sach.");
            printMenuLine("0. Ve lai cua so quan ly sach.");
            printBorder('=');
            printPromptLine("Nhap vao thong tin can chinh sua: ");
            printf(">> ");
            scanf("%d", &choice);
            // cin.ignore();
            switch (choice)
            {
            case 1:
                // cout << "ISBN moi: ";
                // cin.getline(books[bookIndex].bookISBN, 20);
                do
                {
                    cin.ignore();
                    cout << "ISBN moi: ";
                    char newISBN[20];
                    cin.getline(newISBN, 20);
                    string formattedISBN = formatISBN(string(newISBN));
                    if (strcmp(books[bookIndex].bookISBN, formattedISBN.c_str()) == 0) break;
                    strcpy(newISBN, formattedISBN.c_str());
                    if (isUniqueISBN(books, countBooks, newISBN, bookIndex))
                    {
                        cout << "Ma ISBN nay da ton tai. Xin hay nhap lai.\n";
                    }
                    else
                    {
                        strcpy(books[bookIndex].bookISBN, newISBN);
                        break;
                    }
                } while (true);
                break;
            case 2:
                cin.ignore();
                cout << "Tua de moi: ";
                cin.getline(books[bookIndex].bookTitles, 100);
                break;
            case 3:
                cin.ignore();
                cout << "Tac gia: ";
                cin.getline(books[bookIndex].bookAuthor, 100);
                break;
            case 4:
                cin.ignore();
                cout << "Nha xuat ban: ";
                cin.getline(books[bookIndex].bookPublisher, 100);
                break;
            case 5:
                cin.ignore();
                cout << "The loai: ";
                cin.getline(books[bookIndex].bookGenres, 50);
                break;
            case 6:
                cout << "Nam xuat bam: ";
                cin >> books[bookIndex].bookPublisherYear;
                break;
            case 7:
                cout << "Gia sach: ";
                cin >> books[bookIndex].bookPrices;
                break;
            case 8:
                cout << "So luong sach: ";
                cin >> books[bookIndex].bookQuantitites;
                break;
            case 0:
                cout << "Roi cua so chinh sua sach.\n";
                system("pause");
                system("cls");
                break;
            default:
                cout << "Lua chon khong hop le.\n";
                break;
            }
            if (choice != 0)
            {
                system("cls");
                cout << "Thong tin sau khi chinh sua.\n";
                displayBookInfo(books, bookIndex);
                system("pause");
            }

        } while (choice != 0);
        return;
    }
    cout << "Khong tim thay sach can tim de thay doi.\n";
    system("pause");
    system("cls");
}
void removeBooks(Book books[], int &countBooks, int &totalBooks, int &remainBooks)
{
    system("cls");
    cout << "Nhap vao isbn cua sach can xoa: ";
    cin.ignore();
    char inputISBN[20];
    cin.getline(inputISBN, 20);
    int bookIndex = -1;
    bookIndex = FindBookBasedOnISBN(books, countBooks, inputISBN);
    if (bookIndex != -1)
    {
        cout << "Da tim thay sach theo yeu cau.\n";
        displayBookInfo(books, bookIndex);
        cout << "Ban co muon xoa sach nay khong (1. co, 0. khong) ? ";
        int choice;
        cin >> choice;
        if (choice == 0)
        {
            cout << "Khong xoa sach, ve lai menu chinh cua quan ly sach.\n";
            system("pause");
            system("cls");
            return;
        }
        else
        {
            totalBooks -= books[bookIndex].bookQuantitites;
            remainBooks -= books[bookIndex].bookQuantitites;
            for (int j = bookIndex; j < countBooks - 1; j++)
            {
                books[j] = books[j + 1];
            }
            countBooks--;
            cout << "Sach da duoc xoa thanh cong!.\n";
            system("pause");
            system("cls");
            return;
        }
    }
    cout << "Khong tim thay sach theo yeu cau de chinh sua.\n";
    system("pause");
    system("cls");
}
void findBookBaseOnISBN(Book books[], int countBook)
{
    system("cls");
    char inputISBN[20];
    cout << "Nhap vao ISBN sach can tim kiem: ";
    cin.ignore();
    cin.getline(inputISBN, 20);
    int bookIndex = FindBookBasedOnISBN(books, countBook, inputISBN);
    if (bookIndex != -1)
    {
        cout << "Da tim thay sach theo yeu cau.\n";
        displayBookInfo(books, bookIndex);
        system("pause");
        system("cls");
        return;
    }
    cout << "Khong tim thay sach theo yeu cau.\n";
    system("pause");
    system("cls");
    return;
}
void findBookBaseOnTitle(Book books[], int countBook)
{
    system("cls");
    char inputTitle[100];
    cout << "Nhap vao tua de sach can tim kiem: ";
    cin.ignore();
    cin.getline(inputTitle, 100);
    int bookIndex = FindBookBasedOnTitle(books, countBook, inputTitle);
    if (bookIndex != -1)
    {
        cout << "Da tim thay sach theo yeu cau.\n";
        displayBookInfo(books, bookIndex);
        system("pause");
        system("cls");
        return;
    }
    cout << "Khong tim thay sach theo yeu cau.\n";
    system("pause");
    system("cls");
    return;
}
