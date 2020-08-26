#include <bits/stdc++.h>
using namespace std;

long long n;

bool is_prime() {
    for(long long i = 2; i*i <= n; i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}

int main(){
    cin >> n;
    if( is_prime() ) {
        cout << n;
    } else {
        long long G = 0;
        // --
        for(long long i = 2; i*i <= n; i++) {
            if(n % i == 0) {
                G = __gcd(G, i);
                G = __gcd(G, n/i);
            }
        }
        // --
        cout << G;
    }
}