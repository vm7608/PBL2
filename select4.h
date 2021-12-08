#ifndef SELECT4_H
#define SELECT4_H
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

class Select4 : public Select { // Question: English -> Answer: Vietnamese
    int trueans;
    void Setup();
    public:
        Select4();
        Select4(int);
        Select4(const Select4&);
        ~Select4();
        int Show();
};

Select4::Select4() {}

Select4::Select4(const Select4& a) {}
Select4::Select4(int a) {
    trueans = a;
}

Select4::~Select4() {}

void Select4::Setup() {
    Select::Setup();
    trueans = RandomNumber(0, 4);
}

int Select4::Show() {
    this->Setup();
    wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;

    wstring blank = L"\t";
    int w = 35;
    int wp = w - 1;
    // cout << inputtt[trueans][1] << " is:.....?" << endl;
    wcout << setfill(L' ') << left << setw(w) << converter.from_bytes(inputtt[trueans][1]) + L" is:.....?" << right << setw(10) << L"Score: " << score << endl; 
    wcout << setfill(L'=') << L" /" << setw(w) << L"\\" << blank << L" /" << setw(w) << L"\\" << endl;
    wcout << L"||" << setfill(L' ') << left << setw(wp) << L"   1. " + converter.from_bytes(inputtt[0][0]) << L"||" << blank;
    wcout << L"||" << setfill(L' ') << left << setw(wp) << L"   2. " + converter.from_bytes(inputtt[1][0]) << L"||" << endl;
    wcout << right << setfill(L'=') << L" \\" << setw(w) << L"/" << blank << L" \\" << setw(w) << L"/" << endl;
    wcout << endl;
    wcout << right << setfill(L'=') << L" /" << setw(w) << L"\\" << blank << L" /" << setw(w) << L"\\" << endl;
    wcout << L"||" << setfill(L' ') << left << setw(wp) << L"   3. " + converter.from_bytes(inputtt[2][0]) << L"||" << blank;
    wcout << L"||" << setfill(L' ') << left << setw(wp) << L"   4. " + converter.from_bytes(inputtt[3][0]) << L"||" << endl;
    wcout << right << setfill(L'=') << L" \\" << setw(w) << L"/" << blank << L" \\" << setw(w) << L"/" << endl;
    wstring answer;
    wcout << L"-> Write down your answer: ";
    wcin >> answer;

    if(int(answer[0]) == 49 + trueans || answer == converter.from_bytes(inputtt[trueans][2])) {
        wcout << L"Correct!" << endl;
        return 5;
    } else {
        wcout << L"Oh! Wrong answer!" << endl;
        wcout << L"Correct Answer : " << converter.from_bytes(inputtt[trueans][0]) << endl;
        return 0;
    }
}

#endif