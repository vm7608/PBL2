#include <iostream>
#include <string>
#include "HashTable.h"
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

hashTable::hashTable(int size)
{
    this->tableSize = size;
    table = new linkedList[this->tableSize];

    word temp;
    wstring trash; 
    wifstream input(L"./data/input.txt");

    std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);

    if (input.fail())
        wcout << L"Failed to open data file!" << endl;
    else
    {
        input.imbue(loc);
        while (!input.eof())
        {
            input >> temp.eWord;
            input >> temp.pronunciation;
            input >> temp.type;
            getline(input, trash, L'\n'); //ignore trash char
            getline(input, temp.vnMeaning, L'\n');
            this->addToTable(temp);
        }
    }
    input.close();
}

int hashTable::hashFunction(wstring value)
{
    int i;
    int c = 0;
    unsigned long hash = 5381;
    for (i = 0; i < value.length(); ++i)
    {
        c = (int)value.at(i);
        hash = ((hash << 5) + hash) + c;
    }
    return hash % this->tableSize;
}

bool hashTable::addToTable(word input)
{
    bool check;
    int viTri = hashFunction(input.eWord);
    check = table[viTri].addNode(input);
    return check;
}

bool hashTable::delFromTable(wstring inputWord)
{
    bool check;
    int index = hashFunction(inputWord);
    check = table[index].delNode(inputWord);
    return check;
}

void hashTable::traverseTable()
{
    for (int i = 0; i < this->tableSize; i++)
    {
        table[i].printList();
    }
}

//return searched word or return an empty word if can't find input word
word hashTable::findInTable(wstring inputWord)
{
    word temp;
    int viTri = hashFunction(inputWord);
    int position = table[viTri].findNode(inputWord);
    //check if the list is empty or word is in list or not
    if (this->table[viTri].isEmpty() || position == -1)
    {
        return temp;
    }
    else
    {
        temp = table[viTri].getNode(position);
        return temp;
    }
}

hashTable::~hashTable()
{
    for (int i = 0; i < this->tableSize; i++)
    {
        table[i].~linkedList();
    }
    delete[] table;
}

void hashTable::editInTable(wstring inputWord, int userChoice)
{
    /*
    case 1: edit eWord
    case 2: edit type
    case 3: edit pronunciation
    case 4: edit vnMeaning 
    case 5: break and return
    */
    switch (userChoice)
    {
        case 1:
        {
            word editedWord = this->findInTable(inputWord);
            wcout << L"Enter edited English word: ";
            std::fflush(stdin);
            getline(wcin, editedWord.eWord);

            if (this->addToTable(editedWord))
            {
                this->delFromTable(inputWord);
            }
            else
            {
                wcout << L"\nFail! The edited word has already in the dictionary!" << endl;
                return;
            }
            break;
        }
        case 2:
        {
            word editedWord = this->findInTable(inputWord);
            wcout << L"Enter edited word's type: ";
            std::fflush(stdin);
            getline(wcin, editedWord.type);
            this->delFromTable(inputWord);
            this->addToTable(editedWord);
            break;
        }
        case 3:
        {
            word editedWord = this->findInTable(inputWord);
            wcout << L"Enter edited word's pronunciation: ";
            std::fflush(stdin);
            getline(wcin, editedWord.pronunciation);
            this->delFromTable(inputWord);
            this->addToTable(editedWord);
            break;
        }

        case 4:
        {
            word editedWord = this->findInTable(inputWord);
            wcout << L"Enter edited Vietnamese meaning: ";
            std::fflush(stdin);
            getline(wcin, editedWord.vnMeaning);
            this->delFromTable(inputWord);
            this->addToTable(editedWord);
            break;
        }
        case 5:
        {
            break;
        }
    }
    wcout << L"\nSuccessfully edited!" << endl;
}