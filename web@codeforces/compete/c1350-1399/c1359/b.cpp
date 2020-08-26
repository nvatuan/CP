#include <bits/stdc++.h>
using namespace std;

const int __MULTITEST = 1;
const int __DEBUGMODE = 0;
#define db if(__DEBUGMODE)

template<typename T>
T In() { T x; cin >> x; return x; }

// --
int n, m, x, y;
vector< vector<int> > wall (1003, vector<int> (1003, 0));
vector< vector<int> > dp (1003, vector<int> (1003));

void solve() {
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            wall.at(i).at(j + 2) = (c == '*' ? 1 : 0);
        }
        wall.at(i).at(0) = 1;
        wall.at(i).at(1) = 1;
    }
    //
    for (int i = 0; i < n; i++) dp.at(i) = vector<int> (1003, 0);
    //
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ( wall.at(i).at(j + 2) ) {
                dp.at(i).at(j + 2) = dp.at(i).at(j + 2 - 1);
            } else 
            if ( wall.at(i).at(j + 1) ) {
                dp.at(i).at(j + 2) = dp.at(i).at(j + 2 - 1) + x;
            } else {
                dp.at(i).at(j + 2) = min (
                    dp.at(i).at(j + 2 - 1) + x,
                    dp.at(i).at(j + 2 - 2) + y
                );
            }
            //
        }
    }
    //
    long long ans = 0;
    for (int i = 0; i < n; i++) ans += dp.at(i).at(m + 2 - 1);
    cout << ans << endl;
}

// --
int main() {
    for (int t = (__MULTITEST ? In<int>() : 1); t; t--) solve();
}