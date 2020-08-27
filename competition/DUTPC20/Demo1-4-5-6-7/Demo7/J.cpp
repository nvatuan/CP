#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

int n;
int p[100000];

int main() {
    cin >> n;
    p[0] = 0;
    for (int i = 1; i <= n; i++) cin >> p[i];
    sort(p+1, p+1+n);
    
    int stop = 0;
    while (p[stop+1] - 1 == p[stop]) stop++;

    if (stop == n) {cout << "CPU\n"; return 0;}

    int nimsum = 0;
    for (int i = n; i > stop; i -= 2) {
        nimsum ^= (p[i] - p[i-1] - 1);
    }
    cout << (nimsum ? "TUAN" : "CPU") << '\n';
}