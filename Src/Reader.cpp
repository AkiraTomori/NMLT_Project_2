#include "Reader.h"

void displayReader(Reader readers[], int ReaderIndex)
{
    cout << ReaderIndex + 1 << " - " << readers[ReaderIndex].readerName << " - " << readers[ReaderIndex].readerId << " - " << readers[ReaderIndex].readerCCCD << " - "
         << readers[ReaderIndex].readerMail << " - " << readers[ReaderIndex].readerAddress << " - " << readers[ReaderIndex].readerGender << " - "
         << readers[ReaderIndex].readerBirthday << " - " << readers[ReaderIndex].readerCardDates << " - " << readers[ReaderIndex].readerExpiryDates << "\n";
}

Reader createReader(const Reader readers[], int countReader)
{
    Reader newReader;
    
    cout << "Nhap thong tin cua doc gia moi: \n";
    cout << "Ten: ";
    cin.ignore();
    cin.getline(newReader.readerName, 100);

    // cout << "Ma doc gia: ";
    // cin.getline(newReader.readerId, 20);
    do{
        cout << "Ma doc gia: ";
        cin.getline(newReader.readerId, 20);
        if (!isUniqueID(readers, countReader, newReader.readerId)){
            cout << "Ma doc gia nay da ton tai. Xin hay nhap lai\n";
        }
        else{
            break;
        }
    } while (true);

    // cout << "CCCD: ";
    // cin.getline(newReader.readerCCCD, 100);
    do{
        cout << "CCCD: ";
        cin.getline(newReader.readerCCCD, 100);
        if (!isUniqueCCCD(readers, countReader, newReader.readerCCCD)){
            cout << "Ma CCCD khong the trung. Xin hay nhap lai.\n";
        }
        else{
            break;
        }
    } while(true);

    cout << "Email: ";
    cin.getline(newReader.readerMail, 100);
    
    cout << "Dia chi: ";
    cin.getline(newReader.readerAddress, 100);
    
    cout << "Gioi tinh: ";
    cin.getline(newReader.readerGender, 10);

    cout << "Ngay thang nam sinh (theo dd/mm/yyyy): \n";
    cin >> newReader.readerBirthday;
    
    cout << "Ngay lap the (theo dd/mm/yyyy): \n";
    cin >> newReader.readerCardDates;

    newReader.readerExpiryDates = newReader.readerCardDates;
    newReader.readerExpiryDates.addMonths(48);
    return newReader;
}

void addReader(Reader readers[], int &countReader)
{
    if (countReader >= MAX_READERS)
    {
        cout << "Khong the tiep tuc them doc gia moi vi danh sach da day.\n";
        return;
    }
    Reader newReader = createReader(readers, countReader);

    // cout << "Ngay het han cua doc gia: " << newReader.readerExpiryDates << "\n";
    cout << "Doc gia moi da duoc them thanh cong.\n";
    readers[countReader] = newReader;
    countReader++;
}

void displayAllReaders(Reader readers[], int countReader)
{
    cout << "Danh sach doc gia hien co o trong thu vien: \n";
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
