#include <bits/stdc++.h>
using namespace std;

string S;

const int MOD = 11092019;
typedef long long llong;

int main() {
    cin >> S;
    unordered_map<char, int> cnt;
    int n = (int)(S.length());
    for (char c : S) cnt[c]++;

    llong ans = 1;
    for (char c='a'; c<='z'; c++) {
        ans = (ans * (cnt[c]+1)) % MOD;
    }
    cout << ans << endl;
}