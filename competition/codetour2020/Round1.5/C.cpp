#include <bits/stdc++.h>
using namespace std;

int m, n;
long long T;

int max_col[10001];
long long max_all = 0;

int mat[2002][2002];

int main() {
    cin >> n >> m >> T;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &mat[i][j]);
            max_col[j] = max(max_col[j], mat[i][j]);
        }
    }

    for (int i=0; i<m; i++) max_all += max_col[i];
    set<pair<int, int>> bags;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat[i][j] < max_col[j])
                bags.insert({mat[i][j], j});
        }
    }
    // for (int i=0; i<m; i++) cout << max_col[i] << ' '; cout << endl;
    if (T == 0) {
        cout << 0 << endl;
        return 0;
    }
    T -= max_all;
    int ans = 1;
    try {
        while (T > 0) {
            set<pair<int, int>>::iterator it = prev(bags.end());
            long long new_max = max_all - max_col[it->second] + it->first;
            bags.erase(prev(bags.end()));
            T -= new_max;
            ans++;
        }
        cout << ans << '\n';
    } catch {
        cout << T / max_all << '\n';
    }
}