#include <iostream>
#include <algorithm>
#include <fstream>
#include <locale>
#include <cstring>
#include <bits/stdc++.h>
#include "Dict.h"
#include "game.h"
using namespace std;

// convert to lower case
wstring toLowerCase(wstring eWord) 
{
    transform(eWord.begin(), eWord.end(), eWord.begin(), ::tolower);
    return eWord;
}

dictionary::dictionary() {}

void dictionary::searchWordInDictionary()
{
    system("cls");
    word result;
    word empty;
    wstring inputWord;

    wcout << L"\t<<===== SEARCHING =====>>" << endl;
    wcout << L"\nEnter the word you want to search: ";
    std::fflush(stdin);
    getline(wcin, inputWord);
    inputWord = toLowerCase(inputWord);
    wcout << L"\nSearching..." << endl;

    result = this->appDict.findInTable(inputWord);
    //check if result is an empty word (that's mean word isn't in dictionary)
    if (result == empty)
    {
        wcout << L"\nFail! This word isn't in the dictionary!" << endl;
    }
    else //print out searched word
    {
        wcout << result;
    }
}

void dictionary::addNewWordToDictionary()
{
    system("cls");
    word temp;
    wcout << L"\t<<===== ADDING =====>>" << endl;
    wcin >> temp;
    temp.eWord = toLowerCase(temp.eWord);
    wcout << L"\nAdding..." << endl;

    if (this->appDict.addToTable(temp))
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

    wcout << L"\t<<===== DELETING =====>>" << endl;
    wcout << L"\nEnter the word you want to delete: ";
    std::fflush(stdin);
    getline(wcin, inputWord);
    inputWord = toLowerCase(inputWord);
    wcout << L"\nDeleting..." << endl;

    if (this->appDict.delFromTable(inputWord))
    {
        wcout << L"\nSuccessfully deleted!" << endl;
    }
    else
    {
        wcout << L"\nFail! This word isn't in the dictionary!" << endl;
    }
}

void dictionary::editWordInDictionary()
{
    system("cls");
    word result;
    word empty;
    wstring inputWord;

    wcout << L"\t<<===== EDITING =====>>" << endl;
    wcout << L"\nEnter the word you want to edit: ";
    std::fflush(stdin);
    getline(wcin, inputWord);
    inputWord = toLowerCase(inputWord);

    //check if edited word is currently in table or not
    result = this->appDict.findInTable(inputWord);
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
          << L"|       1. Edit English word             |" << endl
          << L"|       2. Edit word's type              |" << endl
          << L"|       3. Edit word's pronunciation     |" << endl
          << L"|       4. Edit Vietnamese meaning       |" << endl
          << L"|       5. Return                        |" << endl
          << L"|                                        |" << endl
          << L"+----------------------------------------+" << endl;

    //Validate choices
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

    this->appDict.editInTable(inputWord, selection);
    
}

void dictionary::playGame()
{
    system("cls");
    wcout << L"\t<<===== PLAYING GAME =====>>" << endl;
    Game dictGame;
    wcout << L"\nLoading game..." <<endl;
    system("pause > nul");
    dictGame.Start();
}

void dictionary::updateToFile()
{
    word temp;
    wfstream input;
    input.open(L"./data/input.txt", ios::out);
    std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);
    input.imbue(loc);
    input.close();

    wcout << L"Waiting for updating data..." << endl;
    for (int i = 0; i < this->appDict.tableSize; i++)
    {
        if (this->appDict.table[i].isEmpty())
            continue;
        this->appDict.table[i].saveListToFile();
    }
    wcout << L"Successfully saved!" << endl;
    system("pause");
}

dictionary::~dictionary()
{
    system("cls");
    wcout << L"Waiting for cleaning memory..." << endl;
    wcout << L"Cleaning done!" << endl;
}