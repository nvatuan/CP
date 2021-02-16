#include <bits/stdc++.h>
using namespace std;

void solve(int k) {
    if (k == 6) {
        cout << "-1\n"; return;
    }
    if (k % 2 == 1) { // odd
        cout << "1\n"; return;
    }
    if (k % 2 == 0) { // even
        if (k % 4 == 0) {
            cout << "2\n"; return;
        }
        int trii=k/3;
        int ans = 4;
        for (int tri=trii-2; tri<=trii+2; tri++) {
            for (int d=-4; d<0; d++) {
                vector<int> trips;
                trips.push_back(tri);
                trips.push_back(tri + d);
                trips.push_back(k - (tri) - (tri+d));
                if (trips[0] < 2) continue;
                
                sort(trips.begin(), trips.end());
                bool pos=true;
                for (int i=0; i<3; i++)
                    for (int j=i+1; j<3; j++)
                        if (__gcd(trips[i], trips[j]) != 1) pos = false;
                
                if (pos) {
                    ans = min(trips.back() - trips[0], ans);
                }
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    int t; cin >> t;
    for (int tt=1; tt<=t; tt++) {
        printf("Case #%d: ", tt);
        int x;
        cin >> x;
        solve(x);
    }
}

/*
- Chi co the co 1 so chan
- Neu x la so chan: x/2 - 1, x/2 + 1
20 = 3 + 6 + 
*/