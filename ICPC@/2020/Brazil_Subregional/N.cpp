#include <bits/stdc++.h>
using namespace std;

typedef long long llong;
const int N = 31622778;
int np[N];
vector<llong> primes;

void sieve() {
    np[0] = np[1] = 1;
    for (int i=2; i<N; i++)
        if (!np[i]) {
            for (llong j=1LL*i*i; j<N; j+=i) np[j] = 1;
            primes.push_back(i);
        }
}

int main() {
    sieve();
    cout << primes.size() << endl;
}