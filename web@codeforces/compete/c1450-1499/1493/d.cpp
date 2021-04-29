#include <bits/stdc++.h>
using namespace std;

const int N = (int)(2e5)+15;
int minPrime[N];
void sieve() {
    for (int i=2; i<N; i++)
        if (minPrime[i] == 0) {
            minPrime[i] = i;
            for (long long j=1LL*i*i; j < N; j += i) 
                if (minPrime[j] == 0) 
                    minPrime[j] = i;
        }
}

const int MOD = (int)(1e9)+7;
long long ans=1;

map<int, int> cnt[N];
multiset<int> factor_cnt[N];

int n, q;

void query(int idx, int val) {
    while (val > 1) {
        int mp = minPrime[val];
        int mp_cnt = 0;
        while (mp == minPrime[val]) {
            val /= mp;
            mp_cnt++;
        }

        if (cnt[idx][mp] == 0) {
            cnt[idx][mp] += mp_cnt;
            factor_cnt[mp].insert(cnt[idx][mp]);

            if (factor_cnt[mp].size() == n) {
                for (int j=0; j < (*factor_cnt[mp].begin()); j++) {
                    ans = ans * mp % MOD;
                }
            }
        
        } else {
            int prv_mp_cnt = *factor_cnt[mp].begin();

            factor_cnt[mp].erase(factor_cnt[mp].find(cnt[idx][mp]));
            cnt[idx][mp] += mp_cnt;
            factor_cnt[mp].insert(cnt[idx][mp]);
        
            if (factor_cnt[mp].size() == n) {
                for (int j=prv_mp_cnt; j < (*factor_cnt[mp].begin()); j++) {
                    ans = ans * mp % MOD;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    cin >> n >> q;

    for (int i=0; i<n; i++) {
        int x; cin >> x;
        query(i, x);
    }

    while (q--) {
        int i, x; cin >> i >> x;
        i--;
        query(i, x);
        printf("%lld\n", ans);
    }
}