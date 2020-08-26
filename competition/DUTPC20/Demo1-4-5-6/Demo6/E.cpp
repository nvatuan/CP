#include <bits/stdc++.h>
using namespace std;

int n, m;
int z[52][52];

int ans = INT_MAX;

int pen[52];

void dq(int cost, int job) {
    if (job == n) {
        ans = min(ans, cost);
    } else {
        for (int fac = 0; fac < m; fac++)
            if (cost + z[job][fac] < ans) {
                pen[fac] += z[job][fac];
                dq(cost + pen[fac], job+1);
                pen[fac] -= z[job][fac];
            }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> z[i][j];
        }
    }

    dq(0, 0);
    cout << setprecision(2) << fixed << (double)(ans)/n << '\n';
}