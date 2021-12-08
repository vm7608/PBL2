#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
// #include <cctype>
#include <cwctype>
#include <io.h>    //setmode lib
#include <fcntl.h> //setmode lib
using namespace std;

void setColor();
void clrscr();
void pause();

void setMode() // setmode to UTF16 to read and write Vietnamese (đổi sang UTF16 để đọc ghi tiếng Việt)
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
}

void setColor(int background_color, int text_color) // change background and text color (đổi màu nền và màu chữ)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int color_code = background_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
    /*-----------------------------------------------------------
    0 = Black       1 = Blue        2 = Green       3 = Aqua
    4 = Red         5 = Purple      6 = Yellow      7 = White
    8 = Gray        9 = Li Blue     10 = Li Green    11 = Li Aqua
    12 = Li Red     13 = Li Purple  14 = Li Yellow  15 = Bri White
    -------------------------------------------------------------*/
}

void clrscr() // clear screen (xóa toàn bộ màn hình)
{
    system("cls");
}

void pause() // pause screen and waiting (dừng chương trình và đợi)
{
    setColor(0, 10);
    wcout << L"\nLoading......" << endl;
    setColor(0, 15);
    system("pause > nul");
}

void welcomeScreen() //welcome screen (màn hình bắt đầu chương trình)
{
    clrscr();
    wcout << L"+----------------------------------------------+" << endl
          << L"|    ĐỒ ÁN LẬP TRÌNH TÍNH TOÁN  PBL2 20.15A    |" << endl
          << L"+----------------------------------------------+" << endl
          << L"|                                              |" << endl
          << L"|                   ĐỀ TÀI:                    |" << endl
          << L"|              TỪ ĐIỂN TIẾNG ANH               |" << endl
          << L"|           KẾT HỢP TRÒ CHƠI TỪ VỰNG           |" << endl
          << L"|                                              |" << endl
          << L"|            Sinh viên thực hiện:              |" << endl
          << L"|            1. Võ Hoàng Bảo                   |" << endl
          << L"|            2. Đặng Huỳnh Khánh Dương         |" << endl
          << L"|            3. Cao Kiều Văn Mạnh              |" << endl
          << L"|                                              |" << endl
          << L"|          GVHD: TS. Trần Hồ Thủy Tiên         |" << endl
          << L"|                                              |" << endl
          << L"+----------------------------------------------+" << endl
          << endl
          << endl;
}

int selectMenu() // menu for selecting (bảng chọn thao tác cho user)
{
    // Menu
    clrscr();
    wcout << L"+----------------------------------------+" << endl
          << L"|       DICTIONARY AND VOCAB GAME        |" << endl
          << L"+----------------------------------------+" << endl
          << L"|                                        |" << endl
          << L"|          1. Search a word              |" << endl
          << L"|          2. Add a new word             |" << endl
          << L"|          3. Delete a word              |" << endl
          << L"|          4. Edit a word                |" << endl
          << L"|          5. Game                       |" << endl
          << L"|          6. Exit and save              |" << endl
          << L"|                                        |" << endl
          << L"+----------------------------------------+" << endl
          << endl;
    //Validate choices (kiểm tra các lựa chọn của user)
    bool isSelected = false;
    int selection;
    do
    {
        // isSelected = false; //dư à?
        wcout << L"\n===>> Choose your option: ";
        fflush(stdin);
        wcin >> selection;

        if (selection == 1 || selection == 2 || selection == 3 ||
            selection == 4 || selection == 5 || selection == 6)
            isSelected = true;
        else
            wcout << L"\nFail! Invalid choice!" << endl;
    } while (!isSelected);

    return selection;
}

int toContinue() // check if user want to continue (kiểm tra nếu user muốn thực hiện lại thao tác)
{
    int selection;
    wcout << L"\n\nPress 1 to continue.\nPress 2 to back to menu.\nPress any key else to exit.\n===>> Select one: ";
    fflush(stdin);
    wcin >> selection;
    return selection;
}

void exitScreen() // goodbye screen (màn hình kết thúc chương trình)
{
    clrscr();
    wifstream exitFile(L"./datafile/thanks.txt");
    wchar_t str[300];
    if (exitFile.fail())
        wcout << L"Failed to open data file!" << endl;
    else
    {
        while (exitFile)
        {
            exitFile.getline(str, 300);
            if (exitFile)
                wcout << str << endl;
        }
    }
    exitFile.close();
    pause();
}