#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> A, B, Ar;

void solve() {
    cin >> n >> m;
    A.resize(n); B.resize(n); Ar.resize(n);
    for (int i=0; i<n; i++) {
        cin >> A[i];
        Ar[i] = A[i];
    }
    for (int i=0; i<n; i++) {
        cin >> B[i];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            Ar[i][j] = (A[i][j] == '.' ? 'X' : '.');
        }
    }

    int changes_1 = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            changes_1 += (B[i][j] != A[i][j]);
        }
    }
    int changes_2 = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            changes_2 += (B[i][j] != Ar[i][j]);
        }
    }
    if (changes_1 < changes_2) {
        for (int i=0; i<n; i++) {
            cout << A[i] << '\n';
        }
    } else {
        for (int i=0; i<n; i++) {
            cout << Ar[i] << '\n';
        }
    }
}

int main() {
    solve();
}