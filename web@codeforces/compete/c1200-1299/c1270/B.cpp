#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int a[200001];

int main() {
    for(cin >> t; t; t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        // --
        bool yes = 0;
        for(int i = 0; i < n-1; i++) {
            if( abs(a[i] - a[i+1]) >= 2 ) {
                printf("YES\n%d %d\n", i+1, i+2);
                yes = 1;
                break;
            }
        }
        if(!yes) {
            printf("NO\n");
        }
    }
    return 0;
}