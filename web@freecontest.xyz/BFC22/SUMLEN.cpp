#include <bits/stdc++.h>
using namespace std;

const long long MOD = (long long) 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (long long& ll : A) cin >> ll;
    // --
    long long sumSeg = 0;
    for (long long ll : A) { sumSeg = sumSeg + ll; sumSeg = (sumSeg >= MOD ? sumSeg - MOD : sumSeg); }
    
    long long sumPwr3 = 0;
    for (long long i = 1; i <= N; i++) { sumPwr3 += (i*i%MOD*i%MOD); sumPwr3 = (sumPwr3 >= MOD ? sumPwr3 - MOD : sumPwr3); }

    auto cubeMod = [&](long long x) -> long long {
        return x*x%MOD*x%MOD;
    };

    long long ans = 0;
    for (int i = 0, j = N-1; i <= j; i++, j--) {
        ans += (sumSeg * sumPwr3 % MOD);
        ans = (ans >= MOD ? ans - MOD : ans);

        sumSeg -= A[i]; sumSeg -= A[j];
        while(sumSeg < 0) sumSeg += MOD;

        sumPwr3 -= cubeMod(i+1); sumPwr3 -= cubeMod(j+1);
        while(sumPwr3 < 0) sumPwr3 += MOD;
    }
    cout << ans << '\n';
}