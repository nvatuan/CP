#include <bits/stdc++.h>
using namespace std;

int n;
int a[int(1e6) + 10];
const int MOD = (int)(1e9) + 7;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    
    long long ans = 0;
    map<int, long long> dp;
    for (int i=0; i<n; i++) {
        if (a[i] == 1) {
            dp[1]++;
        } else {
            dp[a[i]] = (dp[a[i]] + dp[a[i] - 1]) % MOD;
        }
    }
    
    for (auto p : dp) {
        ans += p.second;
        ans %= MOD;
    }
    cout << ans << '\n';
}