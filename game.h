#ifndef GAME_H
#define GAME_H
#include <string>
#include <iostream>
#include <fstream>
#include <random>
#include "select.h"
#include "select1.h"
#include "select2.h"
#include "select3.h"
#include "select4.h"
#include "find.h"
using namespace std;

class Game
{
protected:
    int Score;
    int NumOfQues;
    int Level;
    int best_score;
    int n;
    string *input;
    int index;

public:
    Game();
    Game(int, int, int);
    Game(const Game &a);
    ~Game();

    int RandomNumber();
    string *removeDupWord(std::string, int);

    void GetBest();
    void GetIndex();
    void GetData();

    void SaveBest();
    void SaveIndex();
    void SaveData();

    void Start();
    void Run();
    void Practice();
    void ResetGameData();
};

Game::Game() : Score(0), NumOfQues(5), n(5), Level(1) {}

Game::Game(int score, int num, int level) : Score(score), NumOfQues(num), n(5), Level(level) {}

Game::Game(const Game &a) : Score(a.Score), NumOfQues(a.NumOfQues), n(5), Level(a.Level) {}

Game::~Game() {}

void Game::GetIndex()
{
    f.open("./data/index.txt");
    f >> index;
    f.close();
}

void Game::GetBest()
{
    fstream f;
    f.open("./data/best_score.txt");
    f >> best_score;
    f.close();
}

// get data and write into GameData.txt
void Game::GetData()
{

    input = new string[n];
    int k = 0;
    char temp[MAX];

    f.open("./data/input.txt");
    for (int i = 0; i < index; i++)
    {
        f.getline(temp, MAX); // ignore offset
        f.getline(temp, MAX);
    }
    for (int i = 0; i < n; i++)
    {
        f.getline(temp, MAX);
        input[k] = temp;
        f.getline(temp, MAX);
        input[k] += " ";
        input[k] += temp;
        string *inputt = removeDupWord(input[k], 4);
        k++;
    }
    f.close();

    // Ghi data
    f.open("./data/GameData.txt", ios::app);
    for (int i = 0; i < n; i++)
    {
        f << input[i] << '\n';
    }
    f.close();

    index = index + n;
    SaveIndex();
}

void Game::SaveIndex()
{
    f.open("./data/index.txt", ios::out);
    f << index;
    f.close();
}

void Game::SaveBest()
{
    fstream f;
    f.open("./data/best_score.txt", ios::out);
    f << best_score;
    f.close();
}

void Game::SaveData()
{
    SaveIndex();
    SaveBest();
}

string *Game::removeDupWord(string str, int n)
{
    string word = "";
    string *res = new string[n];
    int i = 0;
    for (auto x : str)
    {
        if ((x == '\t' || x == ' ') && i < n - 1)
        {
            res[i] = word;
            i++;
            word = "";
        }
        else
        {
            word = word + x;
        }
    }
    res[i] = word;
    return res;
}

// Using C++11 random features
int Game::RandomNumber()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0.0, 100.0);
    return dist(mt);
}

void Game::Start()
{
    GetIndex();
    GetBest();
    system("cls");
    wcout << L"\t+---------------------------------+\n";
    wcout << L"\t|         PRACTICING GAME         |\n";
    wcout << L"\t+---------------------------------+\n";
    wcout << L"\t|                                 |\n";
    wcout << L"\t|           1. Play               |\n";
    wcout << L"\t|           2. Practice           |\n";
    wcout << L"\t|           3. Reset              |\n";
    wcout << L"\t|           X. Exit               |\n";
    wcout << L"\t|                                 |\n";
    wcout << L"\t+---------------------------------+\n";
    wcout << L"==>> Select one function: ";
    wstring a;
    wcin >> a;
    if (a[0] == L'1')
        Run();
    else if (a[0] == L'2')
        Practice();
    else if (a[0] == L'3')
        ResetGameData();
    else
        return;
}

void Game::Practice()
{
    if (index == 0)
    {
        system("cls");
        wcout << L"Opps! You haven't learnt nothing! Praticing at game first!" << endl;
    }
    else
    {
        wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
        int w = 18;
        f.open("./data/GameData.txt");
        system("cls");
        wcout << L"\nWoahh! You have already learnt " << index << " word!\n"
              << endl;
        char temp[MAX];
        wcout << setfill(L' ');
        wcout << L"\t|| " << setw(w) << L"Word" << setw(w)
              << L"||" << setw(w) << L"Pronounce" << setw(w)
              << L"||" << setw(w / 2) << L"Type" << setw(w / 2)
              << L"||" << setw(w) << L"Mean" << setw(w) << L" ||" << endl;
        wcout << L"\t||" << setfill(L'=') << setw(7 * w + 1) << L"||" << endl;
        wcout << setfill(L' ');
        for (int i = 0; i < index; i++)
        {
            f.getline(temp, MAX);
            string *a = removeDupWord(temp, 4);
            wcout << L"\t|| " << left << setw(2 * w - 2) << converter.from_bytes(a[0])
                  << L"|| " << setw(2 * w - 3) << converter.from_bytes(a[1])
                  << L"|| " << setw(w - 3) << converter.from_bytes(a[2])
                  << L"|| " << setw(2 * w - 3) << converter.from_bytes(a[3]) << L"||" << endl;
        }
        wcout << L"\t||" << right << setfill(L'=') << setw(7 * w + 1) << L"||" << endl;
        wcout << setfill(L' ');
        f.close();
    }

    wstring c;
    wcout << L"Enter c to continue!" << endl;
    wcout << L"==>> ";
    wcin >> c;
    if (c[0] == L'c')
        Start();
}

void Game::ResetGameData()
{
    // clear GameData.txt
    f.open("./data/GameData.txt", ios::out);
    f.close();

    f.open("./data/index.txt", ios::out);
    f << 0;
    f.close();

    f.open("./data/overlap.txt", ios::out);
    f << 0;
    f.close();

    f.open("./data/best_score.txt", ios::out);
    f << 0;
    f.close();

    wcout << L"Reset data successfully! " << endl;
    system("pause");
    string a;
    getline(cin, a, '\n');
    cin.ignore(1000, '\n');
    Start();
}

// Game Play
void Game::Run()
{
    system("cls");
    wcout << L"\t+----------------------------------+\n";
    wcout << L"\t|       Select question pack       |\n";
    wcout << L"\t+----------------------------------+\n";
    wcout << L"\t|                                  |\n";
    wcout << L"\t|          1. 10 question          |\n";
    wcout << L"\t|          2. 15 question          |\n";
    wcout << L"\t|          3. 20 question          |\n";
    wcout << L"\t|          4. 30 question          |\n";
    wcout << L"\t|          X. Exit                 |\n";
    wcout << L"\t|                                  |\n";
    wcout << L"\t+----------------------------------+\n";
    wcout << L"==>> Select one pack: ";
    wstring a;
    wcin >> a;
    if (a == L"1")
    {
        this->NumOfQues = 10;
        n = 6;
    }
    else if (a == L"2")
    {
        this->NumOfQues = 15;
        n = 10;
    }
    else if (a == L"3")
    {
        this->NumOfQues = 20;
        n = 12;
    }
    else if (a == L"4")
    {
        this->NumOfQues = 30;
        n = 15;
    }
    else
        return;

    Score = 0;

    GetData();
    system("cls");
    wcout << L"You have selected " << NumOfQues << " questions pack. Let's started!\n"
          << endl;
    for (int i = 0; i < NumOfQues; i)
    {
        Select *a;
        Find *b;

        wcout << L"Question " << ++i << L": ";
        b = new Find;
        b->SetOffset(index - n, index, Score);
        Score += b->Show();
        wcout << endl
              << endl;
        if (i >= NumOfQues)
            break;
        //===========
        a = new Select1;
        wcout << L"Question " << ++i << L": ";
        a->SetOffset(index - n, index, Score);
        Score += a->Show();
        wcout << endl
              << endl;
        if (i >= NumOfQues)
            break;
        //===========
        wcout << L"Question " << ++i << L": ";
        a = new Select2;
        a->SetOffset(index - n, index, Score);
        Score += a->Show();
        wcout << endl
              << endl;
        if (i >= NumOfQues)
            break;
        //===========
        wcout << L"Question " << ++i << L": ";
        a = new Select3;
        a->SetOffset(index - n, index, Score);
        Score += a->Show();
        wcout << endl
              << endl;
        if (i >= NumOfQues)
            break;
        //===========
        wcout << L"Question " << ++i << L": ";
        a = new Select4;
        a->SetOffset(index - n, index, Score);
        Score += a->Show();
        wcout << endl
              << endl;
        if (i >= NumOfQues)
            break;
    }

    // Assign & Save best_score
    if (Score > best_score)
    {
        wcout << L"Hurray! You make new best score!" << endl;
        wcout << L"Your total score: " << Score << endl;
        wcout << L"Best score: " << best_score << endl;
        wcout << L"\nLet's break the record again!!!" << endl;
        best_score = Score;
        SaveBest();
    }
    else
    {
        wcout << L"Your total score: " << Score << endl;
        wcout << L"Best score: " << best_score << endl;
        wcout << L"Don't worry! Let's try again!!!" << endl;
    }

    wstring c;
    wcout << L"\nEnter c to continue!" << endl;
    wcout << L"==>> ";
    wcin >> c;
    if (c[0] == L'c')
        Start();
}
#endif //GAME_H