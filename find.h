#include "question.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <iomanip>
#include <io.h>
#include <fcntl.h>
#include <locale>
#include <codecvt>

using namespace std;
#define MAX 512
#ifndef FIND_H
#define FIND_H
class Find : public Question {
    protected:
        string inp; // Hello
        int trueans; // e
        string ques; // H_llo
        string mean;
        int score;
        int offset;
        int num;
        void Setup();
        string* removeDupWord(string str, int n);
        int RandomNumber(double, double);
        string upper(string);
    public:
        Find();
        Find(const Find&);
        ~Find();
        int Show();
        void SetOffset(int, int, int);
};

Find::Find() {}

Find::Find(const Find& a) {}

Find::~Find() {
}

int Find::RandomNumber(double a, double b) { // Using C++11 random features
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(a, b);
    return dist(mt);
}


// Split str to n components
string* Find::removeDupWord(string str, int n) {
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

string Find::upper(string a) {
    string temp = a;
    for(int i = 0; i < a.length(); i++) {
        if(a[i] >= 97 && a[i] <=122) {
            temp[i] = char(a[i] - 32);
        }
    }
    return temp;
}

void Find::Setup() {
    // Get data for question from gamedata.txt
    f.open("./dataset/GameData.txt");    
    // offset = 12; // fix
    // num = 4; // fix
    int r1 = RandomNumber(offset, num);

    char temp[MAX];
    for(int i = 0; i < r1; i++) {
        f.getline(temp, MAX);
    }
    f.getline(temp, MAX);
    string input = temp;
    string* input_list = removeDupWord(input, 3);
    inp = input_list[0];
    mean = input_list[2];
    int k = inp.length();
    int r2 = RandomNumber(0, k);
    ques = inp;
    ques = upper(ques);
    trueans = ques[r2];
    ques.replace(r2,1,"_");
    f.close();
    return;
}

void Find::SetOffset(int offset, int num, int score) {
    this->offset = offset;
    this->num = num; 
    this->score = score;
}

int Find::Show() {
    this->Setup();
    
    wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
    wchar_t answer;


    wstring blank = L"\t";
    int w = 36;
    int wp = w - 1;
    wcout << endl;
    wcout << blank << L"==" << right << setfill(L'=') << setw(w) << L"==" << setfill(L' ') << left << L"    " << L"Score: " << score << endl;
    wcout << right << blank << L"||" << setfill(L' ') << setw(w/2+2) << converter.from_bytes(ques) << setw(w/2-2) << L"||" << endl;
    wcout << blank << L"==" << right << setfill(L'=') << setw(w) << L"==" << endl;
    wcout << L"Write your answer: " ;
    wcin >> answer;
    if (answer == char(trueans) || answer == char(trueans + 32)) {
        wcout << L"Correct!" << endl;
        wcout << L"Mean: " << converter.from_bytes(mean) << endl;
        return 5;
    } else {
        wcout << L"Oh! Wrong answer!" << endl;
        wcout << L"Correct Answer : " << converter.from_bytes(inp) << endl;
        wcout << L"Mean: " << converter.from_bytes(mean) << endl;
        return 0;
    }
}

#endif