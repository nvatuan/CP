#include <bits/stdc++.h>
using namespace std;

int n, m;

void solve() {
    scanf("%d%d", &n, &m);
    vector<vector<int>> day (m, vector<int>());
    map<int, int> cnt;

    for (int i=0; i<m; i++) {
        int k; scanf("%d", &k);
        day[i].resize(k);
        for (int &i : day[i]) {
            scanf("%d", &i);
            cnt[i]++;
        }
    }

    for (int i=0; i<m; i++) {
        sort(day[i].begin(), day[i].end(), [&](int a, int b) -> bool {
            int ca = cnt[a], cb = cnt[b];
            if (ca == cb) return a < b;
            return cnt[a] > cnt[b];
        });
    }

    int neet=cnt.begin()->first;
    for (auto p : cnt) {
        if (cnt[neet] < p.second) neet = p.first;
    }

    int neet_days = 0;
    for (int i=0; i<m; i++) {
        if (day[i].size() == 1 and day[i][0] == neet) neet_days++;
    }

    if (neet_days > (m+1)/2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        int play_counter = (m+1)/2 - neet_days;
        for (int i=0; i<m; i++) {
            if (day[i].size() == 1) printf("%d ", day[i][0]);
            else {
                if (day[i][0] == neet && play_counter > 0) {
                    play_counter--;
                    printf("%d ", day[i][0]);
                } else printf("%d ", day[i][1]);
            }
        }
        printf("\n");
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}