#include <bits/stdc++.h>
using namespace std;

int n;
const int N = (int)(2e5);
int a[N];

vector<vector<int>> m;

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    m.resize(n+1, vector<int>());
    m[0].push_back(n+1);
    for (int i=n-1; i>=0; i--) {
        if (m[a[i]].size() == 0) m[a[i]].push_back(n+1);
        m[a[i]].push_back(i);
    }
    
    int x,y; x = y = 0;
    int ans = 0;

    for (int i=0; i<n; i++) {
        if (a[i] != x and a[i] != y) {
            if (m[x].back() < m[y].back()) {
                x = a[i];
                ans++;
            } else {
                y = a[i];
                ans++;
            }
        } else 
        if (a[i] != x) {
            x = a[i];
            ans++;
        } else
        if (a[i] != y) {
            y = a[i];
            ans++;
        } else;

        m[a[i]].pop_back();
    }
    cout << ans << endl;

}

int main() {
    solve();
}