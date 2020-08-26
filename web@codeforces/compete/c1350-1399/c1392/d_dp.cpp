#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int a[200001];
int dp[2][2][2][2][200005];

const int INF = (int) 1e9;

int good(int i1, int i2, int i3) {
    return (i1 != i2 or i2 != i3);
}

int cost(int first, int second, int i1, int i2) {
    int ans = 0;
    ans += (a[i1] != first);
    ans += (a[i2] != second);
    return ans;
}

int go(int twoBack, int oneBack, int first, int second, int position) {
    if (dp[twoBack][oneBack][first][second][position] != -1) 
        return dp[twoBack][oneBack][first][second][position];
    
    if (position == n) {
        if (good(oneBack, first, second) and good(twoBack, oneBack, first)) return 0;
        return INF;
    } else {
        int best = INF;
        for (int flip = 0; flip <= 1; flip++) {
            if (good(twoBack, oneBack, a[position]^flip)) {
                best = min(best, 
                    go(oneBack, a[position]^flip, first, second, position+1) + flip
                );
            }
        }
        dp[twoBack][oneBack][first][second][position] = best;
        return best;
    }
    assert("None return statement in a non-void return value function" == "!");
}

void solve() {
    cin >> n; cin >> s;

    for (int i = 0; i < n; i++) a[i] = (s[i] == 'L' ? 0 : 1);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int m = 0; m < 2; m++)
                    fill(dp[i][j][k][m], dp[i][j][k][m] + n + 2, -1);

    int best = INF;
    best = min(best, cost(0, 0, 0, 1) + go(0, 0, 0, 0, 2));
    best = min(best, cost(0, 1, 0, 1) + go(0, 1, 0, 1, 2));
    best = min(best, cost(1, 0, 0, 1) + go(1, 0, 1, 0, 2));
    best = min(best, cost(1, 1, 0, 1) + go(1, 1, 1, 1, 2));

    cout << best << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}
