#include <bits/stdc++.h>
using namespace std;

int n, q;
long long a[300010];

const int INF = (int) 1e9 + 10;

long long premax[300010], postmax[300010];

void solve() {
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<int> pinnacle;
    for (int i=1; i<=n; i++)
        if (a[i-1] < a[i] && a[i] > a[i+1]) pinnacle.push_back(i);
    
    //cerr << "pinnacle: "; for (int i : pinnacle) cerr << i << ' ';  cerr << endl;`
    long long ans = a[pinnacle[0]];
    for (int i = 1; i < (int) pinnacle.size(); i++) {
        long long min_valley = INF;
        int ptr = pinnacle[i-1] + 1;
        while (ptr < pinnacle[i]) { 
            min_valley = min(min_valley, a[ptr]); ptr++;
        }
        ans = (ans - min_valley + a[pinnacle[i]]);
    }

    cout << ans << '\n';
    fill(a, a + n + 5, 0);
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}