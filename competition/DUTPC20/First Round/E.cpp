#include <bits/stdc++.h>
using namespace std;

const int SIZE = (int)(1e5);
const int mod=1e9+7;

int n, k;
int a[SIZE + 1];
int L[SIZE + 1];
int dp[SIZE+1];
int pre[SIZE+1];

void solve() {
    vector<int> segs;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    map<int, int> cnt;
    queue<int> Queue;

    for (int i = 1; i <= n; i++) {
        // printf("%d\n", cnt[a[i]]);
        if (cnt[a[i]] < k) {
            cnt[a[i]]++;
            Queue.push(i);
        }
        else {
            while (cnt[a[i]] == k) {
                // printf("Pop %d\n", Queue.front());

                cnt[a[Queue.front()]]--;
                Queue.pop();
            }

            cnt[a[i]]++;
            Queue.push(i);
        }
        // printf("i = %d -> L = %d\n", i, Queue.front() );
        L[i] = Queue.front();
    }
    /* for (int i=1;i<=n;i++)
    {
        cout << L[i]<<' ';
    }
    cout << endl; */
    dp[0]=1;
    pre[0]=1;
    for (int i=1;i<=n;i++)
    {
        if (L[i]-2<0)
        {
            dp[i]=(pre[i-1]+mod)%mod;
            pre[i]=(pre[i-1]+dp[i])%mod;
        }
        else
        {
            dp[i]=(pre[i-1]-pre[L[i]-2]+mod)%mod;
            pre[i]=(pre[i-1]+dp[i])%mod;
        }
    }
    cout << dp[n]<<endl;
}
int main()
{
    // freopen("data.inp", "r", stdin);
    // freopen("data.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
