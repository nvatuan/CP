#include<bits/stdc++.h>
using namespace std;

int n;
int k[(int)(2e5)+10];

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", k+i);

    queue<int> q;
    int l=0, r=0;
    map<int, int> cnt;
    int ans=0;

    while (r < n) {
        cnt[k[r]]++;
        while (cnt[k[r]] > 1) {
            cnt[k[l]]--;
            l++;
        }
        r++;
        ans = max(ans, r-l);
    }
    printf("%d\n", ans);
}
