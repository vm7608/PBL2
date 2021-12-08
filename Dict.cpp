#include <iostream>
#include <algorithm>
#include <fstream>
#include <locale>
#include <cstring>
#include <bits/stdc++.h>
#include "Dict.h"
#include "game.h"
using namespace std;

wstring toLowerCase(wstring eWord)
{
    transform(eWord.begin(), eWord.end(), eWord.begin(), ::tolower);
    return eWord;
}

dictionary::dictionary()
{
}

void dictionary::searchWordInDictionary()
{
    system("cls");
    word result;
    word empty;
    wstring inputWord;
    wcout << L"<<===== SEARCHING =====>>" << endl;
    wcout << L"Enter the word you want to search: ";
    std::fflush(stdin);
    getline(wcin, inputWord);
    inputWord = toLowerCase(inputWord);
    wcout << L"\nSearching..." << endl;
    result = this->myDict.findInTable(inputWord);
    if (result == empty)
    {
        wcout << L"\nFail! This word isn't in the dictionary!" << endl;
    }
    else
    {
        wcout << result;
    }
}

void dictionary::addNewWordToDictionary()
{
    system("cls");

    word temp;
    wcout << L"<<===== ADDING =====>>" << endl;
    wcin >> temp;
    temp.eWord = toLowerCase(temp.eWord);
    wcout << L"\nAdding..." << endl;
    if (this->myDict.addToTable(temp))
    {
        wcout << L"\nSuccessfully added!" << endl;
    }
    else
    {
        wcout << L"\nFail! This word has already in the dictionary" << endl;
    }
}

void dictionary::delWordFromDictionary()
{
    system("cls");
    wstring inputWord;
    wcout << L"<<===== DELETING =====>" << endl;
    wcout << L"Enter the word you want to delete: ";
    std::fflush(stdin);
    getline(wcin, inputWord);
    inputWord = toLowerCase(inputWord);
    wcout << L"Deleting..." << endl;
    if (this->myDict.delFromTable(inputWord))
    {
        wcout << L"Successfully deleted!" << endl;
    }
    else
    {
        wcout << L"Fail! This word isn't in the dictionary!" << endl;
    }
}

void dictionary::editWordInDictionary()
{
    system("cls");
    word result;
    word empty;
    wstring inputWord;
    wcout << L"<<===== EDITING =====>>" << endl;
    wcout << L"Enter the word you want to edit: ";
    std::fflush(stdin);
    getline(wcin, inputWord);
    inputWord = toLowerCase(inputWord);

    result = this->myDict.findInTable(inputWord);
    if (result == empty)
    {
        wcout << L"\nFail! This word isn't in the dictionary!" << endl;
        return;
    }
    else
    {
        wcout << result;
    }

    int userChoice;
    wcout << endl;
    wcout << L"+------ Choose your editing option ------+" << endl
          << L"|                                        |" << endl
          << L"|      1. Edit English word              |" << endl
          << L"|      2. Edit word's type               |" << endl
          << L"|      3. Edit word's pronunciation      |" << endl
          << L"|      4. Edit Vietnamese meaning        |" << endl
          << L"|      5. Return                         |" << endl
          << L"|                                        |" << endl
          << L"+----------------------------------------+" << endl;

    //Validate choices (kiểm tra các lựa chọn của user)
    bool isSelected = false;
    int selection;
    do
    {
        wcout << L"\n====>> Choose your option: ";
        fflush(stdin);
        wcin >> selection;

        if (selection == 1 || selection == 2 || selection == 3 ||
            selection == 4 || selection == 5)
            isSelected = true;
        else
            wcout << L"\nFail! Invalid choice!" << endl;
    } while (!isSelected);
    this->myDict.editInTable(inputWord, selection);
    
}

void dictionary::playGame()
{
    system("cls");
    wcout << L"<<=====PLAYING GAME=====>>" << endl;
    Game dictGame;
    wcout << L"\nLoading game..." <<endl;
    system("pause > nul");
    dictGame.Start();
    
    // nối của dương vào
}

void dictionary::updateToFile()
{
    word temp;
    wfstream input;
    input.open(L"./datafile/input.txt", ios::out);
    std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);
    input.imbue(loc);
    input.close();

    wcout << L"Waiting for updating data..." << endl;
    for (int i = 0; i < this->myDict.tableSize; i++)
    {
        if (this->myDict.table[i].isEmpty())
            continue;
        this->myDict.table[i].saveListToFile();
    }
    wcout << L"Successfully saved!" << endl;
    system("pause");
}

dictionary::~dictionary()
{
    system("cls");
    wcout << L"Waiting for cleaning memory..." << endl;
    // myDict.~hashTable(); // có vẻ gọi như này nó sẽ lỗi gì đó, có crack nhẹ
    wcout << L"Cleaning done!" << endl;
}