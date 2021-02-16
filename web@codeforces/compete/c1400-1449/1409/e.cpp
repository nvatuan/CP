#include <bits/stdc++.h>
using namespace std;

int n, k;
const int SIZE = 200005;
int x[SIZE], y[SIZE];

int ans[SIZE];
int INF = int(1e9) + 5;

void solve() {
    cin >> n >> k;
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++) cin>>y[i];

    map<int, int> point_on_x;
    for (int i=0;i<n;i++) point_on_x[x[i]]++;

    sort(x, x + n);

    n = (unique(x, x+n) - x);
    //cerr << n << endl;

    // -- cal answer for placing 1 platform
    fill(ans, ans+n, 0);
    int curr_point = 0;
    for (int L = 0, R = 0; R < n; R++) {
        curr_point += point_on_x[x[R]];
        while (x[R] - k > x[L]) {
            curr_point -= point_on_x[x[L]];
            L++;
        }
        ans[R] = curr_point;
        //printf("%d @%d = %d\n", R, x[R], ans[R]);
    }

    //for (int i = 0; i < n; i++) {
    //    cerr << ans[i] << ' ';
    //}
    //cerr << endl;

    // -- cal answer by combining two max platform
    int ultimate_answer = 0;
    int max_platform1 = 0;
    for (int L = 0, R = 0; R < n; R++) {
        while (x[R] - k > x[L]) {
            if (max_platform1 < ans[L]) max_platform1 = ans[L];
            L++;
        }
        ultimate_answer = max(ultimate_answer, max_platform1 + ans[R]);
    }
    cout << ultimate_answer << '\n';
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}