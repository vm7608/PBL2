#ifndef SELECT3_H
#define SELECT3_H
#include "select.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <iomanip>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <locale>
#include <codecvt>
#define MAX 512
using namespace std;

class Select3 : public Select { // Question: English -> Answer: Vietnamese
    int trueans;
    void Setup();
    public:
        Select3();
        Select3(int);
        Select3(const Select3&);
        ~Select3();
        int Show();
};

Select3::Select3() {}

Select3::Select3(const Select3& a) {}
Select3::Select3(int a) {
    trueans = a;
}

Select3::~Select3() {}

void Select3::Setup() {
    Select::Setup();
    trueans = RandomNumber(0, 4);
}

int Select3::Show() {
    this->Setup();
    wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;

    wstring blank = L"\t";
    int w = 35;
    int wp = w - 1;
    // cout << inputtt[trueans][0] << " pronounce:.....?" << endl;
    wcout << setfill(L' ') << left << setw(w) << converter.from_bytes(inputtt[trueans][0]) + L" pronounce:.....?" << right << setw(10) << L"Score: " << score << endl; 
    wcout << setfill(L'=') << L" /" << setw(w) << L"\\" << blank << L" /" << setw(w) << L"\\" << endl;
    wcout << L"||" << setfill(L' ') << left << setw(wp) << L"   1. " + converter.from_bytes(inputtt[0][1]) << L"||" << blank;
    wcout << L"||" << setfill(L' ') << left << setw(wp) << L"   2. " + converter.from_bytes(inputtt[1][1]) << L"||" << endl;
    wcout << right << setfill(L'=') << L" \\" << setw(w) << L"/" << blank << L" \\" << setw(w) << L"/" << endl;
    wcout << endl;
    wcout << right << setfill(L'=') << L" /" << setw(w) << L"\\" << blank << L" /" << setw(w) << L"\\" << endl;
    wcout << L"||" << setfill(L' ') << left << setw(wp) << L"   3. " + converter.from_bytes(inputtt[2][1]) << L"||" << blank;
    wcout << L"||" << setfill(L' ') << left << setw(wp) << L"   4. " + converter.from_bytes(inputtt[3][1]) << L"||" << endl;
    wcout << right << setfill(L'=') << L" \\" << setw(w) << L"/" << blank << L" \\" << setw(w) << L"/" << endl;
    wstring answer;
    wcout << L"-> Write down your answer: ";
    wcin >> answer;

    if(int(answer[0]) == 49 + trueans || answer == converter.from_bytes(inputtt[trueans][2])) {
        wcout << L"Correct!" << endl;
        return 5;
    } else {
        wcout << L"Oh! Wrong answer!" << endl;
        wcout << L"Correct Answer : " << converter.from_bytes(inputtt[trueans][1]) << endl;
        return 0;
    }
}

#endif