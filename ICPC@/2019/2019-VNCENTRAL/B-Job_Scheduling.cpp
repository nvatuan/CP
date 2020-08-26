#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int N;

int main() {
    cin >> N;
    vector<int64> D(N, 0);
    vector<int64> T(N, 0);
    for(int i = 0; i < N; i++) cin >> D[i] >> T[i];
    // --
    vector<int> done(N, 0);
    vector<int64> answer(N, -1);
    //
    int64 currentTime = 0;

    for(int i = 0; i < N; i++) {
        int64 minIdx = -1;
        int64 minCost = INT_MAX;
        for( int j = 0; j < N; j++ ){
            if(!done[j]) {
                if(minCost > (currentTime + T[j] - D[j])) {
                    minCost = currentTime + T[j] - D[j];
                    minIdx = j;
                }
            }
        }
        done[minIdx] = 1;
        answer[minIdx] = max(currentTime + T[minIdx] - D[minIdx], 0LL);
        currentTime += T[minIdx];
    }
    // --
    for(int64 i = 0; i < N; i++) {
        cout << answer[i] << '\n';
    }
}