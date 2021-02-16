#include <bits/stdc++.h>
using namespace std;

string s;
int n;

const int N = int(2e5) + 10;
int table[26][N];

string exists(string x) {
    int idx = 0;
    string res = "";
    for (int i=0; i<(int)x.length(); i++) {
        int ic = (int)(x[i] - 'a');
        idx = table[ic][idx];

        if (idx != -1) res += x[i];
        else {
            if (res == "") return string("IMPOSSIBLE");
            else return res;
        }

        idx++;
    }
    return res;
}

void solve() {
    cin >> s;

    for (int i=0; i<26; i++) {
        char c = (char)('a' + i);
        fill(table[i], table[i] + N, -1);
        int idx = 0, next_idx = s.find(c);
        while (next_idx != string::npos) {
            while (idx <= next_idx) table[i][idx++] = next_idx;
            next_idx = s.find(c, idx);
        }
    }
    //for (int i=0; i<26; i++) {
    //    for (int j=0; j<s.length(); j++) {
    //        cout << table[i][j] << ' ';
    //    }
    //    cout << '\n';
    //}

    cin >> n;
    while (n--) {
        string q;
        cin >> q;
        cout << exists(q) << '\n';
    }

}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
}