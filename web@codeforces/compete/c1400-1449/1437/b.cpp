#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n;
    cin >> s;
    vector<int> ac1 (n+1, 0), ac0(n+1, 0);
    ac0[0] = (s[0] == '0');
    ac1[0] = (s[0] == '1');

    for (int i=1; i<n; i++) {
        if (s[i] == '0') ac0[i] = (ac0[i-1] + 1);
        else ac1[i] = (ac1[i-1] + 1);
    }

    int ans1 = 0;
    for (int i=1; i<n; i++) {
        if (ac1[i-1] > 0 and ac1[i] == 0) ans1 += (ac1[i-1] - 1);
    }
    
    int ans0 = 0;
    for (int i=1; i<n; i++) {
        if (ac0[i-1] > 0 and ac0[i] == 0) ans0 += (ac0[i-1] - 1);
    }

    cout << max(ans1, ans0) << endl;
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}