#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    vector<vector<int>> mat (n, vector<int>(n, 0));
    int times = (n-1)/2;
    for (int inc=1; inc <= times; inc++) {
        set<int> s;
        for (int i=0; i<n; i++) s.insert(i);
        
        while (! s.empty()) {
            int start= *s.begin();

            int cur = start;
            while (true) {
                int nxt = (cur + inc) % n;
                if (nxt == start) break;

                s.erase(cur);
                mat[cur][nxt] = 1;
                mat[nxt][cur] = -1;

                cur = nxt;
            }

        }
    }

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            cout << mat[i][j] << ' ';
        }
    }
    cout << endl;

    // map<int, int> score;
    // for (int i=0; i<n; i++) {
    //     for (int j=i+1; j<n; j++) {
    //         if (mat[i][j] == 1) {
    //             score[i] += 3;
    //         } else
    //         if (mat[i][j] == 0) {
    //             score[i] += 1;
    //             score[j] += 1;
    //         } else {
    //             score[j] += 3;
    //         }
    //     }
    // }
    // for (auto p : score) {
    //     cerr << p.first << ": " << p.second << endl;
    // }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}