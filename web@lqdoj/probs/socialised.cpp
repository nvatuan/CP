#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a (n);
    for (int &i : a) cin >> i;

    for (int g=1; g<=n; g++) {
        int ans = -1;
        for (int day=g; day<=300; day++){
            map<int, int> same;
            for (int i : a) same[i/day]++;
            for (auto p : same)
                if (p.second == g) {
                    ans = day;
                    break;
                }
            if (ans > 0) break;
        }
        cout << ans << '\n';
    }
}

int main() {
    solve();
}