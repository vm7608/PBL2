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

    // if list is empty or word is not in list
    if (head == NULL || position == -1) 
    {
        return false;
    }

    // if list has only head or the node to be deleted is head
    if (this->head->next == NULL || position == 0) 
    {
        this->head = this->head->next;
    }
    else //other cases
    {
        while (temp != NULL && k != position - 1)
        {
            temp = temp->next;
            ++k; //go to node before the node to be deleted
        }
        temp->next = temp->next->next; // put pointer after the node to be deleted
    }
    return true;
}

// this func add new node to the head of list
bool linkedList::addNode(word newWord)
{                                    
    // list is empty or new word is not in list => add                           
    if (this->isEmpty() || this->findNode(newWord.eWord) == -1) 
    {
        node *temp = new node();
        temp->data = newWord;
        temp->next = this->head;
        head = temp;
        return true;
    }
    else // if word has already in list => return false
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
    return -1; // -1 means node isn't in list
}

void linkedList::printList()
{
    node *temp = this->head;
    for (temp; temp != NULL; temp = temp->next)
    {
        wcout << temp->data << L" --> ";
    }
}

//save all word in list into input file
void linkedList::saveListToFile()
{
    node *temp = this->head;
    word tempWord;

    wfstream input;
    input.open(L"./data/input.txt", ios::app);
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