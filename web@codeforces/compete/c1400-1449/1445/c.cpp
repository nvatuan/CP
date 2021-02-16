#include <bits/stdc++.h>
using namespace std;

long long p;
int q;

void solve() {
    cin >> p >> q;
    if (p < q) cout << p << endl;
    else
    if (p % q != 0) cout << p << endl;
    else 
    if (p % q == 0) {
        map<long long, int> fact;
        {
            int qq = q;
            for (int d=2; 1LL*d*d <= qq; d++) {
                while (qq % d == 0) {
                    fact[d]++;
                    qq /= d;
                }
            }
            if (qq > 1) fact[qq]++;
        }

        vector<long long> fs;
        for (auto f : fact) fs.push_back(f.first);

        map<long long, int> factBig;
        {
            long long pp = p;
            for (auto f : fs) {
                while (pp % f == 0) {
                    factBig[f]++;
                    pp /= f;
                }
            }
            if (pp > 1) factBig[pp]++;
        }

        long long ans = 1;


        // for (auto f : fs) {
        //     cout << f << "fs= " << fact[f] << "| fb=" << factBig[f] << endl;
        // }

        for (long long f : fs) {
            int t = (factBig[f] - fact[f] + 1);
            long long temp = p;
            while (t--) temp/=f;
            ans = max(ans, temp);
        }

        cout << ans << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}