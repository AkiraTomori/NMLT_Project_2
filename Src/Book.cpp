#include "Book.h"

Book::Book()
{
    char newLine[11] = " ";
    strcpy(this->bookISBN, newLine);
    strcpy(this->bookTitles, newLine);
    strcpy(this->bookAuthor, newLine);
    strcpy(this->bookPublisher, newLine);
    strcpy(this->bookGenres, newLine);
    this->bookPublisherYear = 0;
    this->bookPrices = 0;
    this->bookQuantitites = 0;
}
Book::Book(char bookISBN[20], char bookTitles[100], char bookAuthor[100], char bookPulisher[100], char bookGenres[50], int bookPublisherYear, int bookPrices, int bookQuantites)
{
    strcpy(this->bookISBN, bookISBN);
    strcpy(this->bookTitles, bookTitles);
    strcpy(this->bookAuthor, bookAuthor);
    strcpy(this->bookPublisher, bookPulisher);
    strcpy(this->bookGenres, bookGenres);
    this->bookPublisherYear = bookPublisherYear;
    this->bookPrices = bookPrices;
    this->bookQuantitites = bookQuantites;
}
Book::Book(const Book &other)
{
    strcpy(this->bookISBN, other.bookISBN);
    strcpy(this->bookTitles, other.bookTitles);
    strcpy(this->bookAuthor, other.bookAuthor);
    strcpy(this->bookPublisher, other.bookPublisher);
    strcpy(this->bookGenres, other.bookGenres);
    this->bookPublisherYear = other.bookPublisherYear;
    this->bookPrices = other.bookPrices;
    this->bookQuantitites = other.bookQuantitites;
}
Book &Book::operator=(const Book &other)
{
    if (this != &other)
    {
        strcpy(this->bookISBN, other.bookISBN);
        strcpy(this->bookTitles, other.bookTitles);
        strcpy(this->bookAuthor, other.bookAuthor);
        strcpy(this->bookPublisher, other.bookPublisher);
        strcpy(this->bookGenres, other.bookGenres);
        this->bookPublisherYear = other.bookPublisherYear;
        this->bookPrices = other.bookPrices;
        this->bookQuantitites = other.bookQuantitites;
    }
    return *this;
}
void displayBookInfo(Book books[], int bookIndex)
{
    cout << bookIndex + 1 << " - " << books[bookIndex].bookISBN << " - " << books[bookIndex].bookTitles << " - " << books[bookIndex].bookAuthor << " - "
         << books[bookIndex].bookPublisher << " - " << books[bookIndex].bookGenres << " - " << books[bookIndex].bookPublisherYear << " - " << books[bookIndex].bookPrices << " - " << books[bookIndex].bookQuantitites << "\n";
}
void viewBooks(Book books[], int countBooks)
{
    header2();
    for (int i = 0; i < countBooks; i++)
        displayBookInfo(books, i);
    header2();
}
Book createBook()
{
    Book newBook;
    cout << "Nhap thong tin cua sach moi: \n";
    cin.ignore();
    cout << "ISBN: ";
    cin.getline(newBook.bookISBN, 20);
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
    if (countBooks >= MAX_BOOKS)
    {
        cout << "So luong sach da du.\n";
        return;
    }
    Book newBook = createBook();
    totalBooks += newBook.bookQuantitites;
    remainBooks += newBook.bookQuantitites;
    books[countBooks] = newBook;
    countBooks++;
    cout << "Them sach thanh cong.\n";
    return;
}
void editBooks(Book books[], int countBooks, int &totalBooks, int &remainBooks)
{
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
            cout << "Chon thong tin can thay doi: \n";
            cout << "1. ISBN.\n";
            cout << "2. Tua de sach.\n";
            cout << "3. Tac gia.\n";
            cout << "4. Nha xuat ban.\n";
            cout << "5. The loai.\n";
            cout << "6. Nam xuat ban.\n";
            cout << "7. Gia sach.\n";
            cout << "8. So luong sach.\n";

            cin >> choice;
            cin.ignore();
            switch (choice)
            {
            case 1:
                cout << "ISBN moi: ";
                cin.getline(books[bookIndex].bookISBN, 20);
                break;
            case 2:
                cout << "Tua de moi: ";
                cin.getline(books[bookIndex].bookTitles, 100);
                break;
            case 3:
                cout << "Tac gia: ";
                cin.getline(books[bookIndex].bookAuthor, 100);
                break;
            case 4:
                cout << "Nha xuat ban: ";
                cin.getline(books[bookIndex].bookPublisher, 100);
                break;
            case 5:
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
                break;
            default:
                cout << "Lua chon khong hop le.\n";
                break;
            }
            if (choice != 0)
            {
                cout << "Thong tin sau khi chinh sua.\n";
                displayBookInfo(books, bookIndex);
            }

        } while (choice != 0);
        return;
    }
    cout << "Khong tim thay sach can tim de thay doi.\n";
}
void removeBooks(Book books[], int &countBooks, int &totalBooks, int &remainBooks)
{
    cout << "Nhap vao isbn cua sach can tim kiem: ";
    cin.ignore();
    char inputISBN[20];
    cin.getline(inputISBN, 20);
    int bookIndex = -1;
    bookIndex = FindBookBasedOnISBN(books, countBooks, inputISBN);
    if (bookIndex != -1)
    {
        cout << "Da tim thay sach theo yeu cau.\n";
        displayBookInfo(books, bookIndex);
        cout << "Ban co muon xoa sach nay khong (1. co, 0. khong) ?";
        int choice;
        cin >> choice;
        if (choice == 0)
        {
            cout << "Khong xoa sach, ve lai menu chinh cua quan ly sach.\n";
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
            return;
        }
    }
    cout << "Khong tim thay sach theo yeu cau de chinh sua.\n";
}
void findBookBaseOnISBN(Book books[], int countBook)
{
    char inputISBN[20];
    cout << "Nhap vao ISBN sach can tim kiem: ";
    cin.ignore();
    cin.getline(inputISBN, 20);
    int bookIndex = FindBookBasedOnISBN(books, countBook, inputISBN);
    if (bookIndex != -1)
    {
        cout << "Da tim thay sach theo yeu cau.\n";
        displayBookInfo(books, bookIndex);
    }
    cout << "Khong tim thay sach theo yeu cau.\n";
    return;
}
void findBookBaseOnTitle(Book books[], int countBook)
{
    char inputTitle[100];
    cout << "Nhap vao tua de sach can tim kiem: ";
    cin.ignore();
    cin.getline(inputTitle, 100);
    int bookIndex = FindBookBasedOnTitle(books, countBook, inputTitle);
    if (bookIndex != -1)
    {
        cout << "Da tim thay sach theo yeu cau.\n";
        displayBookInfo(books, bookIndex);
    }
    cout << "Khong tim thay sach theo yeu cau.\n";
    return;
}

int FindBookBasedOnISBN(Book books[], int countBook, char bookISBN[])
{
    int index = -1;
    for (int i = 0; i < countBook; i++)
    {
        if (strcmp(books[i].bookISBN, bookISBN) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}
int FindBookBasedOnTitle(Book books[], int countBook, char bookTitle[])
{
    int index = -1;
    for (int i = 0; i < countBook; i++)
    {
        if (strcmp(books[i].bookTitles, bookTitle) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}