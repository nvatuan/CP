#include <bits/stdc++.h>
using namespace std;

const int SIZE = 3000;

int n;
double dp[SIZE][SIZE + 1];

int main() {
    // dp[n][i] - probability of tossing n coins and having i HEADS
    dp[0][0] = 1.0; // base
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        double p; cin >> p;
        for (int h = 0; h <= i; h++) {
            dp[i][h+1] += dp[i-1][h] * p;
            dp[i][h] += dp[i-1][h] * (1 - p);
        }
    }

    double ans = 0.0;
    for (int heads = n; heads > n - heads; heads--) {
        ans += dp[n][heads];
    }
    printf("%.10lf\n", ans);
}