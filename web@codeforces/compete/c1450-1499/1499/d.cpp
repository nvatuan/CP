#include <bits/stdc++.h>
using namespace std;

const int N = (int)(2e7)+2;
int prime_count[N];

void sieve() {
    for (int i=2; i<N; i++) {
        if (!prime_count[i]) {
            prime_count[i] = 1;
            for (long long j=1LL*i*2; j<N; j += i)
                prime_count[j]+=1;
        }
    }
}

long long twoPower(int exp) {
    return (1LL << exp);
}

int c, d, x;
void solve() {
    cin >> c >> d >> x;
    long long ans=0;
    for (int g=1; 1LL*g*g <= x; g++) {
        if (x % g == 0) {
            int gs[] = {g, x/g};
            for (int gs_i=0;gs_i<2; gs_i++) {
                if ((x/gs[gs_i] + d) % c == 0) {
                    int k = ((x/gs[gs_i])+d)/c;
                    ans += twoPower(prime_count[k]);
                }
                if (gs[0] == gs[1]) break;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    sieve();
    // vector<int> v = {2,4,8,16,2*3*5,4*3*5,7*7*4*3*2*9*11*13};
    // for (int i:v) cout << prime_count[i] << ' ';
    // cout << endl;
    
    int t;
    for (cin >> t; t; t--) {
        solve();
    }
}