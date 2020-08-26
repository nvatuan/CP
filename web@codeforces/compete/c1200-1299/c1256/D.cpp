#include <bits/stdc++.h>
using namespace std;

long long q, n, k;
string S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //
    for(cin >> q; q; q--) {
        cin >> n >> k >> S;
        // --
        int zeroCount = 0;
        int L = S.length();
        for(int i = 0; i < L; i++) {
            if(S[i] == '0' and k > 0) {
                if(i == zeroCount) {
                    zeroCount++;
                    continue;
                }
                // opcount = i - zeroCount
                if(k >= i - zeroCount) {
                    S[zeroCount] = '0';
                    S[i] = '1';

                    k -= (i - zeroCount);
                    zeroCount++;
                } else {
                    S[i]     = '1';
                    S[i - k] = '0';
                    break;
                }
            }
        }
        //
        cout << S << "\n";
    }
}