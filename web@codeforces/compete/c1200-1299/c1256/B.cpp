#include <bits/stdc++.h>
using namespace std;

int q, n;
int a[1001];

int main() {
    ios::sync_with_stdio(0);
    //
    for(cin >> q; q; q--) {
        cin >> n;
        //
        vector <int> op(n, 0);
        op[0] = 1;
        //
        for(int i = 0; i < n; i++) cin >> a[i];
        a[n] = INT_MAX;
        // --
        int opCount = n-1;
        int idx = 0;
        while(opCount) {
            while(a[idx] == idx+1) idx++;
            if(idx == n) break;
            // --
            int mind, m = INT_MAX;
            for(int j = idx; j < n; j++) {
                if(m > a[j]) {
                    m = a[j];
                    mind = j;
                }
            }
            // --
            while(opCount && !op[mind] && a[mind-1] > a[mind]) {
                swap(a[mind], a[mind-1]);
                op[mind] = 1;
                mind--;
                opCount--;
            }
            // --
            idx++;
        }
        // --
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
}