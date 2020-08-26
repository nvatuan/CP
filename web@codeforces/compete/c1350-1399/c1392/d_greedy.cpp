#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void solve() {
    cin >> n; cin >> s;

    if ( std::count(s.begin(), s.end(), s[0]) == n ) {
        cout << (n + 2)/3 << '\n';
    } else {
        for (int i = 1; i < n; i++)
            if (s[i] != s[i-1]) {
                std::rotate(s.begin(), s.begin() + i, s.end());
                break;
            }

        int ans = 0;
        int continuousCount = 0;
        char currentChar = s[0];
        s += '$';
        for (const char& c : s) {
            if (currentChar != c) {
                ans += (continuousCount/3);
                currentChar = c;
                continuousCount = 0;
            }
            continuousCount++;
        }

        cout << ans << '\n';
    }
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}
