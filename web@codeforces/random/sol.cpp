/*
https://codeforces.com/contest/1492/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
string s, sr, t;

vector<vector<int>> jmp (26), jmpr (26);

int toi(char c) {
    return c-'a';
}

void make_table(vector<vector<int>> &tb, string& s) {
    for (int i=0; i<26; i++) tb[i].assign(s.length(), -1);

    for (char c='a'; c<='z'; c++) {
        int idx = -1;
        for (int i=(int)(s.length())-1; i>=0; i--) {
            if (s[i] == c) idx=i;
            tb[toi(c)][i] = idx;
        }
    }
}

int main() {
    cin >> n >> m;
    cin >> s >> t;
    sr = s;
    reverse(sr.begin(), sr.end());

    make_table(jmp, s);
    make_table(jmpr, sr);


    vector<int> prefix1 (m, 0), prefix2(m, 0);
    int idx=-1;
    for (int i=0; i<m; i++) {
        idx = jmp[ toi(t[i]) ][idx+1];
        prefix1[i] = idx;
    }
    idx=-1;
    for (int i=0; i<m; i++) {
        idx = jmpr[ toi(t[m-i-1]) ][idx+1];
        prefix2[i] = idx;
    }

    int ans = 0;
    for (int i=0; i+1<m; i++){
        ans = max(ans,
            n-1 - prefix2[m-i-2] - prefix1[i]
        );
    }
    cout << ans << endl;
}