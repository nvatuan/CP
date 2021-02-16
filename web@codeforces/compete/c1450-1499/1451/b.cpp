#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    int n, q;
    cin >> n >> q;
    cin >> s;

    while (q--) {
        int l, r; scanf("%d%d", &l, &r);
        l--, r--;
        bool flag = true;
        string subL = s.substr(0, l);
        string subR = s.substr(r+1);
        //cerr << subL << ' ' << subR << endl;
        if (subL.find(s[l]) != string::npos || subR.find(s[r]) != string::npos) 
            printf("YES\n");
        else 
            printf("NO\n");
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}