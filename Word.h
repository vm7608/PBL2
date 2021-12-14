#include <iostream>
using namespace std;
#ifndef WORD_H
#define WORD_H

class word
{
private:
    wstring eWord;
    wstring type;
    wstring pronunciation;
    wstring vnMeaning;

public:
    word();
    word(const word &a);
    ~word();
    const word &operator=(const word &x);
    bool operator==(word a);
    friend wistream &operator>>(wistream &in, word &a);
    friend wostream &operator<<(wostream &out, const word &a);
    friend class dictionary;
    friend class hashTable;
    friend class linkedList;
};

#endif //WORD_H