#include <bits/stdc++.h>
using namespace std;

int u, v;

void solve() {
    cin >> u >> v;

    string su="", sv="";
    for (int b=29; b>=0; b--) {
        if ((u >> b) & 1) su += "1";
        else su += "0";
        if ((v >> b) & 1) sv += "1";
        else sv += "0";
    }

    //cerr << su << '\n' << sv << endl;

    int poss = 1;
    int ptr2=0;
    int joinable = 0;
    assert (su.length() == 30);
    for (int i=0; i<30; i++) {
        if (!poss) break;
        if (sv[i] == '1') {
            if (ptr2 == 30) {
                poss = 0;
                break;
            }
            while (ptr2 < 30) {
                if (su[ptr2]=='1') {
                    if (ptr2 == i) {
                        ptr2++;
                        break;
                    }
                    if (ptr2 < i) {
                        if (joinable) {
                            ptr2 = i-1;
                        } else {
                            poss = 0;
                        }
                    }
                    if (ptr2 > i) {
                        ptr2++;
                        joinable = 1;
                        break;
                    }
                }
                ptr2++;
                if (ptr2 == 30) {
                    poss = 0;
                    break;
                }
            }
        }
    }

    int one_left = 0;
    while (ptr2 < 30) one_left |= (su[ptr2++] == '1');

    if (one_left)
        if (joinable);
        else poss = 0;

    if (poss) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}