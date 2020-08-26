#include <bits/stdc++.h>
using namespace std;

map<vector<int>, int> discount;

int sticker[32];
int ans;

void solve() {
    discount.clear();
    ans = 0;

    int n, m;
    cin >> n >> m;
    vector<int> dprogram;
    for (int i = 0; i < n; i++) {
        int k; cin >> k; dprogram.resize(k);
        for (int & i : dprogram) cin >> i;
        int damount; cin >> damount;

        discount[dprogram] = damount;
    }
    for (int i = 1; i <= m; i++) {
        cin >> sticker[i];
    }
    //
    ans = 0;
    for (auto& p : discount) {
        bool enough = true;
        while (enough) {
            for (const int& type : p.first) {
                sticker[type]--;
                if (sticker[type] < 0) {
                    enough = false; break;
                }
            }
            if (enough) {
                ans += p.second;
            } else break;
        }
    }

    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}