#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> p[int(1e5) + 10];

#define x first
#define y second

void compress() {
    vector<int> vx (n), vy(n);
    for (int i=0; i<n; i++) vx[i] = p[i].x;
    for (int i=0; i<n; i++) vy[i] = p[i].y;
    //
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    map<int, int> cmpr_x, cmpr_y;

    int val = 1;
    for (int i=0; i<n; i++) 
        if (cmpr_x[vx[i]] == 0) {
            cmpr_x[vx[i]] = val; 
            ++val;
        }
    
    val = 1;
    for (int i=0; i<n; i++) 
        if (cmpr_y[vy[i]] == 0) {
            cmpr_y[vy[i]] = val;
            ++val;
        }
    
    for (int i=0; i<n; i++) {
        p[i].x = cmpr_x[p[i].x];
        p[i].y = cmpr_y[p[i].y];
    }
}

const int N = int(1e5) + 10;
int downward[N], upward[N];

void update(int* bit, int x, int val) {
    for (; x < N; x += (x & -x)) bit[x] += val;
}
int sum(int* bit, int x) { // starts with 1
    int res = 0;
    for (; 0 < x ; x -= (x & -x)) res += bit[x];
    return res;
}
int sum_range(int* bit, int l, int r) { //[l, r]
    return sum(bit, r) - sum(bit, l-1);
}


int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> p[i].x >> p[i].y;    
    sort(p, p+n);
    compress();

    for (int i=0; i<n; i++) update(downward, p[i].y, 1);

    long long ans = 0;
    for (int i=0; i<n; i++) {
        ans += sum(downward, p[i].y-1);
        ans += sum_range(upward, p[i].y + 1, N - 1);
        update(upward, p[i].y, 1);
        update(downward, p[i].y, -1);
    }

    cout << ans/2 << '\n';
}