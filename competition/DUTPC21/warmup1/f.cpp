#include <bits/stdc++.h>
using namespace std;

const int N = (int)(1e7) + 10;
int is_np[N];

void sieve() {
    is_np[0] = is_np[1] = 1;
    for (int i=2; i<N; i++)
        if (!is_np[i])
            for (long long j=1LL*i*i; j < N; j += i)
                is_np[j] = 1;
}

int prime(int k) {
    return !is_np[k];
}

int ans[N];

int main() {
    sieve();

    int a, b, k;
    cin >> a >> b >> k;

    int prevl;
    int l=a, r=a-1;
    int pr = 0;
    int ans=-1;

    while (r <= b) {
        while (pr < k) {
            r++;
            if (r > b) {
                if (ans != -1) {
                    ans = max(ans, b - prevl+1);
                }
                break;
            }
            pr += prime(r);
        }
        if (r > b) break;
        ans = max(ans, r - l + 1);

        prevl = l;

        pr -= prime(l);
        l++;
        r++;
        pr += prime(r);
    }

    cout << ans << endl;
}