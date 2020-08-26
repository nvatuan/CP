#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[10000];

int main(){
    for(cin >> t; t; t--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n, greater<int>());
        // --
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(i+1 <= a[i]) ans = max(ans, i+1);
        }
        // --
        cout << ans << "\n";
    }
}