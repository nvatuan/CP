#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int TESTS = 10;
const string inputFile = "in";
const string juryOut = "jury";
const string contestantOut = "out";

string contestantProgram = "";

void gen() {
    ofstream f (inputFile, ios::out);

    int n = 100000;
    f << n << endl;
    for (int i = 0; i < n; i++) {
        int a = 0;
        int digit = 7; //rand() % 7;
        while (digit--) a = a * 10 + (rand() % 10);

        f << a;
        if (i + 1 < n) f << ' ';
        else f << endl;
    }
    f.close();
}

void solve() {
    ofstream f (juryOut, ios::out);
    ifstream fi (inputFile, ios::in);

    int n; fi >> n;
    vector<int> a(n);
    for (int& i : a) fi >> i;

    sort(a.begin(), a.end());

    for (int i : a) f << i << ' ';
    f << endl;
    f.close();
}

int check() {
    vector<string> token1, token2;
    ifstream fin;
    //
    fin.open(juryOut, ios::in);
    while (true) {
        string tok;
        if (fin >> tok) token1.push_back(tok);
        else break;
    }
    fin.close();
    //
    fin.open(contestantOut, ios::in);
    while (true) {
        string tok;
        if (fin >> tok) token2.push_back(tok);
        else break;
    }
    fin.close();
    return token1 == token2;
}

int main(int argc, char** argv) {
    if (argc == 1) return 0;
    else {
        contestantProgram = "";
        for (int i = 1; i < argc; i++) {
            contestantProgram += std::string(argv[i]);
            if (i + 1 < argc) contestantProgram += " ";
        }
    }
    srand(time(NULL));

    int correct = 0;
    for (int t = 0; t < TESTS; t++) {
        gen();
        solve();

        string command = "type " + inputFile + " | " +
            " " + contestantProgram + " > " + contestantOut;
        time_t timer = clock();
        system(command.c_str());
        time_t duration = (clock() - timer);

        if (check()) {
            correct++;
            cerr << "TEST#" << t << " correct.";
        } else {
            cerr << "WRONG ANSWER ON TEST#" << t;
        }
        cerr << " | runtime = " << duration*1.0/CLOCKS_PER_SEC << "s \n";
    }
    cerr << "Correct/Total=" << correct << '/' << TESTS << '\n';
}