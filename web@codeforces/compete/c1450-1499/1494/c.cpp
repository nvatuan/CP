#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> a1, a2;
vector<int> b1, b2;

int subsolve(vector<int>& box, vector<int>& spec) {
    int N = (int) box.size();
    int M = (int) spec.size();

    vector<int> good (M+5, 0);
    int cumulate = 0;
    for (int i=M-1; i>=0; i--) {
        int& sp = spec[i];
        if (binary_search(box.begin(), box.end(), sp)) cumulate++;
        good[i] = cumulate;
    }
    

    int ans=good[0];
    for (int i=0; i<M; i++) {
        int boxcnt = (int)(upper_bound(box.begin(), box.end(), spec[i]) - box.begin());
        // _ * _ _ _ * _ _ *
        //   # # # # # # # #
        // [spec[i] - boxcnt + 1, spec[i] + 1)
        int left_spec = (int)(lower_bound(spec.begin(), spec.end(), spec[i] - boxcnt + 1) - spec.begin());
        ans = max(ans, (i-left_spec+1) + good[i+1]);
    }
    return ans;
}

void solve() {
    a1.clear(); a2.clear(); b1.clear(); b2.clear();
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int tmp; scanf("%d", &tmp);
        if (tmp > 0) a1.push_back(tmp);
        else a2.push_back(-tmp);
    }
    for (int i=0; i<m; i++) {
        int tmp; scanf("%d", &tmp);
        if (tmp > 0) b1.push_back(tmp);
        else b2.push_back(-tmp);
    }
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    sort(b1.begin(), b1.end());
    sort(b2.begin(), b2.end());

    printf("%d\n", subsolve(a1, b1) + subsolve(a2, b2));
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}