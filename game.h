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
// using namespace std;
// fstream f;
class Game {
    protected:
        int Score;
        int NumOfQues;
        int Level;
        int best_score;
        int n;
        string* input;
        int index;
    public:
        Game();
        Game(int, int, int);
        Game(const Game &a);
        ~Game();

        int RandomNumber();
        string* removeDupWord(std::string, int);

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

Game::Game(int score, int num, int level) : Score(score), NumOfQues(num),n(5), Level(level) {}

Game::Game(const Game &a) : Score(a.Score), NumOfQues(a.NumOfQues),n(5), Level(a.Level) {}

Game::~Game() {}

void Game::GetIndex() {
    f.open("./dataset/index.txt");
    f >> index;
    f.close();
}

void Game::GetBest() {
    fstream f;
    f.open("./dataset/best_score.txt");
    f >> best_score;
    f.close();
}

void Game::GetData() {
    // get data and write that to GameData.txt
    input = new string[n];
    int k = 0;
    char temp[MAX];  

    // Đọc data cũ
    // f.open("./dataset/data.txt");
    // for(int i = 0; i < index; i++) {
    //     f.getline(temp, MAX); // ignore offset
    // }
    // for(int i = 0; i < n; i++) {
    //     f.getline(temp, MAX);
    //     input[k] = temp;
    //     k++;
    // }
    // f.close();  

    // Đọc data mới
    f.open("./dataset/input.txt");
    for(int i = 0; i < index; i++) {
        f.getline(temp, MAX); // ignore offset
        f.getline(temp, MAX);
    }
    for(int i = 0; i < n; i++) {
        f.getline(temp, MAX);
        input[k] = temp;
        f.getline(temp, MAX);
        input[k] += " ";
        input[k] += temp;
        string* inputt = removeDupWord(input[k], 4);
        input[k] = inputt[0] + '\t' + inputt[1] + '\t' + inputt[3];
        k++;
    }
    f.close(); 
    
    // Ghi data
    f.open("./dataset/GameData.txt", ios::app);
    for(int i = 0; i < n; i++) {
        f << input[i] << '\n';
    }
    f.close();

    index = index + n;
    SaveIndex();
}




void Game::SaveIndex() {
    f.open("./dataset/index.txt", ios::out);
    f << index;
    f.close();
}

void Game::SaveBest() {
    fstream f;
    f.open("./dataset/best_score.txt", ios::out);
    f << best_score;
    f.close();
}

void Game::SaveData() {
    SaveIndex();
    SaveBest();
} 





string* Game::removeDupWord(string str, int n) {
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

int Game::RandomNumber() { // Using C++11 random features
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0.0, 100.0);
    return dist(mt);
}





void Game::Start() {
    system("cls"); //manh
    GetIndex();
    GetBest();

    std::wcout << L"\t+------------------------------------+\n";
    std::wcout << L"\t|                                    |\n";
    std::wcout << L"\t|              Start                 |\n";
    std::wcout << L"\t|          1. Play                   |\n";
    std::wcout << L"\t|          2. Practice               |\n";
    std::wcout << L"\t|          3. Reset                  |\n";
    std::wcout << L"\t|          X. Exit                   |\n";
    std::wcout << L"\t|                                    |\n";
    std::wcout << L"\t+------------------------------------+\n";
    std::wcout << L"Write down here (just 1 character): ";
    std::wstring a;
    std::wcin >> a;
    if(a[0] == L'1') Run();
    else if(a[0] == L'2') Practice();
    else if(a[0] == L'3') ResetGameData();
    else return;
}

void Game::Practice() {
    if (index == 0) {
        wcout << L"Nothing to learn!" << endl;
    } else {
        wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
        int w = 18;
        f.open("./dataset/GameData.txt");

        char temp[MAX];
        std::wcout << std::setfill(L' ');
        std::wcout << L"\t|| " << std::setw(w) << L"Word" << std::setw(w) 
            << L"||" << std::setw(w) << L"Pronounce" << std::setw(w) 
            << L"||" << std::setw(w) << L"Mean" << std::setw(w) << L" ||" << endl;
        std::wcout << L"\t||" << setfill(L'=') << setw(6*w+1) << L"||" << endl;
        std::wcout << std::setfill(L' ');
        for(int i = 0; i < index; i++) {
            f.getline(temp, MAX);
            std::string* a = removeDupWord(temp, 3);
            std::wcout << L"\t|| " << std::left << setw(2*w-2) << converter.from_bytes(a[0]) 
                << L"|| " << std::setw(2*w-3) << converter.from_bytes(a[1]) 
                << L"|| " << std::setw(2*w-3) << converter.from_bytes(a[2]) << L"||" << endl;
        }
        std::wcout << L"\t||" << std::right << setfill(L'=') << setw(6*w+1) << L"||" << endl;
        std::wcout << std::setfill(L' ');
        f.close(); 
    }

    wstring c;
    wcout << L"Enter c to continue" << endl;
    wcin >> c;
    if(c[0] == L'c') Start();
}

void Game::ResetGameData() {
    // clear GameData.txt
    f.open("./dataset/GameData.txt", ios::out);
    f.close();
    
    f.open("./dataset/index.txt", ios::out);
    f << 0;
    f.close();

    std::wcout << L"Reset data successfully! " << endl;

    string a;
    getline(cin, a, '\n');
    cin.ignore(1000, '\n');
    Start();
}

// Game Play
void Game::Run() {
    system("cls"); //manh
    std::wcout << L"\t+------------------------------------+\n";
    std::wcout << L"\t|                                    |\n";
    std::wcout << L"\t|      Select number of question     |\n";
    std::wcout << L"\t|          1. 10 question            |\n";
    std::wcout << L"\t|          2. 15 question            |\n";
    std::wcout << L"\t|          3. 20 question            |\n";
    std::wcout << L"\t|          4. 30 question            |\n";
    std::wcout << L"\t|          X. Exit                   |\n";
    std::wcout << L"\t|                                    |\n";
    std::wcout << L"\t+------------------------------------+\n";
    std::wcout << L"Write down here (just 1 character): ";
    std::wstring a;
    std::wcin >> a;
    if (a == L"1") {
        this->NumOfQues = 10;
        n = 6;
    } 
    else if (a == L"2") {
        this->NumOfQues = 15;
        n = 10;
    } 
    else if (a == L"3") {
        this->NumOfQues = 20;
        n = 12;
    } 
    else if (a == L"4") {
        this->NumOfQues = 30;
        n = 15;
    }
    else return;

    Score = 0;

    GetData();

    for(int i = 0; i < NumOfQues; i) {
        Select* a;
        Find *b;

        wcout << L"Question " << ++i << L": ";
        b = new Find;
        b->SetOffset(index - n, index, Score);
        Score += b->Show();
        wcout << endl << endl;
        if(i >= NumOfQues) break;
        //===========
        a = new Select1;
        wcout << L"Question " << ++i << L": ";
        a->SetOffset(index - n, index, Score);
        Score += a->Show();
        wcout << endl << endl;
        if(i >= NumOfQues) break;
        //===========
        wcout << L"Question " << ++i << L": ";
        a = new Select2;
        a->SetOffset(index - n, index, Score);
        Score += a->Show(); 
        wcout << endl << endl;
        if(i >= NumOfQues) break;
        //===========
        wcout << L"Question " << ++i << L": ";
        a = new Select3;
        a->SetOffset(index - n, index, Score);
        Score += a->Show();
        wcout << endl << endl;
        if(i >= NumOfQues) break;
        //===========
        wcout << L"Question " << ++i << L": ";
        a = new Select4;
        a->SetOffset(index - n, index, Score);
        Score += a->Show(); 
        wcout << endl << endl;
        if(i >= NumOfQues) break;
    }

    // Assign & Save best_score
    if(Score > best_score) {
        wcout << L"Huray! You get new best score!" << endl;
        best_score = Score;
        SaveBest();
    }

    wstring c;
    wcout << L"Enter c to continue" << endl;
    wcin >> c;
    if(c[0] == L'c') Start();
}
#endif