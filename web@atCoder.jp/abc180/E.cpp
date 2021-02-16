#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n;
int path[N][N];

int p[N][3];
const int INF = (int)1e9;
int calculate_cost(int i1, int i2) {
    return abs(p[i2][0] - p[i1][0]) + abs(p[i2][1] - p[i1][1]) + max(0, p[i2][2] - p[i1][2]);
}

int LAST = N-1;

int main() {
    cin >> n;

    for (int j : {0, 1, 2}) cin >> p[LAST][j];

    n--;
    for (int i=0; i<n; i++) {
        for (int j : {0, 1, 2}) cin >> p[i][j];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j) path[i][j] = INF;
            else {
                path[i][j] = min(calculate_cost(i, j), calculate_cost(i, LAST) + calculate_cost(LAST, j));
            }
        }
    }

    vector<vector<int>> dp (n, vector<int> (1 << n, INF));
    for (int toCity = 0; toCity < n; toCity++) {
        dp[toCity][(1 << toCity)] = calculate_cost(LAST, toCity);
        
    }

    for (int subset = 1; subset < (1 << n); subset++) {
        for (int fromCity=0; fromCity < n; fromCity++)
            if (subset & (1 << fromCity)) {
                for (int toCity=0; toCity < n; toCity++)
                    if ((subset & (1 << toCity)) == 0) {
                        int newMask = subset | (1 << toCity);
                        int newCost = dp[fromCity][subset] + path[fromCity][toCity];

                        if (dp[toCity][newMask] > newCost) {
                            dp[toCity][newMask] = newCost;
                        }
                    }
            }
    }

    int LAST_MASK = (1 << n) - 1;
    
    int ans = INF;
    for (int lastCity = 0; lastCity < n; lastCity++) {
        ans = min(ans, dp[lastCity][LAST_MASK] + calculate_cost(lastCity, LAST));
    }
    cout << ans << '\n';
}