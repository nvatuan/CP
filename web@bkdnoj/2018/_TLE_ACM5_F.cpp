#include <bits/stdc++.h>
#define MODUL 10007

using namespace std;

long fib (long long k){
	if( k == 0 ) return 0;
	if( 3 > k ) return 1;
	return( pow() % MODUL );
}

int main(){
	long long n;
	cin >> n;
	cout << fib(n);
	return 0;
}