#include <iostream>
#include "Word.h"
using namespace std;
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class node
{
private:
    word data;
    node *next;

public:
    node()
    {
        next = NULL;
    }
    friend class linkedList;
};

class linkedList
{
private:
    node *head;

public:
    linkedList();                      // hàm dựng list
    ~linkedList();                     // hàm hủy list
    int listLenght();                  // trả về độ dài list
    word getNode(int position);        // trả về từ của node có vị trí = postion
    bool delNode(wstring deletedWord); // xóa node khỏi list: true - thành công; false - không có node để xóa
    bool addNode(word newWord);        // thêm node vào đầu list: true - thành công; false - từ đã có trong từ điển
    bool isEmpty();                    // kiểm tra list: true -> rỗng, false -> không rỗng
    int findNode(wstring eWord);       // trả về position của node hoặc -1 (không có node)
    void printList();                  // in toàn bộ list
    void saveListToFile();
};

#endif //LINKEDLIST_H