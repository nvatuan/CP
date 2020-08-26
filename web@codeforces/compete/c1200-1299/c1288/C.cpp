#include <bits/stdc++.h>
using namespace std;

const long long MOD = (long long)(1e9) + 7;

long long dpA[12][1002];
long long dpB[12][1002];
int N, M;

long long subA[1002], subB[1002];

int main() {
    cin >> N >> M;
    for(int ix = 1; ix <= N; ix++) {
        dpA[0][ix] = dpB[0][ix] = 1;
    }
    // --
    // generate A table
    for(int i = 1; i <= M; i++) {
        for(int new_a = 1; new_a <= N; new_a++) {
            for(int old_a = 1; old_a <= new_a; old_a++) {
                dpA[i][new_a] += dpA[i-1][old_a];
                dpA[i][new_a] %= MOD;
            }
            // dpA[i][new_a] -= dpA[i][new_a-1];
            // dpA[i][new_a] = (dpA[i][new_a] + MOD) % MOD;
        }
    }
    for(int i = 0; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            cout << dpA[i][j] << " ";
        }
        cout << endl;
    }
    // generate B table
    for(int i = 1; i <= M; i++) {
        for(int new_b = N; new_b >= 1; new_b--) {
            for(int old_b = new_b; old_b <= N; old_b++) {
                dpB[i][new_b] += dpB[i-1][old_b];
                dpB[i][new_b] %= MOD;
            }
            // dpB[i][new_b] -= dpB[i][new_b+1];
            // dpB[i][new_b] = (dpB[i][new_b] + MOD) % MOD;
        }
    }

    cout << endl;
    for(int i = 0; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            cout << dpB[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    //
    for(int i = 1; i <= N; i++) {
        subA[i] = dpA[M][i] - dpA[M][i-1];
    }
    for(int i = 1; i <= N; i++) {
        subB[i] = dpB[M][i] - dpB[M][i+1];
    }

    long long ANS = 0;
    for(int CAP = 1; CAP <= N; CAP++) {
        ANS += (subA[CAP] * subB[CAP]);
        ANS %= MOD;
    }
    cout << ANS;
}