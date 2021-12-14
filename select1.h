#ifndef SELECT1_H
#define SELECT1_H
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

// Question: English -> Answer: Vietnamese
class Select1 : public Select
{
    int correctAnswer;
    void Setup();

public:
    Select1();
    Select1(int);
    Select1(const Select1 &);
    ~Select1();
    int Show();
};

Select1::Select1() {}

Select1::Select1(const Select1 &a) {}

Select1::Select1(int a)
{
    correctAnswer = a;
}

Select1::~Select1() {}

void Select1::Setup()
{
    Select::Setup();
    correctAnswer = RandomNumber(0, 4);
}

// Question: Tieng Anh, Answer: Tieng Viet
int Select1::Show()
{
    this->Setup();
    wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;

    wstring blank = L"\t";
    int w = 35;
    int wp = w - 1;

    string ques = inputtt[correctAnswer][0];
    string ans0 = inputtt[0][3];
    string ans1 = inputtt[1][3];
    string ans2 = inputtt[2][3];
    string ans3 = inputtt[3][3];

    wstring q = converter.from_bytes(ques);
    wstring a0 = converter.from_bytes(ans0);
    wstring a1 = converter.from_bytes(ans1);
    wstring a2 = converter.from_bytes(ans2);
    wstring a3 = converter.from_bytes(ans3);

    wcout << setfill(L' ') << left << setw(w) << q + L" mean:.....?" << right << setw(10) << L"Score: " << score << endl;
    wcout << setfill(L'=') << L" /" << setw(w) << L"\\" << blank << " /" << setw(w) << L"\\" << endl;
    wcout << L"||" << setfill(L' ') << left << setw(wp) << L"   1. " + a0 << L"||" << blank;
    wcout << L"||" << setfill(L' ') << left << setw(wp) << L"   2. " + a1 << L"||" << endl;
    wcout << right << setfill(L'=') << L" \\" << setw(w) << L"/" << blank << L" \\" << setw(w) << L"/" << endl;
    wcout << endl;
    wcout << right << setfill(L'=') << L" /" << setw(w) << L"\\" << blank << L" /" << setw(w) << L"\\" << endl;
    wcout << L"||" << setfill(L' ') << left << setw(wp) << L"   3. " + a2 << L"||" << blank;
    wcout << L"||" << setfill(L' ') << left << setw(wp) << L"   4. " + a3 << L"||" << endl;
    wcout << right << setfill(L'=') << L" \\" << setw(w) << L"/" << blank << L" \\" << setw(w) << L"/" << endl;
    wstring answer;
    wcout << L"==>> Your answer: ";
    wcin >> answer;

    if (int(answer[0]) == 49 + correctAnswer || answer == converter.from_bytes(inputtt[correctAnswer][2]))
    {
        wcout << L"Hurray! Correct answer!" << endl;
        return 5;
    }
    else
    {
        wcout << L"Oh! Wrong answer!" << endl;
        wcout << L"Correct answer is: " << converter.from_bytes(inputtt[correctAnswer][2]) << endl;
        return 0;
    }
}

#endif //SELECT1_H