#include <bits/stdc++.h>
using namespace std;

int n, m, D;
int c[10000];

long long sumC;
int ans[10000];

int main() {
    cin >> n >> m >> D;
    for(int i = 0; i < m; i++) {
        cin >> c[i];
        sumC += c[i];
    }
    // --
    long long x = -1;
    long long nextx;
    int board = 0;
    while(x < n) {
        if(board == m) {
            if(x + D >= n) {
                cout << "YES\n";
                for(int i = 0; i < n; i++) cout << ans[i] << " ";
            } else {
                cout << "NO";   
            }
            return 0;
        }
        // --
        nextx = min(x + D, n - sumC);
        // cout << "nextx for placing == " << nextx << endl;
        for(int i = 0; i < c[board]; i++) {
            ans[i + nextx] = board+1;
            x = max(x, i + nextx);
        }
        sumC -= c[board];
        board++;
        // cout << "DEBUG\n";
        // cout << "board == " << board << endl;
        // cout << "x == " << x << endl;
        // for(int i = 0; i < n; i++) cout << ans[i] << " ";
        // cout << endl;
    }
    return 0;
}