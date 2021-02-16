#include <bits/stdc++.h>
using namespace std;

const int N = int(3e5) + 20;
int to_r[N], to_l[N];
int n;
char d;

void solve() {
    cin >> n;
    fill(to_r, to_r + n + 10, 0);
    fill(to_l, to_l + n + 10, 0);
    for (int i=0; i<n; i++) {
        cin >> d;
        switch(d) {
            case '-':
                to_r[i] = to_l[(i+1) % n] = true;
                break;
            case '<':
                to_l[(i+1) % n] = true;
                break;
            case '>':
                to_r[i] = true;
                break;
        }
    }
    // check for circular path
    if ( count(to_r, to_r + n, 1) == n or count(to_l, to_l + n, 1) == n ) {
        cout << n << '\n';
    } else {
        int ans = 0;
        for (int i=0; i<n; i++) {
            int adj_left = (i-1 + n) % n;
            int adj_right = (i+1) % n;
            if (
                (to_l[i] and to_r[adj_left]) or (to_r[i] and to_l[adj_right])
            ) ans++;
        }
        cout << ans << '\n';
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}