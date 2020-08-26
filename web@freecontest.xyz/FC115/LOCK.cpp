#include <bits/stdc++.h>
using namespace std;

const int __debug_mode = 1;
const int __multitest = 0;
#define db if(__debug_mode)

template<typename T>
T In() { T x; cin >> x; return x; }

// -- template ends here
void solve() {
    int N; cin >> N;
    string S; cin >> S;
    for (int i = 0; i < N-1; i++)
        if (S[i] == S[i+1]) {
            cout << "0\n"; return;
        }
    set<char> s;
    for (char c : S) s.insert(c);
    if (s.size() < 5) {
        cout << "0\n"; return;
    } else {
        cout << "1\n"; return;
    }
}

int main() {
    for (int t = (__multitest ? In<int>() : 1); t; t--) solve();
}

