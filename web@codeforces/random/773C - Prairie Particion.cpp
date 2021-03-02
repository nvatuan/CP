#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

int n;
vector<long long> a;

int main() {
    scanf("%d", &n);
    a.resize(n);
    for (auto &ll : a) scanf("%lld", &ll);

    map<long long, int> cnt;
    for (auto &ll : a) cnt[ll]++;
    
    map<llong, int> summand;
    int seq_cnt_bound = n;

    priority_queue<llong> remains;

    for (llong i = 1; i<(llong)(1e13); i<<=1) {
        seq_cnt_bound = min(seq_cnt_bound, cnt[i]);
        summand[i] = seq_cnt_bound;

        for (int j=0; j<cnt[i]-summand[i]; j++) {
            remains.push(i);
        }

        // fprintf(stderr, "%lld: %d\n", i, summand[i]);
    }

    for (auto &ll : a) {
        if (__builtin_popcountll(ll) > 1) remains.push(ll);
    }
    // fprintf(stderr, "Residue vector size: %d\n", remains.size());

    auto check = [&](int x, priority_queue<llong> r, map<llong, int> summand) -> bool {
        for (llong i=1; i<(llong)(1e13); i<<=1) {
            for (int j=0; j<(summand[i]-min(summand[i], x)); j++) r.push(i);
        }

        while (not r.empty()) {
            llong rtop = r.top(); r.pop();
            // fprintf(stderr, "Currently largest r=%lld\n", rtop);
            if (!x) return false;
            x--;

            llong largest_pwr2=1;
            for (llong i=1; i<(llong)(1e16); i<<=1) {
                if (summand[i] > 0) {
                    summand[i]--;
                    largest_pwr2 <<= 1;
                } else break;
            }

            if (rtop > largest_pwr2) return false;
        }
        
        return true;
    };


    int upper = cnt[1];
    int lower = upper;

    if (check(upper, remains, summand)) {
        // printf("ok with hi=%d\n", upper);
    } else {
        printf("-1\n");
        return 0;
    }

    int lo = 0, hi = upper;
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (check(mid, remains, summand)) {
            hi = mid;
            lower = hi;
        } else {
            lo = mid;
        }
    }

    while (lower <= upper) {
        printf("%d ", lower);
        lower++;
    }
    printf("\n");
}