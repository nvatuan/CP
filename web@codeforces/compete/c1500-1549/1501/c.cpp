#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
int a[(int)(2e5)+100];
map<int, int> cnt;
vector<int> found;

void solve() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
        if (cnt[a[i]] == 2) found.push_back(a[i]);
    }

    if (found.size() >= 2) { // manual
        vector<int> xs, ys;
        for (int i=0; i<n; i++) {
            if (a[i] == found[0]) {
                xs.push_back(i+1);
            } else
            if (a[i] == found[1]) {
                ys.push_back(i+1);
            }
        }
        printf("YES\n");
        printf("%d %d %d %d\n", xs[0], ys[0], xs[1], ys[1]);
        return;
    } else {
        unordered_map<int, pair<int, int>> mp;
        // if (n <= 10000) {
        if (false) {
            for (int i=0; i<n; i++) {
                for (int j=i+1; j<n; j++)
                    if (mp.find(a[i]+a[j]) == mp.end()) {
                        mp[a[i]+a[j]] = make_pair(i, j);
                    } else {
                        auto p = mp[a[i]+a[j]];
                        if (p.first == i || p.first == j) continue;
                        if (p.second == i || p.second == j) continue;
                        printf("YES\n");
                        printf("%d %d %d %d\n", p.first+1, p.second+1, i+1, j+1);
                        return;
                    }
            }
            printf("NO\n");
        } else { // random solution
            vector<int> p(n);
            for (int i=0; i<n; i++) p[i] = i;
            shuffle(p.begin(), p.end(), rng);

            int TIMES = (int)(4e8)/n;
            for (int i=0; i<min(n, TIMES); i++) {
                for (int j=i+1; j<n; j++)
                    if (mp.find(a[p[i]]+a[p[j]]) == mp.end()) {
                        mp[a[p[i]]+a[p[j]]] = make_pair(p[i], p[j]);
                    } else {
                        auto pi = mp[a[p[i]]+a[p[j]]];
                        if (pi.first == p[i] || pi.first == p[j]) continue;
                        if (pi.second == p[i] || pi.second == p[j]) continue;
                        printf("YES\n");
                        printf("%d %d %d %d\n", pi.first+1, pi.second+1, p[i]+1, p[j]+1);
                        return;
                    }
            }
            printf("NO\n");
        }
    }
}

int main() {
    solve();
}