/*
ID: nvatuan2
TASK: palsquare
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

#define TASK "palsquare"

char digit[100] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string to_base(int num, int base) {
    string p;
    while (num > 0) {
        p += digit[num % base];
        num /= base;
    }
    reverse(p.begin(), p.end());
    return p;
}

int main() {
    #ifndef LOCAL
        freopen(TASK".in", "r", stdin);
        freopen(TASK".out", "w", stdout);
    #endif
    int b; cin >> b;
    for (int i=1; i<=300; i++) {
        string s = to_base(i*i, b);
        string rs = s; reverse(rs.begin(), rs.end());
        if (s == rs) {
            cout << to_base(i, b) << ' ' << s << endl;
        }
    }
}