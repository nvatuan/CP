#include <bits/stdc++.h>
using namespace std;

int N;
long long K;
int vol[100001];
int ans1, ans2;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> vol[i];

    // -- find earliest moment N-th barrel is filled
    vector<int> filled (N, 0);
    auto check1 = [&](int t) -> bool {
        long long cum = 0;
        for (int i = 0; i < N; i++) {
            filled[i] = false;
            if (t*K >= vol[i]) {
                cum += (t*K - vol[i]);
                filled[i] = true;
            } else 
            if (t*K + cum >= vol[i]) {
                cum -= (vol[i] - t*K);
                filled[i] = true;
            } else {
                filled[i] = false;
                cum = 0;
            }
        }
        return filled[N-1];
    };
    int tL = 1, tR = 1000000000;
    while (tL < tR) {
        int tMid = (tL + tR) / 2;
        if (check1(tMid)) tR = tMid;
        else tL = tMid + 1;
    }
    ans1 = tL;

    // -- find earliest moment N barrels are filled
    auto check2 = [&](int t) -> bool {
        long long cum = 0;
        for (int i = 0; i < N; i++) {
            if (t*K >= vol[i]) {
                cum += (t*K - vol[i]);
            } else 
            if (t*K + cum >= vol[i]) {
                cum -= (vol[i] - t*K);
            } else {
                cum = 0;
                return false;
            }
        }
        return true;
    };
    tL = 1, tR = 1000000000;
    while (tL < tR) {
        int tMid = (tL + tR) / 2;
        if (check2(tMid)) tR = tMid;
        else tL = tMid + 1;
    }
    ans2 = tL;
    //

    cout << ans1 << ' ' << ans2 << endl;
}