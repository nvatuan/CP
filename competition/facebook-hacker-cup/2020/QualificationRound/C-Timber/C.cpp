#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.hpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

set<pair<long long, long long>> Segs;
vector<pair<long long, long long>> Tree;

void solve() {
    Segs.clear();
    int n; cin >> n;
    Tree.resize(n);
    for(pair<long long, long long>& p : Tree) cin >> p.first >> p.second;
    sort(Tree.begin(), Tree.begin() + n);
    
    //
    Segs.insert(make_pair(Tree[0].first, Tree[0].second));
    Segs.insert(make_pair(Tree[0].first + Tree[0].second, Tree[0].second));

    
    for (int i = 1; i < n; i++) {
        long long coord1, coord2;
        long long extend = 0;
        set<pair<long long, long long>>::iterator it1, it2;
        //
        coord1 = Tree[i].first - Tree[i].second;  
        it1 = prev(Segs.upper_bound(make_pair(coord1, LLONG_MAX)));

        coord2 = Tree[i].first;  
        it2 = prev(Segs.upper_bound(make_pair(coord2, LLONG_MAX)));

        if (it1->first != coord1) extend = 0;
        else extend = it1->second;
        Segs.insert(make_pair(Tree[i].first, extend + Tree[i].second));

        if (it2->first != coord2) extend = 0;
        else extend = it2->second;
        Segs.insert(make_pair(Tree[i].first + Tree[i].second, extend + Tree[i].second));
    }

    long long ans = 0;
    for (const pair<long long, long long>& p : Segs) ans = max(ans, p.second);
    printf("%lld\n", ans);
}

int main() {
    int t; cin >> t;
    for (int it = 1; it <= t; it++) {
        printf("Case #%d: ", it);
        solve();
    }
}