#include <bits/stdc++.h>
using namespace std;

int n;
const int M = 1000000007;
vector<long long> dp;

int main() {
    cin >> n;
    dp = vector<long long> (n*2 + 9);
    dp[1] = 1;
    for(int i = 1; i <= 2*n; i++) {
        if( i & 1 ) {
            dp[i+1] = (dp[i+1] + dp[i]) % M;
            dp[i+2] = (dp[i+2] + dp[i]) % M;
            dp[i+3] = (dp[i+3] + dp[i]) % M;
        } else {
            dp[i+1] = (dp[i+1] + dp[i]) % M;
            dp[i+2] = (dp[i+2] + dp[i]) % M;
        }
    }
    cout << dp[n*2];
}