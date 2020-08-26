#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> flower(n);
    for (int& i : flower) cin >> i;

    set<int> cnt;
    for (int& i : flower) cnt.insert(i);

    int L = 0, R = 0;
    int ans = n;
    map<int, int> gather;

    while (L < n) {
        if (gather.size() < cnt.size() and R < n) {
            gather[flower[R]]++;
            R++;
        } else {
            if (gather.size() == cnt.size()) ans = min(ans, R - L);
            
            gather[flower[L]]--;
            if (gather[flower[L]] == 0) gather.erase(flower[L]);

            L++;
        }
    }

    cout << ans << endl;
}