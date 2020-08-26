#include <bits/stdc++.h>
using namespace std;

long long N;

inline int sumDig(long long k) {
    int s = 0;
    while(k) {
        s += (k % 10);
        k /= 10;
    }
    return s;
} 

const int size = 10000001;
int minPrime[size + 1];
vector<int> prime;
void sieve(){
    //fill(minPrime, minPrime + size, 1);
    minPrime[0] = minPrime[1] = 1;
    for(long long i = 2; i <= size; i++) {
        if(!minPrime[i]) {
            prime.push_back(i);
            minPrime[i] = i;
            for(long long j = i*i; j <= size; j += i) {
                if(!minPrime[j]) minPrime[j] = i;
            }
        }
    }
    reverse(prime.begin(), prime.end());
}

bool check(long long n) {
    int s1 = sumDig(n);
    int s2 = 0;
    unsigned p = 0;
    //
    while(1) {
        if( n > size ) {
            for(;p < prime.size(); p++) {
                if( n % prime[p] == 0) {
                    while(n % prime[p] == 0) {
                        s2 += sumDig(prime[p]);
                        n /= prime[p];
                    }
                    break;
                }
            }
            if(p == prime.size()) break;
        } else {
            while(minPrime[n] != 1) {
                s2  += sumDig(minPrime[n]);
                n   /= minPrime[n];
            }
            if(minPrime[n] == 1) break;
        }
    }
    //
    if(n != 1) s2 += sumDig(n);
    //
    return (s1 == s2);
}


int main() {
    sieve();
    cin >> N;
    for(; !check(N); N++);
    cout << N;
}