#include <bits/stdc++.h>
using namespace std;

const int N = (int(1e6)) + 5;
int minPrime[N];

void sieve() {
    for (int i=0; i<N; i++) minPrime[i] = i;
    minPrime[0] = 1;
    for (int i=2; i<N; i++)
        if (minPrime[i] == i)
            for (int j=2*i; j<N; j+=i)
                minPrime[j] = (minPrime[j] == j ? i : minPrime[j]); // might be wrong    
}

map<int, int> factors[N];
map<int, int> lcm_factors;

void factorize(int k, int index) {
    //vector<int>& f = factors[index];
    map<int, int>& f = factors[index];
    int mp = 1;
    while (k != 1) {
        if (mp != minPrime[k]) {
            mp = minPrime[k];
            //f.push_back(mp);
            while (minPrime[k] == mp) {
                k /= mp;
                lcm_factors[mp]++;
                f[mp]++;
            }
        }
    }
}

int n;
int a[N];

void solve() {
    sieve();
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        factorize(a[i], i);
    }

    //for (auto p:lcm_factors) cout << p.first << ' ' << p.second << '\n';
    
    bool flag1 = true;
    for (int i=0; i<n; i++)
        for (auto ppf : factors[i])
            flag1 &= (lcm_factors[ppf.first] == ppf.second);
    if (flag1) {
        cout << "pairwise coprime\n";
        return;
    }
    
    int g = a[0];
    for (int i=1; i<n; i++) g = __gcd(g, a[i]);
    if (g == 1) {
        cout << "setwise coprime\n";
    } else {
        cout << "not coprime\n";
    }

}

int main() {
    solve();
}