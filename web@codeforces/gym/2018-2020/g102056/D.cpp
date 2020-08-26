#include <bits/stdc++.h>
using namespace std;

int main() {
    int tmp, T, m, n;
    for(cin >> T; T; T--) {
        cin >> n >> m;
        if( n <= m )    printf("Yes\n");
        else            printf("No\n");
        while(n--) cin >> tmp;
        while(m--) cin >> tmp;
    }
}