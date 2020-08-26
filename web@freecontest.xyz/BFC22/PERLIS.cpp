#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int n;

int b[1000];
int dp[100];
int b2[100];

int check() {
    fill(dp, dp + n+1, 1);

    for (int i = n-1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) 
            if (a[i] < a[j])
                dp[i] = max(dp[i], dp[j] + 1);
    }
    
    for (int i = 0; i < n; i++)
        if (b[i] != dp[i]) return 0;
    return 1;
}


int main() {
    cin >> n;
    assert(n <= 10);
    for (int i = 0; i < n; i++) cin >> b[i];
    a.resize(n);
    for (int i = 1; i <= n; i++) a[i-1] = i;

    do {
        if (check()) {
            for (int i : a) cout << i << ' ';
            cout << '\n';
        }
    } while (next_permutation(a.begin(), a.end()));

}