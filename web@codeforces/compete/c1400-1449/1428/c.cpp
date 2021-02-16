#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    stack<int> stacc;
    cin >> s;
    for (char c : s) {
        int cc = (c == 'A' ? 1 : 0);
        if (stacc.empty()) stacc.push(cc);
        else {
            if (cc == 0) stacc.pop();
            else stacc.push(cc);
        }
    }
    cout << stacc.size() << '\n';
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
    
}