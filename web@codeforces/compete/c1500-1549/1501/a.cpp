#include <stdio.h>
#include <iostream>
using namespace std;

int n;
int a[10000], b[100000];
int tm[100000];

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) {
        scanf("%d%d", &a[i], &b[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &tm[i]);
    }

    int arrive;
    int depart=0;
    for (int i=0; i<n; i++) {
        arrive = depart + (a[i] - (i==0 ? 0 : b[i-1]) + tm[i]);
        depart = max(arrive + (b[i] - a[i]+1)/2, b[i]);
    }

    printf("%d\n", arrive);
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}