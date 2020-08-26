#include <bits/stdc++.h>
using namespace std;

int dp[303][303];

void solve() {
    string s;
	//int n;
	//cin >> n;
    cin >> s;
    int n = s.length();
    s = "?" + s;
    //
    for(int i = 0; i < 303; i++)
        for(int j = 0; j < 303; j++)
            dp[i][j] = 0;
    //
    for(int length = 1; length <= n; length++) {
        for(int i = 1, j = length; j <= n; i++, j++) {
            if(length == 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 1 + dp[i+1][j];
                if (s[i] == s[i + 1]) {
                    dp[i][j] = min(1 + dp[i + 2][j], dp[i][j]);
                }
                for(int k = i+2; k <= j; k++)
                    if(s[i] == s[k]) 
                        dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k+1][j]);
            }
        }
    }
    //
    cout << dp[1][n] << endl;
}

int main() {
    int t;
    for(cin >> t; t; t--) solve();
}