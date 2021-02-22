#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000];
long long x;

int b[1000];

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    cin >> x;

    for (int ik=1; ik<=k; ik++) {
        long long target = x % ik;

        for (int i=0; i<n; i++) b[i] = (b[i] % ik);
        vector<vector<int>> dp (ik+1, vector<int> (n+1, 0));
        vector<vector<int>> trace (ik+1, vector<int> (n+1, 0));
        vector<vector<int>> cnt (ik+1, vector<int> (n+1, 0));
        trace[0][0] = -1;
        dp[0][0] = 1;
        cnt[0][0] = 0;

        for (int item=0; item<n; item++) {
            for (int w=ik; w>=1; w--){
                int prv_w = ((w - b[item] + k) % k);
                if (
                    dp[item][prv_w]
                    &&
                    cnt[item][prv_w] < k
                ) {
                    dp[item+1][w] = 1;
                    trace[item+1][w] = item;
                    cnt[item+1][w] = cnt[item][prv_w] + 1;
                }
            } 
        }

    }
}

int main() {
    solve();
}