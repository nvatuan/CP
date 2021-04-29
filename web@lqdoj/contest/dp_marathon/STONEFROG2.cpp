#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h (n);
    for (int &i : h) cin >> i;


    vector<int> dp (n, INT_MAX);
    dp[0] = 0;
    for (int i=0; i<n; i++) {
        for (int j=max(0, i-k); j<i; j++)
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
    }
    printf("%d\n", dp[n-1]);
}