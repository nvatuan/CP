#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
struct Condition {
    int x, y, z;
    Condition(int a1, int a2, int a3) : x(a1), y(a2), z(a3) {
    }
};

vector<Condition> X[20];

int check(int state) {
    vector<int> prefix (21, 0);
    int len=0;
    for (int i=0; i<n; i++) {
        if ( (state&(1<<i)) ) {
            len++;
            prefix[i+1] = 1;
        }
    }

    for (int i=0; i<20; i++) {
        prefix[i+1] += prefix[i];
    }

    int flag=1;
    for (Condition &C : X[len]) {
        if (prefix[C.y] <= C.z);
        else flag = 0;
    }

    return flag;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        X[x].push_back(Condition(x,y,z));
    }

    vector<ll> dp ((1<<n), 0LL);
    dp[0] = 1;
    for (int state=0; state < (1<<n); state++) {
        for (int x=0; x<n; x++)
            if ((state & (1<<x)) == 0) {
                int new_state = (state | (1<<x));
                if (check(new_state)) dp[new_state] += dp[state];
            }
    }

    cout << dp[(1<<n)-1] << endl;
}
