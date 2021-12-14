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
/**************/
class linkedList
{
private:
    node *head;

public:
    linkedList();
    ~linkedList();
    int listLenght();                  // return list lenght
    word getNode(int position);        // return data (word) of the node has position
    bool delNode(wstring deletedWord); // true - success; false - fail (nothing to del)
    bool addNode(word newWord);        // true - success; false - fail (word has already in list)
    bool isEmpty();                    // true - empty; false - not empty
    int findNode(wstring eWord);       // return node's position or -1 (node isn't in list)
    void printList();                  // in toàn bộ list
    void saveListToFile();             // save data back to input.txt - mode append
};

#endif //LINKEDLIST_H