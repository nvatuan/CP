#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

llong Com[55][55];
int _ComInit = false;
llong C(int k, int n) {
    if (!_ComInit) {
        Com[0][0] = 1;
        for (int i=1; i<55; i++) {
            Com[i][0] = 1;
            for (int j=1; j<=i; j++) 
                Com[i][j] = Com[i-1][j-1] + Com[i-1][j];
        }
        _ComInit = true;
    }
    if (k > n) return 0;
    return Com[n][k];
}

int N, K;
vector<llong> box;
llong A, B;

llong countWays(llong W, int start=0, int used=0) {
    if (used == K) return 1;
    if (start == N) return 0;

    if (box[start] > W) return countWays(W, start+1, used);
    else {
        llong result = 
            //countWays(W, start+1, used) + 
            C(K-used, N-start-1) +
            countWays(W-box[start], start+1, used+1);
        return result;
    }
}

int main() {
    cin >> N >> K;
    box.resize(N);
    for (llong &b : box) cin >> b;
    cin >> A >> B;
    
    sort(box.begin(), box.end(), greater<llong>());
    cout << countWays(B)  - countWays(A-1) << endl;
}