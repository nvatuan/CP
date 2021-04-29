#include <bits/stdc++.h>
using namespace std;

int n, m;
int t[205], x[205], y[205];

struct State {
    long long banana;
    int step;
    State(long long k, int st) {
        banana=k; step=st;
    }
};

const int TEN5 = 100000;

long long apply_first(long long k, long long x) {
    if (x % TEN5 == 0) return k + x/TEN5;
    else return k + x/TEN5 + 1;
}

long long  apply_second(long long k, long long x) {
    long long new_k = k;
    new_k *= x;
    if (new_k % TEN5 != 0) return new_k / TEN5 + 1;
    else return new_k / TEN5;
}

void solve() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }

    vector<int> mark (m+1, -1);
    mark[0] = 0;

    for (int i=1; i<=n; i++) {
        vector<int> times (m+1, 0);
        for (int state=0; state<=m; state++) {
            if (mark[state] != -1){
                int new_st; 
                if (t[i] == 1) new_st = apply_first(state, x[i]);
                else new_st = apply_second(state, x[i]);
                if (new_st <= m) {
                    if (times[state] == 0) {
                        if (mark[new_st] == -1) {
                            mark[new_st] = mark[state]+1;
                        }
                        times[new_st] = 1;
                    } else {
                        times[new_st] = times[state] + 1;
                        if (mark[new_st] == -1) {
                            mark[new_st] = mark[state];
                        }
                    }
                } 
            }
            if (times[state] >= y[i]) break;
        }
    }


    for (int i=1; i<=m; i++) {
        if (mark[i] == -1) cout << -1 << ' ';
        else cout << mark[i] << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}