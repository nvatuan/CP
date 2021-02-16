#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

void solve() {
    llong n;
    cin >> n;
    
    map<llong, int> facts;
    for (llong i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            facts[i]++;
            n/=i;
        }
    }
    if (n>1) {facts[n]++; n=1;}

    vector<pair<int, llong>> a;
    auto it = facts.begin();
    std::generate_n(std::back_inserter(a), facts.size(),
        [&]() {
            pair<int, llong> p = make_pair(it->second, it->first);
            it++;
            return p;
        }
    );

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    //for (auto p : a) cout << p.first << ' ' << p.second << '\n';
    //cout << "----------\n";

    vector<llong> q (a[0].first, 1);
    for (pair<int, llong> p : a) {
        int times; llong factor;
        std::tie(times, factor) = make_tuple(p.first, p.second);
        for (int t=0; t<times; t++) q[t]*=factor;
    }

    reverse(q.begin(), q.end());
    printf("%d\n", (int)q.size());
    for (llong i : q) cout << i << ' ';
    cout << endl;
}

int main() {
    int t;
    for (cin >> t; t; t--)
        solve();
}