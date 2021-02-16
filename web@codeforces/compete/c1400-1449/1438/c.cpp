#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[2000][2000], b[2000][2000];

void solve() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int input;
            cin >> input;
            b[i][j] = input;
            if (input % 2 != (i+j) % 2) b[i][j] = input+1;
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << b[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}