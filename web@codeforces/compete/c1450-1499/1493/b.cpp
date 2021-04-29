#include <bits/stdc++.h>
using namespace std;

int valid_reflc[] {
   0,1,5,-1,-1,2,-1,-1,8,-1
};
map<char, char> refl {
    {'0', '0'}, {'1', '1'}, {'2', '5'}, {'3', 'x'}, {'4', 'x'},
    {'5', '2'}, {'6', 'x'}, {'7', 'x'}, {'8', '8'}, {'9', 'x'}
};
// 0 1 2 3 4 5 6 7 8 9

int H, M;
string s;

string conv(int time) {
    int h = time / M;
    int m = time % M;
    string form = "";

    form += (char)(h/10 + '0');
    form += (char)(h%10 + '0');
    form += ':';
    form += (char)(m/10 + '0');
    form += (char)(m%10 + '0');
    //cerr << h << ' '<< m << ' ' << form << endl;
    return form;
}

int toi(char c) {
    return (int)(c - '0');
}

int fullday;
int check(string s) {
    string rlf = "";
    for (char c : s) {
        if (refl[c] == 'x') return 0;
        rlf += refl[c];
    }
    reverse(rlf.begin(), rlf.end());
    int h = (toi(rlf[0])*10+toi(rlf[1]));
    int m = (toi(rlf[3])*10+toi(rlf[4]));
    if (h >= H) return 0;
    if (m >= M) return 0;
    int tm = h * M + m;
    if (tm > fullday) return 0;
    return 1;
}

void solve() {
    cin >> H >> M;
    cin >> s;
    fullday = H*M - 1;

    int current = (toi(s[0])*10+toi(s[1])) * M + (toi(s[3])*10+toi(s[4]));
    int ptr2=current;
    while (true) {
        if (check(conv(ptr2))) {
            cout << conv(ptr2) << endl;
            return;
        }
        ptr2++; if (ptr2 > fullday) ptr2 = 0;
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}