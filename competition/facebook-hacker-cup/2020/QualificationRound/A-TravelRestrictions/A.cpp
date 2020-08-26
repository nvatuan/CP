#include <bits/stdc++.h>
using namespace std;

int in[51], out[51];
int possible[51][51];

void solve() {
    int n; cin >> n;
    char c;

    for (int i = 0; i < n; i++) { cin >> c; in[i] = (c == 'Y'); }
    for (int i = 0; i < n; i++) { cin >> c; out[i] = (c == 'Y'); }

    for (int i = 0; i < n; i++) fill(possible[i], possible[i] + n, 0);

    for (int i = 0; i < n; i++) {
        possible[i][i] = 1;
        for (int j = i-1; j <= i+1; j += 2)
            if (0 <= j && j < n) {
                if (out[i] && in[j]) possible[i][j] = 1;
            }
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                if (possible[i][k] && possible[k][j]) possible[i][j] = 1;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        string ansToken = "";
        for (int j = 0; j < n; j++) {
            ansToken += (possible[i][j] ? 'Y' : 'N');
        }
        cout << ansToken << '\n';
    }
}

int main() {
    int t; cin >> t;
    for (int it = 1; it <= t; it++) {
        cout << "Case #" << it << ":\n";
        solve();
    }
}