#include <bits/stdc++.h>
using namespace std;

int n, m;
int head[20002], knight[20002];
long long ans = -1;

int main() {
    while(scanf("%d%d", &n, &m), n && m) {
        ans = 0;
        for(int i = 0; i < n; i++) scanf("%d", &head[i]);
        for(int i = 0; i < m; i++) scanf("%d", &knight[i]);
        //
        sort(head, head + n);
        sort(knight, knight + m);
        //
        int hp = 0, kp = 0;
        while(hp < n) {
            while( knight[kp] < head[hp] ) {
                kp++;
                if(kp == m) goto NO;
            }
            ans += knight[kp];
            hp++;
            kp++;
            if(hp < n && kp >= m) goto NO;
        }
        goto YES;
NO:
        printf("Loowater is doomed!\n");
        continue;
YES:
        printf("%lld\n", ans);
    }
}