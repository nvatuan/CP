#include <bits/stdc++.h>
using namespace std;

int N;
int A[20000];

int main() {
    cin >> N;
    assert(N <= 1000);
    for (int i = 0; i < N; i++) cin >> A[i];

    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            ans += (1LL*A[i] > 2LL*A[j]);
    
    cout << ans << '\n';
}