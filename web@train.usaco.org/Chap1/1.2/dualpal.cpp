/*
ID: nvatuan2
TASK: dualpal 
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

#define TASK "dualpal"

char digit[100] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string to_base(int num, int base) {
    string p;
    while (num > 0) {
        p += digit[num % base];
        num /= base;
    }
    // reverse(p.begin(), p.end());
    return p;
}

int is_dualpal(int n) {
    int pal_cnt = 0;
    for (int b=2; b<=10; b++) {
        string s = to_base(n, b);
        string p = s;
        reverse(p.begin(), p.end());

        pal_cnt += (p == s);
        if (pal_cnt == 2) return true;
    }
    return false;
}

int main() {
    #ifndef LOCAL
        freopen(TASK".in", "r", stdin);
        freopen(TASK".out", "w", stdout);
    #endif
    int n, s;
    cin >> n >> s;
    while (n) {
        s++;
        if (is_dualpal(s)) {
            cout << s << endl;
            n--;
        }
    }
}