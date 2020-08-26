#include <bits/stdc++.h>
using namespace std;

int n, k;

void binrep(int k) {
    stack<int> S;
    for(int i = 0; k>>i; i++) {
        S.push( (k>>i) & 1);
    }
    while(!S.empty()) {
        printf("%d", S.top());
        S.pop();
    }
    return;
}

void f(int n) {
    for(int i = 0; i < 10000000; i++) {
        if( n + i == (n^i)<<1 ) {
            printf("%d | ", n); binrep(n);
        
            printf("\n%d | ", i); binrep(i);
            printf("\nSUM  = %d | ", n+i); binrep(n+i);
            printf("\nXSum = %d | ", (n^i)*2); binrep((n^i)*2);
            return;
        }
    }
    cerr << "NO!\n";
}

int main() {
    while(1) {
        cout << "\ninput = "; cin >> k;
        f(k);
    }
    return 0;
}