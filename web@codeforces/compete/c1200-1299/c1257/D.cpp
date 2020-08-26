#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[200001];
vector< pair<int, int> > heroes_raw;
vector< pair<int, int> > heroes;

#define P first
#define E second

void solve() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) { scanf("%d", &a[i]); }
    scanf("%d", &m);
    heroes_raw.resize(m, pair<int, int>() );
    for(int i = 0; i < m; i++) { scanf("%d%d", &heroes_raw[i].P, &heroes_raw[i].E); }
    // --
    sort(heroes_raw.begin(), heroes_raw.end(), greater<pair<int, int>>());
    heroes.resize(0);
    
    int du = -1;
    for(const auto& Pa : heroes_raw) {
        if(du < Pa.E) {
            du = Pa.E;
            heroes.push_back(Pa);
        }
    }
    reverse(heroes.begin(), heroes.end());
    // --
    int maxPower;
    //
    int ans = 0;
    auto idx = heroes.begin();
    //
    for(int R = 0, L = 0; L < n; /*cout << L << " " << R << endl*/) {
        if(R >= n) {
            // printf("L,R = [%d, %d] with hero[%d,%d]!!!\n", L, R, idx->P, idx->E);
            ans++;
            break;
        }
        // --
        if(L == R) {
            maxPower = a[L];
            idx = lower_bound(heroes.begin(), heroes.end(), make_pair(maxPower, 0));
            if(idx == heroes.end()) {
                printf("%d\n", -1);
                return;
            }
        } else{
            if(R - L + 1 > idx->E) {
                // printf("L,R = [%d, %d] with hero[%d,%d]!\n", L, R, idx->P, idx->E);
                L = R;
                
                ans++;
                continue;
            }
            maxPower = max(maxPower, a[R]);
            //
            if(idx->P < maxPower) {
                auto newIdx = lower_bound(idx, heroes.end(), make_pair(maxPower, 0));

                if(newIdx == heroes.end()) {
                    printf("%d\n", -1);
                    return;
                }

                if(newIdx->E < (R - L + 1)) {
                    // printf("L,R = [%d, %d] with hero[%d,%d]!!\n", L, R, idx->P, idx->E);
                    L = R;
                    ans++;
                    continue;
                } else {
                    idx = newIdx;
                }
            }
        }
        // --
        R++;
    }
    //
    printf("%d\n", ans);
}

int main() {
    int t;
    for(cin >> t; t; t--) {
        solve();
    }
}