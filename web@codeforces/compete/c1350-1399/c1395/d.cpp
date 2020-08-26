#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

int n, d, m;
vector<llong> a, big, small;

void solve() {
    cin >> n >> d >> m;
    a.resize(n); 
    for (llong& i : a) {
        cin >> i;
        if (i <= m) small.push_back(i);
        else big.push_back(i);
    }
    sort(small.begin(), small.end(), greater<llong>());
    sort(big.begin(), big.end(), greater<llong>());

    llong fun = 0;
    int p1 = 0, p2 = 0, day = 0;
    for (; day < n;) {
        debug(day, p1, p2, fun);
        if (p1 < (int) small.size()) {
            fun += small[p1++]; day++;
        } else {
            fun += big[p2++]; day += (d + 1);
        }
    }

    llong ans = fun;
    while (p2 < (int) big.size() and p1 > 0) {
        day--;
        fun -= small[--p1];
        if (day < n) {
            fun += big[p2++];
            day += (d + 1);
            ans = max(ans, fun);
        }
    }

    cout << ans << endl;
}

int main() {
        solve();
}