#include <bits/stdc++.h>
using namespace std;

int M;
vector<pair<int, int>> segs;

void solve() {
    segs.clear();

    cin >> M;
    for (int a, b; true; ) {
        cin >> a >> b;
        if (!a && !b) break;
        segs.push_back({a, b});
    }

    sort(segs.begin(), segs.end());

    vector<int> ans;

    int Left = 0, Right = 0;
    int usedIndex = 0;
    for (int i = 0; i < segs.size(); i++) {
        if (Left < segs[i].first) {
            Left = Right;
            ans.push_back(usedIndex);
        }
        if (M <= Left) break;

        if (segs[i].first <= Left) {
            if (Right < segs[i].second) {
                Right = segs[i].second;
                usedIndex = i;
            }
        }
    }
    if (Left < M && Left < Right) {
        Left = Right;
        ans.push_back(usedIndex);
    }

    if (Left < M) {
        printf("0\n");
    } else {
        printf("%d\n", ans.size());
        for (int& i : ans) {
            printf("%d %d\n", segs[i].first, segs[i].second);
        }
    }
    printf("\n");
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}