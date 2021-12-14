#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cwctype>
#include <io.h>
#include <fcntl.h>
using namespace std;

void setColor();
void clrscr();
void pause();

//setmode to UTF16 to read and write Vietnamese
void setMode()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
}

//change background and text color
void setColor(int background_color, int text_color)
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

//clear screen
void clrscr()
{
    system("cls");
}

//pause screen and waiting
void pause()
{
    setColor(0, 10);
    wcout << L"\nLoading......" << endl;
    setColor(0, 15);
    system("pause > nul");
}

//welcome screen
void welcomeScreen()
{
    clrscr();
    wcout << L"\t+----------------------------------------------+" << endl
          << L"\t|    ĐỒ ÁN LẬP TRÌNH TÍNH TOÁN  PBL2 20.15A    |" << endl
          << L"\t+----------------------------------------------+" << endl
          << L"\t|                                              |" << endl
          << L"\t|                   ĐỀ TÀI:                    |" << endl
          << L"\t|              TỪ ĐIỂN TIẾNG ANH               |" << endl
          << L"\t|           KẾT HỢP TRÒ CHƠI TỪ VỰNG           |" << endl
          << L"\t|                                              |" << endl
          << L"\t|            Sinh viên thực hiện:              |" << endl
          << L"\t|            1. Võ Hoàng Bảo                   |" << endl
          << L"\t|            2. Đặng Huỳnh Khánh Dương         |" << endl
          << L"\t|            3. Cao Kiều Văn Mạnh              |" << endl
          << L"\t|                                              |" << endl
          << L"\t|          GVHD: TS. Trần Hồ Thủy Tiên         |" << endl
          << L"\t|                                              |" << endl
          << L"\t+----------------------------------------------+" << endl
          << endl
          << endl;
}

//user menu
int selectMenu()
{
    // Menu
    clrscr();
    wcout << L"\t+----------------------------------------+" << endl
          << L"\t|       DICTIONARY AND VOCAB GAME        |" << endl
          << L"\t+----------------------------------------+" << endl
          << L"\t|                                        |" << endl
          << L"\t|          1. Search a word              |" << endl
          << L"\t|          2. Add a new word             |" << endl
          << L"\t|          3. Delete a word              |" << endl
          << L"\t|          4. Edit a word                |" << endl
          << L"\t|          5. Game                       |" << endl
          << L"\t|          6. Exit and save              |" << endl
          << L"\t|                                        |" << endl
          << L"\t+----------------------------------------+" << endl
          << endl;
    //Validate choices
    bool isSelected = false;
    int selection;
    do
    {
        wcout << L"\n==>> Select one function: ";
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

//check if user want to continue
int toContinue()
{
    int selection;
    wcout << L"\n\n--++----------++--" << endl;
    wcout << L"Press 1 to continue." << endl;
    wcout << L"Press 2 to back to menu." << endl;
    wcout << L"Press any key else to exit." << endl;
    wcout << L"==>> Select one: ";
    fflush(stdin);
    wcin >> selection;
    return selection;
}

//exit screen
void exitScreen()
{
    clrscr();
    wifstream exitFile(L"./data/thanks.txt");
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