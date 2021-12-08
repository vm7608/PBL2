#include <iostream>
#include <locale>
#include <bits/stdc++.h>
#include <fstream>
#include "LinkedList.h"
using namespace std;

linkedList::linkedList()
{
    this->head = NULL;
}

int linkedList::listLenght()
{
    int lenght = 0;
    node *temp = this->head;
    for (temp; temp != NULL; temp = temp->next)
    {
        ++lenght;
    }
    return lenght;
}

linkedList::~linkedList()
{
    node *temp = NULL;
    while (this->head)
    {
        temp = this->head;
        this->head = this->head->next;
        free(temp);
    }
}

word linkedList::getNode(int position)
{
    int k = 0;
    node *temp = this->head;
    while (k != position && temp != NULL)
    {
        temp = temp->next;
        ++k;
    }
    return temp->data;
}

bool linkedList::delNode(wstring deletedWord)
{
    int position = this->findNode(deletedWord);
    int k = 0;
    node *temp = this->head;

    if (head == NULL || position == -1) // danh sách rỗng, hoặc từ không có trong ds
    {
        return false;
    }

    if (this->head->next == NULL || position == 0) // list chỉ có mình head hoặc vị trí cần xóa là head
    {
        this->head = this->head->next;
    }
    else // trường hợp còn lại
    {
        while (temp != NULL && k != position - 1)
        {
            temp = temp->next;
            ++k; // phần tử trước pt cần xóa
        }
        temp->next = temp->next->next; // đưa con trỏ ra phía sau phần tử cần xóa
    }
    return true;
}

bool linkedList::addNode(word newWord)
{                                                               // thêm node vào đầu dslk
    if (this->isEmpty() || this->findNode(newWord.eWord) == -1) // nếu danh sách rỗng hoặc ko có từ đó trong list
    {
        node *temp = new node();
        temp->data = newWord;
        temp->next = this->head;
        head = temp;
        return true;
    }
    else // từ đã có trong list
    {
        return false;
    }
}

bool linkedList::isEmpty()
{
    if (this->head == NULL)
        return true;
    return false;
}

int linkedList::findNode(wstring eWord)
{
    node *temp = this->head;
    int position = 0;
    for (temp; temp != NULL; temp = temp->next)
    {
        if (temp->data.eWord == eWord)
        {
            return position;
        }
        ++position;
    }
    return -1; // nghĩa là ko có node
}

void linkedList::printList()
{
    node *temp = this->head;
    for (temp; temp != NULL; temp = temp->next)
    {
        wcout << temp->data << L" --> ";
    }
}

void linkedList::saveListToFile()
{
    node *temp = this->head;
    word tempWord;

    wfstream input;
    input.open(L"./datafile/input.txt", ios::app);
    std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);
    input.imbue(loc);

    for (temp; temp != NULL; temp = temp->next)
    {
        tempWord = temp->data;
        input << tempWord.eWord << L" " << tempWord.pronunciation << L" " << tempWord.type << endl;
        input << tempWord.vnMeaning << endl;
    }
    input.close();
}