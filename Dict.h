#include <iostream>
#include "HashTable.h"
using namespace std;
#ifndef DICT_H
#define DICT_H

class dictionary
{
private:
    hashTable myDict;

public:
    dictionary();
    void addNewWordToDictionary();
    void delWordFromDictionary();
    void searchWordInDictionary();
    void editWordInDictionary();
    void playGame();
    void updateToFile();
    ~dictionary();
};

#endif //DICT_H