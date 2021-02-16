#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int n;
int c[3][N];
int ans[N];

void solve() {
    fill(ans, ans + N, 0);
    cin >> n;
    for (int j=0; j<3; j++)
        for (int i=0; i<n; i++) 
            cin >> c[j][i];
        
    ans[0] = c[0][0];
    for (int i=1; i<n; i++) {
        if (i+1 == n) {
            for (int j=0; j<3; j++)
                if (ans[i-1] != c[j][i] and ans[0] != c[j][i]) {
                    ans[i] = c[j][i];
                    break;
                }
        } else {
            for (int j=0; j<3; j++) {
                if (ans[i-1] != c[j][i]) {
                    ans[i] = c[j][i];
                    break;
                }
            }
        }
    }
    for (int i=0; i<n; i++) cout << ans[i] << ' ';
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();    
}