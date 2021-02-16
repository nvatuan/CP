#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = (int)(2e5)+10;
int a[N], b[N], c[N];

int ass[N];

void solve() {
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    for (int i=0; i<m; i++) cin >> c[i];

    map<int, vector<int>> color2plank;
    for (int i=0; i<n; i++) {
        if (a[i] == b[i]) color2plank[b[i]].push_back(i+1);
    }
    for (int i=0; i<n; i++) {
        if (a[i] != b[i]) color2plank[b[i]].push_back(i+1);
    }

    int prev_success = -1;
    int pos = 1;

    for (int i=m-1; i>=0; i--) {
        if (color2plank[c[i]].size() == 0) {
            if (prev_success == -1) {
                pos = 0; break;
            } else {
                ass[i] = prev_success;
            }
        } else {
            int pl = color2plank[c[i]].back();
            ass[i] = pl;
            prev_success = pl;
            
            a[pl-1] = c[i];

            color2plank[c[i]].pop_back();
            //cout << "@" << pl << endl;
        }
    }

    //for (int i=0; i<n; i++) {
    //    printf("a:%d, b:%d\n", a[i], b[i]);
    //}

    for (int i=0; i<n; i++) {
        pos &= (a[i] == b[i]);
    }

    cout << (pos ? "YES" : "NO") << endl;
    if (pos) {
        for (int i=0; i<m; i++) cout << ass[i] << ' ';
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}