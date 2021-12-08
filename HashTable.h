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
    bool addToTable(word input);                         // thêm từ vào bảng true - oke; false - fail
    bool delFromTable(wstring inputWord);                // xóa từ khỏi bảng true - oke; false - fail
    void editInTable(wstring inputWord, int userChoice); // sửa từ trong bảng: true - oke; false - fail
    void traverseTable();                                // duyệt qua bảng băm
    word findInTable(wstring inputWord);                 // tìm và trả về từ tìm được
    bool fastFind(wstring inputWord);                    // tìm nhanh 1 từ trong bảng true có - false không
    ~hashTable();

    friend class dictionary;
};

#endif //HASHTABLE_H