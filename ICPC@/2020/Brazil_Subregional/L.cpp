#include <bits/stdc++.h>
using namespace std;

int L, C, N;
char mat[50][50];
string word[50];

int matMatch[50][50];

map<string, map<char, int>> wordBag;
void prepWordBag() {
    for (int i=0; i<N; i++) {
        map<char, int> &MAP = wordBag[word[i]];
        for (char c : word[i]) MAP[c]++;
    }
}

string dirs[] = {"RIGHT", "DOWN", "MDIAG", "ADIAG"};

void expandTo(int x, int y, string direction) {
    int dx, dy;
    if (direction == "RIGHT") tie(dx, dy) = make_tuple(0, 1);
    if (direction == "DOWN") tie(dx, dy) = make_tuple(1, 0);
    if (direction == "MDIAG") tie(dx, dy) = make_tuple(1, 1);
    if (direction == "ADIAG") tie(dx, dy) = make_tuple(1, -1);
    //
    int cx = x, cy = y;
    map<char, int> bag;
    for (;;) {
        bag[mat[cx][cy]]++;
        //cout << "@@ board:==================\n";
        //for (auto p : bag) {
        //    cout << p.first << ' ' << p.second << '\n';
        //}
        for (int w=0; w<N; w++) {
            const map<char, int>& wMap = wordBag[word[w]];
            //cout << "wordBag:================\n";
            //for (auto p : wMap) {
            //    cout << p.first << ' ' << p.second << '\n';
            //}
            if (wMap == bag) {
                //cout << "HIT\n";
                for (int px=x,py=y;; px+=dx, py+=dy) {
                    matMatch[px][py] |= (1 << w);
                    if (px == cx && py == cy) break;
                }
            }
        }

        cx += dx; cy += dy;
        if (cx == L || cy == C || cx < 0 || cy < 0) break;
    }
}

int main() {
    cin >> L >> C;
    for (int i=0; i<L; i++)
        for (int j=0; j<C; j++)
            cin >> mat[i][j];
    cin >> N;
    for (int i=0; i<N; i++)
        cin >> word[i];
    prepWordBag();
    for (int i=0; i<N; i++) {
        map<char, int> &MAP = wordBag[word[i]];
        //cout << "DEBUG: " << word[i] << "----------\n";
        //for (auto p : MAP) {
        //    cout << p.first << ' ' << p.second << '\n';
        //}
    }
    //
    for (int i=0; i<L; i++) {
        for (int j=0; j<C; j++) {
            for (int ds=0; ds<4; ds++)
                expandTo(i, j, dirs[ds]);
        }
    }
    int ans = 0;
    for (int i=0; i<L; i++) {
        for (int j=0; j<C; j++) {
            ans += (__builtin_popcount(matMatch[i][j]) > 1);
        }
    }
    //for (int i=0; i<L; i++) {
    //    for (int j=0; j<C; j++) cout << matMatch[i][j] << ' ';
    //    cout << endl;
    //}
    cout << ans << endl;
}