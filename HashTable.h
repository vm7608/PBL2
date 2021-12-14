#include <iostream>
#include "LinkedList.h"
using namespace std;
#ifndef HASHTABLE_H
#define HASHTABLE_H

class hashTable
{
private:
    int tableSize;
    linkedList *table;

public:
    hashTable(int kichThuocTuDien = 400);
    int hashFunction(wstring value);
    bool addToTable(word input);                         // add new word; true - oke; false - fail
    bool delFromTable(wstring inputWord);                // del word; true - oke; false - fail
    void editInTable(wstring inputWord, int userChoice); // edit word; true - oke; false - fail
    word findInTable(wstring inputWord);                 // find and return word
    bool fastFind(wstring inputWord);                    // fast find the word
    void traverseTable();                                // traverse table
    ~hashTable();

    friend class dictionary;
};

#endif //HASHTABLE_H