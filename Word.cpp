#include <iostream>
#include <string>
#include <cstring>
#include <io.h>    //wstr
#include <fcntl.h> //wstr
#include "Word.h"
using namespace std;

word::word()
{
    this->type = L"";
    this->eWord = L"";
    this->pronunciation = L"";
    this->vnMeaning = L"";
}

word::word(const word &a)
{
    this->eWord = a.eWord;
    this->type = a.type;
    this->pronunciation = a.pronunciation;
    this->vnMeaning = a.vnMeaning;
}

word::~word() {}

const word &word::operator=(const word &x)
{
    this->eWord = x.eWord;
    this->vnMeaning = x.vnMeaning;
    this->type = x.type;
    this->pronunciation = x.pronunciation;
    return *this;
}

wostream &operator<<(wostream &out, const word &a)
{
    wcout << endl;
    wcout << L"------------" << endl;
    wcout << a.eWord << endl;
    wcout << L"Word's type: " << a.type << endl;
    wcout << L"Word's pronunciation: " << a.pronunciation << endl;
    wcout << L"Vietnamese meaning: " << a.vnMeaning << endl;
    wcout << L"------------" << endl;
    return out;
}

wistream &operator>>(wistream &in, word &a)
{
    wcout << endl;

    wcout << L"Enter English word: ";
    std::fflush(stdin);
    getline(wcin, a.eWord);

    wcout << L"Enter word's type: ";
    std::fflush(stdin);
    getline(wcin, a.type);

    wcout << L"Enter word's pronunciation: ";
    std::fflush(stdin);
    getline(wcin, a.pronunciation);

    wcout << L"Enter Vietnamese meaning: ";
    std::fflush(stdin);
    getline(wcin, a.vnMeaning);

    return in;
}

bool word::operator==(word a)
{
    if (a.eWord != this->eWord)
        return false;
    if (a.vnMeaning != this->vnMeaning)
        return false;
    if (a.type != this->type)
        return false;
    if (a.pronunciation != this->pronunciation)
        return false;
    return true;
}