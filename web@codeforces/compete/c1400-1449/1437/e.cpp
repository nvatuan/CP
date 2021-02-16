#include <bits/stdc++.h>
using namespace std;

void die() {
    cout << "-1\n";
    exit(0);
}

void solve() {
    int n, k;
    cin >> n >> k;
    n+=2;
    vector<int> a(n);
    for (int i=1; i<n-1; i++) {
        cin >> a[i];
        a[i] -= i;
    }

    a[0] = -(int)(1e9 + 100);
    a[n-1] = (int)(1e9 + 100);

    k+=2;
    vector<int> b(k);
    for (int i=1; i<k-1; i++) {
        cin >> b[i]; 
    }
    b[0] = 0;
    b[k-1] = n-1;

    int ans = 0;
    for (int i=1; i<k; i++) {
        int l = b[i - 1], r = b[i];
        if (a[l] > a[r]) die();
    
        vector<int> _lis;
        int skipped = 0;
        for (int j = l+1; j < r; j++) {
            if (a[l] <= a[j] and a[j] <= a[r]) {
                auto idx = upper_bound(_lis.begin(), _lis.end(), a[j]);
                if (idx == _lis.end()) _lis.push_back(a[j]);
                else *idx = a[j];
            }
        }
        
        ans += (r - l - 1) - (int)(_lis.size());
    }

    cout << ans << '\n';
}

int main() { solve(); }