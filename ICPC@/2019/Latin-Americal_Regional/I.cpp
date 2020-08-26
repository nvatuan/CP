#include <bits/stdc++.h>
using namespace std;

int N, L;
vector<vector<int>> edge(2002, vector<int>());

const int M = int(1e9) + 7;

int computed[2002];
long long dp[2002];
int dp2[2002];

long long dfs(int x) {
    if(computed[x]) return dp[x];
    //
    long long ways = 0;
    for(const int& v : edge[x]) {
        ways = (ways + dfs(v)) % M;
        dp2[x] |= dp2[v];
    }
    //
    computed[x] = 1;
    dp[x] = ways;
    return ways;
}

long long ans2(){
    long long a = 0;
    for(int i = L; i < N; i++) a += dp2[i];
    return a;
}

int main() {
    scanf("%d%d", &N, &L);
    //
    for(int m, u, i = 0; i < L; i++) {
        scanf("%d", &m);
        while(m--){
            scanf("%d", &u);
            u--;
            edge[u].push_back(i);
        }
    }
    for(int i = L; i < N; i++)
        edge[N].push_back(i);
    // --
    dp[0] = computed[0] = dp2[0] = 1;
    //
    cout << dfs(N);
    cout << " " << ans2();
}