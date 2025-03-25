#include "Reader.h"

Reader::Reader()
{
    char newLine[11] = "";
    strcpy(this->readerName, newLine);
    strcpy(this->readerId, newLine);
    strcpy(this->readerCCCD, newLine);
    strcpy(this->readerMail, newLine);
    strcpy(this->readerAddress, newLine);
    strcpy(this->readerGender, newLine);
}
Reader::Reader(char readerName[100], char readerId[20], char readerCCCD[100], char readerMail[100], char readerAddress[100], char readerGender[10], Date readerBirtday, Date readerCardDates, Date readerExpiryDates)
{
    strcpy(this->readerName, readerName);
    strcpy(this->readerId, readerId);
    strcpy(this->readerCCCD, readerCCCD);
    strcpy(this->readerMail, readerMail);
    strcpy(this->readerAddress, readerAddress);
    strcpy(this->readerGender, readerGender);
    this->readerBirthday = readerBirthday;
    this->readerCardDates = readerCardDates;
    this->readerExpiryDates = readerExpiryDates;
}
Reader::Reader(const Reader &other)
{
    strcpy(this->readerName, other.readerName);
    strcpy(this->readerId, other.readerId);
    strcpy(this->readerCCCD, other.readerCCCD);
    strcpy(this->readerMail, other.readerMail);
    strcpy(this->readerAddress, other.readerAddress);
    strcpy(this->readerGender, other.readerGender);
    this->readerBirthday = other.readerBirthday;
    this->readerCardDates = other.readerCardDates;
    this->readerExpiryDates = other.readerExpiryDates;
}
Reader &Reader::operator=(const Reader &other)
{
    if (this != &other)
    {
        strcpy(this->readerName, other.readerName);
        strcpy(this->readerId, other.readerId);
        strcpy(this->readerCCCD, other.readerCCCD);
        strcpy(this->readerMail, other.readerMail);
        strcpy(this->readerAddress, other.readerAddress);
        strcpy(this->readerGender, other.readerGender);
        this->readerBirthday = other.readerBirthday;
        this->readerCardDates = other.readerCardDates;
        this->readerExpiryDates = other.readerExpiryDates;
    }
    return *this;
}
Reader::~Reader(){}
void displayReader(Reader readers[], int ReaderIndex)
{
    cout << ReaderIndex + 1 << " - " << readers[ReaderIndex].readerName << " - " << readers[ReaderIndex].readerId << " - " << readers[ReaderIndex].readerCCCD << " - "
         << readers[ReaderIndex].readerMail << " - " << readers[ReaderIndex].readerAddress << " - " << readers[ReaderIndex].readerGender << " - "
         << readers[ReaderIndex].readerBirthday << " - " << readers[ReaderIndex].readerCardDates << " - " << readers[ReaderIndex].readerExpiryDates << "\n";
}
void addReader(Reader readers[], int &countReader)
{
    if (countReader >= MAX_READERS)
    {
        cout << "Khong the tiep tuc them doc gia moi vi danh sach da day.\n";
        return;
    }
    cout << "Nhap thong tin cua doc gia moi: \n";
    cout << "Ten: ";
    cin.ignore();
    cin.getline(readers[countReader].readerName, 100);
    cout << "Ma doc gia: ";
    cin.getline(readers[countReader].readerId, 20);
    cout << "CCCD: ";
    cin.getline(readers[countReader].readerCCCD, 100);
    cout << "Email: ";
    cin.getline(readers[countReader].readerMail, 100);
    cout << "Dia chi: ";
    cin.getline(readers[countReader].readerAddress, 100);
    cout << "Gioi tinh: ";
    cin.getline(readers[countReader].readerGender, 10);
    cout << "Ngay thang nam sinh (theo dd/mm/yyyy): ";
    cin >> readers[countReader].readerBirthday;
    cout << "Ngay lap the (theo dd/mm/yyyy): ";
    cin >> readers[countReader].readerCardDates;

    readers[countReader].readerExpiryDates = readers[countReader].readerCardDates;
    readers[countReader].readerExpiryDates.addMonths(48);

    cout << "Ngay het han cua doc gia: " << readers[countReader].readerExpiryDates << "\n";
    cout << "Doc gia moi da duoc them thanh cong.\n";
    countReader++;
}
void displayAllReaders(Reader readers[], int countReader)
{
    header2();
    for (int i = 0; i < countReader; i++)
        displayReader(readers, i);
    header2();
}
void editReader(Reader readers[], int countReader)
{
    char inputReaderId[20];
    cout << "Nhap vao ma doc gia can chinh sua: ";
    cin.ignore();
    cin.getline(inputReaderId, 20);
    int readerIndex = -1;
    readerIndex = FindReaderBasedOnId(readers, countReader, inputReaderId);
    if (readerIndex != -1)
    {
        cout << "Da tim thay doc gia theo yeu cau.\n";
        displayReader(readers, readerIndex);
        int choice;
        do
        {
            cout << "Chon thong tin can thay doi: \n";
            cout << "1. Ho ten.\n";
            cout << "2. Ma doc gia.\n";
            cout << "3. CCCD.\n";
            cout << "4. Email.\n";
            cout << "5. Dia chi.\n";
            cout << "6. Gioi tinh.\n";
            cout << "7. Ngay sinh.\n";
            cout << "0. Ve lai cua so quan ly doc gia.\n";

            cin >> choice;
            cin.ignore();
            switch (choice)
            {
            case 1:
                cout << "Nhap ten moi: ";
                cin.getline(readers[readerIndex].readerName, 100);
                break;
            case 2:
                cout << "Ma doc gia: ";
                cin.getline(readers[readerIndex].readerId, 20);
                break;
            case 3:
                cout << "CCCD: ";
                cin.getline(readers[readerIndex].readerCCCD, 100);
                break;
            case 4:
                cout << "Mail: ";
                cin.getline(readers[readerIndex].readerMail, 100);
                break;
            case 5:
                cout << "Dia chi moi: ";
                cin.getline(readers[readerIndex].readerAddress, 100);
                break;
            case 6:
                cout << "Chinh sua gioi tinh: ";
                cin.getline(readers[readerIndex].readerGender, 10);
                break;
            case 7:
                cout << "Chinh sua ngay sinh: ";
                cout << "Nhap ngay sinh theo dinh dang dd/mm/yyyy: ";
                cin >> readers[readerIndex].readerBirthday;
                break;
            case 0:
                cout << "Roi cua so chinh sua doc gia.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
                break;
            }
            if (choice != 0)
            {
                cout << "Thong tin sau khi chinh sua.\n";
                displayReader(readers, readerIndex);
            }
        } while (choice != 0);
        return;
    }
    cout << "Khong tim thay doc gia can tim de thay doi.\n";
}
void removeReader(Reader readers[], int &countReader)
{
    char inputId[20];
    cout << "Nhap vao id cua doc gia can xoa: ";
    cin.ignore();
    cin.getline(inputId, 20);
    int readerIndex = -1;
    readerIndex = FindReaderBasedOnId(readers, countReader, inputId);
    if (readerIndex != -1)
    {
        cout << "Da tim thay doc gia theo yeu cau.\n";
        displayReader(readers, readerIndex);
        cout << "Ban co muon xoa doc gia nay khong (1. co, 0. khong) ?\n";
        int choice;
        cin >> choice;
        if (choice == 0)
        {
            cout << "Khong xoa doc gia, ve lai menu chinh cua doc gia.\n";
            return;
        }
        else
        {
            for (int j = readerIndex; j < countReader - 1; j++)
            {
                readers[j] = readers[j + 1];
            }
            countReader--;
            cout << "Doc gia da duoc xoa thanh cong!.\n";
            return;
        }
    }
    cout << "Khong tim thay ten doc gia theo yeu cau.\n";
}
void findReaderBaseOnCCCD(Reader readers[], int countReader)
{
    char inputCCCD[100];
    printf("Nhap vao CCCD cua doc gia muon tim kiem: ");
    cin.ignore();
    cin.getline(inputCCCD, 100);
    int readerIndex = FindReaderBasedOnCCCD(readers, countReader, inputCCCD);
    if (readerIndex != -1)
    {
        displayReader(readers, readerIndex);
    }
    printf("Khong tim thay doc gia can tim.\n");
}
void findReaderBaseOnName(Reader readers[], int countReader)
{
    char inputName[100];
    printf("Nhap vao ten cua doc gia can tim kiem: ");
    cin.ignore();
    cin.getline(inputName, 100);
    int readerIndex = FindReaderBasedOnName(readers, countReader, inputName);
    if (readerIndex != -1)
    {
        displayReader(readers, readerIndex);
    }
    printf("Khong tim thay doc gia can tim.\n");
}

int FindReaderBasedOnCCCD(Reader readers[], int countReader, char cccd[])
{
    int index = -1;
    for (int i = 0; i < countReader; i++)
    {
        if (strcmp(readers[i].readerCCCD, cccd) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}
int FindReaderBasedOnName(Reader readers[], int countReader, char name[])
{
    int index = -1;
    for (int i = 0; i < countReader; i++)
    {
        if (strcmp(readers[i].readerName, name) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}
int FindReaderBasedOnId(Reader readers[], int countReader, char id[])
{
    int index = -1;
    for (int i = 0; i < countReader; i++)
    {
        if (strcmp(readers[i].readerId, id) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}