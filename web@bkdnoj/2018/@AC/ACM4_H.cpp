#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i < b; i++)

using namespace std;

void primecheck(long long n){
	FOR(i, 2, sqrt(n)+1)
		if( n % i == 0 ){ cout << "NO"; return; }
	cout << "YES";
	return;
}

int main(){
	long long n;
	cin >> n;

	if(n == 1) cout << "NO";
	else if(n == 2) cout << "YES";
		 else primecheck(n);
}