#include "Reader.h"

void displayReader(Reader readers[], int ReaderIndex)
{
    ostringstream birthday, cardDate, expiryDate;
    birthday << readers[ReaderIndex].readerBirthday;
    cardDate << readers[ReaderIndex].readerCardDates;
    expiryDate << readers[ReaderIndex].readerExpiryDates;
    header3();
    printf("| %-4d | %-20s | %-10s | %-8s | %-20s | %-20s | %-5s | %-10s | %-10s | %-10s |\n",
           ReaderIndex + 1, readers[ReaderIndex].readerName, readers[ReaderIndex].readerId, readers[ReaderIndex].readerCCCD, readers[ReaderIndex].readerMail, readers[ReaderIndex].readerAddress, readers[ReaderIndex].readerGender, birthday.str().c_str(), cardDate.str().c_str(), expiryDate.str().c_str());
    header3();
}

Reader createReader(const Reader readers[], int countReader)
{
    Reader newReader;

    cout << "Nhap thong tin cua doc gia moi: \n";
    cout << "Ten: ";
    cin.ignore();
    cin.getline(newReader.readerName, 100);

    do
    {
        cout << "Ma doc gia: ";
        cin.getline(newReader.readerId, 20);
        if (isUniqueID(readers, countReader, newReader.readerId))
        {
            cout << "Ma doc gia nay da ton tai. Xin hay nhap lai.\n";
        }
        else
        {
            break;
        }
    } while (true);

    do
    {
        cout << "CCCD: ";
        cin.getline(newReader.readerCCCD, 100);
        if (isUniqueCCCD(readers, countReader, newReader.readerCCCD))
        {
            cout << "Ma CCCD khong the trung. Xin hay nhap lai.\n";
        }
        else
        {
            break;
        }
    } while (true);

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
    system("cls");
    if (countReader >= MAX_READERS)
    {
        cout << "Khong the tiep tuc them doc gia moi vi danh sach da day.\n";
        system("pause");
        system("cls");
        return;
    }
    Reader newReader = createReader(readers, countReader);

    cout << "Doc gia moi da duoc them thanh cong.\n";
    readers[countReader] = newReader;
    countReader++;
    system("pause");
    system("cls");
}

void displayAllReaders(Reader readers[], int countReader)
{
    system("cls");
    cout << "Danh sach doc gia hien co o trong thu vien: \n";
    displayReaderHeader();
    for (int i = 0; i < countReader; i++)
        displayReader(readers, i);
    header1();
    system("pause");
    system("cls");
}

void editReader(Reader readers[], int countReader)
{
    system("cls");
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
            printBorder('=');
            printCenteredLine("CHINH SUA THONG TIN DOC GIA");
            printBorder('=');
            printMenuLine("1. Ho ten.");
            printMenuLine("2. Ma doc gia.");
            printMenuLine("3. CCCD.");
            printMenuLine("4. Email.");
            printMenuLine("5. Dia chi.");
            printMenuLine("6. Gioi tinh.");
            printMenuLine("7. Ngay sinh.");
            printMenuLine("0. Ve lai cua so quan ly doc gia.");
            printBorder('=');
            printPromptLine("Nhap vao thong tin can chinh sua: ");
            printf(">> ");
            scanf("%d", &choice);

            // cin.ignore();
            switch (choice)
            {
            case 1:
                cin.ignore();
                cout << "Nhap ten moi: ";
                cin.getline(readers[readerIndex].readerName, 100);
                break;
            case 2:
                do
                {
                    cin.ignore();
                    cout << "Ma doc gia: ";
                    char newId[20];
                    cin.getline(newId, 20);
                    if (strcmp(newId, readers[readerIndex].readerId) == 0) break;
                    if (isUniqueID(readers, countReader, newId, readerIndex))
                    {
                        cout << "Ma doc gia nay da ton tai. Xin hay nhap lai.\n";
                    }
                    else{
                        strcpy(readers[readerIndex].readerId, newId);
                        break;
                    }
                } while (true);
                
                break;
            case 3:
                do
                {
                    cin.ignore();
                    cout << "CCCD: ";
                    char newCCCD[100];
                    cin.getline(newCCCD, 100);
                    if (strcmp(readers[readerIndex].readerCCCD, newCCCD) == 0) break;
                    if (isUniqueCCCD(readers, countReader, newCCCD, readerIndex))
                    {
                        cout << "Ma CCCD khong the trung. Xin hay nhap lai.\n";
                    }
                    else{
                        strcpy(readers[readerIndex].readerCCCD, newCCCD);
                        break;
                    }
                } while (true);
                
                break;
            case 4:
                cin.ignore();
                cout << "Mail: ";
                cin.getline(readers[readerIndex].readerMail, 100);
                break;
            case 5:
                cin.ignore();
                cout << "Dia chi moi: ";
                cin.getline(readers[readerIndex].readerAddress, 100);
                break;
            case 6:
                cin.ignore();
                cout << "Chinh sua gioi tinh: ";
                cin.getline(readers[readerIndex].readerGender, 10);
                break;
            case 7:
                cout << "Chinh sua ngay sinh: \n";
                cout << "Nhap ngay sinh theo dinh dang dd/mm/yyyy: \n";
                cin >> readers[readerIndex].readerBirthday;
                break;
            case 0:
                cout << "Roi cua so chinh sua doc gia.\n";
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
                displayReader(readers, readerIndex);
                system("pause");
            }
        } while (choice != 0);
        return;
    }
    cout << "Khong tim thay doc gia can tim de thay doi.\n";
    system("pause");
    system("cls");
}
void removeReader(Reader readers[], int &countReader)
{
    system("cls");
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
            system("pause");
            system("cls");
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
            system("pause");
            system("cls");
            return;
        }
    }
    cout << "Khong tim thay ten doc gia theo yeu cau.\n";
    system("pause");
    system("cls");
}
void findReaderBaseOnCCCD(Reader readers[], int countReader)
{
    system("cls");
    char inputCCCD[100];
    printf("Nhap vao CCCD cua doc gia muon tim kiem: ");
    cin.ignore();
    cin.getline(inputCCCD, 100);
    int readerIndex = FindReaderBasedOnCCCD(readers, countReader, inputCCCD);
    if (readerIndex != -1)
    {
        displayReader(readers, readerIndex);
        system("pause");
        system("cls");
        return;
    }
    printf("Khong tim thay doc gia can tim.\n");
    system("pause");
    system("cls");
}
void findReaderBaseOnName(Reader readers[], int countReader)
{
    system("cls");
    char inputName[100];
    printf("Nhap vao ten cua doc gia can tim kiem: ");
    cin.ignore();
    cin.getline(inputName, 100);
    int readerIndex = FindReaderBasedOnName(readers, countReader, inputName);
    if (readerIndex != -1)
    {
        displayReader(readers, readerIndex);
        system("pause");
        system("cls");
        return;
    }
    printf("Khong tim thay doc gia can tim.\n");
    system("pause");
    system("cls");
}
