// Courtesy to :
// https://github.com/truongcongthanh2000/TrainACM-ICPC-OLP/blob/master/2018%20ICPC%20North%20Central%20North%20America%20Regional%20Contest/B.cpp
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

const long long INF_LL = 1e17;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
const int Base = 30;
const double EPS = 1e-9;
const int BLOCK = 1000;
const int dx[6] = {0, 0, 1, -1, 1, -1};
const int dy[6] = {1, -1, 0, 0, 1, -1};

const int maxN = 5e3 + 10;

int a[maxN];
long long dp[maxN][maxN];

const int SIZE = 1e7;

long long res = -INF_LL;

void sol() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) dp[i][j] = -INF_LL;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        long long mx = -INF_LL;
        for (int j = i; j <= n; j++) {
            mx = max(mx, dp[i - 1][j - 1]);
            dp[i][j] = max(dp[i][j - 1], mx) + a[j];
        }
    }
    for (int i = k; i <= n; i++) res = max(res, dp[k][i]);
}


int main() {
    sol();
    vector<int> pushpop;
    pushpop.reserve(10);
    
    srand(time(NULL));
    // for (int epoch=0; epoch < (int)(2e8); epoch++) {
    //     if ((pushpop.size() == 0) || (rand() & 1) ) pushpop.push_back(123);
    //     if ((pushpop.size() > 7) || (rand() & 1 == 0)) pushpop.pop_back();
    // }
    if (pushpop[-1]) cout << res;
    else printf("%lld", res);
}