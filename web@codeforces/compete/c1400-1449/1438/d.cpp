#include <bits/stdc++.h>
using namespace std;

int n;
int a[(int)(1e5)+100];

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    switch (n%2) {
        case 0: {
            map<int, int> bit_count;
            for (int i =0; i<n; i++) {
                for (int b=0; b<=31; b++) {
                    bit_count[b] += ((a[i] & (1 << b)) != 0);
                }
            }
            bool possible = true;
            for (auto p : bit_count)
                possible &= (!(p.second & 1));
            if (not possible) printf("NO\n");
            else {
                printf("YES\n");
                vector<vector<int>> ops;
                for (int i=0; i<n-1; i+=3) {
                    ops.push_back({i+1, i+2, i+3});   
                }
                printf("%d\n", int(ops.size()));
                for (auto v : ops) {
                    printf("%d %d %d\n", v[0], v[1], v[2]);
                }
            }
            break;
        }
        case 1: {
            printf("YES\n");
            vector<vector<int>> ops;
            for (int i=0; i<n-1; i+=2) {
                ops.push_back({i+1, i+2, i+3});
            }
            for (int i=0; i<n-3; i+=2) {
                ops.push_back({i+1, i+2, n});
            }
            printf("%d\n", int(ops.size()));
            for (auto v : ops) {
                printf("%d %d %d\n", v[0], v[1], v[2]);
            }
        }
    }
}

int main() {
    // int t; cin >> t;
    // while(t--)
        solve();
}