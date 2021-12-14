#ifndef SELECT2_H
#define SELECT2_H
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

// Question: Vietnamese -> Answer: English
class Select2 : public Select
{ 
    int correctAnswer;
    void Setup();

public:
    Select2();
    Select2(int);
    Select2(const Select2 &);
    ~Select2();
    int Show();
};

Select2::Select2() {}

Select2::Select2(const Select2 &a) {}
Select2::Select2(int a)
{
    correctAnswer = a;
}

Select2::~Select2() {}

void Select2::Setup()
{
    Select::Setup();
    correctAnswer = RandomNumber(0, 4);
}

int Select2::Show()
{
    this->Setup();
    wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;

    wstring blank = L"\t";
    int w = 35;
    int wp = w - 1;

    wcout << setfill(L' ') << left << setw(w) << converter.from_bytes(inputtt[correctAnswer][3]) + L" is:.....?" << right << setw(10) << L"Score: " << score << endl;
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
    wcout << L"==>> Write down your answer: ";
    wcin >> answer;

    if (int(answer[0]) == 49 + correctAnswer || answer == converter.from_bytes(inputtt[correctAnswer][3]))
    {
        wcout << L"Hurray! Correct answer!" << endl;
        return 5;
    }
    else
    {
        wcout << L"Oh! Wrong answer!" << endl;
        wcout << L"Correct answer is: " << converter.from_bytes(inputtt[correctAnswer][0]) << endl;
        return 0;
    }
}

#endif //SELECT2_H