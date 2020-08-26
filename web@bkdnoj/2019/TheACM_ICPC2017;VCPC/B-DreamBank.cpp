#include <bits/stdc++.h>
#define FOR(i, a, b) for(i = a; i < b; i++)
using namespace std;

long long qexp(double n, long long k, long long m){
	if(k == 0) return 1;
	if(k == 1) return n % m;
	else if(k % 2 == 0) return( qexp(n*n % m, k/2, m) );
	 	 else return( qexp(n*n % m, k/2, m) * n % m);
}

int main(){
	long long t, m
	double r = sqrt(11)+3 + 1;
	cin >> n, m;

	cout << (int) floor(qexp(r, t, m));
}