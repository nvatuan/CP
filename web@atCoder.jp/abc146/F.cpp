#include <bits/stdc++.h>
using namespace std;

int furthest[int(1e6)];
int no[int(1e6)];
int N, M;

int main() {
    cin >> N >> M;
    for(int i = 0; i <= N; i++) {
        char c;
        cin >> c;
        no[i] = (c == '1');
    }
    // --
    for(int i = 0; i < N; i++) {
        if(no[i] && no[i+1]) no[i+1] = no[i] + 1;
    }
    if(no[0] || no[N]) {
        cout << -1;
        return 0;
    }
    for(int i = 0; i <= N; i++) {
        if(no[i] >= M) {
            cout << -1;
            return 0;
        }
    }
    // --
    for(int i = N; i >= 0; i--) {
        if(!no[i + M]) {
            furthest[i] = min(N, i + M);
        } else {
            furthest[i] = min(N, (i+M) - no[i+M]);
        }
    }
    
    //--
    int i = 0;
    while(i != N) {
        printf("%d ", furthest[i] - i);
        i = furthest[i];
    }
}