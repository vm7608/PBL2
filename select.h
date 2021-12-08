#ifndef SELECT_H
#define SELECT_H
#include "question.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#define MAX 512
using namespace std;
fstream f;

class Select : public Question {
    protected:
        string** inputtt;
        int offset;
        int num;
        int score;
        void Setup();
        string* removeDupWord(string str, int n);
        int RandomNumber(double, double);
    public:
        Select();
        Select(int, int);
        Select(const Select &a);
        ~Select();
        int Show();
        void SetOffset(int, int, int);
};

int Select::RandomNumber(double a, double b) { // Using C++11 random features
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(a, b);
    return dist(mt);
}


// Split str to n components
string* Select::removeDupWord(string str, int n) {
    string word = "";
    string* res = new string[n];
    int i = 0;
    for (auto x : str) 
    {
        if ((x == '\t' || x == ' ') && i < n - 1) // co the bo x == ' '
        {
            res[i] = word;
            i++;
            word = "";
        }
        else {
            word = word + x;
        }
    }
    res[i] = word;
    return res;
}

Select::Select() : Question() {}

Select::Select(int score, int sodapan) : Question(score) {}

Select::Select(const Select &a) : Question(a.score) {}

Select::~Select() {
    for(int i = 0; i < 3; i++) {
        delete [] inputtt[i];
    }
    delete [] inputtt;
}

void Select::Setup() {

    // Get data for question from gamedata.txt
    f.open("./dataset/GameData.txt");    
    // offset = 12; // fix
    // num = 4; // fix
    int r1,r2,r3,r4;
    if(offset == 0) {
        r1 = RandomNumber(0, num-3);
        r2 = RandomNumber(r1+1, num-2);
        r3 = RandomNumber(r2+1, num-1);
        r4 = RandomNumber(r3+1, num);
    } else {
        r1 = RandomNumber(0, offset-1);
        r2 = RandomNumber(r1+1, offset);
        // r3 = RandomNumber(offset+1, offset+num - 1);
        r3 = RandomNumber(offset+1, num - 1);
        // r4 = RandomNumber(r3+1, offset+num);
        r4 = RandomNumber(r3+1, num);
    }

    int k = 0;
    inputtt = new string* [4];
    for(int i = 0; i <= r4; i++) {
        char temp[MAX];
        f.getline(temp, MAX);
        if(i == r1 || i == r2 || i == r3 || i == r4) {
            string input = temp;
            string* input_list = removeDupWord(input, 3);
            inputtt[k] = input_list;
            k++;
        }
    }
    f.close();
    
    return;
}

void Select::SetOffset(int offset, int num, int score) {
    this->offset = offset;
    this->num = num; 
    this->score = score;
    // cout << offset << " " << num << " ";
}

int Select::Show() {
    Setup();
    return 0;
}


#endif